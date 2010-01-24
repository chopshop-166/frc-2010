/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Inertia166.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for robot code which uses inertial sensors
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#if !defined(_INERTIA166_H)
#define _INERTIA166_H
#include "WPILib.h"
#include "Robot166.h"
#include "semLib.h"

//
// This constant defines how often we want this task to run in the form
// of miliseconds. Max allowed time is 999 miliseconds.
//
#define INERTIA_CYCLE_TIME (100) // 100ms

//
// This defines a sample intertia task
//
class Team166Inertia : public Team166Task
{
	
// Methods
public:
	
	// Inertia task constructor
	Team166Inertia(void);
	
	// Inertia task destructor
	virtual ~Team166Inertia(void);
	
	// Main function of the inertia task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);

// Members
public:
	float acc_vector;                       // Current acceleration vector
	
};
#endif // !defined(_INERTIA166_H)
