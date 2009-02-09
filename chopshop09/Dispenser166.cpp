#include "WPILib.h"
#include "Team166Task.h"
#include "Dispenser166.h"
#include "MemoryLog166.h"
#include "Robot166.h"

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	float x_acc;                     // accelarometer x value
	float y_acc;					//  accelarometer y value
	float acc_vector;
	
};

// Sample Memory Log
class DispLog : public MemoryLog166
{
public:
	DispLog() : MemoryLog166(128*1024) {return;};
	~DispLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float x_acc, float y_acc, float acc_vector);     // Log the x and y values
};

// Write one buffer into memory
unsigned int DispLog::PutOne(float x_acc, float y_acc, float acc_vector)
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
unsigned int DispLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f, %f, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->x_acc, ab->y_acc, ab->acc_vector);
	
	// Done
	return (sizeof(struct abuf166));
}


// Dispenser task constructor
Team166Dispenser::Team166Dispenser(void)
{
	Start((char *)"166DispenserTask");
	return;
};
	
// Dispenser task destructor
Team166Dispenser::~Team166Dispenser(void)
{
	return;
};
	
// Main function of the dispenser task
int Team166Dispenser::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
		
	Robot166 *lHandle;            // Local handle
	DispLog sl;                   // Dispenser log
	int sample_count = 0;         // Count of log samples
	
	
	// Let the world know we're in
	printf("In the 166 dispenser task\n");
		
	// Indicate that we've now completed initialization
	MyTaskInitialized = 1;
		
	// Ensure we get into Autononmous or Tele Operated mode
	while (!Robot166::getInstance() ||
	       ((Robot166::getInstance()->RobotMode != T166_AUTONOMOUS) &&
	    	(Robot166::getInstance()->RobotMode != T166_OPERATOR))) {
		Wait (0.050); // 50ms
	}
	MyTaskInitialized = 2;
	lHandle = Robot166::getInstance();
		
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		t_ConveyerDirection cdir;                 // Agitator direction
		float lift_motor;                         // Lift motor direction/power

		// Strobe the sensors
		
		// Get the command we're asked to apply
        lHandle->GetDispenser(&cdir, &lift_motor);   //gives the values for the conveyor direction and the desired lift motor speed
        //printf("cdir = %u, lift_motor = %f\n", cdir, lift_motor);
        
        switch(cdir)                                     	//switch for the direction of the conveyor belt
        {
        	case T166_CB_BACKWARD:                        	  //when the direction given is backward...
        		lHandle->treadmill_victor.Set(TREADMILL_REVERSE_SPEED); //set the treadmill victor to the set reverse speed
        		break;											
        	case T166_CB_FORWARD: 								//when the direction given is forward...
        		lHandle->treadmill_victor.Set(TREADMILL_FORWARD_SPEED); //set the treadmill victor to the set forward speed
        		break;
        	default:										//when no direction is given
        		lHandle->treadmill_victor.Set(NO_SPEED);				//set the treadmill victor speed to 0
        }
        //if(/*(lHandle->limitswitch_top1.Get()==1)&&*/(lHandle->limitswitch_top2.Get()==0)/*&&(lHandle->limitswitch_bottom1.Get()==1)&&(lHandle->limitswitch_bottom2.Get()==1)*/)
        //{
        	lHandle->lift_victor.Set(lift_motor);         //set the speed of the victor equal to the value of the joystick output
        //}
       // else
       // {
       // 	lHandle->lift_victor.Set(0);
       // }
        
        // Check limit switches, user command and motor direction
        
        // Set motor direction for lifter
        
        // Should we log this value?
		if (sample_count < 200) {
			sl.PutOne(0, 0, 0);
			sample_count++;
		} else {
			if (sample_count == 200) {
				sl.DumpToFile("dispenser.csv");
				sample_count++;
			}
		}
		MyWatchDog = 1;
		Wait (0.100); // 100ms

		// 
	}
	return (0);
	
};
