/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Kicker166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code which controls the kicker
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "Team166Task.h"
#include "Kicker166.h"
#include "MemoryLog166.h"
#include "Robot166.h"
#include "BaeUtilities.h"
#include "Proxy166.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(true)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	float x_acc;                     // accelarometer x value
	float y_acc;					//  accelarometer y value
	float acc_vector;
	
};

// Sample Memory Log
class KickerLog : public MemoryLog166
{
public:
	KickerLog() : MemoryLog166(128*1024, "kicker") {return;};
	~KickerLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float x_acc, float y_acc, float acc_vector);     // Log the x and y values
};

// Write one buffer into memory
unsigned int KickerLog::PutOne(float x_acc, float y_acc, float acc_vector)
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
unsigned int KickerLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f, %f, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->x_acc, ab->y_acc, ab->acc_vector);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166Kicker::Team166Kicker(void): Kicker_jag(T166_KICKER_CHANNEL),
	Kicker_Limit_Switch(T166_KICKER_LIMIT_SWITCH)
//	Kick_timer()
{
	Start((char *)"166KickerTask", KICKER_CYCLE_TIME);
	Cocked = Kicker_Limit_Switch.Get();
	Firing = false;
};
	
// task destructor
Team166Kicker::~Team166Kicker(void)
{
	return;
};


// Main function of the task
int Team166Kicker::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	Proxy166 *proxy;	//Get handle for joystick
	Robot166 *lHandle;            // Local handle
	KickerLog sl;                   // Arm log
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 Kicker task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);	


	// Get handle to main Proxy166
	proxy = Proxy166::getInstance();
	
	int printstop=0;
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		// Get limit switch value
		Cocked = Kicker_Limit_Switch.Get();
		
		if ((++printstop)%(1000/KICKER_CYCLE_TIME)==0)
		{
			DPRINTF(LOG_DEBUG, "%d, %d", Cocked, proxy->GetButton(3,1));
		}
		//Is the kicker cocked, is the trigger pressed?
		if ((proxy->GetButton(3,1) == true) || Cocked == false)
		{

			// Move motor till limit not pressed
			Kicker_jag.Set(1);
			
		    // Should we log this value?
			sl.PutOne(0, 0, 0);
				
			// Wait for our next lap
			WaitForNextLoop();
			continue;
		}
		
		//Stop motor when the limit switch is pressed
		Kicker_jag.Set(0); 

        // Should we log this value?
		sl.PutOne(0, 0, 0);
		
		// Wait for our next lap
		WaitForNextLoop();
	}
	return (0);
	
};
