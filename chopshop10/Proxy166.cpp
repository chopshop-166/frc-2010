/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: TankDrive166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Code for Proxy class to hold shared variables
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/


#include <semLib.h>
#include "Proxy166.h"

void Proxy166::SetJoystickX(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id > 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id][0] = value;
	semGive(JoystickLocks[joy_id]);
}
void Proxy166::SetJoystickY(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id > 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id][1] = value;
	semGive(JoystickLocks[joy_id]);
}
void Proxy166::SetJoystickZ(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id > 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id][2] = value;
	semGive(JoystickLocks[joy_id]);
}

float Proxy166::GetJoystickX(int joy_id) {
	float value = 0;
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id > 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id][0];
	semGive(JoystickLocks[joy_id]);
	return value;
}
float Proxy166::GetJoystickY(int joy_id) {
	float value = 0;
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id > 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id][1];
	semGive(JoystickLocks[joy_id]);
	return value;
}
float Proxy166::GetJoystickZ(int joy_id) {
	float value = 0;
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id > 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id][2];
	semGive(JoystickLocks[joy_id]);
	return value;
}

void Proxy166::SetSwitch(int switch_id, int value) {
	wpi_assert(switch_id < NUMBER_OF_SWITCHES && switch_id > 0);
	semTake(SwitchLocks[switch_id], WAIT_FOREVER);
	Switches[switch_id] = value;
	semGive(SwitchLocks[switch_id]);
}

int Proxy166::GetSwitch(int switch_id) {
	int value = 0;
	wpi_assert(switch_id < NUMBER_OF_SWITCHES && switch_id > 0);
	semTake(SwitchLocks[switch_id], WAIT_FOREVER);
	value = Switches[switch_id];
	semGive(SwitchLocks[switch_id]);
	return value;
}

int Proxy166::Main(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	MyTaskInitialized = 1;
	
	return 0;
}
