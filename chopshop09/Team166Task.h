/********************************************************************************
*  Project   		: Chopshop 2009
*  File Name  		: Team166Task.h          
*  Contributors   	: PSH
*  Creation Date 	: February 6, 2008
*  Revision History	: Source code & revision history maintained at code.google.com    
*  File Description	: This file defines the high level and shared context for a Team 166
*/

#if !defined(_TEAM166TASK_H)
#define _TEAM166TASK_H
#include "WPILib.h"

//
// task (as in kernel task)
/** Stack size 64 KB */
#define TEAM166TASK_K_STACKSIZE (64 * 1024) 
/** Spawned task priority (100) */
#define TEAM166TASK_K_PRIO (100)

//
// Analog Pin layout
// _MOD refers to cRIO module (1 or 2)
// If module 2 is used, make sure you have 2 sidecars
// Other stuff is the channel in the module
//
/** \def #define T166_ANALOG_MODULE_1 (1)  
 * \brief cRIO analog module 1 */
#define T166_ANALOG_MODULE_1 (1)
#define T166_ANALOG_MODULE_2 (2)

/** \def #define T166_CURRENT_SENSOR_MOD (1)  
 * \brief current sensor module */
#define T166_CURRENT_SENSOR_MOD (T166_ANALOG_MODULE_1)         // Module for current sensors
/** \def #define T166_CURRENT_SENSOR_LF (1)  
 * \brief current sensor left front channel */
#define T166_CURRENT_SENSOR_LF (1)          // Current sensor Left Front
#define T166_CURRENT_SENSOR_LB (2)          // Current sensor Left Back
#define T166_CURRENT_SENSOR_RF (3)          // Current sensor Right Front
#define T166_CURRENT_SENSOR_RB (4)          // Current sensor Right Back
#define T166_GYRO_MOD (T166_ANALOG_MODULE_1)                   // Gyro module
#define T166_GYRO_TWIST (5)                 // Twist
#define T166_GYRO_TEMP (6)                  // Temperature
#define T166_US_MOD (T166_ANALOG_MODULE_1)                     // Ultrasound module
#define T166_US_DIST (7)                    // Ultrasound distance pin
#define T166_BAT_MOD (T166_ANALOG_MODULE_1)                    // Module for battery sensor
#define T166_BAT_VOLT (8)                   // Channel for battery voltage
#define T166_ACCEL_MOD (T166_ANALOG_MODULE_1)                  // Accelerometer module
#define T166_ACCEL_X (9)                    // X-Axis for acccelerometer
#define T166_ACCEL_Y (10)                    // Y-Axis for acccelerometer

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
/** \def #define T166_LEFT_FRONT_MOTOR_CHANNEL (1)  
 * \brief Stores the channel for the Left Front Motor */
#define T166_LEFT_FRONT_MOTOR_CHANNEL (1)  
/** Stores the channel for the Right Front Motor */   
#define T166_RIGHT_FRONT_MOTOR_CHANNEL (2)  
/** Stores the channel for the Left Back Motor */
#define T166_LEFT_BACK_MOTOR_CHANNEL (3)   
/** Stores the channel for the Right Back Motor */    
#define T166_RIGHT_BACK_MOTOR_CHANNEL (4)	
/** Stores the channel for the Horizontal Servo */    
#define T166_HORIZONTAL_SERVO_CHANNEL (9)     
/** Stores the channel for the Vertical Servo */    
#define T166_VERTICAL_SERVO_CHANNEL (10)    
//
// USB port layout
//
/** First stick is in USB port #1 */
#define T166_USB_STICK_1 (1)                
/** Second stick is in USB port #2 */
#define T166_USB_STICK_2 (2)               


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
