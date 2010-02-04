#include "WPILib.h"
#include "Team166Task.h"
#include "TankDrive166.h"
#include "MemoryLog166.h"
#include "Robot166.h"
#include "BaeUtilities.h"
#include "Joystick.h"
#include "RobotDrive.h"
#include "Proxy166.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	float x_acc;                     // accelarometer x value
	float y_acc;					//  accelarometer y value
	float acc_vector;
	
};

// Sample Memory Log
class TankDriveLog : public MemoryLog166
{
public:
	TankDriveLog() : MemoryLog166(128*1024, "tank_drive") {return;};
	~TankDriveLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float x_acc, float y_acc, float acc_vector);     // Log the x and y values
};

class Team166Drive : public Team166Task
{
public:
};
// Write one buffer into memory
unsigned int TankDriveLog::PutOne(float x_acc, float y_acc, float acc_vector)
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
unsigned int TankDriveLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f, %f, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->x_acc, ab->y_acc, ab->acc_vector);
	
	// Done
	return (sizeof(struct abuf166));
}

// Arm task constructor
Team166TankDrive::Team166TankDrive(void) :
	RobotDrive(	(UINT32)T166_LEFT_FRONT_MOTOR_CHANNEL,
				(UINT32)T166_RIGHT_FRONT_MOTOR_CHANNEL)
{
	Start((char *)"166TankDriveTask", TANK_CYCLE_TIME);
	return;
};
	
// Arm task destructor
Team166TankDrive::~Team166TankDrive(void)
{
	return;
};

// Main function of the drive task
int Team166TankDrive::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	float leftValue;
	float rightValue;
	Robot166 *lHandle;            // Local handle
	TankDriveLog sl;                   // Arm log
	Proxy166 *proxy;				// Handle to data associated with the Proxy object
	
	/* Jerry, Ryan, Anthony Added this >>*/
	/*
	GenericHID leftStick;
	GenericHID rightStick;
 	Jerry & Anthony's additions. */
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 TankDrive task\n");
		
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
		
	// Obtain access to the proxy object
	proxy = Proxy166::getInstance();

	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);

	int timer=0;
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		leftValue = proxy->GetJoystickY(1);
		rightValue = proxy->GetJoystickY(2);
		TankDrive(leftValue, rightValue);
		if(((++timer)%(1000 / TANK_CYCLE_TIME)) == 0 ) {
			printf("%f\t%f\n",leftValue,rightValue);
		}
		
        // Should we log this value?
		sl.PutOne(0, 0, 0);
		
		// Wait for our next lap
		WaitForNextLoop();		
	}
	return (0);
	
};
