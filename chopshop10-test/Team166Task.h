/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Team166Task.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for main robot task and global paramters
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#if !defined(_TEAM166TASK_H)
#define _TEAM166TASK_H
#include "WPILib.h"
#include <math.h>
#include <sysLib.h>

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
#define T166_ANALOG_MODULE_1 (1)
#define T166_ANALOG_MODULE_2 (2)

// first analog module
#define T166_CURRENT_SENSOR_MOD (T166_ANALOG_MODULE_1)         // Module for current sensors
#define T166_CURRENT_SENSOR_LF (1)          // Current sensor Left Front
#define T166_CURRENT_SENSOR_LB (2)          // Current sensor Left Back
#define T166_CURRENT_SENSOR_RF (3)          // Current sensor Right Front
#define T166_CURRENT_SENSOR_RB (4)          // Current sensor Right Back
#define T166_GYRO_MOD (T166_ANALOG_MODULE_1)// Gyro module
#define T166_GYRO_TWIST (5)                 // Twist
#define T166_GYRO_TEMP (6)                  // Temperature
#define T166_BAT_MOD (T166_ANALOG_MODULE_1) // Module for battery sensor
#define T166_BAT_VOLT (8)                   // Channel for battery voltage

// second analog module
#define T166_ACCEL_MOD (T166_ANALOG_MODULE_2)// Accelerometer module
#define T166_ACCEL_X (1)                    // X-Axis for acccelerometer
#define T166_ACCEL_Y (2)                    // Y-Axis for acccelerometer
#define T166_ACCEL_Z (3)                    // Z-Axis for acccelerometer (currently not used)
#define T166_POT_MOD (T166_ANALOG_MODULE_2)	// Mod for the pot 
#define T166_POT_CHANNEL (6)				// Channel for the pot
#define T166_US_MOD (T166_ANALOG_MODULE_2)  // Ultrasound module
#define T166_US_DIST (7)                    // Ultrasound distance pin

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

#define TOP_LIMITSWITCH_DIGITAL_INPUT    (13)  //top limit switch 
#define BOTTOM_LIMITSWITCH_DIGITAL_INPUT (14)  //bottom limit switch

#define DS_ALLIANCE_SWITCH_INPUT          (1)  // Driver station switch for alliance
#define DS_AUTOTRACKNG_SWITCH_INPUT       (2)  // Driver station switch for auto tracking
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

#define T166_LIFT_MOTOR (5)                 // Lift motor
#define T166_TREADMILL_MOTOR (6)            // Treadmill for balls



//
// USB port layout
//
/** First stick is in USB port #1 */
#define T166_USB_STICK_1 (1)                
/** Second stick is in USB port #2 */
#define T166_USB_STICK_2 (2)   
/** Second stick is in USB port #2 */
#define T166_USB_STICK_3 (3)   


//
// Max tasks we support being started in Robot166
//
#define T166_MAXTASK (32)

//
// Count of times a particular task can fail to report its watchdog before
// we start to display errors.
//
#define T166_WATCHDOG_MIN (3)

//
// Wait time in each task for getting into Autonomous or Teleoperated mode
//
#define T166_TA_WAIT_LENGTH (0.050) // 50ms

class Team166Task
{

// Methods
public:
	
	// Constructor
	Team166Task(int IsEssential=1);
	
	// Destructor
	virtual ~Team166Task();
	
	// General start routine; needs to be called by target constructor
	int Start(char *tname, unsigned int loop_interval);
	
	// Jacket routine that leads into the actual Main routine of target
	static int MainJacket(void *this_p, int a2, int a3, int a4, int a5,
					int a6, int a7, int a8, int a9, int a10);
	
	// Each class needs to implement this Main function
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10) = 0;
	
	// Wait for Robot go-ahead
	void WaitForGoAhead(void);
	
	// Wait for next lap
	void WaitForNextLoop(void);

	// Check if all registered tasks are up
	static int IfUp(void);
	
	// Should we feed the watchdog?
	static int FeedWatchDog(void);

// Data members
public:
	int MyTaskId;               // Id of our own task
	int MyTaskInitialized;      // This task has been initialized
	int MyWatchDog;             // Feeding my own watch dog
	int MyTaskIsEssential;      // Flag indicating if this task is essential
	char *MyName;               // Name of this task
	int MissedWatchDog;         // Missed watchdog count
	float MyLoopInterval;       // Timing interval for loop
	unsigned int MyLoopMs;      // Length of loop for this 
	unsigned int OverRuns;      // Task over runs
	
private:
	
	// This array points to tasks that have requested to be initialized
	static Team166Task *ActiveTasks[T166_MAXTASK + 1];
	
	// Used for time calculations
	unsigned int crate;           // Clock rate
	unsigned int half_tick;       // Length of a half tick
	struct timespec start_time;   // Time when our logic starts		
	unsigned int nano_left;       // Nano seconds left of second
	struct timespec exit_time;    // Time when we left the wait call
	unsigned int last_print_sec;  // Last second we printed out a log message
	unsigned int loop_calls;      // Times we've been called to wait
	
};
#endif // !defined(_TEAM166TASK_H)
