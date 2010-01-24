/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Sonar166.cpp
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code which reads the sonar sensors
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "Sonar166.h"
#include "MemoryLog166.h"
#include <math.h>
#include <sysLib.h>

// Sample in memory buffer
struct sobuf166
{
	struct timespec tp;               // Time of snapshot
	float distance;                   // Distance seen
	
};

// Sample Memory Log
class SonarLog : public MemoryLog166
{
public:
	SonarLog() : MemoryLog166(128*1024, "sonar") {return;};
	~SonarLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float distance); // Log the distanace
};

// Write one buffer into memory
unsigned int SonarLog::PutOne(float dist)
{
	struct sobuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct sobuf166 *)GetNextBuffer(sizeof(struct sobuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		ob->distance = dist;
		return (sizeof(struct sobuf166));
	}
	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int SonarLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct sobuf166 *ab = (struct sobuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->distance);
	
	// Done
	return (sizeof(struct sobuf166));
}


// Sonar task constructor
Team166Sonar::Team166Sonar(void)
{
	// Initialize assorted fields
	
	// Start our task
	Start((char *)"166SonarTask", 0.025);	
};
	
// Sonar task destructor
Team166Sonar::~Team166Sonar(void)
{		
	return;
};
	
// Main function of the Sonar task
int Team166Sonar::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{

	Robot166 *lHandle;            // Local handle
	AnalogChannel ac(T166_US_MOD, T166_US_DIST); // Ultrasound sensor
	SonarLog sl;                  // Sonar log
	struct timespec start_time;   // Time when our logic starts	
	struct timespec current_time; // Time when we check again
	struct timespec delta_time;   // Time when we check again
	struct timespec non_sleep;    // Time not slept
	unsigned int nano_left;       // Nano seconds left of second
	unsigned int crate;           // Clock rate
	unsigned int half_tick;       // Length of a half tick
#define UMAX (10)                 // Window size for rolling average		
	INT16 uval[UMAX];             // Ultrasound value
	int uidx = 0;                 // Index into array
	int al;                       // Average distance loop
	unsigned int aavg;            // Cumulative count
	static int cc = 0;            // Counter to control print out
	
	// Let the world know we're in
	printf("In the 166 Sonar task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);
	
	printf("Sonar task is getting ready...\n");

	// Figure out this board's tick size (in nano seconds)
	crate = (1000 * 1000 * 1000) / sysClkRateGet();
	
	// And then the duration of a half-tick (in nano seconds)
	half_tick = crate / 2;
	
	// Establish our start time
	clock_gettime(CLOCK_REALTIME, &start_time);
	
	// And then the nano seconds left to the next full second
	nano_left = (1000*1000*1000) - start_time.tv_nsec;
	
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
        // Pick up Ultrasound values
        uval[(uidx++ % UMAX)] = ac.GetValue();
#if 0       
		if (!(cc % 20))
       printf("US value: %d\n", ac.GetValue());
#endif   
        // Compute an average
        aavg = 0;
        for (al=0; al<UMAX; al++)
        	aavg += uval[al];
        distance = (((aavg / UMAX) * (20.0 / 4.096)) / 10.0) * 2.54;
#if 0
        if (!(uidx % UMAX))
        	printf("Current Ultrasound value: %f\n", distance);
#endif	
		// Should we log this value?
        sl.PutOne(distance);

		// Get the current time
		clock_gettime(CLOCK_REALTIME, &current_time);
		
		// Compute delta time since we started out loop
		delta_time.tv_sec = current_time.tv_sec - start_time.tv_sec;
		if (current_time.tv_nsec >= start_time.tv_nsec) {
			delta_time.tv_nsec = current_time.tv_nsec - start_time.tv_nsec;
		} else {
			delta_time.tv_nsec = current_time.tv_nsec + nano_left;
			delta_time.tv_sec--; // We do not care about this for our sleep
		}
#define MS_SLEEP (50*1000000)		
		// How far into this cycle have we run?
#if 0
		if (!(cc % 500))
		  printf("%u = Delta: %u s, %u ns (%u ms)\n", cc, delta_time.tv_sec, delta_time.tv_nsec, delta_time.tv_nsec / (1000000));
#endif
		delta_time.tv_nsec = MS_SLEEP - (delta_time.tv_nsec % MS_SLEEP); // 5ms into nano seconds
		if ((unsigned int)delta_time.tv_nsec < half_tick)
			  delta_time.tv_nsec = MS_SLEEP;
		delta_time.tv_sec = 0;
		
		// Display the sleep time
#if 0
		if (!(cc % 500))
			printf("%u = Sleep Delta: %u s, %u ns (%u ms)\n", cc, delta_time.tv_sec, delta_time.tv_nsec, delta_time.tv_nsec / (1000000));
#endif
		nanosleep((const struct timespec *)&delta_time, &non_sleep);
		cc++;
		
		MyWatchDog = 1;
		//Wait (0.100); // 25ms
	}
	return (0);
}
