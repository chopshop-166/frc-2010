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
#define DPRINTF if(false)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;              // Time of snapshot
	int timer;						// Timer value
};

// Sample Memory Log
class KickerLog : public MemoryLog166
{
public:
	KickerLog() : MemoryLog166(sizeof(struct abuf166), KICKER_CYCLE_TIME, "kicker") {
		return;
	};
	~KickerLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(int);     // Log the values
};

// Write one buffer into memory
unsigned int KickerLog::PutOne(int timer)
{
	struct abuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct abuf166 *)GetNextBuffer(sizeof(struct abuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		ob->timer = timer;
		
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
	fprintf(ofile, "%u, %u, %4.5f, %d\n",
			ab->tp.tv_sec, ab->tp.tv_nsec,
			((ab->tp.tv_sec - starttime.tv_sec) + ((ab->tp.tv_nsec-starttime.tv_nsec)/1000000000.)),
			ab->timer
	);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166Kicker::Team166Kicker(void)
{
	Start((char *)"166KickerTask", KICKER_CYCLE_TIME);
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
	// TODO THE VARS LIVE HERE!!!!!!!!!!
	Proxy166 *proxy;	                            // Get handle for joystick
	Robot166 *lHandle;                              // Local handle
	KickerLog sl;                                   // Arm log
	int delay=500;									// Delay before the kick
	
	Solenoid unkickSolenoid(T166_UNKICKER_PISTON);                  // Unkicker solenoid
	Solenoid kickSolenoid(T166_KICKER_PISTON);                      // Kicker solenoid
	
	int timer = 0;                                      // Latch release wait counter
	bool buttondown = false;
	DigitalInput Latch_Magnet_Sensor (T166_LATCH_MAGNET_SENSOR);
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 Kicker task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();


	// Get handle to main Proxy166
	proxy = Proxy166::getInstance();
	
	//int printstop=0;
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		if( proxy->GetButton(T166_COPILOT_STICK, T166_KICKER_BUTTON, false) && !buttondown ) {
			buttondown = true;
			timer = 1;
		}
		if(timer) {
			if(proxy->GetPressure() < T166_PNEU_KICK_MIN) {
				timer = 0;
				lHandle->DriverStationDisplay("Not enough pressure!");
			} else {
				++timer;
				if(timer <= (delay / KICKER_CYCLE_TIME) ) {
					unkickSolenoid.Set(false);
				} else {
					kickSolenoid.Set(true);
				}
				if(timer >= ((1000 + delay) / KICKER_CYCLE_TIME) ) {
					timer = 0;
				}
			}
		} else {
			kickSolenoid.Set(false);
			unkickSolenoid.Set(true);
		}
		if( !proxy->GetButton(T166_COPILOT_STICK, T166_KICKER_BUTTON) ) {
			buttondown = false;
		}
		
        // Should we log this value? 
		sl.PutOne(timer);
		
		// Wait for our next lap
		WaitForNextLoop();
	}
	return (0);
	
};
