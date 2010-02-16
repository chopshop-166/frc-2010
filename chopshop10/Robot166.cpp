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
#include "LiftCan166.h"
#include "SensorTest166.h"
#include "Banner166.h"
#include "Vision166.h"
#include "Sonar166.h"
#include "RobotCamera166.h"
#include "CANDrive166.h"
#include "EBrake166.h"
#include "HealthMon166.h"
#include "Inclinometer.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Are we using the CAN bus?
#define UsingCan (1)

// List of tasks that have requested to come up
Team166Task *Team166Task::ActiveTasks[T166_MAXTASK + 1] = {0};

// Declare external tasks
Proxy166 Team166ProxyObject; // This task has to always be started first or it'll error
#if UsingCan
Team166CANDrive Team166CANDriveObject;
#else
Team166TankDrive Team166TankDriveObject;
#endif

#if 0
Team166LiftCan Team166LiftCanObject;
#else
Team166Lift Team166LiftObject;
#endif

Team166Kicker Team166KickerObject;
Team166Banner Team166BannerObject;
Team166Vision Team166VisionObject;
Team166Sonar Team166SonarObject; 
//Team166EBrake Team166EBrakeObject;
Team166HealthMon Team166HealthMonObject;
Team166Inclinometer Team166InclinometerObject;

// This links to the single instance of the Robot task
class Robot166;
static Robot166 *RobotHandle = 0;

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
Robot166::Robot166(void)  
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
	dsHandleLCD = DriverStationLCD::GetInstance();
	RobotHandle = this;
	mlHead = 0;
	
	// Trim log files down to 16MB
	maxLogId = MemoryLog166::PruneLogs(16*1024*1024);

	// update DS
	DriverStationDisplay("Starting 166 Robot");

	/* allow writing to vxWorks target */
	Priv_SetWriteFileAllowed(1);   	
	
	// Setup expiration for task watchdog.
	GetWatchdog().SetExpiration(5.0); // 5 seconds

	// Wait for all of our tasks to come up
	printf("Getting ready to check if tasks are up");
	while (!Team166Task::IfUp()) {
		printf("Waiting for task(s) to come up: ");
		Team166Task::PrintInactive();
		printf("\n");
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
	Autonomous166().Autonomous();
}

/** 
 * Runs the motors with arcade steering. 
 */
void Robot166::OperatorControl(void)
{
	int has_been_disabled = 0;
	int joystickImageCount = 0;
	char imageName[80]; 
	
	Timer debugTimer;
	debugTimer.Start();
	
	printf("Operator control\n");
	RobotMode = T166_OPERATOR;
	GetWatchdog().SetEnabled(true);
	DriverStationDisplay("Teleoperated Enabled.");
		dsHandleLCD->UpdateLCD();
	while (IsOperatorControl())
	{
		if(debugTimer.HasPeriodPassed(0.5))
			Team166Task::PrintStats();
		
		// Are we being disabled?
		if (IsDisabled()) {
			if (!has_been_disabled) {
				has_been_disabled = 1;
				DriverStationDisplay("Dumping Memory Log...");
				dsHandleLCD->UpdateLCD();
			    printf("Dumping log files...\n");
			    DumpLoggers(maxLogId);
			    printf("Logfiles dumped!\n");
			    maxLogId++;
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

/**
 * Send text to DS LCD display
 */
int Robot166::DriverStationDisplay(char* dsTextString)
{ 
	static char *string1;
	static char *string2;
	static char *string3;
	static char *string4;
	static char *string5;
	static char *string6;
	static bool init=true;
	if(init) {
		//Initializes it first call.
		string1=new char [DASHBOARD_BUFFER_MAX];
		strncpy(string1,"                                           ",DASHBOARD_BUFFER_MAX);
		string2=new char [DASHBOARD_BUFFER_MAX];
		strncpy(string2,"                                           ",DASHBOARD_BUFFER_MAX);
		string3=new char [DASHBOARD_BUFFER_MAX];
		strncpy(string3,"                                           ",DASHBOARD_BUFFER_MAX);
		string4=new char [DASHBOARD_BUFFER_MAX];
		strncpy(string4,"                                           ",DASHBOARD_BUFFER_MAX);
		string5=new char [DASHBOARD_BUFFER_MAX];
		strncpy(string5,"                                           ",DASHBOARD_BUFFER_MAX);
		string6=new char [DASHBOARD_BUFFER_MAX];
		strncpy(string6,"                                           ",DASHBOARD_BUFFER_MAX);
		init=false;
	}
	
	//Clears the current values on the Dashboard.
	
	//dsHandleLCD->Printf(DriverStationLCD::kUser_Line1,1,"                     ");
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line2,1,"                     ");
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line3,1,"                     ");
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line4,1,"                     ");
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line5,1,"                     ");
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line6,1,"                     ");

	//Clears line to make room for next output.
	//strncpy(string1,string2,DASHBOARD_BUFFER_MAX);
	strncpy(string6,string5,DASHBOARD_BUFFER_MAX);
	strncpy(string5,string4,DASHBOARD_BUFFER_MAX);
	strncpy(string4,string3,DASHBOARD_BUFFER_MAX);
	strncpy(string3,string2,DASHBOARD_BUFFER_MAX);
	strncpy(string2,dsTextString,DASHBOARD_BUFFER_MAX);
	
	//Outputs each line back onto the station.	
	//dsHandleLCD->Printf(DriverStationLCD::kUser_Line1,1,string1);
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line2,1,string2);
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line3,1,string3);
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line4,1,string4);
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line5,1,string5);
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line6,1,string6);
	dsHandleLCD->UpdateLCD();
	return 0;
}

/**
 * Send text to DS LCD display
 */
int Robot166::DriverStationDisplayHS(char* dsTextString)
{ 
	static char *string1;
	static bool init=true;
	if(init) {
		//Initializes it first call.
		string1=new char [DASHBOARD_BUFFER_MAX];
		strncpy(string1,"                                           ",DASHBOARD_BUFFER_MAX);
		init=false;
	}
	
	//Clears the current values on the Dashboard.
	
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line1,1,"                     ");

	//Clears line to make room for next output.
	strncpy(string1,dsTextString,DASHBOARD_BUFFER_MAX);
	
	//Outputs each line back onto the station.	
	dsHandleLCD->Printf(DriverStationLCD::kUser_Line1,1,string1);
	dsHandleLCD->UpdateLCD();
	return 0;
}
START_ROBOT_CLASS(Robot166);

