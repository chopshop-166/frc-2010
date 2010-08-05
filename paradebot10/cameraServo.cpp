/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: cameraServo.cpp
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Control a camera by moving the servos its mounted on
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "cameraServo.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	// Any values that need to be logged go here
};

//  Memory Log
class CameraServoLog : public MemoryLog166
{
public:
	CameraServoLog() : MemoryLog166(
			sizeof(struct abuf166), CAMERA_SERVO_CYCLE_TIME, "cameraServo",
			"Seconds,Nanoseconds,Elapsed Time\n" // Put the names of the values in here, comma-seperated
			) {
		return;
	};
	~CameraServoLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(void);     // Log the values needed-add in arguments
};

// Write one buffer into memory
unsigned int CameraServoLog::PutOne(void)
{
	struct abuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct abuf166 *)GetNextBuffer(sizeof(struct abuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		// Add any values to be logged here
		return (sizeof(struct abuf166));
	}
	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int CameraServoLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u,%u,%4.5f\n",
			ab->tp.tv_sec, ab->tp.tv_nsec,
			((ab->tp.tv_sec - starttime.tv_sec) + ((ab->tp.tv_nsec-starttime.tv_nsec)/1000000000.))
			// Add values here
	);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
CameraServo::CameraServo(void): cameraX(CAMERA_PORT_X), cameraY(CAMERA_PORT_Y), camera(AxisCamera::GetInstance()) 
{
	Start((char *)"166CameraServoes", CAMERA_SERVO_CYCLE_TIME);
	Cone_Range->minValue = 100;
	Cone_Range->maxValue = 150;
	camera.WriteResolution(AxisCamera::kResolution_320x240);
	camera.WriteCompression(20);
	camera.WriteBrightness(0);
	return;
};
	
// task destructor
CameraServo::~CameraServo(void)
{
	return;
};
	
// Main function of the task
int CameraServo::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	Proxy166 *proxy;				// Handle to proxy
	Robot *lHandle;            // Local handle
	CameraServoLog sl;                   // log
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 Template task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot::getInstance();
	lHandle->RegisterLogger(&sl);
	
	// Register the proxy
	proxy = Proxy166::getInstance();
	float CamJoystickX = 0.0;
	float CamJoystickY = 0.0;
	float CamX = 0.5;
	float CamY = 0.5;
	double distanceX = 0;
	double distanceY = 0;
	double CenterValueX = 0;
	double CenterValueY = 0;
	float CamValueX = 0;
	float CamValueY = 0;
	#define DEADBAND (0.2)
	#define CAMMOVE (.5 / (1000/CAMERA_SERVO_CYCLE_TIME))
	// Center pixel of camera along x axis
	#define CAMERA_CENTER_X (160)
	// Center pixel of camera along y axis
	#define CAMERA_CENTER_Y (120)
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		if(proxy->GetThrottle(3)) {
			if(!proxy->GetTrigger(3)) {
			CamJoystickX = proxy->GetJoystickX(T166_COPILOT_STICK);
			CamJoystickY = proxy->GetJoystickY(T166_COPILOT_STICK);
			if(CamJoystickX >= DEADBAND) {
				CamX += CAMMOVE;
			} else if(CamJoystickX <= -DEADBAND) {
				CamX -= CAMMOVE;
			}
			if(CamJoystickY >= DEADBAND) {
				CamY -= CAMMOVE;
			} else if(CamJoystickY <= -DEADBAND) {
				CamY += CAMMOVE;
			}
			if(CamX > 1.0) {
				CamX = 1.0;
			} else if(CamX < .0) {
				CamX = .0;
			}
			if(CamY > 1.0) {
				CamY = 1.0;
			} else if(CamY < .0) {
				CamY = .0;
			}
			} else {
				CamX = CamY = 0.5;
			}	
		} else {
			FindColor(Cone_Range, Particle_Report);
			CenterValueX = Particle_Report->center_mass_x_normalized;
			CenterValueY = Particle_Report->center_mass_y_normalized;
			distanceX = CenterValueX - .5;
			distanceY = CenterValueY - .5;
			CamValueX = cameraX.Get();
			CamValueY = cameraY.Get();
			CamX = CamValueX + distanceX;
			CamY = CamValueY = distanceY;
			CamX = NormalizeToRange(CamX, 0, 1);
			CamY = NormalizeToRange(CamY, 0, 1);
		}
        cameraX.Set(CamX);
		cameraY.Set(CamY);
		// Logging any values
		sl.PutOne();
		
		// Wait for our next lap
		WaitForNextLoop();		
	}
	return (0);
	
};
