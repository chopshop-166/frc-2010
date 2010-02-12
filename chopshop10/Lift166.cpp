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
#include "Lift166.h"
#include "MemoryLog166.h"
#include "Robot166.h"
#include "BaeUtilities.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

int limit;

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;              // Time of snapshot
	float x_acc;                     // accelerometer x value
	float y_acc;					 // accelerometer y value
	float acc_vector;
	
};

//  Memory Log
class LiftLog : public MemoryLog166
{
public:
	LiftLog() : MemoryLog166(128*1024, "lift") {return;};
	~LiftLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float x_acc, float y_acc, float acc_vector);     // Log the x and y values
};

// Write one buffer into memory
unsigned int LiftLog::PutOne(float x_acc, float y_acc, float acc_vector)
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
unsigned int LiftLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f, %f, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->x_acc, ab->y_acc, ab->acc_vector);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166Lift::Team166Lift(void): lift_jag(T166_LIFT_CHANNEL), Lift_BOTTOM_Limit_Switch(BOTTOM_LIMITSWITCH_DIGITAL_INPUT)
{
	Start((char *)"166LiftTask", LIFT_CYCLE_TIME);
	return;
};
	
// task destructor
Team166Lift::~Team166Lift(void)
{
	return;
};
	
// Main function of the task
int Team166Lift::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
		
	Robot166 *lHandle;            // Local handle
	LiftLog sl;                   // log
	Proxy166 *proxy;
	float joystickY;
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 Lift task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);	
	
	proxy=Proxy166::getInstance();
	
	int printstop=0;
		
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		
        // Some code that doesn't do anything:
//		int dir;
//        lHandle->GetLift(&dir, &lift_motor);   // Get the direction of the lift
    			  //gives the values for the desired lift motor speed
//	if (proxy->GetSwitch())
		if (proxy->GetButton(3,2,false)){
			limit = Lift_BOTTOM_Limit_Switch.Get();
            DPRINTF(LOG_DEBUG,"Limit Switch: %d", limit);
			if (Lift_BOTTOM_Limit_Switch.Get()==1){
				lift_jag.Set(0);
				}
	        else{
	        	DPRINTF(LOG_DEBUG,"Button pushed: now in LIFT mode.\n");
	        	joystickY = proxy->GetJoystickY(3);
	        	lift_jag.Set(joystickY);
	        	}
		}
		else{
			lift_jag.Set(0);
		}
        if(((++printstop)%10)==0) {
        	joystickY = proxy->GetJoystickY(3);
        	DPRINTF(LOG_DEBUG, "Joystick Y: %f", joystickY);
        	
        }

        // Should we log this value?
		sl.PutOne(0, 0, 0);
		
		// Wait for our next lap
		WaitForNextLoop();
	}
	return (0);
	
};
