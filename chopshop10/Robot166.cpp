/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Robot166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Base class used in entire robot
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include <semLib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "WPILib.h"
#include "Team166Task.h"
#include "TankDrive166.h"
#include "Kicker166.h"
#include "SensorTest166.h"
#include "Banner166.h"
#include "Vision166.h"
#include "Sonar166.h"
#include "RobotCamera166.h"
#include "CANDrive166.h"
#include "EBrake166.h"
#include "HealthMon166.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(true)dprintf

// List of tasks that have requested to come up
Team166Task *Team166Task::ActiveTasks[T166_MAXTASK + 1] = {0};

// Declare external tasks
Team166Lift Team166LiftObject;
Team166TankDrive Team166TankDriveObject;
Team166Kicker Team166KickerObject;
Team166Banner Team166BannerObject;
Team166Vision Team166VisionObject;
Team166Sonar Team166SonarObject; 
Team166CANDrive Team166CANDriveObject;
Team166EBrake Team166EBrakeObject;
Team166HealthMon Team166HealthMonObject;
Proxy166 Team166ProxyObject;

// This links to the single instance of the Robot task
class Robot166;
static Robot166 *RobotHandle = 0;

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
Robot166::Robot166(void) :
	lfEncoder(T166_ENC_LF_A, T166_ENC_LF_B, true), // Left Front encoder pins
	rfEncoder(T166_ENC_RF_A, T166_ENC_RF_B, false), // Right Front encoder pins
	lbEncoder(T166_ENC_LB_A, T166_ENC_LB_B, true), // Left Back encoder pins
	rbEncoder(T166_ENC_RB_A, T166_ENC_RB_B, false), // Right Back encoder pins
	lift_victor(T166_LIFT_MOTOR),       // Victor controlling the lift
    limitswitch_top(TOP_LIMITSWITCH_DIGITAL_INPUT),  //top limit switch digital input
    limitswitch_bottom(BOTTOM_LIMITSWITCH_DIGITAL_INPUT) //bottom limit switch digital input 
{
	/* set up debug output: 
	 * DEBUG_OFF, DEBUG_MOSTLY_OFF, DEBUG_SCREEN_ONLY, DEBUG_FILE_ONLY, DEBUG_SCREEN_AND_FILE  */
	SetDebugFlag ( DEBUG_SCREEN_ONLY  ) ;

	DPRINTF(LOG_DEBUG, "Constructor\n");
	
	RobotMode = T166_CONSTRUCTOR;
	JoyLock = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
	DSLock = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
	LiftLock = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
	KickLock = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
	JoyX = JoyY = 0.0;
	dsHandle = DriverStation::GetInstance();
	RobotHandle = this;
	mlHead = 0;

	/* start the CameraTask  */
	DPRINTF(LOG_DEBUG, "StartCamera\n");
	//StartCamera();

	/* allow writing to vxWorks target */
	Priv_SetWriteFileAllowed(1);   	
	
	// Setup expiration for task watchdog.
	GetWatchdog().SetExpiration(5.0); // 5 seconds

	// Wait for all of our tasks to come up
	printf("Getting ready to check if tasks are up");
	while (!Team166Task::IfUp()) {
		printf("Waiting for task(s) to come up..");
		Wait (0.100);
	}
	printf("All tasks we depend upon are up!\n");	
}

/**
 * Obtain battery voltage. Wrapper here ensures we do not collide with
 * other tasks touching the drive station.
 */
float Robot166::GetBatteryVoltage(void)
{
	static unsigned int ds_a = 0;
	unsigned int prev_a = ds_a;
	semTake(DSLock, WAIT_FOREVER);
	float bv = dsHandle->GetBatteryVoltage();
	for (int i=0; i<8; i++)
		ds_a = (ds_a & ~(1<<i)) | dsHandle->GetDigitalIn(i+1)<<i;
	semGive(DSLock);
	if (prev_a != ds_a) {
		for (int i=0; i<8; i++) {
			if ((prev_a & 1<<i) != (ds_a & 1<<i)) {
				if (ds_a & 1<<i) {
					DPRINTF(LOG_INFO, "Digital port %d is ON\n", i);
				} else {
					DPRINTF(LOG_INFO, "Digital port %d is OFF\n", i);
				}
			}
		}
	}
	return (bv);	
}

/**
 * Drive left & right motors for 2 seconds then stop
 */
void Robot166::Autonomous(void)
{
	DPRINTF(LOG_DEBUG,"autonomous\n");
	RobotMode = T166_AUTONOMOUS;
	GetWatchdog().SetEnabled(false);
	//Autonomous166();
}

/** 
 * Runs the motors with arcade steering. 
 */
void Robot166::OperatorControl(void)
{
	int has_been_disabled = 0;
	static int dnum = 0;
	int joystickImageCount = 0;
	char imageName[80]; 
	
	printf("Operator control\n");
	RobotMode = T166_OPERATOR;
	GetWatchdog().SetEnabled(true);
	static int print_throttle = 0;
	while (IsOperatorControl())
	{
		print_throttle++;
		if (print_throttle%30==0){
			print_throttle = 0;
			DPRINTF(LOG_DEBUG, 
				"joy1 buttons %i %i %i %i %i %i %i %i %i %i %i\n", 
				Team166ProxyObject.GetButton(1,1), 
				Team166ProxyObject.GetButton(1,2),
				Team166ProxyObject.GetButton(1,3), 
				Team166ProxyObject.GetButton(1,4), 
				Team166ProxyObject.GetButton(1,5),
				Team166ProxyObject.GetButton(1,6), 
				Team166ProxyObject.GetButton(1,7), 
				Team166ProxyObject.GetButton(1,8),
				Team166ProxyObject.GetButton(1,9),
				Team166ProxyObject.GetButton(1,10),
				Team166ProxyObject.GetButton(1,11)
				);
			DPRINTF(LOG_DEBUG, 
				"joy2 buttons %i %i %i %i %i %i %i %i %i %i %i\n", 
				Team166ProxyObject.GetButton(2,1), 
				Team166ProxyObject.GetButton(2,2),
				Team166ProxyObject.GetButton(2,3), 
				Team166ProxyObject.GetButton(2,4), 
				Team166ProxyObject.GetButton(2,5),
				Team166ProxyObject.GetButton(2,6), 
				Team166ProxyObject.GetButton(2,7), 
				Team166ProxyObject.GetButton(2,8),
				Team166ProxyObject.GetButton(2,9),
				Team166ProxyObject.GetButton(2,10),
				Team166ProxyObject.GetButton(2,11)
				);
			DPRINTF(LOG_DEBUG, 
				"joy3 buttons %i %i %i %i %i %i %i %i %i %i %i\n", 
				Team166ProxyObject.GetButton(3,1), 
				Team166ProxyObject.GetButton(3,2),
				Team166ProxyObject.GetButton(3,3), 
				Team166ProxyObject.GetButton(3,4), 
				Team166ProxyObject.GetButton(3,5),
				Team166ProxyObject.GetButton(3,6), 
				Team166ProxyObject.GetButton(3,7), 
				Team166ProxyObject.GetButton(3,8),
				Team166ProxyObject.GetButton(3,9),
				Team166ProxyObject.GetButton(3,10),
				Team166ProxyObject.GetButton(3,11)
				);
		}
		
		// Are we being disabled?
		if (IsDisabled()) {
			if (!has_been_disabled) {
				has_been_disabled = 1;
				if (dnum < 10) {
				    printf("Dumping log files...\n");
				    DumpLoggers(dnum);
				    printf("Logfiles dumped!\n");
				    dnum++;
				}
			}
			Wait (0.5);
			continue;
		}
		
		// Each task needs to update for us to feed the watch dog.
		if (Team166Task::FeedWatchDog())
		    GetWatchdog().Feed();
		
		// take a picture 
		if (Team166ProxyObject.GetButton(1,8) or Team166ProxyObject.GetButton(1,9))
		{
			joystickImageCount++;
			sprintf(imageName, "166_joystick_img_%03i.png", joystickImageCount);
			TakeSnapshot(imageName);
		}
		Wait (0.5);
	}
	
}
	
/**
 * Return a pointer to myself
 */
Robot166 *Robot166::getInstance(void)
{
	return (RobotHandle);
}

/**
 * Register a log object
 */
void Robot166::RegisterLogger(MemoryLog166 *ml)
{
	
	// Has this handler been registered already?
	if (!ml->Registered) {
		
		// No. Insert it at the head
		ml->mlNext = mlHead;
		mlHead = ml;
		ml->Registered = 1;
	}
}

/**
 * Dump log objects
 */
void Robot166::DumpLoggers(int dnum)
{
	MemoryLog166 *ml;
	
	// Iterate through the list of loggers
	ml = mlHead;
	while (ml) {
		
		// Dump the next one
		ml->DumpToFile(dnum);
		
		// Advance to the next log
		ml = ml->mlNext;
	}
}

START_ROBOT_CLASS(Robot166);

