#include <semLib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "WPILib.h"
#include "BaeUtilities.h"
#include "Team166Task.h"
#include "Drive166.h"
#include "Dispenser166.h"
#include "SensorTest166.h"
#include "Inertia166.h"
#include "Vision166.h"
#include "Sonar166.h"


// needed for Camera Init
#include "AxisCamera.h" 
#include "FrcError.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(true)dprintf

// Declare external tasks
Team166Dispenser Team166DispenserObject;
Team166Drive Team166DriveObject;
Team166SensorTest Team166SensorTestObject;
Team166Inertia Team166InertiaObject;
Team166Vision Team166VisionObject;
Team166Sonar Team166SonarObject;

class Robot166;
Robot166 *RobotHandle = 0;

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
Robot166::Robot166(void) :
	myDrive(T166_LEFT_FRONT_MOTOR_CHANNEL, T166_LEFT_BACK_MOTOR_CHANNEL, T166_RIGHT_FRONT_MOTOR_CHANNEL, T166_RIGHT_BACK_MOTOR_CHANNEL), // Motors in use
	driveStick(T166_USB_STICK_1),        // USB port for 1st stick
	dispStick(T166_USB_STICK_2),        // USB port for 2nd stick
	lfEncoder(T166_ENC_LF_A, T166_ENC_LF_B, true), // Left Front encoder pins
	rfEncoder(T166_ENC_RF_A, T166_ENC_RF_B, false), // Right Front encoder pins
	lbEncoder(T166_ENC_LB_A, T166_ENC_LB_B, true), // Left Back encoder pins
	rbEncoder(T166_ENC_RB_A, T166_ENC_RB_B, false), // Right Back encoder pins
	lift_victor(T166_LIFT_MOTOR),       // Victor controlling the lift
	treadmill_victor(T166_TREADMILL_MOTOR), // Victor controlling the treadmill
    limitswitch_top1(TOP_LIMITSWITCH_DIGITAL_INPUT1),  //top limit switch digital input
    limitswitch_top2(TOP_LIMITSWITCH_DIGITAL_INPUT2), 	//top limit switch digital input		  
    limitswitch_bottom1(BOTTOM_LIMITSWITCH_DIGITAL_INPUT1), //bottom limit switch digital input        
    limitswitch_bottom2(BOTTOM_LIMITSWITCH_DIGITAL_INPUT2)  //bottom limit switch digital input
{
	/* set up debug output: 
	 * DEBUG_OFF, DEBUG_MOSTLY_OFF, DEBUG_SCREEN_ONLY, DEBUG_FILE_ONLY, DEBUG_SCREEN_AND_FILE  */
	SetDebugFlag ( DEBUG_SCREEN_ONLY  ) ;

	DPRINTF(LOG_DEBUG, "Constructor\n");
	
	RobotMode = T166_CONSTRUCTOR;
	JoyLock = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
	DSLock = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
	DispLock = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
	JoyX = JoyY = 0.0;
	dsHandle = DriverStation::GetInstance();
    ConvDir = T166_CB_UNKNOWN;
    ConvLift = 0.0;
	RobotHandle = this;
	

	/* start the CameraTask -keep this here for now, maybe move to Vision166 later  */
	if (StartCameraTask(15, 0, k160x120, ROT_180) == -1) {
		DPRINTF( LOG_ERROR,"Failed to spawn camera task; exiting. Error code %s", 
				GetVisionErrorText(GetLastVisionError()) );
	}
	/* allow writing to vxWorks target */
	Priv_SetWriteFileAllowed(1);   	
	
	GetWatchdog().SetExpiration(5.0); // 5 seconds
	while (!(Team166DispenserObject.MyTaskInitialized && 
			Team166DriveObject.MyTaskInitialized &&
			Team166VisionObject.MyTaskInitialized &&
			Team166SonarObject.MyTaskInitialized &&
			Team166SensorTestObject.MyTaskInitialized &&
			Team166InertiaObject.MyTaskInitialized)) {
		printf("Constructor is waiting %d %d %d %d %d %d..\n",
				//printf("Constructor is waiting %d  %d %d %d %d..\n",
				Team166DispenserObject.MyTaskInitialized,
				Team166DriveObject.MyTaskInitialized,
				Team166VisionObject.MyTaskInitialized,
				Team166SonarObject.MyTaskInitialized,
				Team166SensorTestObject.MyTaskInitialized,
				Team166InertiaObject.MyTaskInitialized);
		Wait (0.100);
	}
	printf("All tasks we depend upon are up!\n");
	
	
}

/**
 * Joy stick control. X and Y value are in range -1.0 to +1.0
 */
void Robot166::SetJoyStick(float x, float y)
{
	// Set a new X/Y value
	semTake(JoyLock, WAIT_FOREVER);
	JoyX = x;
	JoyY = y;
	semGive(JoyLock);
	
	// Done
	return;
}
void Robot166::GetJoyStick(float *x, float *y)
{
	
	// Pick up the X/Y value
	switch (RobotMode) {
	case T166_OPERATOR: {
		semTake(DSLock, WAIT_FOREVER);
		*x = driveStick.GetX();
		*y = -driveStick.GetY();		
		semGive(DSLock);
		break;
	    }
	default: {
		semTake(JoyLock, WAIT_FOREVER);
		*x = JoyX;
		*y = JoyY;
		semGive(JoyLock);
		break;
	    }
	}
	
	// Done
	return;
}

/**
 * Dispenser command
 */
void Robot166::SetDispenser(t_ConveyerDirection dir, float lift_motor)
{
	// Set conveyer direction
	semTake(DispLock, WAIT_FOREVER);
	ConvDir = dir;
	ConvLift = lift_motor;
	semGive(DispLock);
	
	// Done
	return;
}
void Robot166::GetDispenser(t_ConveyerDirection *dir, float *lift_motor)
{
	
	// Pick up the dispenser command
	switch (RobotMode) {
	case T166_OPERATOR: {
		semTake(DSLock, WAIT_FOREVER);
		float agit = dispStick.GetX();
		*lift_motor = -dispStick.GetY();		
		semGive(DSLock);
		if (agit <= -0.4) {
			*dir = T166_CB_BACKWARD;
		} else {
			if (agit >= 0.4) {
				*dir = T166_CB_FORWARD;
			} else {
				*dir = T166_CB_STILL;
			}
		}
		break;
	    }
	default: {
		semTake(DispLock, WAIT_FOREVER);
		*dir = ConvDir;
		*lift_motor = ConvLift;
		semGive(DispLock);
		break;
	    }
	}
	
	// Done
	return;
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
	while(IsAutonomous())
	{
		printf("autonomous\n");
		RobotMode = T166_AUTONOMOUS;
		GetWatchdog().SetEnabled(false);
		steveautonomous.autonomous_main();
	}
	
	
	
}

/** 
 * Runs the motors with arcade steering. 
 */
void Robot166::OperatorControl(void)
{
	printf("Operator control\n");
	RobotMode = T166_OPERATOR;
	GetWatchdog().SetEnabled(true);
	while (IsOperatorControl())
	{
		// Each task needs to update for us to feed the watch dog.
		if (Team166DispenserObject.MyWatchDog && 
				Team166DriveObject.MyWatchDog &&
				Team166SensorTestObject.MyWatchDog) {
		    GetWatchdog().Feed();
		    Team166DispenserObject.MyWatchDog = 0;
		    Team166DriveObject.MyWatchDog = 0;
		    Team166SensorTestObject.MyWatchDog = 0;
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

START_ROBOT_CLASS(Robot166);

