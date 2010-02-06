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
#include "Vision/AxisCamera2010.h"
#include "Vision/HSLImage.h"

// Constants
#define PI 3.14159265358979
#define DEFAULT_VERTICAL_PAN_POSITION 0

/** ratio of horizontal image field of view (54 degrees) to horizontal servo (180) */
#define HORIZONTAL_IMAGE_TO_SERVO_ADJUSTMENT (54.0/180.0)   // this seems to work
/** ratio of vertical image field of view (40.5 degrees) to vertical servo (180) */
#define VERTICAL_IMAGE_TO_SERVO_ADJUSTMENT (40.5/180.0)	    // this seems to work

#define SERVO_DEADBAND 0.1
#define VISION_LOOP_TIME 0.050 // seconds
#define SCORE_MINIMUM 0.01
#define SCORE_GOOD 0.4

class DashboardDataSender;

/*
 * Team 166 Vision Class
 * 
 */
class Team166Vision : public Team166Task
{
	
// Public functions and attributes
public:
	
	// Vision task constructor
	Team166Vision(void);
	
	// Vision task destructor
	virtual ~Team166Vision(void);
	
	// Main function of the vision task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);	

	// Accessors
	bool IsTargetAcquired(void);
	float AngleToTarget(void);
	float GetBearing(void);
	int IsActive(void);
	// Control
	void SetActive(bool);
	
	ColorImage *GetImage();
	
// Private functions and attributes
private:	
	ColorMode colorMode;
	
	bool targetAcquired; // Target has been acquired since last run
	bool visionActive; // Vision task should be looking for the target
	bool staleFlag; 
	
	float bearing; // Angle to target
	float tilt; 
	
	Servo horizontalServo;
	Servo verticalServo;
	
	DashboardDataSender *dds;
	
	void AcquireTarget(vector<Target>&);
	void IsTargetAccquired();
	void SetServoPositions(float normalizedHorizontal, float normalizedVertical);
	void AdjustServoPositions(float normDeltaHorizontal, float normDeltaVertical);
	void _SetServoPositions(float servoHorizontal, float servoVertical);
};
#endif // !defined(_VISION166_H)
