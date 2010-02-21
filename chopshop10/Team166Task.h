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
#define T166_US_MOD (T166_ANALOG_MODULE_1)  // Ultrasound module
#define T166_US_DIST (7)                    // Ultrasound distance pin
#define T166_BAT_MOD (T166_ANALOG_MODULE_1) // Module for battery sensor
#define T166_BAT_VOLT (8)                   // Channel for battery voltage

//
// Digital Pin layout
//
#define T166_ENC_INCL_A (1)             // Inclinometer encoder; channel A
#define T166_ENC_INCL_B (2)             // Inclinometer encoder; channel B
#define T116_ENC_INCL_I (3)		        // Inclinometer encoder; Index Channel/

#define T166_PNEUMATIC_PRESSURE_READY (5)	// Pneumatic pressure ready for use

#define T166_EBRAKE_LIMIT_TOP (7)           // EBrake top limit
#define T166_EBRAKE_LIMIT_BOTTOM (8)        // Brake bottom limit

#define T166_KICKER_LIMIT_SWITCH (9)		// Kicker limit switch !!! CRF: Eliminate when kicker code is updated !!!
#define T166_BANNER_SENSOR_DIGITAL_INPUT (10)	// Banner Sensor

//#define TOP_LIMITSWITCH_DIGITAL_INPUT    (13)  //top limit switch for lift
		//this limit switch is probably no longer needed
#define BOTTOM_LIMITSWITCH_DIGITAL_INPUT (14)  //bottom limit switch for lift

//
// PWM layout
//
/** channel for the Left Motor */
#define T166_LEFT_BACK_MOTOR_CHANNEL (1)
/** channel for the Right Motor */   
#define T166_RIGHT_BACK_MOTOR_CHANNEL (2)
/** channel for the pneumatic pump */
#define T166_PNEUMATIC_PUMP_MOTOR_CHANNEL (3)
/** channels for the Kicker */
#define T166_KICKER_PNEUMATIC_SETUP_CHANNEL (4)   // Activate to setup kicker for use
#define T166_KICKER_PNEUMATIC_RELEASE_CHANNEL (5) // Activate to kick the ball
#define T166_KICKER_CHANNEL (5)   // !!! CRF: Eliminate when kicker code is updated !!!
/** channel for the E-Brake Motor */    
#define T166_EBRAKE_CHANNEL (6)	
/** channel for the Lift Motor */    
#define T166_LIFT_CHANNEL (7)	
/** channel for the Horizontal Servo */    
#define T166_HORIZONTAL_SERVO_CHANNEL (8)     
/** channel for the Vertical Servo */    
#define T166_VERTICAL_SERVO_CHANNEL (9) 
/** channel for pneumatic lift extender **/
#define T166_LIFT_PNEUMATIC_ACTIVATE (10)

//
// Relay Layout
//
/** Channels for Vacuum */
#define T166_VACUUM_RELAY_CHANNEL (1)
/** Channels for Compressor */
#define T166_COMPRESSOR_RELAY_CHANNEL (2)

//
// Pneumatics Bumper */
//
/** Channel for Latch piston */
#define T166_LATCH_PISTON (1)
/** Channel for Kicker piston */
#define T166_KICKER_PISTON (2)
/** Channel for Lift Piston */
#define T166_LIFT_PISTON (3)

//
// CAN bus layout
//
/** Number of Jags used */
#define T166_NUM_JAGS (5)

/** channel for the Left Motor */
#define T166_LEFT_MOTOR_CAN (7)
/** channel for the Right Motor */
#define T166_RIGHT_MOTOR_CAN (10)
/** channel for the Lift Winch Motor */
#define T166_LIFT_MOTOR_CAN (5)
/** channel for the Ebrake motor */
#define T166_EBRAKE_MOTOR_CAN (6)
/** channel for the Kicker motor */
#define T166_KICKER_MOTOR_CAN (9)	// !!! CRF: Eliminate when kicker code is updated !!!

//
// USB port layout
//
/** First stick is in USB port #1 */
#define T166_USB_STICK_1 (1)                
/** Second stick is in USB port #2 */
#define T166_USB_STICK_2 (2)   
/** Third stick is in USB port #3 */
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
	
	//! Sets the loop exit status 
	void SetStatus(int,const char* = "");
	
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
	
	static void PrintStats(void);
	// Check if all registered tasks are up
	static int IfUp(void);
	
	// Should we feed the watchdog?
	static int FeedWatchDog(void);
	
	static void PrintInactive(void);

// Data members
public:
	int MyTaskId;               // Id of our own task
	int MyTaskInitialized;      // This task has been initialized
	int MyWatchDog;             // Feeding my own watch dog
	int MyTaskIsEssential;      // Flag indicating if this task is essential
	int MyStatus;
	const char* MyStatusString;
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
	struct timespec next_checkin; // Time when we're expected to checkin next
	unsigned int nano_left;       // Nano seconds left of second
	struct timespec exit_time;    // Time when we left the wait call
	unsigned int last_print_sec;  // Last second we printed out a log message
	unsigned int loop_calls;      // Times we've been called to wait
	
};
#endif // !defined(_TEAM166TASK_H)
