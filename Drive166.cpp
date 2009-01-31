#include "WPILib.h"
#include "Drive166.h"
#include "MemoryLog166.h"
#include "PIDControl166.h"
#define Calculatemax(x, y) (((x) > (y)) ? (x) : (y))
#define USE_JAGUAR (0)  //Set to 1 to use Jaguar code
#define USE_VICTOR (1)  //Set to 1 to use Victor code

// Sample in memory buffer
struct sbuf166
{
	struct timespec tp;               // Time of snapshot
	float volt;                       // Voltage
	float lfCurrent;                  // Left front motor current
	float lbCurrent;                  // Left back motor current
	float rfCurrent;                  // Right front motor current
	float rbCurrent;                  // Right back motor current
	
	INT32 lfEncoderCount;             // Left Front Encoder Count
	INT32 lbEncoderCount;			  // Left Back Encoder Count
	INT32 rfEncoderCount;			  // Right Front Encoder Count
	INT32 rbEncoderCount; 			  // Right Back Encoder counnt
	
	bool lfEncoderDir; 			  	  // Left Front Encoder Direction
	bool lfIsStopped;				  // Left Front Encoder Stopped Flag
	bool lbEncoderDir; 			  	  // Left Back Encoder Direction
	bool lbIsStopped;				  // Left Back Encoder Stopped Flag
	
	bool rfEncoderDir; 			  	  // Right Front Encoder Direction
	bool rfIsStopped;				  // Right Front Encoder Stopped Flag
	bool rbEncoderDir; 			  	  // Right Back Encoder Direction
	bool rbIsStopped;				  // Right Back Encoder Stopped Flag	
};



// Sample Memory Log
class SensorLog : public MemoryLog166
{
public:
	SensorLog() : MemoryLog166(32*1024) {return;};
	~SensorLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float v, float lfc, float lbc, float rfc, float rbc, INT32 lfec, INT32 lbec, INT32 rfec, INT32 rbec, bool lfd, bool lfs, bool lbd, bool lbs, bool rfd, bool rfs, bool rbd, bool rbs );     // Log the voltage
};

// Write one buffer into memory
unsigned int SensorLog::PutOne(float v, float lfc, float lbc, float rfc, float rbc, INT32 lfec, INT32 lbec, INT32 rfec, INT32 rbec, bool lfd, bool lfs, bool lbd, bool lbs, bool rfd, bool rfs, bool rbd, bool rbs)
{
	struct sbuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct sbuf166 *)GetNextBuffer(sizeof(struct sbuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		ob->volt = v;
		ob->lfCurrent = lfc;
		ob->lbCurrent = lbc;
		ob->rfCurrent = rfc;
		ob->rbCurrent = rbc;
		ob->lfEncoderCount = lfec;
		ob->lbEncoderCount = lbec;
		ob->rfEncoderCount = rfec;
		ob->rbEncoderCount = rbec;
		ob->lfEncoderDir = lfd;
		ob->lbEncoderDir = lbd;
		ob->rfEncoderDir = rfd;
		ob->rbEncoderDir = rbd;
		ob->lfIsStopped = lfs;
		ob->lbIsStopped = lbs;
		ob->rfIsStopped = rfs;
		ob->rbIsStopped = rbs;
		return (sizeof(struct sbuf166));
	}
	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int SensorLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct sbuf166 *sb = (struct sbuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f\n", sb->tp.tv_sec, sb->tp.tv_nsec, sb->volt);
	
	// Done
	return (sizeof(struct sbuf166));
}
Team166Drive::Team166Drive(void)
:lfPID()
,lbPID()
,rfPID()
,rbPID()
,lfwheel(T166_LEFT_FRONT_MOTOR_CHANNEL)  //To Use the Jaguar Speed Controlled for Left Front Motor
,lbwheel(T166_LEFT_BACK_MOTOR_CHANNEL)   //To Use the Jaguar Speed Controlled for Left Back Motor
,rfwheel(T166_RIGHT_FRONT_MOTOR_CHANNEL) //To Use the Jaguar Speed Controlled for Right Front Motor
,rbwheel(T166_RIGHT_BACK_MOTOR_CHANNEL)  //To Use the Jaguar Speed Controlled for Right Back Motor
,vlfwheel(T166_LEFT_FRONT_MOTOR_CHANNEL)  //To Use the Victor Speed Controlled for Left Front Motor
,vlbwheel(T166_LEFT_BACK_MOTOR_CHANNEL)   //To Use the Victor Speed Controlled for Left Back Motor
,vrfwheel(T166_RIGHT_FRONT_MOTOR_CHANNEL) //To Use the Victor Speed Controlled for Right Front Motor
,vrbwheel(T166_RIGHT_BACK_MOTOR_CHANNEL)  //To Use the Victor Speed Controlled for Right Back Motor

{
	// Initialize assorted fields
	encoder_count_lf = 0;                             // Left front encoder value
	encoder_count_lb = 0;                             // Left back encoder value
	encoder_count_rf = 0;                             // Right front encoder value
	encoder_count_rb = 0;                             // Right Back encoder value
	
	encoder_direction_lf = 0;                          // Left front encoder direction
	encoder_direction_lb = 0;                          // Left back encoder direction
	encoder_direction_rf = 0;                          // Right front encoder direction
	encoder_direction_rb = 0;                          // Right back encoder direction
		
	encoder_stopped_lf = 0;                            // Left front encoder stopped
	encoder_stopped_lb = 0;                            // Left back encoder stopped
	encoder_stopped_rf = 0;                            // Right front encoder stopped
	encoder_stopped_rb = 0;                            // Right back encoder stopped
	
	lfvolt = 2.5;										// Left Front motor current sensor value
	lbvolt = 2.5;										// Left Back motor current sensor value
	rfvolt = 2.5;										// Right Front motor current sensor value
	rbvolt = 2.5;										// Right Back motor current sensor value
	
	// Start our task
	Start((char *)"166DriveTask");	
};
	
// Drive task destructor
Team166Drive::~Team166Drive(void)
{		
	return;
};
	
// Main function of the drive task
int Team166Drive::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{

	Robot166 *lHandle;            // Local handle
	AnalogChannel lfCurrent(T166_CURRENT_SENSOR_MOD, T166_CURRENT_SENSOR_LF); // Current sensor channel for Left Front wheel
	AnalogChannel lbCurrent(T166_CURRENT_SENSOR_MOD, T166_CURRENT_SENSOR_LB); // Current sensor channel for Left Back wheel
	AnalogChannel rfCurrent(T166_CURRENT_SENSOR_MOD, T166_CURRENT_SENSOR_RF); // Current sensor channel for Right Front wheel
	AnalogChannel rbCurrent(T166_CURRENT_SENSOR_MOD, T166_CURRENT_SENSOR_RB); // Current sensor channel for Left Back wheel
	SensorLog sl;                 // Sensor log
	int sample_count = 0;         // Count of log samples
	
	
	// Let the world know we're in
	printf("In the 166 drive task\n");
		
	// Indicate that we've now completed initialization
	MyTaskInitialized = 1;
		
	// Ensure we get into Autononmous or Tele Operasted mode
	while (!Robot166::getInstance() ||
	       ((Robot166::getInstance()->RobotMode != T166_AUTONOMOUS) &&
	    	(Robot166::getInstance()->RobotMode != T166_OPERATOR))) {
		Wait (0.050); // 50ms
	}
	MyTaskInitialized = 2;
	lHandle = Robot166::getInstance();
	
	// How long we're still until encoder logic considers this as not moving
	lHandle->lfEncoder.SetMaxPeriod(0.5);  // 500ms
	lHandle->rfEncoder.SetMaxPeriod(0.5);  // 500ms
	lHandle->lbEncoder.SetMaxPeriod(0.5);  // 500ms
	lHandle->rbEncoder.SetMaxPeriod(0.5);  // 500ms
	
	// Reset and start all encoders
	lHandle->lfEncoder.Reset();
	lHandle->lfEncoder.Start();
	
	lHandle->rfEncoder.Reset();
	lHandle->rfEncoder.Start();
	
	lHandle->lbEncoder.Reset();
	lHandle->lbEncoder.Start();
	
	lHandle->rbEncoder.Reset();
	lHandle->rbEncoder.Start();
	int printIt = 0;
    // General main loop (while in Autonomous or Tele mode)
	printf("Drive task is getting ready...\n");
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		float x, y;                       // Our copy of the X and Y for drive
		float bat_volt;                   // Battery Volt
		// Strobing all of the values to log
		bat_volt = lHandle->GetBatteryVoltage();  					// Get battery voltage
		
		lfvolt = lfCurrent.GetValue() * (20.0 / 4096.0);    		// Get Left front voltage 
		lbvolt = lbCurrent.GetValue() * (20.0 / 4096.0);			// Get Left back voltage
		rfvolt = rfCurrent.GetValue() * (20.0 / 4096.0);			// Get Right front voltage
		rbvolt = rbCurrent.GetValue() * (20.0 / 4096.0);			// Get Right back voltage
		
		encoder_count_lf = lHandle->lfEncoder.Get();    			// Get the Left front Encoder count
		encoder_count_lb = lHandle->lbEncoder.Get();    			// Get the Left back Encoder count
		encoder_count_rf = lHandle->rfEncoder.Get();    			// Get the Right front Encoder count
		encoder_count_rb = lHandle->rbEncoder.Get();    			// Get the Right back Encoder count
		
		encoder_direction_lf = lHandle->lfEncoder.GetDirection();   // Get the Left front encoder direction
		encoder_direction_lb = lHandle->lbEncoder.GetDirection();   // Get the Left back encoder direction
		encoder_direction_rf = lHandle->rfEncoder.GetDirection();   // Get the Right front encoder direction
		encoder_direction_rb = lHandle->rbEncoder.GetDirection();   // Get the Left back encoder direction
		
		encoder_stopped_lf = lHandle->lfEncoder.GetStopped();		// Get the Left front stopped flag
		encoder_stopped_lb = lHandle->lbEncoder.GetStopped();		// Get the Left back stopped flag
		encoder_stopped_rf = lHandle->rfEncoder.GetStopped();		// Get the Right front stopped flag
		encoder_stopped_rb = lHandle->rbEncoder.GetStopped();		// Get the Right back stopped flag
		
		// Should we log this value?
		if (sample_count < 50) {
			sl.PutOne(bat_volt, lfvolt, lbvolt, rfvolt, rbvolt, encoder_count_lf, encoder_count_lb, encoder_count_rf, encoder_count_rb, encoder_direction_lf, encoder_direction_lb, encoder_direction_rf, encoder_direction_rb, encoder_stopped_lf, encoder_stopped_lb, encoder_stopped_rf, encoder_stopped_rb);
			sample_count++;
		} else {
			if (sample_count == 50) {
				sl.DumpToFile("volt_sample.csv");
				sample_count++;
			}
		}
#if 0		
		
		// How is the left front wheel doing?
		cvolt_lf = ac1.GetValue() * (20.0 / 4096.0);
		printf("Current sensor (LF): %f Volt\n", cvolt_lf);
		encoder_count_lf = lHandle->lfEncoder.Get();
		encoder_direction_lf = lHandle->lfEncoder.GetDirection();
		encoder_stopped_lf = lHandle->lfEncoder.GetStopped();
        printf("Encoder (LF); Val: %d, Dir: %d, Stopped: %d\n", encoder_count_lf,
        		encoder_direction_lf, encoder_stopped_lf);
#endif
        
		// Drive it as requested by the joystick.
		lHandle->GetJoyStick(&x, &y);
		if(printIt++ % 100)
			printf("SID Drive task; JoyStick at X=%f, Y=%f\n", x, y);
	
		
		
		
		ArcadeDrive166(y, -x, false);	// Calls an arade drive that has the PID Control

		MyWatchDog = 1;					// Sets Watch dog to 1
		Wait(0.05);
	}
	return (0);
}

void Team166Drive::ArcadeDrive166(float moveValue, float rotateValue, bool squaredInputs)
{
	
	if (squaredInputs)
	{
		// square the inputs (while preserving the sign) to increase fine control while permitting full power
		if (moveValue >= 0.0)
		{
			moveValue = (moveValue * moveValue);
		}
		else
		{
			moveValue = -(moveValue * moveValue);
		}
		if (rotateValue >= 0.0)
		{
			rotateValue = (rotateValue * rotateValue);
		}
		else
		{
			rotateValue = -(rotateValue * rotateValue);
		}
	}
	// Calculates the speed float values for the motors on the left and the right side motors
	if (moveValue > 0.0)
		{
			if (rotateValue > 0.0)
			{
				leftMotorSpeed = moveValue - rotateValue;
				rightMotorSpeed = Calculatemax(moveValue, rotateValue);
			}
			else
			{
				leftMotorSpeed = Calculatemax(moveValue, -rotateValue);
				rightMotorSpeed = moveValue + rotateValue;
			}
		}
		else
		{
			if (rotateValue > 0.0)
			{
				leftMotorSpeed = - Calculatemax(-moveValue, rotateValue);
				rightMotorSpeed = moveValue + rotateValue;
			}
			else
			{
				leftMotorSpeed = moveValue - rotateValue;
				rightMotorSpeed = - Calculatemax(-moveValue, -rotateValue);
			}
		}	
	SetMotorSpeeds(leftMotorSpeed, rightMotorSpeed);

}

void Team166Drive::SetMotorSpeeds(float leftSpeed, float rightSpeed)
{	
	
	leftSpeed = limitSpeed(leftSpeed);
	rightSpeed = limitSpeed(rightSpeed);
	//Stores the Speed Float values to be used to set the motor speed
	float lfSpeed = leftSpeed;                      //Left Front Motor
	float lbSpeed = leftSpeed;						//Left Back Motor
	float rfSpeed = rightSpeed;						//Right Front Motor
	float rbSpeed = rightSpeed;						//Right Back Motor
#if 0	
	//Send the Speed values to the PIDController to recived error corrected values
	lfSpeed = lfPID.calculate(lfSpeed,lfWheelSpeed);		
	lbSpeed = lbPID.calculate(lbSpeed,lbWheelSpeed);
	rfSpeed = rfPID.calculate(rfSpeed,rfWheelSpeed);
	rbSpeed = rbPID.calculate(rbSpeed,rbWheelSpeed);
#endif	
	
#if USE_JAGUAR
	//Send the Speed Values to the Jaguars to set the motor speeds
	lfwheel.Set(lfSpeed);
	lbwheel.Set(lbSpeed);
	rfwheel.Set(-rfSpeed);
	rbwheel.Set(-rbSpeed);	
#endif
	

#if USE_VICTOR
	//Send the Speed Values to the Victors to set the motor speeds
	vlfwheel.Set(lfSpeed);
	vlbwheel.Set(lbSpeed);
	vrfwheel.Set(-rfSpeed);
	vrbwheel.Set(-rbSpeed);	
#endif
}

void Team166Drive::getWheelSpeed()
{
	Robot166 *lHandle;            // Local handle
	
	INT32 lfPast, lbPast, rfPast, rbPast, lfNew, lbNew, rfNew, rbNew; //Temporary storage to calculate the actual wheel Speed
	
	//Gets the current encoder count
	lfPast = lHandle->lfEncoder.Get();
	lbPast = lHandle->lbEncoder.Get();
	rfPast = lHandle->rfEncoder.Get();
	rbPast = lHandle->rbEncoder.Get();
	
	//Waits for 10 Milisencods
	Wait(.01);
	
	//Gets the encoder counts after the wait
	lfNew = lHandle->lfEncoder.Get();
	lbNew = lHandle->lbEncoder.Get();
	rfNew = lHandle->rfEncoder.Get();
	rbNew = lHandle->rbEncoder.Get();
	
	//Calculates the actual wheel speeds
	lfWheelSpeed = (100 / (CLICKS_PER_REV*4)) * (lfNew - lfPast);
	lbWheelSpeed = (100 / (CLICKS_PER_REV*4)) * (lbNew - lbPast);
	rfWheelSpeed = (100 / (CLICKS_PER_REV*4)) * (rfNew - rfPast);
	rbWheelSpeed = (100 / (CLICKS_PER_REV*4)) * (rbNew - rbPast);
	
}

float Team166Drive::limitSpeed(float speed)
{
	if(speed > 1.0)
	{
		speed = 1.0;
	}
	else if(speed < -1.0)
	{
		speed = -1.0;
	}
	return speed;
}
