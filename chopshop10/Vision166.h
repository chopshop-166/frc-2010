/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Vision166.h    
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code header which handles vision of camera
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#ifndef _VISION166_H
#define _VISION166_H

#include "semLib.h"
#include "WPILib.h"
#include "Team166Task.h"
#include "MemoryLog166.h"
#include "Target166.h" 
#include "Target.h"


// WPILib include files for vision
#include "TrackAPI.h" 
#include "Vision/AxisCamera.h"
#include "Vision/HSLImage.h"

// Constants
#define PI 3.14159265358979
#define DEFAULT_VERTICAL_PAN_POSITION 0
#define CAMERA_SPAWN_TRY_WAIT 0.5 // seconds to wait for each thread
#define CAMERA_SPAWN_WAIT_MAX 20.0 // seconds to wait for the camera to come up. 

/** ratio of horizontal image field of view (54 degrees) to horizontal servo (180) */
#define HORIZONTAL_IMAGE_TO_SERVO_ADJUSTMENT (54.0/180.0)   // this seems to work
/** ratio of vertical image field of view (40.5 degrees) to vertical servo (180) */
#define VERTICAL_IMAGE_TO_SERVO_ADJUSTMENT (40.5/180.0)	    // this seems to work
#define DAMPING_FACTOR 0.75

#define SERVO_DEADBAND 0.01
#define SCORE_MINIMUM 0.01
#define SCORE_GOOD 0.4

#define DISTORTION_DELTA_MAX 0.25

//
// This constant defines how often we want this task to run in the form
// of miliseconds. Max allowed time is 999 miliseconds.
//
#define VISION_CYCLE_TIME (100) // 100ms

class DashboardDataSender;

/*
 * Team 166 Vision Class
 * 
 */
class Team166Vision : public Team166Task
{
	
// Public functions and attributes
public:
	
	Team166Vision(void);
	
	virtual ~Team166Vision(void);
	
	//! Main function of the Vision task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);	

	//! Whether or not the target has been acquired
	bool IsTargetAcquired(void);
	//! The bearing in degrees to the angle. 
	float GetBearing(void);
	//! Whether the camera is no or off
	int IsActive(void);
	//! Controls the output of Team166Vision::IsActive()
	void SetActive(bool);
	//! Tries to start the camera using threads
	void TryStartCamera(bool);
	//! Captures an image from the camera
	ColorImage *GetImage();
	
// Private functions and attributes
private:	
	ColorMode colorMode;
	
	//! Target has been acquired since last run
	bool targetAcquired; 
	//! Whether the vision task should perform vision processing
	bool visionActive;
	//! Whether the image ( Proxy166::GetImage() ) is new or not. 
	bool staleFlag; 
	//! Angle horizontally to the target
	float bearing;
	//! Angle vertically to the target
	float tilt; 
	
	Servo horizontalServo;
	Servo verticalServo;
	
	DashboardDataSender *dds;
	
	//! Main function of the thread, spawned in TryStartCamera.
	//! Calls StartCamera() which will hang the calling thread if it fails.
	static int _StartCameraThreadFunc(void *this_p,int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
	
	void AcquireTarget(vector<Target>&,float&,float&);
	void IsTargetAccquired();
	void SetServoPositions(float normalizedHorizontal, float normalizedVertical);
	void AdjustServoPositions(float normDeltaHorizontal, float normDeltaVertical);
	void _SetServoPositions(float servoHorizontal, float servoVertical);
};
#endif // !defined(_VISION166_H)
