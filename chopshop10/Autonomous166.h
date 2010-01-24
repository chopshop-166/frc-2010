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

#ifndef autonomous_h
#define autonomous_h
#include "MemoryLog166.h"
#include "WPILib.h"
#include "Robot166.h"
#include "Autonomous166.h"
#include "Timer.h"
#include "BaeUtilities.h"
#include "Vision166.h"
#include <math.h>

extern Team166Vision Team166VisionObject;

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf
#define AUTONOMOUS_WAIT_TIME 0.050

class Autonomous166
{
	public:
		Autonomous166(void);
		~Autonomous166(void);
	private:
		Robot166 *lHandle;
		DriverStation *dsHandle;
};





#endif

