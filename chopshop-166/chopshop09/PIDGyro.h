#ifndef PIDGYRO_H
#define PIDGYRO_H

 //Sets the range for when the joystick is zero
#define ZERO_RANGE_MIN (-0.01)	  
#define ZERO_RANGE_MAX (0.01)




class PIDGyro{
public:
	PIDGyro();
	~PIDGyro();


	
	
	
	
	float calculate(float, float, float, float);  //Caluculates the new speed values after taking error into account
private:
	int PIDEnabled;  //Checks to see if PID is Enables
	
	//Error stores the error value
	//Total error stores the total accumalated error
	//max and min Output set the limts on the speed values
	float error, totalError, maxOutput, minOutput;

	float input, sPoint, result;
	
	
	

	
private:
	Timer time;

	
};








#endif // PIDGYRO_H
