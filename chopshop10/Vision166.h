/********************************************************************************
*  Project   		: Chopshop 2009
*  File Name  		: Vision166.h          
*  Contributors   	: ELF, SJE
*  Creation Date 	: February 2, 2008
*  Revision History	: Source code & revision history maintained at code.google.com    
*  File Description	: Header file for vision processing
*/

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
	bool IsTargetAcquired();
	bool AcquireTarget();
	// Control
	float GetBearing();
	void SetVisionOn(bool);
// Private functions and attributes
private:
	Robot166 *lHandle;            // Local handle to  robot instance
	DriverStation *dsHandle;
	
	ColorMode colorMode;
	
	bool targetAcquired;
	bool visionActive;
	bool staleFlag;
	
	float bearing;
	float defaultVerticalPosition;
	float servoDeadband;
	float tilt; 
	
	Servo horizontalServo;
	Servo verticalServo;
	
	void SetServoPositions(float normalizedHorizontal, float normalizedVertical);
	void AdjustServoPositions(float normDeltaHorizontal, float normDeltaVertical);
	void DoServos(float servoHorizontal, float servoVertical);
	//SecondColorPosition GetRelativePosition();
};
#endif // !defined(_VISION166_H)
