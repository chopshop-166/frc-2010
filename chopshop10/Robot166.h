/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Robot166.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for base class used in entire robot
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#if !defined(_ROBOT166_H)
#define _ROBOT166_H
#include "WPILib.h"
#include "Team166Task.h"
#include "TankDrive166.h"
#include "Lift166.h"
#include "Kicker166.h"
#include "Autonomous166.h"
#include "MemoryLog166.h"
//
// Robot modes
//
typedef enum {T166_UNKNOWN=0, T166_CONSTRUCTOR, T166_AUTONOMOUS, T166_OPERATOR, T166_DISABLED} t_RobotMode;

//
// Direction for the conveyer belt
//
typedef enum {T166_CB_UNKNOWN=0, T166_CB_FORWARD, T166_CB_BACKWARD, T166_CB_STILL} t_ConveyerDirection;

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class Robot166 : public SimpleRobot
{
public:
	Joystick driveStick;                      // joy stick for driving
	Joystick dispStick;                       // Dispenser joy stick
	Joystick cameraStick; 					  // Camera joy stick
    t_RobotMode RobotMode;                    // Robot mode
    Encoder lfEncoder;                        // Encoder for the Left Front
    Encoder rfEncoder;						  // Encoder for the Right Front
    Encoder lbEncoder;						  // Encoder for the Left Back
    Encoder rbEncoder;						  // Encoder for the Right Back
	Victor lift_victor;                       // Victor controlling the lift
    Victor treadmill_victor;                  // Victor controlling the treadmill
    DigitalInput limitswitch_top;             //the first of two limit switches on the high end of the lifter
    DigitalInput limitswitch_bottom;          //the first of two limit switches on the bottom end of the lifter
    
    
private:
	SEM_ID JoyLock;                           // Coordination of Joystick parameters
	float JoyX;                               // Joystick X position
	float JoyY;                               // Joystick Y position
    SEM_ID DSLock;                            // Coordination of drive station interface
    SEM_ID LiftLock;                           // Arm lock
    SEM_ID KickLock;                          // Kicker lock
    int LiftDir;            			      // Lift direction //FIX!
    float LiftMotor;                          // Conveyer motor lift
    DriverStation *dsHandle;                  // Driver Station handle
    MemoryLog166 *mlHead;                     // Memory log head
    Autonomous166 AutonomousObject;
    
public:
	Robot166(void);                           // Constructor
	void Autonomous(void);                    // Method called by WPI when we're in autonomous mode
	void OperatorControl(void);               // Method called by WPI when we're in operator control mode
	static Robot166 *getInstance(void);       // Get pointer to our Robot166 instance
	void SetJoyStick(float x, float y);       // Set our virtual joystick
	void GetJoyStick(float *x, float *y);	  // Get our virtual joystick
	float GetBatteryVoltage(void);            // Get voltage of battery on robot
	void SetLift(int speed,	float lift_motor);	// Set lift direction			                //
	void GetLift(int *dir,    // Get the direction of the lift
			float *lift_motor);            

	void SetKicker(float *kick_motor);		// Set kicker moter
	void GetKicker(float *kick_motor);		// Get kicker motor status
	
	void CameraDrive();             // Test routine for autonomous			
	void RegisterLogger(MemoryLog166 *ml);    // Register memory logger
	void DumpLoggers(int dnum);               // Dump all logs
	void GetGains(float *g1, float *g2);      // Pick up joystick gains
	int GetAllianceSwitch(void);    		  // Get Alliance Switch
	
};

#endif // !defined(_ROBOT166_H)
