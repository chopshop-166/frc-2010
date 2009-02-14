#include "WPILib.h"
#include "Team166Task.h"
#include "Dispenser166.h"
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
class DispLog : public MemoryLog166
{
public:
	DispLog() : MemoryLog166(128*1024, "dispenser") {return;};
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
	int tick = 0;
	int print, print2;
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 dispenser task\n");
		
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
	lHandle->RegisterLogger(&sl);	
		
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		t_ConveyerDirection cdir;                 // Agitator direction
		float lift_motor;                         // Lift motor direction/power
        int girate_switch;
		// Strobe the sensors
		
		// Get the command we're asked to apply
        lHandle->GetDispenser(&cdir, &lift_motor,&girate_switch);   //gives the values for the conveyor direction and the desired lift motor speed
        //("cdir = %u, lift_motor = %f\n", cdir, lift_motor);
                if(girate_switch==0)
                {
                    tick = 0;
                }
                else
                {
                	if(lHandle->limitswitch_top.Get()==1)
                	{
                		tick = 4;
                	}
                	if(lHandle->limitswitch_bottom.Get()==1)
                  	{
                   		tick = 0;
                	}
                	if(tick < 4)
                	{
                		lHandle->lift_victor.Set(1);
                		tick++;
                	}
                	else if(tick >= 4)
                	{
                		lHandle->lift_victor.Set(-1);
                		tick++;
                	}
                	if(tick == 7)
                	{
                		lHandle->lift_victor.Set(0);
                		tick = 0;
                	}
                	
                }
                switch(cdir)                                     	//switch for the direction of the conveyor belt
                {
                	case T166_CB_BACKWARD:                        	  //when the direction given is backward...
                		lHandle->treadmill_victor.Set(TREADMILL_FORWARD_SPEED); //set the treadmill victor to the set reverse speed
                		break;											
                	case T166_CB_FORWARD: 								//when the direction given is forward...
                		lHandle->treadmill_victor.Set(TREADMILL_REVERSE_SPEED); //set the treadmill victor to the set forward speed
                		break;
                	default:										//when no direction is given
                		lHandle->treadmill_victor.Set(NO_SPEED);				//set the treadmill victor speed to 0
                }
                print = lHandle->limitswitch_top.Get();
                print2 = lHandle->limitswitch_bottom.Get();
                DPRINTF(LOG_DEBUG,"SWITCH TOP: %d\n",print);
                DPRINTF(LOG_DEBUG,"SWITCH BOTTOM: %d\n",print2);
                    if(girate_switch==0)
                    {
                       if((lHandle->limitswitch_top.Get()==1)&&(lift_motor>0))
                       {
                    	lHandle->lift_victor.Set(0);   
                       }                                          //set the speed of the victor equal to the value of the joystick output
                       else if((lHandle->limitswitch_bottom.Get()==1)&&(lift_motor<0))
                       {
                    	lHandle->lift_victor.Set(0);
                       }
                       else 
                       {
                    	   lHandle->lift_victor.Set(lift_motor);
                       }
                    }
            
        
        // Should we log this value?
		sl.PutOne(0, 0, 0);
		MyWatchDog = 1;
		Wait (0.100); // 100ms

		// 
	}
	return (0);
	
};
