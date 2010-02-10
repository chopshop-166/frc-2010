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
#include "Vision166.h"
#include "Proxy166.h"
#include "Robot166.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(true)dprintf

Autonomous166::Autonomous166() {
	printf("Autonomous constructor\n");	
}

void Autonomous166::Autonomous(void) {
	// Called  by Robot166 Autonomous()
	// Design as a loop
	Proxy166 *proxy;
	while( (proxy = Proxy166::getInstance()) == NULL ) {}
	DPRINTF(LOG_DEBUG,"Autonomous Proxy handle set!");
	while(!( Robot166::getInstance() ) || 
			!( Robot166::getInstance()->IsAutonomous() )
		  ) {
		Wait(AUTONOMOUS_WAIT_TIME);
	}
	while( Robot166::getInstance()->IsAutonomous() ) {
		DPRINTF(LOG_DEBUG,"%d",proxy->GetBannerProxy());
		Wait(AUTONOMOUS_WAIT_TIME);
	}
}

Autonomous166::~Autonomous166(void) { return; }
