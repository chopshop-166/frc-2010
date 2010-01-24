/********************************************************************************
*  Project   		: Chopshop 2009
*  File Name  		: Vision166.cpp          
*  Contributors   	: ELF JWG
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
#define DPRINTF if(true)dprintf
/** ratio of horizontal image field of view (54 degrees) to horizontal servo (180) */
#define HORIZONTAL_IMAGE_TO_SERVO_ADJUSTMENT 0.125   // this seems to work
/** ratio of vertical image field of view (40.5 degrees) to vertical servo (180) */
#define VERTICAL_IMAGE_TO_SERVO_ADJUSTMENT 0.125	    // this seems to work
	
// Vision task constructor
Team166Vision::Team166Vision(void) :
	bearing(0.0),					// current horizontal normalized servo position	
	tilt(0.0),						// current vertical normalized servo position	
	targetAcquired(false),			// target not acquired
	defaultVerticalPosition(0),			// default vertial servo position
	servoDeadband(0.005),			// pan flag to move if > this amount 
	colorMode(IMAQ_HSL), 			    // Color mode (RGB or HSL) for image processing	
	horizontalServo(T166_HORIZONTAL_SERVO_CHANNEL),
	verticalServo(T166_VERTICAL_SERVO_CHANNEL)
{

	/* set up debug output: 
	 * DEBUG_OFF, DEBUG_MOSTLY_OFF, DEBUG_SCREEN_ONLY, DEBUG_FILE_ONLY, DEBUG_SCREEN_AND_FILE 
	 */
	SetDebugFlag ( DEBUG_SCREEN_ONLY  ) ;
	
	// Start our task
	Start((char *)"166VisionTask", 0.050);	
};
	
// Vision task destructor
Team166Vision::~Team166Vision(void)
{		
	return;
};

/////////////// Control

/**
 * @brief Set vision processing on or off
 * If off, the main loop just idles and monitors this flag
 * 
 * @param onFlag if true, process images to find the target
 */
void Team166Vision::SetVisionOn(bool onFlag) {
	visionActive = onFlag;
}

/**
 * Set servo positions (0.0 to 1.0) 
 * 
 * @param servoHorizontal Pan Position from 0.0 to 1.0.
 * @param servoVertical Tilt Position from 0.0 to 1.0.
 */
void Team166Vision::DoServos(float servoHorizontal, float servoVertical)	{
	
	float currentH = horizontalServo.Get();		
	float currentV = verticalServo.Get();
	
	/* make sure the movement isn't too small */
	if ( fabs(servoHorizontal - currentH) > servoDeadband ) {
		horizontalServo.Set( servoHorizontal );
		/* save new normalized horizontal position */
		bearing = RangeToNormalized(servoHorizontal, 1);
	}
	if ( fabs(servoVertical - currentV) > servoDeadband ) {
		// don't look straight up or down
		if (servoVertical > 0.9) servoVertical = 0.9;
		if (servoVertical < 0.1) servoVertical = 0.1;
		
		verticalServo.Set( servoVertical );
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
	float currentH = horizontalServo.Get();  //servo range
	float normCurrentH = RangeToNormalized(currentH, 1);
	float normDestH = normCurrentH + normDeltaHorizontal;	
	/* narrow range keep servo from going too far */
	if (normDestH > 1.0) normDestH = 1.0;
	if (normDestH < -1.0) normDestH = -1.0;		

	/* compute vertical goal */
	float currentV = verticalServo.Get();  //servo range
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

// process images to find target, then pan the camera so we are looking at it
/*
 * @brief Processes images to find a target, then pans the camera so that 
 * 		we are looking at the target. 
 * 
 * @return bool Whether we found the target; copy of Team166Vision::targetAcquired
 */
bool Team166Vision::AcquireTarget() {
	return targetAcquired;
}

/*
 * @brief Returns a float -1.0 to 1.0 returning our position relative to start.
 * 
 * @return float Bearing -1.0 to 1.0
 */
float Team166Vision::GetBearing() {
	return 0;
}

bool Team166Vision::IsTargetAcquired() {
	return targetAcquired;
}
// Main function of the vision task
int Team166Vision::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	// Indicate that we've now completed initialization
	MyTaskInitialized = 1;
	// Ensure we get into Autononmous or Tele Operasted mode
	while (!Robot166::getInstance() ||
	       ((Robot166::getInstance()->RobotMode != T166_AUTONOMOUS) &&
	    	(Robot166::getInstance()->RobotMode != T166_OPERATOR))) {
		Wait (0.050);
	}

	// get handle to robot
	lHandle = Robot166::getInstance();
	dsHandle = DriverStation::GetInstance();
	
	// set servos to start at center position
	SetServoPositions(0.0, defaultVerticalPosition);
					
	/* for controlling loop execution time */
	float loopTime = 0.05;		// should be slightly slower than camera
	double currentTime = GetTime();
	double lastTime = currentTime;
	
    // General main loop (while in Autonomous or Tele mode)
	DPRINTF("Vision task is getting ready...\n");
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
		   (lHandle->RobotMode == T166_OPERATOR)) 
	{
		MyWatchDog = 1;		
		if (visionActive) {
			targetAcquired = AcquireTarget();		
		}
		SetServoPositions(lHandle->cameraStick.GetX(), lHandle->cameraStick.GetY());
		if ( (loopTime > ElapsedTime(lastTime)) && !staleFlag) {
			Wait( loopTime - ElapsedTime(lastTime) ); 
		}
	}
	return 0;
}
