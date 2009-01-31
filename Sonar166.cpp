#include "WPILib.h"
#include "Sonar166.h"
#include "MemoryLog166.h"
#include <math.h>

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
	SonarLog() : MemoryLog166(128*1024) {return;};
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
	Start((char *)"166SonarTask");	
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
	int sample_count = 0;         // Count of log samples
#define UMAX (10)                 // Window size for rolling average		
	INT16 uval[UMAX];             // Ultrasound value
	int uidx = 0;                 // Index into array
	int al;                       // Average distance loop
	unsigned int aavg;            // Cumulative count
	float dist;                   // Distance as an average
	
	// Let the world know we're in
	printf("In the 166 Sonar task\n");
		
	// Indicate that we've now completed initialization
	MyTaskInitialized = 1;
		
	// Ensure we get into Autononmous or Tele Operasted mode
	while (!Robot166::getInstance() ||
	       ((Robot166::getInstance()->RobotMode != T166_AUTONOMOUS) &&
	    	(Robot166::getInstance()->RobotMode != T166_OPERATOR))) {
		Wait (0.050); // 50ms
	}
	MyTaskInitialized = 2;
	lHandle = Robot166::getInstance();
	

    // General main loop (while in Autonomous or Tele mode)
	printf("Sonar task is getting ready...\n");
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
        // Pick up Ultrasound values
        uval[(uidx++ % UMAX)] = ac.GetValue();
        
        // Compute an average
        aavg = 0;
        for (al=0; al<UMAX; al++)
        	aavg += uval[al];
        dist = (((aavg / UMAX) * (20.0 / 4.096)) / 10.0) * 2.54;
        if (!(uidx % UMAX))
        	printf("Current Ultrasound value: %f\n", dist);
	
		// Should we log this value?
		if (sample_count < 200) {
			sl.PutOne(dist);
			sample_count++;
		} else {
			if (sample_count == 200) {
				sl.DumpToFile("sonar.csv");
				sample_count++;
			}
		}
		MyWatchDog = 1;
		Wait (0.025); // 25ms
	}
	return (0);
}
