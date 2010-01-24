/********************************************************************************
*  Project   		: Chopshop 2009
*  File Name  		: Team166Task.h          
*  Contributors   	: PSH
*  Creation Date 	: February 6, 2008
*  Revision History	: Source code & revision history maintained at code.google.com    
*  File Description	: This file defines the high level and shared context for a Team 166
*/

#include "WPILib.h"
#include "Robot166.h"

// Constructor
Team166Task::Team166Task(int IsEssential)
{	
	// Indicate we've never been spawned before
	MyTaskId = 0;
	MyTaskInitialized = 0;
	MyWatchDog = 0;
	MyTaskIsEssential = IsEssential;
	MyName = 0;
	MissedWatchDog = 0;
};
	
// Destructor
Team166Task::~Team166Task()
{
	return;
};
	
// General start routine; needs to be called by target constructor
int Team166Task::Start(char *tname, float loop_interval)
{
	// Do we have a previous instance of this task?
	if (MyTaskId) {
			
		// Yes. Get rid of it.
		printf("Killing previous instance of task '%s' with id '0x%x'\n",
					tname, MyTaskId);
		taskDelete(MyTaskId);
		MyTaskId = 0;
		MyTaskInitialized = 0;
	}

	// Save the task name for later reference
	MyName = tname;
		
	// Capture the preferred loop time
	MyLoopInterval = loop_interval;
		
	// Spawn a new task
	MyTaskId = taskSpawn(tname, TEAM166TASK_K_PRIO, VX_FP_TASK,
				TEAM166TASK_K_STACKSIZE, (FUNCPTR) Team166Task::MainJacket,
				(int)this, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf("Task '%s' spawned with ID '0x%x'\n", tname, MyTaskId);
 		
	// Figure out this board's tick size (in nano seconds)
	crate = (1000 * 1000 * 1000) / sysClkRateGet();
 		
	// And then the duration of a half-tick (in nano seconds)
	half_tick = crate / 2;
		
	//  Back to caller with the ID of the task we just spawned
	return (MyTaskId);		
};
	
// Jacket routine that leads into the actual Main routine of target
int Team166Task::MainJacket(void *this_p, int a2, int a3, int a4, int a5,
		int a6, int a7, int a8, int a9, int a10)
{

	int l;  // Local loop variable
		
	// Find the next available slot
	for (l=0; l<T166_MAXTASK; l++)
		if (!ActiveTasks[l])
			break;
		
	// Do we have room for one more?
	if (l != T166_MAXTASK) {
		ActiveTasks[l] = (Team166Task *)this_p;
	}

	// Just daisy chain over to virtual main function
	return (((Team166Task *)this_p)->Main(a2, a3, a4, a5, a6, a7, a8, a9, a10));
};
	
// Wait for Robot go-ahead
void Team166Task::WaitForGoAhead(void)
{
		
	// Indicate that we've now completed initialization
	MyTaskInitialized = 1;
			
	// Ensure we get into Autononmous or Tele Operated mode
	while (!Robot166::getInstance() ||
		       ((Robot166::getInstance()->RobotMode != T166_AUTONOMOUS) &&
		    	(Robot166::getInstance()->RobotMode != T166_OPERATOR))) {
		Wait (T166_TA_WAIT_LENGTH);
	}
	MyTaskInitialized = 2;
	
	// Done
	return;
};

// Wait for next lap
void Team166Task::WaitForNextLoop(void)
{
		
	// Indicate that we've checked in
	MyWatchDog = 1;
		
	// Just sleep the loop interval for now
	Wait(MyLoopInterval);
};

// Check if all registered tasks are up
int Team166Task::IfUp(void)
{
	int l;  // Local loop variable

	// Loop through all the slots and check each registered task
	for (l=0; l<T166_MAXTASK; l++) {
			
		// If the task is registered but not initialized, we're not done
		if ((ActiveTasks[l]) &&
			 (!ActiveTasks[l]->MyTaskInitialized)) {
			return (0);	
		}
	}
		
	// We're good
	return (1);
};
	
// Should we feed the watchdog?
int Team166Task::FeedWatchDog(void)
{
		
	int l;  // Local loop variable
		
	// Loop through all the slots and check each registered task
	for (l=0; l<T166_MAXTASK; l++) {
			
		// Is this a registered and essential task?
		if ((ActiveTasks[l]) &&
			 (ActiveTasks[l]->MyTaskIsEssential)) {
				
			// Yes. Has this task set its watchdog?
			if (!ActiveTasks[l]->MyWatchDog) {
					
				// No. Tell caller at least one task is not ready
				if (ActiveTasks[l]->MissedWatchDog++ > T166_WATCHDOG_MIN)
					printf("Task '%s' has not reported its watchdog %d times in a row.\n", ActiveTasks[l]->MyName ? ActiveTasks[l]->MyName : "unknown", T166_WATCHDOG_MIN);
				return (0);
			}
		}
	}
		
	// If we get here they have all said we're good. Clear them and tell caller
	for (l=0; l<T166_MAXTASK; l++)
		if ((ActiveTasks[l]) &&
			 (ActiveTasks[l]->MyTaskIsEssential)) {
			ActiveTasks[l]->MyWatchDog = 0;
			ActiveTasks[l]->MissedWatchDog = 0;				
		}
	return (1);
};
