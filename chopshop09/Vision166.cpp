
#include "WPILib.h"
#include <math.h>

// 166 include files
#include "Vision166.h"
#include "MemoryLog166.h"

// WPILib include files for vision
#include "AxisCamera.h" 
#include "BaeUtilities.h"
#include "FrcError.h"
#include "Target166.h"

// To locally enable debug printing: set VisionDemo_debugFlag to a 1, to disable set to 0
int Vision166_debugFlag = 1;
#define DPRINTF if(Vision166_debugFlag)dprintf

// Sample in memory buffer
struct vbuf166
{
	struct timespec tp;               // Time of snapshot
	float bearing;                    // Target bearing
	
};

// Sample Memory Log
class VisionLog : public MemoryLog166
{
public:
	VisionLog() : MemoryLog166(128*1024) {return;};
	~VisionLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float b);     // Log the bearing
};

// Write one buffer into memory
unsigned int VisionLog::PutOne(float b)
{
	struct vbuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct vbuf166 *)GetNextBuffer(sizeof(struct vbuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		ob->bearing = b;
		return (sizeof(struct vbuf166));
	}
	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int VisionLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct vbuf166 *ab = (struct vbuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->bearing);
	
	// Done
	return (sizeof(struct vbuf166));
}


// Vision task constructor
Team166Vision::Team166Vision(void)
{
	// Initialize assorted fields	
	targetAcquired = false;			// target not acquired
	bearing = 0.0;					// current normalized servo position	
	
	// Start our task
	Start((char *)"166VisionTask");	

	// remember to use jumpers on the sidecar for the Servo PWMs
	horizontalServo = new Servo(10); 		// create horizontal servo

	/* set up debug output: 
	 * DEBUG_OFF, DEBUG_MOSTLY_OFF, DEBUG_SCREEN_ONLY, DEBUG_FILE_ONLY, DEBUG_SCREEN_AND_FILE 
	 */
	SetDebugFlag ( DEBUG_FILE_ONLY  ) ;

	/* start the CameraTask	 */
	if (StartCameraTask(framesPerSecond, 0, k160x120, ROT_0) == -1) {
		DPRINTF( LOG_ERROR,"Failed to spawn camera task; exiting. Error code %s", 
				GetVisionErrorText(GetLastVisionError()) );
	}
	/* allow writing to vxWorks target */
	Priv_SetWriteFileAllowed(1);   	
	

	// initialize pan variables
	servoDeadband = 0.01;					// move if > this amount 
	framesPerSecond = 15;					// number of camera frames to get per second
	sinStart = 0.0;							// control where to start the sine wave for pan
	panIncrement = 0;						// pan needs a 1-up number for each call
	
	//initialize targetting variables
	memset(&pinkReport,0,sizeof(ParticleAnalysisReport));			// initialize particle analysis report
	memset(&greenReport,0,sizeof(ParticleAnalysisReport));			// initialize particle analysis report

	/* image data for tracking - override default parameters if needed */
	/* recommend making PINK the first color because GREEN is more 
	 * subsceptible to hue variations due to lighting type so may
	 * result in false positives */
	// PINK
	sprintf (pinkSpec.name, "PINK");
	pinkSpec.hue.minValue = 220;   
	pinkSpec.hue.maxValue = 255;  
	pinkSpec.saturation.minValue = 75;   
	pinkSpec.saturation.maxValue = 255;      
	pinkSpec.luminance.minValue = 85;  
	pinkSpec.luminance.maxValue = 255;
	// GREEN
	sprintf (greenSpec.name, "GREEN");
	greenSpec.hue.minValue = 55;   
	greenSpec.hue.maxValue = 125;  
	greenSpec.saturation.minValue = 58;   
	greenSpec.saturation.maxValue = 255;    
	greenSpec.luminance.minValue = 92;  
	greenSpec.luminance.maxValue = 255;

	mode = IMAQ_HSL; 				// RGB or HSL	
	savedImageTimestamp = 0.0;		// timestamp of last image acquired
};
	
// Vision task destructor
Team166Vision::~Team166Vision(void)
{		
	return;
};

/////////////// Accessors
bool Team166Vision::IsTargetAcquired() { return targetAcquired; }
double Team166Vision::GetTargetArea() { return targetArea; };
int Team166Vision::GetTargetHeight() { return targetHeight; };
float Team166Vision::GetBearing() { return bearing; }


/**
 * Set servo position(0.0 to 1.0) translated from normalized values (-1.0 to 1.0). 
 * 
 * @param normalizedHorizontal Pan Position from -1.0 to 1.0.
 */
void Team166Vision::SetServoPosition(float normalizedHorizontal)	{

	float servoH = NormalizeToRange(normalizedHorizontal);	
	float currentH = horizontalServo->Get();	
	
	/* make sure the movement isn't too small */
	if ( fabs(servoH - currentH) > servoDeadband ) {
		horizontalServo->Set( servoH );
		/* save new normalized horizontal position */
		bearing = RangeToNormalized(servoH, 1);
	}
}

/**
 * Adjust servo positions(0.0 to 1.0) translated from normalized values (-1.0 to 1.0). 
 * 
 * @param normalizedHorizontal Pan adjustment from -1.0 to 1.0.
 */
void Team166Vision::AdjustServoPosition(float normDeltaHorizontal)	{
					
	/* adjust for the fact that servo overshoots based on image input */
	normDeltaHorizontal /= 8.0;
	
	/* compute horizontal goal */
	float currentH = horizontalServo->Get();
	float normCurrentH = RangeToNormalized(currentH, 1);
	float normDestH = normCurrentH + normDeltaHorizontal;	
	/* narrow range keep servo from going too far */
	if (normDestH > 1.0) normDestH = 1.0;
	if (normDestH < -1.0) normDestH = -1.0;			
	/* convert inputs to servo range */
	float servoH = NormalizeToRange(normDestH);

	/* make sure the movement isn't too small */
	if ( fabs(currentH-servoH) > servoDeadband ) {
		horizontalServo->Set( servoH );		
		/* save new normalized horizontal position */
		bearing = RangeToNormalized(servoH, 1);
	}			
}	


// process images to find target
void Team166Vision::AcquireTarget() {
	dprintf(LOG_DEBUG,"start");
	
	// incremental tasking toward dest (-1.0 to 1.0)
	float incrementH;					
	bool staleImage; 
	
	// calculate servo position based on colors found 
	if ( FindTwoColors(pinkSpec, greenSpec, ABOVE, &pinkReport, &greenReport) ){
		//PrintReport(&par2);
		targetAcquired = true;
		// reset pan		
		panIncrement = 0;  		
		if (pinkReport.imageTimestamp == savedImageTimestamp) {
			// This image has been processed already, 
			// so don't do anything for this loop 
			staleImage = true;
			DPRINTF(LOG_DEBUG, "STALE IMAGE");
			
		} else {
			// The target was recognized
			// save the timestamp
			staleImage = false;
			savedImageTimestamp = pinkReport.imageTimestamp;	
			DPRINTF(LOG_DEBUG,"image timetamp: %lf", savedImageTimestamp);

			// number of pixels 
			targetHeight = pinkReport.boundingRect.height + greenReport.boundingRect.height;
			targetArea = pinkReport.particleArea + greenReport.particleArea;
		}
	} else {  // need to pan 
		targetAcquired = false;
	} 
	
	if(targetAcquired && !staleImage) {	
		/* Move the servo a bit each loop toward the destination.
		 * Alternative ways to task servos are to move immediately vs.
		 * incrementally toward the final destination. Incremental method
		 * reduces the need for calibration of the servo movement while
		 * moving toward the target.
		 */
		incrementH = horizontalDestination - horizontalPosition;
		// you may need to reverse this based on your vertical servo installation
		AdjustServoPosition( incrementH);  

		ShowActivity ("** %s & %s found: Servo: x: %f  height: %i  **", 
				pinkSpec.name, greenSpec.name, horizontalDestination, targetHeight);	
		
	} else { //if (!staleImage) {  // new image, but didn't find two colors
		
		// adjust sine wave for panning based on last movement direction
		if(horizontalDestination > 0.0)	{ sinStart = PI/2.0; }
		else { sinStart = -PI/2.0; }

		/* pan to find color after a short wait to settle servos
		 * panning must start directly after panInit or timing will be off */				
		if (panIncrement == 3) {	
			/* don't reset target position & height immediately */
			targetHeight = 0;			
			panInit(8.0);		// number of seconds for a pan
		}
		else if (panIncrement > 3) {	
			panForTarget(horizontalServo, sinStart);	
		}
		panIncrement++;		

		ShowActivity ("** %s and %s not found                                    ", pinkSpec.name, greenSpec.name);
	}  // end if found color
}



// Main function of the vision task
int Team166Vision::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{

	Robot166 *lHandle;            // Local handle
	VisionLog vl;                 // Vision log
	int sample_count = 0;         // Count of log samples
	
	// Let the world know we're in
	printf("In the 166 vision task\n");
		
	// Indicate that we've now completed initialization
	MyTaskInitialized = 1;
		
	// Ensure we get into Autononmous or Tele Operasted mode
	while (!Robot166::getInstance() ||
	       ((Robot166::getInstance()->RobotMode != T166_AUTONOMOUS) &&
	    	(Robot166::getInstance()->RobotMode != T166_OPERATOR))) {
		Wait (0.050); // 50ms
	}
	MyTaskInitialized = 2;
	lHandle = Robot166::getInstance();
	
	// initialize vision stuff

	// image data for tracking
	TrackingThreshold td = GetTrackingData(RED, FLUORESCENT);
	
	
	DPRINTF(LOG_DEBUG, "SERVO - looking for COLOR %s ", td.name);
	
	/* initialize position and destination variables
	* position settings range from -1 to 1
	* setServoPositions is a wrapper that handles the conversion to range for servo 
	*/		
	horizontalDestination = 0.0;		// final destination range -1.0 to +1.0
	
	// bearing is current position range -1.0 to +1.0
	bearing = RangeToNormalized(horizontalServo->Get(),1);	
	
	// set servos to start at center position
	SetServoPosition(horizontalDestination);
			
	/* for controlling loop execution time */
	float loopTime = 0.05;			
	double currentTime = GetTime();
	double lastTime = currentTime;
	
    // General main loop (while in Autonomous or Tele mode)
	printf("Vision task is getting ready...\n");
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		float b=1.66;
		
		// Should we log this value?
		if (sample_count < 200) {
			vl.PutOne(b);
			sample_count++;
		} else {
			if (sample_count == 200) {
				vl.DumpToFile("vision.csv");
				sample_count++;
			}
		}
		MyWatchDog = 1;
		
		AcquireTarget();
		
		// sleep to keep loop at constant rate
		// this helps keep pan consistant
		// elapsed time can vary significantly due to debug printout
		currentTime = GetTime();			
		lastTime = currentTime;					
		if ( loopTime > ElapsedTime(lastTime) ) {
			Wait( loopTime - ElapsedTime(lastTime) );	// seconds
		}			
	}
	return (0);
}
