#if !defined(_TEAM166TASK_H)
#define _TEAM166TASK_H
#include "WPILib.h"

//
// This class defines the high level and shared context for a Team 166
// task (as in kernel task)
//
#define TEAM166TASK_K_STACKSIZE (64 * 1024) // 64KB
#define TEAM166TASK_K_PRIO (100)            // Spawned task priority

//
// Analog Pin layout
//
#define T166_GYRO_MOD (1)                   // Gyro module
#define T166_GYRO_TWIST (1)                 // Twist
#define T166_GYRO_TEMP (2)                  // Temperature
#define T166_CURRENT_SENSOR_MOD (1)         // Module for current sensors
#define T166_CURRENT_SENSOR_LF (1)          // Current sensor Left Front
#define T166_CURRENT_SENSOR_LB (2)          // Current sensor Left Back
#define T166_CURRENT_SENSOR_RF (3)          // Current sensor Right Front
#define T166_CURRENT_SENSOR_RB (4)          // Current sensor Right Back
#define T166_ACCEL_MOD (1)                  // Accelerometer module
#define T166_ACCEL_X (4)                    // X-Axis for acccelerometer
#define T166_ACCEL_Y (5)                    // Y-Axis for acccelerometer
#define T166_BAT_MOD (1)                    // Module for battery sensor
#define T166_BAT_VOLT (8)                   // Channel for battery voltage
#define T166_US_MOD (1)                     // Ultrasound module
#define T166_US_DIST (6)                    // Ultrasound distance pin

//
// Digital Pin layout
//
#define T166_ENC_LF_A (1)                   // Left front wheel encoder; channel A
#define T166_ENC_LF_B (2)                   // Left front wheel encoder; channel B
#define T116_ENC_LF_I (3)					// Left front wheel encoder; Index Channel

#define T166_ENC_RF_A (4)                   // Right front wheel encoder; channel A
#define T166_ENC_RF_B (5)                   // Right front wheel encoder; channel B
#define T116_ENC_RF_I (6)					// Right front wheel encoder; Index Channel

#define T166_ENC_LB_A (7)                   // Left Back wheel encoder; channel A
#define T166_ENC_LB_B (8)                   // Left Back wheel encoder; channel B
#define T116_ENC_LB_I (9)					// Left Back wheel encoder; Index Channel

#define T166_ENC_RB_A (10)                  // Right Back wheel encoder; channel A
#define T166_ENC_RB_B (11)                  // Right Back wheel encoder; channel B
#define T116_ENC_RB_I (12)					// Right Back wheel encoder; Index Channel

//
// PWM layout
//
#define T166_LEFT_FRONT_MOTOR_CHANNEL (1)					// Stores the channel for the Left Front Motor     
#define T166_RIGHT_FRONT_MOTOR_CHANNEL (2)					// Stores the channel for the Right Front Motor
#define T166_LEFT_BACK_MOTOR_CHANNEL (3)						// Stores the channel for the Left Back Motor
#define T166_RIGHT_BACK_MOTOR_CHANNEL (4)	

//
// USB port layout
//
#define T166_USB_STICK_1 (1)                // First stick is in USB port #1
#define T166_USB_STICK_2 (2)                // Second stick is in USB port #2




class Team166Task
{

// Methods
public:
	
	// Constructor
	Team166Task()
	{
		// Indicate we've never been spawned before
		MyTaskId = 0;
		MyTaskInitialized = 0;
		MyWatchDog = 0;
	}
	
	// Destructor
	virtual ~Team166Task() {return;};
	
	// General start routine; needs to be called by target constructor
	int Start(char *tname)
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

		// Spawn a new task
		MyTaskId = taskSpawn(tname, TEAM166TASK_K_PRIO, VX_FP_TASK,
				TEAM166TASK_K_STACKSIZE, (FUNCPTR) Team166Task::MainJacket,
				(int)this, 0, 0, 0, 0, 0, 0, 0, 0, 0);
 		printf("Task '%s' spawned with ID '0x%x'\n", tname, MyTaskId);
		
		//  Back to caller with the ID of the task we just spawned
		return (MyTaskId);		
	};
	
	// Jacket routine that leads into the actual Main routine of target
	static int MainJacket(void *this_p, int a2, int a3, int a4, int a5,
					int a6, int a7, int a8, int a9, int a10)
	{
		// Just daisy chain over to virtual main function
		return (((Team166Task *)this_p)->Main(a2, a3, a4, a5, a6, a7, a8, a9, a10));
	}
	
	// Each class needs to implement this Main function
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10) = 0;

// Data members
public:
	int MyTaskId;               // Id of our own task
	int MyTaskInitialized;      // This task has been initialized
	int MyWatchDog;             // Feeding my own watch dog
	
};
#endif // !defined(_TEAM166TASK_H)
