#include "WPILib.h"
#include "Inertia166.h"
#include "MemoryLog166.h"
#include <math.h>

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	float x_acc;                     // accelarometer x value
	float y_acc;					//  accelarometer y value
	float acc_vector;
	
};

// Sample Memory Log
class Accel_Log2 : public MemoryLog166
{
public:
	Accel_Log2() : MemoryLog166(128*1024, "inertia") {return;};
	~Accel_Log2() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float x_acc, float y_acc, float acc_vector);     // Log the x and y values
};

// Write one buffer into memory
unsigned int Accel_Log2::PutOne(float x_acc, float y_acc, float acc_vector)
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
unsigned int Accel_Log2::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f, %f, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->x_acc, ab->y_acc, ab->acc_vector);
	
	// Done
	return (sizeof(struct abuf166));
}


// Inertia task constructor
Team166Inertia::Team166Inertia(void)
{
	// Initialize assorted fields
	
	// Start our task
	Start((char *)"166InertiaTask", 0.100);	
};
	
// Inertia task destructor
Team166Inertia::~Team166Inertia(void)
{		
	return;
};
	
// Main function of the inertia task
int Team166Inertia::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{

	Robot166 *lHandle;            // Local handle
	Accelerometer acX(T166_ACCEL_MOD, T166_ACCEL_Y);  // Accelerometer, X axis
	Accelerometer acY(T166_ACCEL_MOD, T166_ACCEL_X);  // Accelerometer, Y-axis
	Accel_Log2 sl;                 // Sensor log
	
	// Let the world know we're in
	printf("In the 166 intertia task\n");
		
	// Indicate that we've now completed initialization
	MyTaskInitialized = 1;
		
	// Ensure we get into Autononmous or Tele Operasted mode
	while (!Robot166::getInstance() ||
	       ((Robot166::getInstance()->RobotMode != T166_AUTONOMOUS) &&
	    	(Robot166::getInstance()->RobotMode != T166_OPERATOR))) {
		Wait (T166_TA_WAIT_LENGTH);
	}
	MyTaskInitialized = 2;
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);
	
#if 1 // 2008 model
	// Initialize 2008 Accelerometer (Analog Devices ADXL204)
	// Note: this example assumes it is horizontally mounted.
	acX.SetSensitivity(1.0); // 1000mV/g
	acX.SetZero(2.5); // 2.5V when horizontally mounted
	acY.SetSensitivity(1.0); // 1000mV/g
	acY.SetZero(2.5); // 2.5V when horizontally mounted
#else // 2009 model
	// Note: this example assumes it is horizontally mounted.
	acX.SetSensitivity(0.3); // 300mV/g
	acX.SetZero(1.5); // 1.5V when horizontally mounted
	acY.SetSensitivity(0.3); // 300mV/g
	acY.SetZero(1.5); // 1.5V when horizontally mounted
#endif
	
    // General main loop (while in Autonomous or Tele mode)
	printf("Intertia task is getting ready...\n");
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		float x_acc, y_acc;
		
		// Pick up Accelerometer values
		x_acc = acX.GetAcceleration();
		y_acc = acY.GetAcceleration();
		
		// Calculate strength of resulting force
		acc_vector = sqrt((x_acc*x_acc)+(y_acc*y_acc));

		// Should we log this value?
		sl.PutOne(x_acc,y_acc, acc_vector);
		
		// Wait for our next lap
		WaitForNextLoop();
	}
	return (0);
}
