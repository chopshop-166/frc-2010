#include "WPILib.h"
#include "PIDGyro.h"


PIDGyro::PIDGyro() 
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

PIDGyro::~PIDGyro()
{

}


float PIDGyro::calculate(float setPoint, float in, float K_P, float K_I)
{
	static int foo =0;
	
	if(setPoint == 0)     //If the setpoint is 0 no calculations are done
		return 0;
	
	input = in; //Converts RPS Wheel Speed to Input values
	
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
		foo = 0;
	}

	return result;
	
}









