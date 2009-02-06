#if !defined(_DRIVE166_H)
#define _DRIVE166_H
#include "WPILib.h"
#include "Robot166.h"
#include "semLib.h"
#include "PIDControl166.h"

#define CLICKS_PER_REV (4096.0)							// Stores the Number of Clicks per revolution of the wheel


//
// This defines a sample drive task
//
class Team166Drive : public Team166Task
{
	
// Methods
public:
	
	// Drive task constructor
	Team166Drive(void);
	
	// Drive task destructor
	virtual ~Team166Drive(void);
	
	// Main function of the drive task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
	//Arace Drive with four wheels
	void ArcadeDrive166(float, float, bool);
	
	//Set the motor speeds
	void SetMotorSpeeds(float, float);
	
	// Find the wheel Speeds
	void getWheelSpeed();
	
	// Limit the float values to -1.0 to 1.0
	float limitSpeed(float);
	
// Members
public:
	
	INT32 encoder_count_lf;                             // Left front encoder value
	INT32 encoder_count_lb;                             // Left back encoder value
	INT32 encoder_count_rf;                             // Right front encoder value
	INT32 encoder_count_rb;                             // Right Back encoder value
	
	bool encoder_direction_lf;                          // Left front encoder direction
	bool encoder_direction_lb;                          // Left back encoder direction
	bool encoder_direction_rf;                          // Right front encoder direction
	bool encoder_direction_rb;                          // Right back encoder direction
	
	bool encoder_stopped_lf;                            // Left front encoder stopped
	bool encoder_stopped_lb;                            // Left back encoder stopped
	bool encoder_stopped_rf;                            // Right front encoder stopped
	bool encoder_stopped_rb;                            // Right back encoder stopped
	
	float lfvolt;										// Left Front motor current sensor value
	float lbvolt;										// Left Back motor current sensor value
	float rfvolt;										// Right Front motor current sensor value
	float rbvolt;										// Right Back motor current sensor value
	
	void getGains();									// Get the gains for PI
	
	
	
	
	
private:
	float leftMotorSpeed;								// Float to store the left motor speed values
	float rightMotorSpeed;								// Float to store the roght motor speed values
	
	INT32 lfPast, lbPast, rfPast, rbPast;				// INT32's to continuosly hold encoder values
	
	
	PIDControl lfPID;									// Used to access PID Control for Left Front Wheel
	PIDControl lbPID;									// Used to access PID Control for Right Front Wheel
	PIDControl rfPID;									// Used to access PID Control for Right Front Wheel
	PIDControl rbPID;									// Used to access PID Control for Right Back Wheel
	float lfWheelSpeed;									// Left Front Wheel Speed
	float lbWheelSpeed;									// Left Back Wheel Speed
	float rfWheelSpeed;									// Right Front Wheel Speed
	float rbWheelSpeed;									// Right Back Wheel Speed
	
	Jaguar lfwheel; 									// To Use the Jaguar Speed Controlled for Left Front Motor
	Jaguar lbwheel; 									// To Use the Jaguar Speed Controlled for Left Back Motor
	Jaguar rfwheel; 									// To Use the Jaguar Speed Controlled for Right Front Motor
	Jaguar rbwheel; 									// To Use the Jaguar Speed Controlled for Right Back Motor
	
	Victor vlfwheel; 									// To Use the Victor Speed Controlled for Left Front Motor
	Victor vlbwheel; 									// To Use the Victor Speed Controlled for Left Back Motor
	Victor vrfwheel; 									// To Use the Victor Speed Controlled for Right Front Motor
	Victor vrbwheel; 									// To Use the Victor Speed Controlled for Right Back Motor
	
	float lfSpeed_PID;
	float lbSpeed_PID;
	float rfSpeed_PID;
	float rbSpeed_PID;
	
	float K_P;
	float K_I;
	
	
	
};
#endif // !defined(_DRIVE166_H)
