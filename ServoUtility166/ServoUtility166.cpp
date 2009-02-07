
/********************************************************************************
*  Project   		: Team 166 2009
*  File Name  		: ServoUtility166.cpp
*  Contributors   	: BR
*  Creation Date        : February 4, 2009
*  Revision History	: Source code & revision history maintained at google code   
*  File Description	: This program tests a servo range and centers it
                          by going to position 0.0, 1.0 and then 0.5.
                          Servos in PWM positions 9 and 10 are supported.
*/
#include "WPILib.h"

 
class ServoUtility166 : public SimpleRobot
{
	RobotDrive *myRobot; // robot drive system
	Joystick *stick;     // only joystick
	DriverStation *ds;   // driver station
	Servo *hServo;       // demo servo
	Servo *vServo;       // demo servo

public:
	ServoUtility166(void)
	{
		ds = DriverStation::GetInstance();
		myRobot = new RobotDrive(1, 2);    // create robot drive base
		stick = new Joystick(1);           // create the joysticks
		GetWatchdog().SetExpiration(100);
		hServo = new Servo(9);            // create the demo servo
		vServo = new Servo(10);           // create the other demo servo
		
	}

	/**
	 * Move myServo left & right then center
	 */
	void Autonomous(void)
	{
		GetWatchdog().SetEnabled(false);
		hServo->Set( 0 );
		Wait(.5);
		hServo->Set( 1 );
		Wait(.5);
		hServo->Set(.5 );
		Wait(.5);   
		vServo->Set( 0 );
		Wait(.5);
		vServo->Set( 1 );
		Wait(.5);
		vServo->Set(.5 );
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl(void)
	{
		GetWatchdog().SetEnabled(true);
		while (IsOperatorControl())
		{
			GetWatchdog().Feed();
			myRobot->ArcadeDrive(stick); // drive with arcade style (use right stick)
		}
	}
};

START_ROBOT_CLASS(ServoUtility166);

