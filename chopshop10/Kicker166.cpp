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
	enum {WFP, SIGNAL, TRIGGERWAIT, uLPUSH, KICKWAIT, uKPUSH, uKSENSORWAIT, LPUSH, LWAIT, uKVENT} kickState = TRIGGERWAIT; // Kicker state
	int lwait;                                      // Latch release wait counter
    int kwait;                                      // Kicker release wait counter
    int latchwait;                                  // Latched? wait counter
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
		// Wait to make sure pressure is adequate
		case WFP:
		{
        	// Is there enough pressure?
        	if (proxy->GetPressure() < T166_PNEU_KICK_MIN){
        		// There isn't enough pressure.   :(   Try again later.
        		break;
        	}
			kickSolenoid.Set(true);    // We are getting ready to kick
        	// There is enough pressure!!   :)   We're done here.
        	// Intentionally fall through to SIGNAL
        	kickState = SIGNAL;
		}
		// Signal the DS that we can kick
		case SIGNAL:
		{
        	// Send a ready signal to DS
        	DPRINTF(LOG_DEBUG, "We're READY TO KICK !!!!!\n");
			lHandle->DriverStationDisplay("READY TO KICK");
        	
        	// Done
        	// Intentionally fall through to TRIGGERWAIT
        	kickState = TRIGGERWAIT;
        	DPRINTF(LOG_DEBUG, "TRIGGERWAIT: Wait until the trigger (joy 3 - bttn 4) tells us to kick");
		}
		// Wait for the trigger to tell us to kick
		case TRIGGERWAIT:
		{
			// Is the trigger asking us to kick?
			if (proxy->GetButton(T166_DRIVER_STICK_LEFT, T166_KICKER_BUTTON,true)
				or proxy->GetButton(T166_DRIVER_STICK_RIGHT, T166_KICKER_BUTTON,true)
				or proxy->GetButton(T166_COPILOT_STICK, T166_KICKER_BUTTON,true))
			{
				// The trigger is asking us to kick.
	        	kickState = uLPUSH;
			} else {
				// Done
				// The trigger isn't asking us to kick. Wait.
				break;
			}
        	// Intentionally fall through to next state
		}
		// (PUSH UNLATCH) unlatch the kicker
		case uLPUSH:
		{
			unkickSolenoid.Set(false); // We aren't unkicking
			latchSolenoid.Set(false);  // We aren't latching
			unlatchSolenoid.Set(true); // We ARE unlatching [AND KICKING!!!]
			
        	kwait = 0;  // Reset wait counter
			
        	// Intentionally fall through to next state
        	kickState = KICKWAIT;
		}
		// Wait for the kicker to kick
		case KICKWAIT:
		{
        	// Have we waited long enough?
        	if (kwait++ < 100){
        		
        		// We haven't waited long enough.   :(    Let's try again later.
        		break;
        	}
        	
        	// We've waited long enough!!   :D    We're done here.
			// Intentiionally fall through to the next state
			kickState = uKPUSH;
		}
		// (PUSH UNKICK) pull back the kicker
		case uKPUSH:
		{
			kickSolenoid.Set(false);  // We aren't kicking
			unkickSolenoid.Set(true); // We are unkicking
        	// Intentionally fall through to next state
        	kickState = uKSENSORWAIT;
		}
		// wait for the sensor tells us the kicker is pulled back
		case uKSENSORWAIT:
		{
        	// Is the magnet sensor ready? Are we ready to override it?
        	if (Latch_Magnet_Sensor.Get() && (lwait++ < 100)){//T166_LATCH_OVERRIDE)){
        		// Keep waiting
        		break;
        	}
        	// We have hopefully unkicked
        	// We've waited long enough!!   :D   We're done here.
        	// Intentionally fall through to next state
        	kickState = LPUSH;
		}
		// (PUSH LATCH) latch the kicker
		case LPUSH:
		{
			unlatchSolenoid.Set(false); // We aren't unlatching
			latchSolenoid.Set(true);    // We are latching
        	// Intentionally fall through to next state
        	kickState = LWAIT;
        	latchwait = 0; // Reset the latch wait timer
		}
		// Wait for the latch to be down
		case LWAIT:
		{
        	// Have we waited long enough?
        	if (latchwait++ < 100){
        		
        		// We haven't waited long enough.   :(    Let's try again later.
        		break;
        	}
        	
        	// We've waited long enough!!   :D    We're done here.
			// Intentiionally fall through to the next state
        	kickState = uKVENT;
		}
		// (VENT UNKICK) release the latched kicker
		case uKVENT:
		{
			unkickSolenoid.Set(false);  // We aren't unkicking
        	// Intentionally fall through to next state
        	kickState = WFP;
		}
		}
		
        // Should we log this value?
		sl.PutOne(0, 0, 0);
		
		// Wait for our next lap
		WaitForNextLoop();
	}
	return (0);
	
};
