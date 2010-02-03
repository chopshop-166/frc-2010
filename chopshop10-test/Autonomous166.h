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
#include <math.h>

extern Team166Vision Team166VisionObject;

#define AUTONOMOUS_WAIT_TIME 0.050

class Autonomous166
{
	public:
		Autonomous166(void);
		~Autonomous166(void);
		void Autonomous(void);
};

#endif
