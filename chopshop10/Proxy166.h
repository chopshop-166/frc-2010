/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Lift166.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for Proxy class
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/
#include "Utility.h"
#include "Team166Task.h"
#ifndef _PROXY166_H
#define _PROXY166_H

#define NUMBER_OF_JOYSTICKS 4
#define NUMBER_OF_SWITCHES 10

class Proxy166 : public Team166Task {
	public:		
		void SetJoystickX(int, float);  
		void SetJoystickY(int, float);
		void SetJoystickZ(int, float);
		
		float GetJoystickX(int);
		float GetJoystickY(int);
		float GetJoystickZ(int);
		
		void SetSwitch(int, int);
		
		int GetSwitch(int);
		
		virtual int Main(int a2, int a3, int a4, int a5,
					int a6, int a7, int a8, int a9, int a10);
	private:
		float Joysticks[NUMBER_OF_JOYSTICKS][3];
		
		int Switches[NUMBER_OF_SWITCHES];
		
		SEM_ID JoystickLocks[NUMBER_OF_JOYSTICKS];
		SEM_ID SwitchLocks[NUMBER_OF_SWITCHES];
};

#endif
