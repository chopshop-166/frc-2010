/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: SensorTest166.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for robot code which accesses various sensors
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#if !defined(_SENSORTEST166_H)
#define _SENSORTEST166_H
#include "WPILib.h"
#include "Robot166.h"
#include "semLib.h"

//
// This constant defines how often we want this task to run in the form
// of miliseconds. Max allowed time is 999 miliseconds.
//
#define SENSORTEST_CYCLE_TIME (100) // 100ms
//
// This defines a sample sensor test task
//
class Team166SensorTest : public Team166Task
{
	
public:
	
	// Sensor test task constructor
	Team166SensorTest(void);
	
	// Sensor Test task destructor
	virtual ~Team166SensorTest(void);
	
	// Main function of the sensor testtask
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
	
};
#endif // !defined(_SENSORTEST166_H)
