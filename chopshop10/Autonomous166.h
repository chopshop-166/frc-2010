/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Autonomous166.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for robot code to execute in autonomous mode
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#ifndef _AUTONOMOUS_H
#define _AUTONOMOUS_H
#include "MemoryLog166.h"
#include "WPILib.h"
#include "Timer.h"
#include "BaeUtilities.h"
#include "Vision166.h"
#include "Robot166.h"
#include <math.h>

#define AUTONOMOUS_WAIT_TIME (0.050)
#define SONAR_NEAR (12.5)
#define AUTONOMOUS_RETREAT_TIME (2000)

class Autonomous166
{
public:
	typedef enum State {
		sSetup=0,
		sSearching=1,
		sBallHeld=2,
		sPoised=3,
		sDodging=4,
		sGuarding=5,
		sResting=6,
		sRetreating=7,
		sGoGoGo=8
	};
	Autonomous166(void);
	~Autonomous166(void);
	void Autonomous(void);
};

#endif
