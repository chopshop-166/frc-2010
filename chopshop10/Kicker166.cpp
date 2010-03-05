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
	float x_acc;                     // accelerometer x value
	float y_acc;					 //  accelerometer y value
	float acc_vector;
	
};

// Sample Memory Log
class KickerLog : public MemoryLog166
{
public:
	KickerLog() : MemoryLog166(sizeof(struct abuf166), KICKER_CYCLE_TIME, "kicker") {return;};
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
	Solenoid latchSolenoid(T166_LATCH_PISTON);                      // Latch solenoid
	Solenoid unkickSolenoid(T166_UNKICKER_PISTON);                  // Unkicker solenoid
	Solenoid unlatchSolenoid(T166_UNLATCH_PISTON);                  // Unlatch solenoid
	Solenoid kickSolenoid(T166_KICKER_PISTON);                      // Kicker solenoid
	
	//enum {WFP, LATCH, LWAIT, LREL, DSREADY, TRIGGER, KWAIT, KREL} sState = WFP;  // Solenoid state
	enum {WFP, TRIGGERWAIT, KICKWAIT, uKSENSORWAIT, LWAIT} kickState = TRIGGERWAIT; // Kicker state
	int lwait = 0;                                      // Latch release wait counter
	int kwait = 0;                                      // Kicker release wait counter
	int latchwait = 0;                                  // Latched? wait counter
	DigitalInput Latch_Magnet_Sensor (T166_LATCH_MAGNET_SENSOR);
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 Kicker task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);	


	// Get handle to main Proxy166
	proxy = Proxy166::getInstance();
	
	//int printstop=0;
	// General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		// Get limit switch value TODO GET RID OF ME
		//Cocked = Latch_Magnet_Sensor.Get();
		
		/*
		*  NEW state machine to control the pistons.
		*/
		
		switch (kickState)
		{
		case WFP:
			// Wait to make sure pressure is adequate
			// Is there enough pressure?
			if (proxy->GetPressure() < T166_PNEU_KICK_MIN){
				// There isn't enough pressure.   :(   Try again later.
			} else {
				// There is enough pressure!!   :)   We're done here.
				kickSolenoid.Set(true);    // We are getting ready to kick
				// Send a ready signal to DS
				DPRINTF(LOG_DEBUG, "We're READY TO KICK !!!!!\n");
				lHandle->DriverStationDisplay("READY TO KICK");
				
				// Wait for user input
				// It's ready to kick, in case the above statements don't explain that.
				kickState = TRIGGERWAIT;
			}
			break;
		case TRIGGERWAIT:
			// Is the trigger asking us to kick?
			if (proxy->GetButton(T166_DRIVER_STICK_LEFT, T166_KICKER_BUTTON,true)
					or proxy->GetButton(T166_DRIVER_STICK_RIGHT, T166_KICKER_BUTTON,true)
					or proxy->GetButton(T166_COPILOT_STICK, T166_KICKER_BUTTON,true))
			{
				// The trigger is asking us to kick.
				
				// Prepare the pneumatics
				unkickSolenoid.Set(false); // We aren't unkicking
				latchSolenoid.Set(false);  // We aren't latching
				unlatchSolenoid.Set(true); // We ARE unlatching [AND KICKING!!!]
				
				kwait = 0;  // Reset wait counter
				
				// Wait for the kicker to finish kicking
				kickState = KICKWAIT;
			}
			break;
		case KICKWAIT:
			// Wait for the kicker to kick
			// Have we waited long enough?
			if (kwait++ >= 100){				
				// We've waited long enough
				// Pull back the kicker
				kickSolenoid.Set(false);  // We aren't kicking
				unkickSolenoid.Set(true); // We are unkicking
				
				// Wait for sensor input
				kickState = uKSENSORWAIT;
			}
			break;
		case uKSENSORWAIT:
			// Wait for the sensor tells us the kicker is pulled back
			// Is the magnet sensor ready? Are we ready to override it?
			if( !(Latch_Magnet_Sensor.Get() && (lwait++ < 100)) ) {
				// Latch the kicker
				unlatchSolenoid.Set(false); // We aren't unlatching
				latchSolenoid.Set(true);    // We are latching
				
				// Latching, now wait for it to finish
				latchwait = 0; // Reset the latch wait timer
				kickState = LWAIT;
			}
			break;
		case LWAIT:
			// Wait for the latch to be down
			// Have we waited long enough?
			if (latchwait++ >= 100){
				// We've waited long enough
				// We aren't unkicking, so get rid
				unkickSolenoid.Set(false);
				// Wait for Pressure
				kickState = WFP;
			}
			break;
		}

		// Should we log this value?
		sl.PutOne(0, 0, 0);
		
		// Wait for our next lap
		WaitForNextLoop();
	}
	return (0);

};
