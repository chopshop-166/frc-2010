/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Lift166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code which controls the banner sensors
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "Team166Task.h"
#include "Proxy166.h"
#include "BallControl.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	// Any values that need to be logged go here
	bool BallControl_On;
	float BallControl_Current;
};

//  Memory Log
class BallControlLog : public MemoryLog166
{
public:
	BallControlLog() : MemoryLog166(sizeof(struct abuf166), BALLCONTROL_CYCLE_TIME, "ballcontrol") {
		return;
	};
	~BallControlLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(bool Vacuum_On, float Vacuum_Current);     // Log the values needed-add in arguments
};

// Write one buffer into memory
unsigned int BallControlLog::PutOne(bool BallControl_On, float BallControl_Current)
{
	struct abuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct abuf166 *)GetNextBuffer(sizeof(struct abuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		// Add any values to be logged here
		ob->BallControl_On = BallControl_On;
		ob->BallControl_Current = BallControl_Current;
		return (sizeof(struct abuf166));
	}
	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int BallControlLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %4.5f, %d, %f\n",
			ab->tp.tv_sec, ab->tp.tv_nsec,
			((ab->tp.tv_sec - starttime.tv_sec) + ((ab->tp.tv_nsec-starttime.tv_nsec)/1000000000.)),
			ab->BallControl_On, ab->BallControl_Current); // Add values here
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166BallControl::Team166BallControl(void): BallControl_Jag(T166_LEFT_MOTOR_CAN)
{
	Start((char *)"166BallControl", BALLCONTROL_CYCLE_TIME);
	return;
};
	
// task destructor
Team166BallControl::~Team166BallControl(void)
{
	return;
};
	
// Main function of the task
int Team166BallControl::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	Proxy166 *proxy;				// Handle to proxy
	Robot166 *lHandle;            // Local handle
	BallControlLog sl;                   // log
	float BallControl_Current;
	bool BallControl_On;
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the Vacuum\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);	
	
	// Register the proxy
	proxy = Proxy166::getInstance();		
	
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		// is the copilot telling it to go in ONE direction?
		BallControl_On = (
				proxy->GetButton(T166_COPILOT_STICK,T166_BALLCONTROL_PULL) -
				proxy->GetButton(T166_COPILOT_STICK,T166_BALLCONTROL_PUSH)
				);
		BallControl_Jag.Set(BallControl_On);
		switch(BallControl_On) {
		case -1:
			SetStatus( "backward" );
			break;
		default:
		case 0:
			SetStatus( "neutral" );
			break;
		case 1:
			SetStatus( "forward" );
			break;
		}
        // Logging any values
		sl.PutOne(BallControl_On, BallControl_Current);
		
		// Wait for our next lap
		WaitForNextLoop();		
	}
	return (0);
	
};
