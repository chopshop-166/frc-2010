/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: EBrake166.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 23, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for code which does electronic motor braking
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#if !defined(_EBRAKE166_H)
#define _EBRAKE166_H
#include "WPILib.h"
#include "Robot166.h"

//
// This constant defines how often we want this task to run in the form
// of miliseconds. Max allowed time is 999 miliseconds.
//
#define EBRAKE_CYCLE_TIME (10) // 10ms

class Team166EBrake : public Team166Task
{
	
public:
	
	// task constructor
	Team166EBrake(void);

	// task destructor
	virtual ~Team166EBrake(void);

	// Main function of the task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
			
private:
	Relay Ebrake_Spike;
	bool Limit_Lower;
	bool Limit_Upper;
	DigitalInput Ebrake_Limit_Top;
	DigitalInput Ebrake_Limit_Bottom;
	
};

#endif // !defined(_EBRAKE166)
