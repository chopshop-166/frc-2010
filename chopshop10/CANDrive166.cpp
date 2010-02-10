/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: CANDrive166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 23, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Code which monitors jaguar return info
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "Team166Task.h"
#include "CANDrive166.h"
#include "MemoryLog166.h"
#include "Robot166.h"
#include "BaeUtilities.h"
#include "Proxy166.h"
#include "CANJaguar.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	float x_acc;                     // accelerometer x value
	float y_acc;					//  accelerometer y value
	float acc_vector;
	
};

//  Memory Log
class CANDriveLog : public MemoryLog166
{
public:
	CANDriveLog() : MemoryLog166(128*1024, "candrive") {return;};
	~CANDriveLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float x_acc, float y_acc, float acc_vector);     // Log the x and y values
};

// Write one buffer into memory
unsigned int CANDriveLog::PutOne(float x_acc, float y_acc, float acc_vector)
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
unsigned int CANDriveLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f, %f, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->x_acc, ab->y_acc, ab->acc_vector);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166CANDrive::Team166CANDrive(void):
	blackJag(T166_BLACK_JAG_CAN),
	leftJag(T166_LEFT_MOTOR_CAN),
	rightJag(T166_RIGHT_MOTOR_CAN)
{
	DPRINTF(LOG_DEBUG, "Black Jag");
	Start((char *)"166CANDriveTask", CAN_CYCLE_TIME);
	return;

};
	
// task destructor
Team166CANDrive::~Team166CANDrive(void)
{
	return;
};
void Team166CANDrive::CANDrive(float leftValue, float rightValue)
{
	leftJag.Set(leftValue);
	rightJag.Set(-rightValue);
}
	
// Main function of the task
int Team166CANDrive::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
		
	Robot166 *lHandle;                  // Local handle
	CANDriveLog sl;                    // log
	Proxy166 *proxy;				  //pointer to proxy	
	proxy = proxy->getInstance();     
	
	int printstop=0;
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 CANDrive task\n");

	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);
	printf("CANDrive is ready.\n");
	
	float leftValue, rightValue;

    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		leftValue = proxy->GetJoystickY(1);
		rightValue = proxy->GetJoystickY(2);
		CANDrive(leftValue, rightValue);
		if(((++printstop)%20)==0){
			DPRINTF(LOG_DEBUG, "Left Jaguar: %f : %f : %f",leftJag.GetBusVoltage(), leftJag.GetOutputVoltage(), leftJag.GetOutputCurrent(), leftJag.GetTemperature() );
			DPRINTF(LOG_DEBUG, "Right Jaguar: %f : %f : %f",rightJag.GetBusVoltage(), rightJag.GetOutputVoltage(), rightJag.GetOutputCurrent(), rightJag.GetTemperature() );
		}
		
		// do stuff
		sl.PutOne(0, 0, 0);
		
		// Wait for our next lap
		WaitForNextLoop();
	}
	return (0);
	
};
