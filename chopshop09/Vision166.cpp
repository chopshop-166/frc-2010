/********************************************************************************
*  Project   		: Chopshop 2009
*  File Name  		: Vision166.cpp          
*  Contributors   	: ELF
*  Creation Date 	: February 2, 2008
*  Revision History	: Source code & revision history maintained at code.google.com    
*  File Description	: Code for vision processing
*/
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

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(true)dprintf

// Vision task constructor
Team166Vision::Team166Vision(void)
{
	VisionLog vl;                 // Vision log
	
	// Initialize assorted fields	
	targetAcquired = false;			// target not acquired
	bearing = 0.0;					// current horizontal normalized servo position	
	tilt = 0.0;						// current vertical normalized servo position	
	
	// Start our task
	Start((char *)"166VisionTask");	

	// remember to use jumpers on the sidecar for the Servo PWMs
	horizontalServo = new Servo(T166_HORIZONTAL_SERVO_CHANNEL);  // create horizontal servo
	verticalServo = new Servo(T166_VERTICAL_SERVO_CHANNEL);  // create vertical servo

	/* set up debug output: 
	 * DEBUG_OFF, DEBUG_MOSTLY_OFF, DEBUG_SCREEN_ONLY, DEBUG_FILE_ONLY, DEBUG_SCREEN_AND_FILE 
	 */
	SetDebugFlag ( DEBUG_SCREEN_ONLY  ) ;
	
#if 0 //moved to robot task
	
	/* start the CameraTask	 */
	if (StartCameraTask(15, 0, k160x120, ROT_0) == -1) {
		DPRINTF( LOG_ERROR,"Failed to spawn camera task; exiting. Error code %s", 
				GetVisionErrorText(GetLastVisionError()) );
	}
	/* allow writing to vxWorks target */
	Priv_SetWriteFileAllowed(1);   	
#endif	

	// initialize pan variables
	servoDeadband = 0.01;					// move if > this amount 
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
	greenSpec.saturation.minValue = 28;   //test - was 58
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
 * Set servo positions (0.0 to 1.0) translated from normalized values (-1.0 to 1.0). 
 * 
 * @param normalizedHorizontal Pan Position from -1.0 to 1.0.
 * @param normalizedVertical Tilt Position from -1.0 to 1.0.
 */
void Team166Vision::SetServoPositions(float normalizedHorizontal, float normalizedVertical)	{

	float servoH = NormalizeToRange(normalizedHorizontal);
	float servoV = NormalizeToRange(normalizedVertical);
	
	float currentH = horizontalServo->Get();		
	float currentV = verticalServo->Get();
	
	/* make sure the movement isn't too small */
	if ( fabs(servoH - currentH) > servoDeadband ) {
		horizontalServo->Set( servoH );
		/* save new normalized horizontal position */
		bearing = RangeToNormalized(servoH, 1);
	}
	if ( fabs(servoV - currentV) > servoDeadband ) {
		verticalServo->Set( servoV );
		//verticalPosition = RangeToNormalized(servoV, 1);
		tilt = RangeToNormalized(servoV, 1);
	}
}	
/**
 * Adjust servo positions (0.0 to 1.0) translated from normalized values (-1.0 to 1.0). 
 * 
 * @param normalizedHorizontal Pan adjustment from -1.0 to 1.0.
 * @param normalizedVertical Tilt adjustment from -1.0 to 1.0.
 */
void Team166Vision::AdjustServoPositions(float normDeltaHorizontal, float normDeltaVertical)	{
					
	/* adjust for the fact that servo overshoots based on image input */
	normDeltaHorizontal /= 8.0;
	normDeltaVertical /= 4.0;
	
	/* compute horizontal goal */
	float currentH = horizontalServo->Get();
	float normCurrentH = RangeToNormalized(currentH, 1);
	float normDestH = normCurrentH + normDeltaHorizontal;	
	/* narrow range keep servo from going too far */
	if (normDestH > 1.0) normDestH = 1.0;
	if (normDestH < -1.0) normDestH = -1.0;			
	/* convert input to servo range */
	float servoH = NormalizeToRange(normDestH);

	/* compute vertical goal */
	float currentV = verticalServo->Get();
	float normCurrentV = RangeToNormalized(currentV, 1);
	float normDestV = normCurrentV + normDeltaVertical;	
	if (normDestV > 1.0) normDestV = 1.0;
	if (normDestV < -1.0) normDestV = -1.0;
	/* convert input to servo range */
	float servoV = NormalizeToRange(normDestV, 0.2, 0.8);

	/* make sure the movement isn't too small */
	if ( fabs(currentH-servoH) > servoDeadband ) {
		horizontalServo->Set( servoH );		
		/* save new normalized horizontal position */
		//horizontalPosition = RangeToNormalized(servoH, 1);
		bearing = RangeToNormalized(servoH, 1);
	}			
	if ( fabs(currentV-servoV) > servoDeadband ) {
		verticalServo->Set( servoV );
		tilt = RangeToNormalized(servoV, 1);
	}
}

// process images to find target
void Team166Vision::AcquireTarget() {
	//DPRINTF(LOG_DEBUG,"start");
	
	// incremental tasking toward dest (-1.0 to 1.0)
	float incrementH, incrementV;					
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

			// get center of target 
			// Average the color two particles to get center x & y of combined target
			horizontalDestination = (pinkReport.center_mass_x_normalized + 
					greenReport.center_mass_x_normalized) / 2;	
			verticalDestination = (pinkReport.center_mass_y_normalized + 
					greenReport.center_mass_y_normalized) / 2;
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
		
		//incrementH = horizontalDestination - horizontalPosition;
		incrementH = horizontalDestination - bearing;
		incrementV = verticalDestination - tilt;
		// you may need to reverse this based on your servo installation
		AdjustServoPositions( incrementH, incrementV);  

		ShowActivity ("** %s & %s found: Servo: x: %f  y: %f height: %i  **", 
				pinkSpec.name, greenSpec.name, horizontalDestination, verticalDestination,
				targetHeight);	
		
	} else { //if (!staleImage) {  // new image, but didn't find two colors
		
		// adjust sine wave for panning based on last movement direction
		if(horizontalDestination > 0.0)	{ sinStart = PI/2.0; }
		else { sinStart = -PI/2.0; }

		/* pan to find color after a short wait to settle servos
		 * panning must start directly after panInit or timing will be off */				
		if (panIncrement == 3) {	
			DPRINTF(LOG_DEBUG, "pan initializing");
			/* don't reset target position & height immediately */
			targetHeight = 0;
			targetArea = 0.0;
			panInit(8.0);		// number of seconds for a pan
		}
		else if (panIncrement > 3) {	
			panForTarget(horizontalServo, sinStart);	

			/* Vertical action: In case the vertical servo is pointed off center,
			 * center the vertical after several loops searching */
			if (panIncrement == 20) { 
				verticalServo->Set( 0.5 );	
				DPRINTF(LOG_DEBUG, "pan resetting vertical servo");
			}
		}
		panIncrement++;		
#if 0		
		// log stuff
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
#endif
		ShowActivity ("** %s and %s not found                                    ", pinkSpec.name, greenSpec.name);
	}  // end if found color
}



// Main function of the vision task
int Team166Vision::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{

	Robot166 *lHandle;            // Local handle
	sample_count = 0;             // Initialize Count of log samples
	
	// Let the world know we're in
	DPRINTF(LOG_INFO, "In the 166 vision task\n");
		
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
	DPRINTF(LOG_DEBUG, "SERVO - looking for COLOR %s ABOVE %s", pinkSpec.name, greenSpec.name);
	
	/* initialize position and destination variables
	* position settings range from -1 to 1
	* setServoPositions is a wrapper that handles the conversion to range for servo 
	*/		
	horizontalDestination = 0.0;		// final destination range -1.0 to +1.0
	verticalDestination = 0.0;		// final destination range -1.0 to +1.0

	// set servos to start at center position
	SetServoPositions(horizontalDestination, verticalDestination);
					
	/* for controlling loop execution time */
	float loopTime = 0.05;			
	double currentTime = GetTime();
	double lastTime = currentTime;
	
    // General main loop (while in Autonomous or Tele mode)
	printf("Vision task is getting ready...\n");
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {

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
