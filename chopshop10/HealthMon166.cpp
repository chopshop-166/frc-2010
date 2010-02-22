	/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: HealthMon166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 23, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Code which monitors health of system
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "Team166Task.h"
#include "HealthMon166.h"
#include "MemoryLog166.h"
#include "Robot166.h"
#include "BaeUtilities.h"
#include "CANJaguar.h"
#include "Vision166.h"
#include "CANDrive166.h"



// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	float x_acc;                     // accelarometer x value
	float y_acc;					//  accelarometer y value
	float acc_vector;
	
};

//  Memory Log
class HealthMonLog : public MemoryLog166
{
public:
	HealthMonLog() : MemoryLog166(sizeof(struct abuf166), HEALTHMON_CYCLE_TIME, "health_monitor") {return;};
	~HealthMonLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float x_acc, float y_acc, float acc_vector);     // Log the x and y values
};

// Write one buffer into memory
unsigned int HealthMonLog::PutOne(float x_acc, float y_acc, float acc_vector)
{
	struct abuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct abuf166 *)GetNextBuffer(sizeof(struct abuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		ob->x_acc = x_acc;
		ob->y_acc = y_acc;
		ob->acc_vector = acc_vector;
		return (sizeof(struct abuf166));
	}
	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int HealthMonLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f, %f, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->x_acc, ab->y_acc, ab->acc_vector);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166HealthMon::Team166HealthMon(void)
{
	Start((char *)"166HealthMonTask", HEALTHMON_CYCLE_TIME);
	MyTaskIsEssential=false;
	return;
};
	
// task destructor
Team166HealthMon::~Team166HealthMon(void)
{
	return;
};
	
// Main function of the task
int Team166HealthMon::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	Robot166 *lHandle;            		// Local handle
	Proxy166 *proxy;              		// Local proxy handle
	HealthMonLog sl;					// log
	Team166Task *kickerTask;			// Kicker task
	Team166Task *ebrakeTask;			// E-Brake task
	Team166Task *vacuumTask;			// Vacuum task
	Team166Task *sonarTask;				// Sonar task
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 HealthMon task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);
	char* buffer = new char[DASHBOARD_BUFFER_MAX];
	
	// Register each task
	proxy = Proxy166::getInstance();
	kickerTask = Team166Task::GetTaskHandle("166KickerTask");
	ebrakeTask = Team166Task::GetTaskHandle("166EBrakeTask");
	vacuumTask = Team166Task::GetTaskHandle("166BallSucker");
	sonarTask = Team166Task::GetTaskHandle("166SonarTask");
	
	// Whether the sonar is valid
	char SonarStatus;
	// Whether the camera is up

	// Print out the key
	lHandle->DriverStationDisplayHS("K E V PSI B S INC C");
	
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		//Determining the Sonar Health
		if(proxy->GetSonarDistance()<1){
			SonarStatus = 'e';
		} else {
			SonarStatus = sonarTask->GetStatus()[0];
		}

		sprintf(buffer,
				"%c %c %c %03.0f %c %c %03d %c",
				kickerTask->GetStatus()[0],
				ebrakeTask->GetStatus()[0],
//				vacuumTask->GetStatus()[0],
				's',
				proxy->GetPressure(),
				((proxy->GetBanner())?'y':'n'),
				SonarStatus,
				proxy->GetInclinometer(),
				((proxy->GetVisionStatus())?'y':'n')
				);
		lHandle->DriverStationDisplayHSData(buffer);
		
		// do stuff
		sl.PutOne(0, 0, 0);
		WaitForNextLoop();
	}
	return (0);
	
};
