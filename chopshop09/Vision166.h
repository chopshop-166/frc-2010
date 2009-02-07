/********************************************************************************
*  Project   		: Chopshop 2009
*  File Name  		: Vision166.h          
*  Contributors   	: ELF
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
	float GetBearing();
	float GetTilt();
	double GetTargetArea();
	int GetTargetHeight();
	bool IsTargetAcquired();
	bool AcquireTarget();

// Private functions and attributes
private:
	VisionLog vl;                 // Vision log
	int sample_count;               // Count of log samples
	float bearing;                  // Current target horizontal bearing
	float tilt;                     // Current target vertical bearing
	double targetArea;	            // area of target
	int targetHeight;				// height of target
	bool targetAcquired;			// target acquisition flag

	Servo *horizontalServo;  		// servo object
	Servo *verticalServo;  		 	// servo object
	float horizontalDestination;	// target position for servo
	float verticalDestination;		// target position for servo
	float servoDeadband;			// percentage servo delta to trigger move
	int framesPerSecond;			// number of camera frames to get per second
	float panControl;				// to slow down pan
	float panPosition;
	double sinStart;
	static double panStartTime;
	int panIncrement;				// pan needs a 1-up number for each call
	
	double savedImageTimestamp;		// timestamp of last image acquired
	
	ColorMode mode;
	ParticleAnalysisReport pinkReport, greenReport;	// particle analysis reports
	TrackingThreshold pinkSpec, greenSpec;			// color thresholds
	
	void SetServoPositions(float normalizedHorizontal, float normalizedVertical);
	void AdjustServoPositions(float normDeltaHorizontal, float normDeltaVertical);
};
#endif // !defined(_VISION166_H)
