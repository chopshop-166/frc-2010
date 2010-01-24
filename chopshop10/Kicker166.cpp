#include "WPILib.h"
#include "Team166Task.h"
#include "Kicker166.h"
#include "MemoryLog166.h"
#include "Robot166.h"
#include "BaeUtilities.h"

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
class KickerLog : public MemoryLog166
{
public:
	KickerLog() : MemoryLog166(128*1024, "kicker") {return;};
	~KickerLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float x_acc, float y_acc, float acc_vector);     // Log the x and y values
};

// Write one buffer into memory
unsigned int KickerLog::PutOne(float x_acc, float y_acc, float acc_vector)
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
unsigned int KickerLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f, %f, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->x_acc, ab->y_acc, ab->acc_vector);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166Kicker::Team166Kicker(void)
{
	Start((char *)"166KickerTask", 0.010);
	return;
};
	
// task destructor
Team166Kicker::~Team166Kicker(void)
{
	return;
};
	
// Main function of the task
int Team166Kicker::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
		
	Robot166 *lHandle;            // Local handle
	KickerLog sl;                   // Arm log
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 Kicker task\n");
		
	// Indicate that we've now completed initialization
	MyTaskInitialized = 1;
		
	// Ensure we get into Autononmous or Tele Operated mode
	while (!Robot166::getInstance() ||
	       ((Robot166::getInstance()->RobotMode != T166_AUTONOMOUS) &&
	    	(Robot166::getInstance()->RobotMode != T166_OPERATOR))) {
		Wait (T166_TA_WAIT_LENGTH);
	}
	MyTaskInitialized = 2;
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);	
		
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
			
		// Get the command we're asked to apply
        // TODO: update this for real Kicker functionality
        //lHandle->GetKicker(&cdir, &lift_motor);   //gives the values for the conveyor direction and the desired lift motor speed
        //("cdir = %u, lift_motor = %f\n", cdir, lift_motor);
                //switch(cdir)                                     	//switch for the direction of the conveyor belt
                //{
                //	case T166_CB_BACKWARD:                        	  //when the direction given is backward...
                //		break;											
                //	case T166_CB_FORWARD: 								//when the direction given is forward...
                //		break;
                //	default:										//when no direction is given
                //		lHandle->treadmill_victor.Set(NO_SPEED);				//set the treadmill victor speed to 0
                //}           
        

        // Should we log this value?
		sl.PutOne(0, 0, 0);
		
		// Wait for our next lap
		WaitForNextLoop();		
	}
	return (0);
	
};
