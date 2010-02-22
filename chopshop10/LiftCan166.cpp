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
	float JoyY;						// Position of Joystick
	bool limit;						// State of limit switch
	
};

//  Memory Log
class LiftCanLog : public MemoryLog166
{
public:
	LiftCanLog() : MemoryLog166(sizeof(struct abuf166), LIFT_CYCLE_TIME, "lift") {return;};
	~LiftCanLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(int liftstate, float JoyY, bool limit);     // Log the x and y values
};

// Write one buffer into memory
unsigned int LiftCanLog::PutOne(int liftstate, float JoyY, bool limit)
{
	struct abuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct abuf166 *)GetNextBuffer(sizeof(struct abuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		ob->liftstate = liftstate;
		ob->JoyY = JoyY;
		ob->limit = limit;
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
	fprintf(ofile, "%u, %u, %d, %f, %d\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->liftstate, ab->JoyY, ab->limit);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166LiftCan::Team166LiftCan(void): lift_jag(T166_LIFT_MOTOR_CAN), Lift_BOTTOM_Limit_Switch(BOTTOM_LIMITSWITCH_DIGITAL_INPUT)
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
	Solenoid Lift_Solenoid(T166_LIFT_PISTON);
	
	// Wait counter
	int ejectwaitcount;
	float JoyY;
	bool limit;
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 Lift task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);	
	
	proxy=Proxy166::getInstance();
	
	int valuethrottle=0;
	
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		switch (lstate) {
			// Waiting for button to be pressed
			case REST: {
				// Check if the button is pressed
				if (proxy->GetButton(3,T166_LIFT_BUTTON) == true) {
					// Pressurize the cylinder
					lstate = EJECT;
				}
				else {
					break;
				}
			}
			// Intiate ejecton of piston
			case EJECT: {
				// Open solenoid, to fill cylinder
				Lift_Solenoid.Set(true);
				// start wait timer
				ejectwaitcount = 0;
				break;
			}
			// Allow Operator to control winch
			case WINCHING: {
				// Get the value of the limit switch
				limit = Lift_BOTTOM_Limit_Switch.Get();
				// Make sure limit is not pressed
				if (limit == true) {
					// If it is go back to rest
					lstate = REST;
				}
				// Get the value of the joystick
				JoyY = proxy->GetJoystickY(3);
				// only get current once a second
				if ((++valuethrottle)% (1000/LIFT_CYCLE_TIME)==0)
				{
					proxy->SetCurrent(T166_LIFT_MOTOR_CAN,lift_jag.GetOutputCurrent());
					Lift_Solenoid.Set(false);
				}
					// Set motor to joystick axis
					lift_jag.Set(JoyY);
				break;
			}
		}
        // Should we log this value?
		sl.PutOne(lstate, JoyY, limit);
		
		// Wait for our next lap
		WaitForNextLoop();
	}
	return (0);
	
};
