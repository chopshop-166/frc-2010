/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Inclinometer.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 11, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code which controls the inclinometer
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "Team166Task.h"
#include "Inclinometer.h"
#include "MemoryLog166.h"
#include "Robot166.h"
#include "BaeUtilities.h"

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

//  Memory Log
class InclinometerLog : public MemoryLog166
{
public:
	InclinometerLog() : MemoryLog166(128*1024, "inclinometer") {return;};
	~InclinometerLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float x_acc, float y_acc, float acc_vector);     // Log the x and y values
};

// Write one buffer into memory
unsigned int InclinometerLog::PutOne(float x_acc, float y_acc, float acc_vector)
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
unsigned int InclinometerLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f, %f, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->x_acc, ab->y_acc, ab->acc_vector);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166Inclinometer::Team166Inclinometer(void):	InclinometerA(T166_ENC_INCL_A), InclinometerB(T166_ENC_INCL_B)

{
	Start((char *)"166InclinometerTask", INCLINOMETER_CYCLE_TIME);
	return;
};
	
// task destructor
Team166Inclinometer::~Team166Inclinometer(void)
{
	return;
};
	
// Main function of the task
int Team166Inclinometer::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
		
		
	Robot166 *lHandle;            // Local handle
	InclinometerLog sl;                   // log
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 Inclinometer task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);	
		
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		static int throttle = 0;
		throttle++;
		if (throttle%10==0){
				throttle = 0;
				DPRINTF(LOG_DEBUG,"Channel: %i Value: %i",InclinometerA.GetChannel(),InclinometerA.Get(),InclinometerB.GetChannel(),InclinometerB.Get());
				}
				
        // Should we log this value?
		sl.PutOne(0, 0, 0);
		
		// Wait for our next lap
		WaitForNextLoop();		
	}
	return (0);
	
};
