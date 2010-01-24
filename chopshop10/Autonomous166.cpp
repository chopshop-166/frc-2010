/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Autonomous166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code to execute in autonomous mode
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "Autonomous166.h"
#include "Robot166.h"

Autonomous166::Autonomous166() {
	while(!( lHandle = Robot166::getInstance() ) || 
			!( lHandle->IsAutonomous() )
		  ) {
		Wait(AUTONOMOUS_WAIT_TIME);
	}
	while(lHandle->IsAutonomous()) {
		// Repeat Autonomous code loop here
		Wait(AUTONOMOUS_WAIT_TIME);
	}
}