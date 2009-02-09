#if !defined(_ROBOT166_H)
#define _ROBOT166_H
#include "WPILib.h"
#include "Team166Task.h"
#include "Drive166.h"
#include "Dispenser166.h"

//
// Robot modes
//
typedef enum {T166_UNKNOWN=0, T166_CONSTRUCTOR, T166_AUTONOMOUS, T166_OPERATOR} t_RobotMode;

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
	RobotDrive myDrive;                       // robot drive system
	Joystick driveStick;                      // joy stick for driving
	Joystick dispStick;                       // Dispenser joy stick
    t_RobotMode RobotMode;                    // Robot mode
    Encoder lfEncoder;                        // Encoder for the Left Front
    Encoder rfEncoder;						  // Encoder for the Right Front
    Encoder lbEncoder;						  // Encoder for the Left Back
    Encoder rbEncoder;						  // Encoder for the Right Back
	Victor lift_victor;                       // Victor controlling the lift
    Victor treadmill_victor;                  // Victor controlling the treadmill
    DigitalInput limitswitch_top1;            //the first of two limit switches on the high end of the lifter
    DigitalInput limitswitch_top2; 			  //the second of two limit switches on the high end of the lifter
    DigitalInput limitswitch_bottom1;         //the first of two limit switches on the bottom end of the lifter
    DigitalInput limitswitch_bottom2;         //the second of two limit switches on the bottom end of the lifter
    
private:
	SEM_ID JoyLock;                           // Coordination of Joystick parameters
	float JoyX;                               // Joystick X position
	float JoyY;                               // Joystick Y position
    SEM_ID DSLock;                            // Coordination of drive station interface
    SEM_ID DispLock;                          // Dispenser lock
    t_ConveyerDirection ConvDir;              // Conveyer direction
    float ConvLift;                           // Conveyer motor lift
    DriverStation *dsHandle;                  // Driver Station handle 
    
public:
	Robot166(void);                           // Constructor
	void Autonomous(void);                    // Method called by WPI when we're in autonomous mode
	void OperatorControl(void);               // Method called by WPI when we're in operator control mode
	static Robot166 *getInstance(void);       // Get pointer to our Robot166 instance
	void SetJoyStick(float x, float y);       // Set our virtual joystick
	void GetJoyStick(float *x, float *y);	  // Get our virtual joystick
	float GetBatteryVoltage(void);            // Get voltage of battery on robot
	void SetDispenser(t_ConveyerDirection dir,// Set dispenser/agitator direction
			float lift_motor);                //
	void GetDispenser(t_ConveyerDirection *dir, // Get the direction of the
			float *lift_motor);               // Dispenser
	void Robot166::CameraDrive();             // Test routine for autonomous			
};

#endif // !defined(_ROBOT166_H)
