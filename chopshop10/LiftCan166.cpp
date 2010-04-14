/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Lift166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code which controls the hanging lift
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "Team166Task.h"
#include "LiftCan166.h"
#include "MemoryLog166.h"
#include "Robot166.h"
#include "BaeUtilities.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf



// Sample in memory buffer
struct abuf166
{
	struct timespec tp;             // Time of snapshot
	int liftstate;					// State of lift
	bool deployed;					// Deployed already?
	bool button;					// Whether the lift button is pressed
};

//  Memory Log
class LiftCanLog : public MemoryLog166
{
public:
	LiftCanLog() : MemoryLog166(sizeof(struct abuf166), LIFT_CYCLE_TIME, "lift") {
		return;
	};
	~LiftCanLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(int liftstate, bool deployed, bool button);     // Log the lift's state
};

// Write one buffer into memory
unsigned int LiftCanLog::PutOne(int liftstate, bool deployed, bool button)
{
	struct abuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct abuf166 *)GetNextBuffer(sizeof(struct abuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		ob->liftstate = liftstate;
		ob->deployed = button;
		ob->deployed = button;
		return (sizeof(struct abuf166));
	}
	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int LiftCanLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	// Output the data into the file
	fprintf(ofile, "%u, %u, %4.5f, %d, %f, %d, %d\n",
			ab->tp.tv_sec, ab->tp.tv_nsec,
			((ab->tp.tv_sec - starttime.tv_sec) + ((ab->tp.tv_nsec-starttime.tv_nsec)/1000000000.)),
			ab->liftstate, ab->button);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166LiftCan::Team166LiftCan(void): lift_jag(T166_LIFT_MOTOR_CAN)
{
	Start((char *)"166LiftCanTask", LIFT_CYCLE_TIME);
	return;
};
	
// task destructor
Team166LiftCan::~Team166LiftCan(void)
{
	return;
};
	
// Main function of the task
int Team166LiftCan::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
		
	Robot166 *lHandle;            // Local handle
	LiftCanLog sl;                   // log
	Proxy166 *proxy;
	
	// State of Lift state machine
	enum {REST, EJECT, WINCHING } lstate = REST;
	
	// Defines Solenoid for Lift piston
	Solenoid LiftLatch_Solenoid(T166_LIFT_PISTON);
	Solenoid LiftUnlatch_Solenoid(T166_UNLIFT_PISTON);
	LiftLatch_Solenoid.Set(false);
	LiftUnlatch_Solenoid.Set(true);
	
	bool deployed = false; 		// Whether the button was pressed
	bool button = false; 		// Whether the button was pressed
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 Lift task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);
	
	proxy=Proxy166::getInstance();
	
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		if(deployed) {
			// Set motor to retract or expand the arm
			lift_jag.Set(
					proxy->GetButton(T166_COPILOT_STICK,T166_LIFT_UP_BUTTON) -
					proxy->GetButton(T166_COPILOT_STICK,T166_LIFT_DOWN_BUTTON)
			);
			LiftLatch_Solenoid.Set(false);
			LiftUnlatch_Solenoid.Set(true);
		} else {
			button = proxy->GetButton(T166_COPILOT_STICK, T166_LIFT_RELEASE_BUTTON);
			if(button) {
				deployed = true;
				LiftLatch_Solenoid.Set(true);
				LiftUnlatch_Solenoid.Set(false);
			} else {
				LiftLatch_Solenoid.Set(false);
				LiftUnlatch_Solenoid.Set(true);
			}
		}
		
        // Should we log this value?
		sl.PutOne(lstate, deployed, button);
		
		// Wait for our next lap
		WaitForNextLoop();
	}
	return (0);
	
};
