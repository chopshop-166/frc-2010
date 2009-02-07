#include "WPILib.h"
#include "Drive166.h"
#include "MemoryLog166.h"
#include "PIDControl166.h"
//#include "DashboardDataFormat.h"
#include <math.h>
#include <sysLib.h>

#define Calculatemax(x, y) (((x) > (y)) ? (x) : (y))
#define USE_JAGUAR (1)  //Set to 1 to use Jaguar code
#define USE_VICTOR (0)  //Set to 1 to use Victor code

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
	
	float gyroAngle;
	
	float sendX;
	float sendY;
	
	float result;					  // Result value
	float setPoint;					  // Set point in PID Controller
	float input;					  // Input for PID Controller	
	float PWMinput;					  // PWM input sent to the wheel
};



// Sample Memory Log
class SensorLog : public MemoryLog166
{
public:
	SensorLog() : MemoryLog166(128*1024) {return;};
	~SensorLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float v, float lfc, float lbc, float rfc, float rbc, INT32 lfec, INT32 lbec, INT32 rfec, INT32 rbec, bool lfd, bool lfs, bool lbd, bool lbs, bool rfd, bool rfs, bool rbd, bool rbs, float x, float y, float angle, float result, float setPoint, float input, float PWMinput);     // Log the voltage
};

// Write one buffer into memory
unsigned int SensorLog::PutOne(float v, float lfc, float lbc, float rfc, float rbc, INT32 lfec, INT32 lbec, INT32 rfec, INT32 rbec, bool lfd, bool lfs, bool lbd, bool lbs, bool rfd, bool rfs, bool rbd, bool rbs, float x, float y, float angle, float result, float setPoint, float input, float PWMinput)
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
		ob->sendX = x;
		ob->sendY = y;
		ob->PWMinput = PWMinput;
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
	fprintf(ofile, "%u, %u, %f, %f, %d, %f, %f, %f, %f\n", sb->tp.tv_sec, sb->tp.tv_nsec, sb->sendX, sb->sendY, sb->lfEncoderCount, sb->result, sb->setPoint, sb->input, sb->PWMinput);
	
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
	
	lfPast = 0;											// Holds all of the encoder values
	lbPast = 0;
	rfPast = 0;
	rbPast = 0;
	// Start our task
	//Start((char *)"166DriveTask");	
	//test
	MyTaskInitialized = 1;
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
	struct timespec start_time;   // Time when our logic starts	
	struct timespec current_time; // Time when we check again
	struct timespec delta_time;   // Time when we check again
	struct timespec non_sleep;    // Time not slept
	unsigned int nano_left;       // Nano seconds left of second
	unsigned int crate;           // Clock rate
	unsigned int half_tick;       // Length of a half tick
	static int cc = 0;            // Counter to control print out
	
	Robot166 *lHandle;            // Local handle
	AnalogChannel lfCurrent(T166_CURRENT_SENSOR_MOD, T166_CURRENT_SENSOR_LF); // Current sensor channel for Left Front wheel
	AnalogChannel lbCurrent(T166_CURRENT_SENSOR_MOD, T166_CURRENT_SENSOR_LB); // Current sensor channel for Left Back wheel
	AnalogChannel rfCurrent(T166_CURRENT_SENSOR_MOD, T166_CURRENT_SENSOR_RF); // Current sensor channel for Right Front wheel
	AnalogChannel rbCurrent(T166_CURRENT_SENSOR_MOD, T166_CURRENT_SENSOR_RB); // Current sensor channel for Left Back wheel

	SensorLog sl;                 // Sensor log
	int sample_count = 0;         // Count of log samples
	AnalogChannel acGyro(T166_GYRO_MOD, T166_GYRO_TEMP); // Declare Gyro channel R=Relative Temperature
	printf("Sensor Test is initializing the Gyro...\n");
	Gyro myGyro(T166_GYRO_MOD, T166_GYRO_TWIST);      // Declare Gyro channel T=Twist
	printf("Gyro init complete!\n");
	
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
	printf("Drive task is getting ready...\n");
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
	
	// Initialize the 2008 Gyro (Analog Devices AD22304)
#if 1
		myGyro.Reset();
		myGyro.SetSensitivity(0.0125); // 12.5mV per degree per second
#else
		//Code for 2009 Gyro
#endif
		
	int printIt = 0;
    // General main loop (while in Autonomous or Tele mode)
	
	
	// Figure out this board's tick size (in nano seconds)
	crate = (1000 * 1000 * 1000) / sysClkRateGet();
		
	// And then the duration of a half-tick (in nano seconds)
	half_tick = crate / 2;
		
	// Establish our start time
	clock_gettime(CLOCK_REALTIME, &start_time);
		
	// And then the nano seconds left to the next full second
	nano_left = (1000*1000*1000) - start_time.tv_nsec;
		
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
		
		encoder_count_lf = lHandle->lfEncoder.GetRaw();    			// Get the Left front Encoder count
		encoder_count_lb = lHandle->lbEncoder.GetRaw();    			// Get the Left back Encoder count
		encoder_count_rf = lHandle->rfEncoder.GetRaw();    			// Get the Right front Encoder count
		encoder_count_rb = lHandle->rbEncoder.GetRaw();    			// Get the Right back Encoder count
		
		encoder_direction_lf = lHandle->lfEncoder.GetDirection();   // Get the Left front encoder direction
		encoder_direction_lb = lHandle->lbEncoder.GetDirection();   // Get the Left back encoder direction
		encoder_direction_rf = lHandle->rfEncoder.GetDirection();   // Get the Right front encoder direction
		encoder_direction_rb = lHandle->rbEncoder.GetDirection();   // Get the Left back encoder direction
		
		encoder_stopped_lf = lHandle->lfEncoder.GetStopped();		// Get the Left front stopped flag
		encoder_stopped_lb = lHandle->lbEncoder.GetStopped();		// Get the Left back stopped flag
		encoder_stopped_rf = lHandle->rfEncoder.GetStopped();		// Get the Right front stopped flag
		encoder_stopped_rb = lHandle->rbEncoder.GetStopped();		// Get the Right back stopped flag
		// Figure out temperature (2.5V = 298K ~= 25C) -> 512 using 12bit ADC
		float gyroTempCelcius = ((acGyro.GetValue() * (20.0 / 4096.0) - 2.5) / 0.0084) + 25;
		float gyroTwist = myGyro.GetAngle();
		

		//UpdateDashboard(encoder_count_lf,encoder_count_lb,encoder_count_rf,encoder_count_rb);
		lHandle->GetJoyStick(&x, &y);
		
		// Should we log this value?
		
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
#if !defined(PRINT)		
		if(!(printIt++%100))
		{
			//printf("JoyStick at X=%f, Y=%f\n", x, y);	
			//printf("Encoder RF: %d", encoder_count_rf);
			//printf("Current sensor at rb %f\n", rbvolt);	
			//printf("Current gyro values: Temp=%fC Twist=%f (angle)\n",
			//		 		gyroTempCelcius, myGyro.GetAngle());
			
		}
#endif		
			

		
		// Get the current time
		clock_gettime(CLOCK_REALTIME, &current_time);
		
		// Compute delta time since we started out loop
		delta_time.tv_sec = current_time.tv_sec - start_time.tv_sec;
		if (current_time.tv_nsec >= start_time.tv_nsec) {
			delta_time.tv_nsec = current_time.tv_nsec - start_time.tv_nsec;
		} else {
			delta_time.tv_nsec = current_time.tv_nsec + nano_left;
			delta_time.tv_sec--; // We do not care about this for our sleep
		}
#define MS_SLEEP (5*1000000)		
		// How far into this cycle have we run?
		if (!(cc % 500))
		  printf("%u = Delta: %u s, %u ns (%u ms)\n", cc, delta_time.tv_sec, delta_time.tv_nsec, delta_time.tv_nsec / (1000000));
		delta_time.tv_nsec = MS_SLEEP - (delta_time.tv_nsec % MS_SLEEP); // 5ms into nano seconds
		if (delta_time.tv_nsec < half_tick)
			  delta_time.tv_nsec = MS_SLEEP;
		delta_time.tv_sec = 0;
		
		// Display the sleep time
		if (!(cc % 500))
			printf("%u = Sleep Delta: %u s, %u ns (%u ms)\n", cc, delta_time.tv_sec, delta_time.tv_nsec, delta_time.tv_nsec / (1000000));
		nanosleep((const struct timespec *)&delta_time, &non_sleep);
		cc++;
		
		getWheelSpeed();
		getGains();
		ArcadeDrive166(y, -x, false);	// Calls an arade drive that has the PID Control
		if (sample_count < 1000) {
			sl.PutOne(bat_volt, lfvolt, lbvolt, rfvolt, rbvolt, encoder_count_lf, encoder_count_lb, encoder_count_rf, encoder_count_rb, encoder_direction_lf, encoder_direction_lb, encoder_direction_rf, encoder_direction_rb, encoder_stopped_lf, encoder_stopped_lb, encoder_stopped_rf, encoder_stopped_rb,x,y, gyroTwist, lfPID.result, lfPID.sPoint, lfPID.input, lfSpeed_PID);
			sample_count++;
		} else {
			if (sample_count == 1000) {
				sl.DumpToFile("drive.csv");
				sample_count++;
			}
		}
		
		MyWatchDog = 1;					// Sets Watch dog to 1
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
	
	
#if 1		//Send the Speed values to the PIDController to recived error corrected values
	getGains();
	lfSpeed_PID = lfPID.calculate(lfSpeed,lfWheelSpeed, K_P, K_P)+lfSpeed;		
	lbSpeed_PID = lbPID.calculate(lbSpeed,lbWheelSpeed, K_P, K_P)+lbSpeed;
	rfSpeed_PID = rfPID.calculate(rfSpeed,rfWheelSpeed, K_P, K_P)+rfSpeed;
	rbSpeed_PID = rbPID.calculate(rbSpeed,rbWheelSpeed, K_P, K_P)+rbSpeed;
#endif	

	lfSpeed_PID = limitSpeed(lfSpeed_PID);
	lbSpeed_PID = limitSpeed(lbSpeed_PID);
	rfSpeed_PID = limitSpeed(rfSpeed_PID);
	rbSpeed_PID = limitSpeed(rbSpeed_PID);
	
#if USE_JAGUAR
	//Send the Speed Values to the Jaguars to set the motor speeds
	lfwheel.Set(lfSpeed_PID);
	lbwheel.Set(lbSpeed_PID);
	rfwheel.Set(-rfSpeed_PID);
	rbwheel.Set(-rbSpeed_PID);	
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
	lHandle = Robot166::getInstance();
	static int abc = 0;
	INT32 lfNew, lbNew, rfNew, rbNew; //Temporary storage to calculate the actual wheel Speed
	
	//Gets the encoder counts after the wait
	lfNew = lHandle->lfEncoder.GetRaw();
	lbNew = lHandle->lbEncoder.GetRaw();
	rfNew = lHandle->rfEncoder.GetRaw();
	rbNew = lHandle->rbEncoder.GetRaw();
	//Calculates the actual wheel speeds

	lfWheelSpeed =((lfNew - lfPast) * 100.0)/CLICKS_PER_REV;
	lbWheelSpeed =((lbNew - lbPast) * 100.0)/CLICKS_PER_REV;
	rfWheelSpeed =((rfNew - rfPast) * 100.0)/CLICKS_PER_REV;
	rbWheelSpeed =((rbNew - rbPast) * 100.0)/CLICKS_PER_REV;
#if defined(PRINTIT)
	if(abc++%100)
	{
			printf("LFSpeed : %f,", lfWheelSpeed);
			abc=0;
	}	
#endif
	
	lfPast = lfNew;
	lbPast = lbNew;
	rfPast = rfNew;
	rbPast = rbNew;
	
	
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

void Team166Drive::getGains()
{
	static int cc = 0;
	AnalogChannel acI(1,6); 
	AnalogChannel acP(1,5); 
	
	
	INT16 potI = acI.GetValue();
	INT16 potP = acP.GetValue();
	
	//K_P = potP/10000.0;
	//K_I = potI/10000.0;
	K_P = 0.10;
	K_I = 0.040;
	if(!(cc++%50))
		printf("K_P: %f, K_I: %f\n",K_P, K_I);
	
}
