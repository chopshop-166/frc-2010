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
#include "RobotCamera166.h"
#include "Proxy166.h"
#include "Robot166.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(true)dprintf

Autonomous166::Autonomous166() {
	
}

void Autonomous166::Autonomous(void) {
	// Called  by Robot166 Autonomous()
	
	// Create and register the local robot handle
	Robot166 *lHandle;
	while( !(lHandle = Robot166::getInstance()) && !( lHandle->IsAutonomous() ) ) {
		Wait(AUTONOMOUS_WAIT_TIME);
	}
	State state = sSetup;
	
	// Create and register proxy handle
	Proxy166 *proxy;
	while( (proxy = Proxy166::getInstance()) == NULL ) {
		Wait(AUTONOMOUS_WAIT_TIME);
	}

	// Dashboard output buffer
	char* buffer = new char[DASHBOARD_BUFFER_MAX];
	
	// Counter for retreat timer
	unsigned long retreatcounter = 0;
	
	// Number of times kicked
	unsigned short kicked = 0;
	
	// Sensor storage data
	int banner=0;
	int inclinometer=0;
	float sonar=0;
	float camerascore=0;
	
	// Starting location. 1 is nearest, 3 is furthest from our goals
	const unsigned short loc = DriverStation::GetInstance()->GetLocation();
	sprintf(buffer,"Field location: %d", loc);
	lHandle->DriverStationDisplay(buffer);
	printf("Field location: %d", loc);
	
	// As long as Autonomous is running, go through the states
	while( lHandle->IsAutonomous() ) {
		// Reset sensors
		banner = proxy->GetBanner();
		sonar = proxy->GetSonarDistance();
		inclinometer = proxy->GetInclinometer();
		camerascore = proxy->GetCameraScoreToTargetX();

		// Output changing debug values
		printf("%f\t%f\t%f\r",proxy->GetJoystickY(1),proxy->GetJoystickY(2),camerascore);
		
		switch(state) {
		
		// Our robot isn't finished setting up
		case sSetup:
			state = sSearching;
			lHandle->DriverStationDisplay("Scanning for ball.");
			break;
			
		// We don't have a ball in our possession yet
		case sSearching:
			if( banner ) {
				// Oops! We shouldn't be sensing a line
				state = sRetreating;
				lHandle->DriverStationDisplay("Line sensed!");
				retreatcounter = AUTONOMOUS_RETREAT_TIME;
				break;
			}
			if( sonar < SONAR_NEAR ) {
				// We have a ball
				state = sBallHeld;
				lHandle->DriverStationDisplay("Ball captured");
				break;
			}
			if( (inclinometer > 5) || (inclinometer < -5) ) {
				// We're tilting...
				state = sResting;
				lHandle->DriverStationDisplay("Stopped: Tilt");
				break;
			}
			proxy->SetJoystickY(1,0.25);
			proxy->SetJoystickY(2,0.25);
			break;
			
		// We have a ball in our possession
		case sBallHeld:
			if( sonar >= SONAR_NEAR ) {
				state = sSearching;
				lHandle->DriverStationDisplay("Scanning for ball");
			}
			if(banner) {
				state = sRetreating;
				lHandle->DriverStationDisplay("Line sensed");
				retreatcounter = AUTONOMOUS_RETREAT_TIME;
				break;
			}
			if(!camerascore) {
				state = sPoised;
				lHandle->DriverStationDisplay("Ready to kick");
			} else {
				DriveTowardsTarget();
			}
			break;
			
		// We have a ball and are aligned with the goal
		case sPoised:
			// Tell the kicker to kick
			proxy->SetButton(3,1,true);
			// Check whether we've kicked all the balls in the area
			if( ++kicked == loc ) {
				if( loc == 3 ) { // Furthest zone from goal
					state = sGuarding;
					lHandle->DriverStationDisplay("Guarding goal");
				} else {
					state = sDodging;
					retreatcounter = AUTONOMOUS_RETREAT_TIME;
					lHandle->DriverStationDisplay("Moving out of the way");
				}
			} else {
				state = sSearching;
				lHandle->DriverStationDisplay("Scanning for ball");
			}
			break;
			
		// Getting out of the way after we take all of our shots
		case sDodging:
			if( --retreatcounter != 0 ) {
				proxy->SetJoystickY(1, 1);
				proxy->SetJoystickY(2, -1);
			} else {
				state = sGoGoGo;
				lHandle->DriverStationDisplay("GoGoGo!");
			}
			break;
			
		// Going back to defend the goal
		case sGuarding:
			proxy->SetJoystickY(1,-0.75);
			proxy->SetJoystickY(2,-0.75);
			break;
			
		// Wait for the end of Autonomous
		case sResting:
			proxy->SetJoystickY(1,0);
			proxy->SetJoystickY(2,0);
			break;
		case sRetreating:
#if 1
			retreatcounter = 1;
#endif
			if( --retreatcounter != 0 ) {
				proxy->SetJoystickY(1,-1);
				proxy->SetJoystickY(2,-0.75);
			} else {
				state = sResting;
				lHandle->DriverStationDisplay("ZZZZZZZZZZZZZZZZZZZZZ");
			}
			break;
		
		// Wait for the end of Autonomous
		case sGoGoGo:
			if( banner ) {
				// Great, we've reached the end of Autonomous. Naptime!
				state = sResting;
				lHandle->DriverStationDisplay("ZZZZZZZZZZZZZZZZZZZZZ");
				break;
			}
			if( (inclinometer > 5) || (inclinometer < -5) ) {
				// Great, we've reached the end of Autonomous. Naptime!
				state = sResting;
				lHandle->DriverStationDisplay("ZZZZZZZZZZZZZZZZZZZZZ");
				break;
			}
			proxy->SetJoystickY(1,1);
			proxy->SetJoystickY(2,1);
			break;
				
		default:
			state = sResting;
			lHandle->DriverStationDisplay("ZZZZZZZZZZZZZZZZZZZZZ");
			break;
		}
		Wait(AUTONOMOUS_WAIT_TIME);
	}
}

Autonomous166::~Autonomous166(void) { return; }
