#include "WPILib.h"
#include "PIDControl166.h"


PIDControl::PIDControl() 
:time()
{
	error = 0;			//Sets the error to zero initailly
	totalError = 0;		//Sets total error to zero initially
	maxOutput = 1.0;	//sets max output
	minOutput = -1.0;	//sets min output
	input = 0;			// Input value for PID Controller
	sPoint = 0;			// Setpoint value for PID Controller
	result = 0;			// Result value
}

PIDControl::~PIDControl()
{

}


float PIDControl::calculate(float setPoint, float wheelSpeed, float K_P, float K_I)
{
	static int foo =0;
	
	if(setPoint == 0)     //If the setpoint is 0 no calculations are done
		return 0;
	
	input = convertToInput(wheelSpeed); //Converts RPS Wheel Speed to Input values
	
	sPoint = setPoint;	//Gets the set points
	result = 0;               //Stores the result
	
	if(1)
	{
		error = sPoint - input;   //Error calculation
		
		if((error >= ZERO_RANGE_MIN) && (error <= ZERO_RANGE_MAX))			  //If the error is 0 then no calculations take place
		{
			return setPoint;
		}
		
		if (((totalError + error) * K_I < maxOutput) &&	((totalError + error) * K_I > minOutput))
					totalError += error;  //Gets the total error
		
		result = (error * K_P) + (totalError * K_I);  //Caluclates the result
		
		if (result > maxOutput)					//Checks the limits on the result
					result = maxOutput;
				else if (result < minOutput)
					result = minOutput;
	}
	if(!(foo++%100))
	{
		//printf("Setpoint: %f, Input: %f, Result: %f\n", setPoint, input, result);		
	}

	return result;
	
}


float PIDControl::convertToRPS(float input)
{
	float wheelSpeed = input*MAX_WHEEL_SPEED;  //Calculates the wheel speed in RPS
	return wheelSpeed;
}

float PIDControl::convertToInput(float wheelSpeed)
{
	float input = (wheelSpeed/MAX_WHEEL_SPEED);  //Caluclates the wheel speed in Float values
	return input;
}







