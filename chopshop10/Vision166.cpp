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

// WPILib include files for vision
#include "AxisCamera.h" 
#include "BaeUtilities.h"
#include "FrcError.h"
#include "Target166.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf
// To show activity printout set true
#define SHOWACTIVITY 0

// Vision task constructor
Team166Vision::Team166Vision(void) :
	visionActive(true),             // vision flag for teleop mode
	bearing(0.0),					// current horizontal normalized servo position	
	targetAcquired(false),			// target not acquired
	tilt(0.0),						// current vertical normalized servo position	
	verticalDefault(0.4),			// default vertial servo position
	servoDeadband(0.005),			// pan flag to move if > this amount 
	sinStart(0.0),					// control where to start the sine wave for pan
	panIncrement(0),				// pan 1-up number for each call
	mode(IMAQ_HSL), 			    // Color mode (RGB or HSL) for image processing	
	savedImageTimestamp(0.0),		// timestamp of last image acquired
	alliance(BLUE)					// default alliance
{		
	// remember to use jumpers on the sidecar for the Servo PWMs
	printf("Vision constructor\n");
	horizontalServo = new Servo(T166_HORIZONTAL_SERVO_CHANNEL);  // create horizontal servo
	verticalServo = new Servo(T166_VERTICAL_SERVO_CHANNEL);  // create vertical servo

	robotHandle=Robot166::getInstance();

	dsHandle = DriverStation::GetInstance();

	/* set up debug output: 
	 * DEBUG_OFF, DEBUG_MOSTLY_OFF, DEBUG_SCREEN_ONLY, DEBUG_FILE_ONLY, DEBUG_SCREEN_AND_FILE 
	 */
	SetDebugFlag ( DEBUG_SCREEN_ONLY  ) ;
	
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

	// Start our task
	Start((char *)"166VisionTask", 0.050);	
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

/////////////// Control

/**
 * @brief Set vision processing on or off
 * If off, the main loop just idles and monitors this flag
 * 
 * @param onFlag if true, process images to find the target
 */
void Team166Vision::SetVisionOn(bool onFlag) {
	if (onFlag) { visionActive = true; }
	else { visionActive = false;	}
}

/**
 * @brief Determine whether the second color (GREEN) is above or below 
 * the first color (PINK)
 * 
 * @return SecondColorPosition if alliance is BLUE, ABOVE, otherwise, BELOW
 */
SecondColorPosition Team166Vision::GetRelativePosition() {

	if (lHandle->RobotMode == T166_OPERATOR or 
			lHandle->RobotMode == T166_AUTONOMOUS) {
#if false  // change to true for FIELD MANAGEMENT SYSTEM
	DriverStation::Alliance fmsAlliance = dsHandle->GetAlliance();

	switch (fmsAlliance)  {
	// return relative position for opposing alliance target
	case DriverStation::kRed:    //pink on top
		DPRINTF(LOG_DEBUG, "RED alliance");  
		return ABOVE;  //green is above pink
		break;
	case DriverStation::kBlue:   // green on bottom
		DPRINTF(LOG_DEBUG, "BLUE alliance");
		return BELOW; 
		break;
	case DriverStation::kInvalid:
		DPRINTF(LOG_DEBUG, "INVALID INPUT FROM FMS");
		break;
	}
	
#else  // enable to use the DRIVERSTATION SWITCH
	
	// must not be in a competition, so use the switch on the DS
	int intAlliance = lHandle->GetAllianceSwitch();
	DriverStation::Alliance myAlliance = (DriverStation::Alliance)intAlliance;
	//DPRINTF(LOG_DEBUG, "Alliance value from GetAllianceSwitch = %i", intAlliance);
	
	switch (myAlliance)  {
	// return relative position for opposing alliance target
	case DriverStation::kRed:    //pink on top	{
		DPRINTF(LOG_DEBUG, "RED alliance from SWITCH");
		return BELOW;  //TODO: check this	
		break;
	case DriverStation::kBlue:   // green on top
		DPRINTF(LOG_DEBUG, "BLUE alliance from SWITCH");
		return ABOVE;  //TODO: check this	
		break;
	case DriverStation::kInvalid:
		DPRINTF(LOG_DEBUG, "INVALID INPUT SWITCH GET");
		break;					
	}
#endif
	
	DPRINTF(LOG_DEBUG, "RED alliance DEFAULT"); 
	return BELOW;
	}
	
	DPRINTF(LOG_DEBUG, "NOT READY returning RED"); 
	return BELOW;
}

/**
 * Set servo positions (0.0 to 1.0) 
 * 
 * @param servoHorizontal Pan Position from 0.0 to 1.0.
 * @param servoVertical Tilt Position from 0.0 to 1.0.
 */
void Team166Vision::DoServos(float servoHorizontal, float servoVertical)	{
	
	float currentH = horizontalServo->Get();		
	float currentV = verticalServo->Get();
	
	/* make sure the movement isn't too small */
	if ( fabs(servoHorizontal - currentH) > servoDeadband ) {
		horizontalServo->Set( servoHorizontal );
		/* save new normalized horizontal position */
		bearing = RangeToNormalized(servoHorizontal, 1);
	}
	if ( fabs(servoVertical - currentV) > servoDeadband ) {
		// don't look straight up or down
		if (servoVertical > 0.9) servoVertical = 0.9;
		if (servoVertical < 0.1) servoVertical = 0.1;
		
		verticalServo->Set( servoVertical );
		/* save new normalized vertical position */
		tilt = RangeToNormalized(servoVertical, 1);
	}
}	

/**
 * Set servo positions (0.0 to 1.0) translated from normalized values (-1.0 to 1.0). 
 * 
 * @param normalizedHorizontal Pan Position from -1.0 to 1.0.
 * @param normalizedVertical Tilt Position from -1.0 to 1.0.
 */
void Team166Vision::SetServoPositions(float normalizedHorizontal, float normalizedVertical)	{
	float servoH = NormalizeToRange(normalizedHorizontal);
	float servoV = NormalizeToRange(normalizedVertical);
	DoServos(servoH, servoV);
}	

/** ratio of horizontal image field of view (54 degrees) to horizontal servo (180) */
//#define HORIZONTAL_IMAGE_TO_SERVO_ADJUSTMENT 0.3   // FOV ratios
//#define HORIZONTAL_IMAGE_TO_SERVO_ADJUSTMENT 0.45  // ratio of sine
//#define HORIZONTAL_IMAGE_TO_SERVO_ADJUSTMENT 0.225   // mysterious sine / 2
#define HORIZONTAL_IMAGE_TO_SERVO_ADJUSTMENT 0.125   // this seems to work
/** ratio of vertical image field of view (40.5 degrees) to vertical servo (180) */
//#define VERTICAL_IMAGE_TO_SERVO_ADJUSTMENT 0.225  // FOV ratios
//#define VERTICAL_IMAGE_TO_SERVO_ADJUSTMENT 0.34   // ratio of sine
//#define VERTICAL_IMAGE_TO_SERVO_ADJUSTMENT 0.175	    // mysterious sine / 2
#define VERTICAL_IMAGE_TO_SERVO_ADJUSTMENT 0.125	    // this seems to work
/**
 * @brief Adjust servo positions (0.0 to 1.0) translated from normalized values (-1.0 to 1.0). 
 * Inputs are normalized values from an image with field of view 
 * horizontal 54 degrees/vertical 40.5 degrees. This value is 
 * multiplied by a factor to correspond to the 180 degree H/V 
 * range of the servo. 
 * 
 * @param normalizedHorizontal Pan adjustment from -1.0 to 1.0.
 * @param normalizedVertical Tilt adjustment from -1.0 to 1.0.
 */
void Team166Vision::AdjustServoPositions(float normDeltaHorizontal, float normDeltaVertical)	{
			
	//NORMALIZED
	/* adjust for the fact that servo overshoots based on image input */
	normDeltaHorizontal *= HORIZONTAL_IMAGE_TO_SERVO_ADJUSTMENT;
	normDeltaVertical *= VERTICAL_IMAGE_TO_SERVO_ADJUSTMENT;
	
	/* compute horizontal goal */
	float currentH = horizontalServo->Get();  //servo range
	float normCurrentH = RangeToNormalized(currentH, 1);
	float normDestH = normCurrentH + normDeltaHorizontal;	
	/* narrow range keep servo from going too far */
	if (normDestH > 1.0) normDestH = 1.0;
	if (normDestH < -1.0) normDestH = -1.0;		

	/* compute vertical goal */
	float currentV = verticalServo->Get();  //servo range
	float normCurrentV = RangeToNormalized(currentV, 1);
	float normDestV = normCurrentV + normDeltaVertical;	
	if (normDestV > 1.0) normDestV = 1.0;
	if (normDestV < -1.0) normDestV = -1.0;
	
	//SERVO RANGE
	/* convert input to servo range */
	float servoH = NormalizeToRange(normDestH);
	//float servoV = NormalizeToRange(normDestV, 0.2, 0.8);
	float servoV = NormalizeToRange(normDestV);

	DoServos(servoH, servoV);
}

// process images to find target
bool Team166Vision::AcquireTarget() {
	//DPRINTF(LOG_DEBUG,"start");
	
	// incremental tasking toward dest (-1.0 to 1.0)
	float incrementH, incrementV;					
	bool staleImage=false; 
	static int staleCount = 0;
	
	// calculate servo position based on colors found 
	if ( FindTwoColors(pinkSpec, greenSpec, GetRelativePosition(), &pinkReport, &greenReport) ){
		//PrintReport(&par2);
		targetAcquired = true;
		// reset pan		
		panIncrement = 0;  		
		if (pinkReport.imageTimestamp == savedImageTimestamp) {
			// This image has been processed already, 
			// so don't do anything for this loop 
			staleImage = true;
			staleCount++;
			DPRINTF(LOG_DEBUG, "STALE IMAGE staleCount:%d",staleCount);
			
		} else {
			// The target was recognized
			// save the timestamp
			staleImage = false;
			savedImageTimestamp = pinkReport.imageTimestamp;	
			//DPRINTF(LOG_DEBUG,"image timetamp: %lf", savedImageTimestamp);

			// number of pixels 
			targetHeight = pinkReport.boundingRect.height + greenReport.boundingRect.height;
			targetArea = pinkReport.particleArea + greenReport.particleArea;

			// get center of target 
			// Average the color two particles to get center x & y of combined target
			horizontalDestination = (pinkReport.center_mass_x_normalized + 
					greenReport.center_mass_x_normalized) / 2;	
			if (GetRelativePosition() == ABOVE) {
				verticalDestination = RangeToNormalized(pinkReport.boundingRect.top, 
						pinkReport.imageHeight);
			} else {
				verticalDestination = RangeToNormalized(greenReport.boundingRect.top, 
						greenReport.imageHeight);
			}
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
		// you may need to reverse this based on your servo installation

		incrementH = horizontalDestination - bearing;
		//incrementH = bearing - horizontalDestination;
		
		incrementV = verticalDestination - tilt;
		//incrementV =  tilt - verticalDestination;
		
		AdjustServoPositions( incrementH, incrementV);  
		
		if (SHOWACTIVITY) {
			ShowActivity ("** %s & %s found: Servo: x: %f  y: %f height: %i  **", 
				pinkSpec.name, greenSpec.name, horizontalDestination, verticalDestination,
				targetHeight);	
		}		
#if 1		
		// log stuff
		// Should we log this value?
		float hs = horizontalServo->Get();
		float vs = verticalServo->Get();
		vl.PutOne(staleCount, pinkReport.imageTimestamp,
				bearing, hs, RangeToNormalized(hs,1), incrementH, 
				tilt, vs, RangeToNormalized(vs,1), incrementV);
#endif
		
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
				verticalServo->Set( verticalDefault );	
				DPRINTF(LOG_DEBUG, "pan resetting vertical servo");
			}
		}
		panIncrement++;	
		if (SHOWACTIVITY) {
			ShowActivity ("** %s and %s not found                                    ", pinkSpec.name, greenSpec.name);
		}
	}  // end if found color
	return(staleImage);
}



// Main function of the vision task
int Team166Vision::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	int loopCounter = 0;
	sample_count = 0;             // Initialize Count of log samples
	bool staleFlag;
	
	// Let the world know we're in
	DPRINTF(LOG_INFO, "In the 166 vision task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
		
	// initialize vision stuff
	DPRINTF(LOG_DEBUG, "SERVO - looking for COLOR %s ABOVE %s", greenSpec.name, pinkSpec.name);
	
	/* initialize position and destination variables
	* position settings range from -1 to 1
	* setServoPositions is a wrapper that handles the conversion to range for servo 
	*/		
	horizontalDestination = 0.0;			// final destination range -1.0 to +1.0
	verticalDestination = verticalDefault;	// final destination range -1.0 to +1.0

	// set servos to start at center position
	SetServoPositions(horizontalDestination, verticalDestination);
					
	/* for controlling loop execution time */
	float loopTime = 0.05;		// should be slightly slower than camera
	double currentTime = GetTime();
	double lastTime = currentTime;
	
    // General main loop (while in Autonomous or Tele mode)
	printf("Vision task is getting ready...\n");
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
		   (lHandle->RobotMode == T166_OPERATOR)) 
	{
		loopCounter++;
		MyWatchDog = 1;		
		if (visionActive) {
			staleFlag=AcquireTarget();		
		}
		
		// sleep to keep loop at constant rate
		// this helps keep pan consistant
		// elapsed time can vary significantly due to debug printout
		currentTime = GetTime();			
		lastTime = currentTime;					
		if ( (loopTime > ElapsedTime(lastTime)) && !staleFlag) {
			//DPRINTF(LOG_DEBUG,"%i WAITING: current time: %f", currentTime, loopCounter);
			Wait( loopTime - ElapsedTime(lastTime) );	// seconds
		} else {
			DPRINTF(LOG_DEBUG,"~~~~~~~~~ %i NOT WAITING: current time: %f", currentTime, loopCounter);
		}
	}
	return (0);
}
