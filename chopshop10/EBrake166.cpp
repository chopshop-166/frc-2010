/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: EBrake166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 23, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Code which does electronic motor braking
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "Team166Task.h"
#include "EBrake166.h"
#include "MemoryLog166.h"
#include "Robot166.h"
#include "BaeUtilities.h"
#include "Proxy166.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	float current;                  // current value
	
};

//  Memory Log
class EBrakeLog : public MemoryLog166
{
public:
	EBrakeLog() : MemoryLog166(sizeof(struct abuf166), EBRAKE_CYCLE_TIME, "ebrake") {return;};
	~EBrakeLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float current);     // Log values
};

// Write one buffer into memory
unsigned int EBrakeLog::PutOne(float current)
{
	struct abuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct abuf166 *)GetNextBuffer(sizeof(struct abuf166)))) {		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		ob->current = current;
		return (sizeof(struct abuf166));
	}	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int EBrakeLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->current);	
	return (sizeof(struct abuf166));
}


// task constructor
Team166EBrake::Team166EBrake(void): Ebrake_Can(T166_EBRAKE_MOTOR_CAN)
{
	Start((char *)"166EBrakeTask", EBRAKE_CYCLE_TIME);
	return;
};
	
// task destructor
Team166EBrake::~Team166EBrake(void)
{
	return;
};
	

// Main function of the task
int Team166EBrake::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	Proxy166 *proxy;	//Get handle for joystick
	Robot166 *lHandle;            // Local handle
	EBrakeLog sl;                   // log
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 EBrake task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	proxy = Proxy166::getInstance();
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);
	
	unsigned printstop=0;
	int valuethrottle=0;
	float myCurrent;
	int sent1=0;
	int sent2=0;
		
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		if ((++valuethrottle)% (1000/EBRAKE_CYCLE_TIME)==0)
		{	
			myCurrent = Ebrake_Can.GetOutputCurrent();
		}
		
		if ((proxy->GetButton(1,1) == true) || (proxy->GetButton(2,1) == true))
        {
			if (!sent1)
			{
				Ebrake_Can.Set(-.3);
				sent1=1;
				sent2=0;
			}
			// log data
			sl.PutOne(myCurrent);
			
			// Wait for our next lap
			WaitForNextLoop();
			continue;
		}	
		if (!sent2)
		{
			Ebrake_Can.Set(.3);
			sent1=0;
			sent2=1;
		}
		if ((++valuethrottle)% (1000/EBRAKE_CYCLE_TIME)==0)
		{	
			proxy->SetCurrent(T166_EBRAKE_MOTOR_CAN, myCurrent);
		}
		
		// log data
		sl.PutOne(myCurrent);
		
		// Wait for our next lap
		WaitForNextLoop();
	}
	return (0);
	
};
