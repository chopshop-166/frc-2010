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
#include "Vacuum.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	// Any values that need to be logged go here
};

//  Memory Log
class VacuumLog : public MemoryLog166
{
public:
	VacuumLog() : MemoryLog166(sizeof(struct abuf166), VACUUM_CYCLE_TIME, "template") {return;};
	~VacuumLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(void);     // Log the values needed-add in arguments
};

// Write one buffer into memory
unsigned int VacuumLog::PutOne(void)
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
unsigned int VacuumLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u\n", ab->tp.tv_sec, ab->tp.tv_nsec); // Add values here
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166Vacuum::Team166Vacuum(void): Vacuum_Relay(T166_VACUUM_RELAY_CHANNEL, Relay::kForwardOnly)
{
	Start((char *)"166BallSucker", VACUUM_CYCLE_TIME);
	return;
};
	
// task destructor
Team166Vacuum::~Team166Vacuum(void)
{
	return;
};
	
// Main function of the task
int Team166Vacuum::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	Proxy166 *proxy;				// Handle to proxy
	Robot166 *lHandle;            // Local handle
	VacuumLog sl;                   // log
	
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
		
		if ((proxy->GetSonarDistance() <= 15) || (proxy->GetButton(3,5)))
		{
			Vacuum_Relay.Set(Relay::kOn);
	        // Logging any values
			sl.PutOne();
			
			// Wait for our next lap
			WaitForNextLoop();	
			continue;
		}
		Vacuum_Relay.Set(Relay::kOff);
		
        // Logging any values
		sl.PutOne();
		
		// Wait for our next lap
		WaitForNextLoop();		
	}
	return (0);
	
};
