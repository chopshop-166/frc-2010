#include "WPILib.h"
#include "Vision166.h"
#include "MemoryLog166.h"
#include <math.h>

// Sample in memory buffer
struct vbuf166
{
	struct timespec tp;               // Time of snapshot
	float bearing;                    // Target bearing
	
};

// Sample Memory Log
class VisionLog : public MemoryLog166
{
public:
	VisionLog() : MemoryLog166(128*1024) {return;};
	~VisionLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float b);     // Log the bearing
};

// Write one buffer into memory
unsigned int VisionLog::PutOne(float b)
{
	struct vbuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct vbuf166 *)GetNextBuffer(sizeof(struct vbuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		ob->bearing = b;
		return (sizeof(struct vbuf166));
	}
	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int VisionLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct vbuf166 *ab = (struct vbuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->bearing);
	
	// Done
	return (sizeof(struct vbuf166));
}


// Vision task constructor
Team166Vision::Team166Vision(void)
{
	// Initialize assorted fields
	
	// Start our task
	Start((char *)"166VisionTask");	
};
	
// Vision task destructor
Team166Vision::~Team166Vision(void)
{		
	return;
};
	
// Main function of the vision task
int Team166Vision::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{

	Robot166 *lHandle;            // Local handle
	VisionLog vl;                 // Vision log
	int sample_count = 0;         // Count of log samples
	
	// Let the world know we're in
	printf("In the 166 vision task\n");
		
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
	printf("Vision task is getting ready...\n");
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		float b=1.66;
		
		// Should we log this value?
		if (sample_count < 200) {
			vl.PutOne(b);
			sample_count++;
		} else {
			if (sample_count == 200) {
				vl.DumpToFile("vision.csv");
				sample_count++;
			}
		}
		MyWatchDog = 1;
		Wait (0.100); // 100ms
	}
	return (0);
}
