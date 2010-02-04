/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Proxy166.h     
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

#define NUMBER_OF_JOYSTICKS (4)
#define NUMBER_OF_SWITCHES (10)
#define NUMBER_OF_JOY_BUTTONS (12)

/**
 * @brief Proxy Joystick class that will be returned if a full cached joystick is requested.
 * 
 * If Proxy1666::GetJoystick is called, then a full joystick should be returned. We don't want
 * to have to set all the values of the Joystick class, though, so we return this simpler class
 * with only 3 axes and some buttons. 
 */
class ProxyJoystick {
	public:
		float X;
		float Y;
		float Z;
		bool button[NUMBER_OF_JOY_BUTTONS];
		
		ProxyJoystick(void);
};

/**
 * @brief Proxy class to store cached values for joysticks and switches.
 * 
 * This class will store the cached values for joysticks and switches. It will also
 * serve as a interface between the joysticks and switches, and any code that wants to 
 * access them like Drive, Autonomous, etc. 
 */

class Proxy166 : public Team166Task {
	public:		
		void SetJoystickX(int, float);  
		void SetJoystickY(int, float);
		void SetJoystickZ(int, float);
		
		float GetJoystickX(int);
		float GetJoystickY(int);
		float GetJoystickZ(int);
		
		ProxyJoystick GetJoystick(int);
		void SetJoystick(int,Joystick);
		
		void SetSwitch(int, int);
		int GetSwitch(int);
		
		void SetButton(int,int,bool);
		bool GetButton(int,int);
		
		int GetGameMode(void);
		int SetGameMode(int);
		
		Proxy166(void);
		~Proxy166(void);
		
		static Proxy166 *getInstance(void);
		
		virtual int Main(int a2, int a3, int a4, int a5,
					int a6, int a7, int a8, int a9, int a10);
	private:
		/**
		 * @brief The single instance handle to Proxy166.
		 */
		static Proxy166* ProxyHandle;
		
		ProxyJoystick Joysticks[NUMBER_OF_JOYSTICKS];
		
		int Switches[NUMBER_OF_SWITCHES];
		
		SEM_ID JoystickLocks[NUMBER_OF_JOYSTICKS];
		SEM_ID SwitchLocks[NUMBER_OF_SWITCHES];

		Joystick driveStickLeft;      // joy stick for driving
		Joystick driveStickRight;     // joy stick for driving
		Joystick driveStickCopilot;	  // Camera / copilot joy stick
};

#endif
