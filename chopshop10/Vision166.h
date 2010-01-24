/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Vision166.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for robot code which handles vision of camera
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#if !defined(_VISION166_H)
#define _VISION166_H

#include "semLib.h"
#include "WPILib.h"
#include "Robot166.h"
#include "Team166Task.h"
#include "MemoryLog166.h"
#include "Target166.h" 

// WPILib include files for vision
#include "TrackAPI.h" 

// constants
#define PI 3.14159265358979

/**
  Team 166 vision task
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
	float GetBearing();
	float GetTilt();
	double GetTargetArea();
	int GetTargetHeight();
	bool IsTargetAcquired();
	bool AcquireTarget();
	
	// Control
	void SetVisionOn(bool onFlag);

// Private functions and attributes
private:
	Robot166 *lHandle;            // Local handle to  robot instance
	VisionLog vl;                   // Vision log
	bool visionActive;              // flag to control vision processon on/off
	int sample_count;               // Count of log samples
	float bearing;                  // Current target horizontal bearing
	double targetArea;	            // area of target
	int targetHeight;				// height of target
	bool targetAcquired;			// target acquisition flag
	float tilt;                     // Current target vertical bearing

	Servo *horizontalServo;  		// servo object
	Servo *verticalServo;  		 	// servo object
	float horizontalDestination;	// target position for servo
	float verticalDestination;		// target position for servo
	float verticalDefault;			// default position of vertical servo
	float servoDeadband;			// percentage servo delta to trigger move
	int framesPerSecond;			// number of camera frames to get per second
	float panControl;				// to slow down pan
	float panPosition;
	double sinStart;
	static double panStartTime;
	int panIncrement;				// pan needs a 1-up number for each call	
	ColorMode mode;
	double savedImageTimestamp;		// timestamp of last image acquired
	Robot166 *robotHandle;			// handle to my robot instance
	DriverStation *dsHandle;		// handle to my ds
	
	ParticleAnalysisReport pinkReport, greenReport;	// particle analysis reports
	TrackingThreshold pinkSpec, greenSpec;			// color thresholds

	enum AllianceType {BLUE, RED};
	AllianceType alliance;
	
	void SetServoPositions(float normalizedHorizontal, float normalizedVertical);
	void AdjustServoPositions(float normDeltaHorizontal, float normDeltaVertical);
	void DoServos(float servoHorizontal, float servoVertical);
	SecondColorPosition GetRelativePosition();
};
#endif // !defined(_VISION166_H)
