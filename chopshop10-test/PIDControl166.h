/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: PIDControl166.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for robot code which controls the drive motors
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#ifndef PIDCONTROL166_H
#define PIDCONTROL166_H

#include "Encoder.h"


//#define K_I (0.02)               //Stores the Integral Gain Value
//define K_P (0.005)				  //Stores the Proporational Gain Value
//#define K_D (0.0)				  //This is not implemented yet, so it is 0			 
#define MAX_WHEEL_SPEED (8.0) //Maximum Wheel Speed in RPS


 //Sets the range for when the joystick is zero
#define ZERO_RANGE_MIN (-0.01)	  
#define ZERO_RANGE_MAX (0.01)

class PIDControl{
public:
	PIDControl();
	~PIDControl();


	float convertToRPS(float);  //Converts Float Speed Values to RPS Values
	float convertToInput(float); //Converts RPS to Float Speed Values
	
	float input, sPoint, result;
	
	
	float calculate(float, float, float, float);  //Caluculates the new speed values after taking error into account
private:
	int PIDEnabled;  //Checks to see if PID is Enables
	
	//Error stores the error value
	//Total error stores the total accumalated error
	//max and min Output set the limts on the speed values
	float error, totalError, maxOutput, minOutput;

private:
	Timer time;
	
};


#endif // PIDCONTROL_H
