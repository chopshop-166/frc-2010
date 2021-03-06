/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Inclinometer.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 11, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for robot code which controls the inclinometer
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#if !defined(_INCLINOMETER_H)
#define _INCLINOMETER_H
#include "WPILib.h"
#include "Robot166.h"

//
// This constant defines how often we want this task to run in the form
// of miliseconds. Max allowed time is 999 miliseconds.
//
// Inclinometer has "near real time" updates

#define INCLINOMETER_CYCLE_TIME (100) // 100ms


#define NO_SPEED				 0    //speed to use when there is no input for the victor

class Team166Inclinometer : public Team166Task
{
	
public:
	
	// task constructor
	Team166Inclinometer(void);

	// task destructor
	virtual ~Team166Inclinometer(void);

	// Main function of the task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
	
private:
	Encoder Inclinometer;
};

#endif // !defined(_INCLINOMETER_166)
