#include "WPILib.h"
#include "PIDControl166.h"


PIDControl::PIDControl() 
:time()
{
	error = 0;			//Sets the error to zero initailly
	totalError = 0;		//Sets total error to zero initially
	maxOutput = 1.0;	//sets max output
	minOutput = -1.0;	//sets min output
}

PIDControl::~PIDControl()
{

}


float PIDControl::calculate(float setPoint, INT32 wheelSpeed)
{
	if(setPoint == 0)     //If the setpoint is 0 no calculations are done
		return 0;
	
	float input = convertToInput(wheelSpeed); //Converts RPS Wheel Speed to Input values
	float sPoint = setPoint;	//Gets the set points
	float result;               //Stores the result
	
	if(PIDEnabled)
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
	return result;
	
}


INT64 PIDControl::convertToRPS(float input)
{
	INT64 wheelSpeed = input*MAX_WHEEL_SPEED;  //Calculates the wheel speed in RPS
	return wheelSpeed;
}

float PIDControl::convertToInput(INT32 wheelSpeed)
{
	float input = (wheelSpeed/MAX_WHEEL_SPEED);  //Caluclates the wheel speed in Float values
	return input;
}







