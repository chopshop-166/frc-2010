/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Proxy166.cpp     
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
#include "Robot166.h"

// This initializes the static pointer
// It has to be declared outside the class
Proxy166 *Proxy166::ProxyHandle = 0;

void Proxy166::SetJoystickX(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].X = value;
	semGive(JoystickLocks[joy_id]);
}
void Proxy166::SetJoystickY(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].Y = value;
	semGive(JoystickLocks[joy_id]);
}
void Proxy166::SetJoystickZ(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].Z = value;
	semGive(JoystickLocks[joy_id]);
}

float Proxy166::GetJoystickX(int joy_id) {
	float value = 0;
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id].X;
	semGive(JoystickLocks[joy_id]);
	return value;
}
float Proxy166::GetJoystickY(int joy_id) {
	float value = 0;
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id].Y;
	semGive(JoystickLocks[joy_id]);
	return value;
}
float Proxy166::GetJoystickZ(int joy_id) {
	float value = 0;
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id].Z;
	semGive(JoystickLocks[joy_id]);
	return value;
}

void Proxy166::SetSwitch(int switch_id, int value) {
	wpi_assert(switch_id < NUMBER_OF_SWITCHES && switch_id >= 0);
	semTake(SwitchLocks[switch_id], WAIT_FOREVER);
	Switches[switch_id] = value;
	semGive(SwitchLocks[switch_id]);
}

int Proxy166::GetSwitch(int switch_id) {
	int value = 0;
	wpi_assert(switch_id < NUMBER_OF_SWITCHES && switch_id >= 0);
	semTake(SwitchLocks[switch_id], WAIT_FOREVER);
	value = Switches[switch_id];
	semGive(SwitchLocks[switch_id]);
	return value;
}

Proxy166::Proxy166(void)
{
	ProxyHandle=this;
	Start((char *)"166ProxyTask", 25);
}

Proxy166::~Proxy166(void)
{
	return;
}

Proxy166 *Proxy166::getInstance(void)
{
	return ProxyHandle;
}

int Proxy166::Main(	int a2, int a3, int a4, int a5,
					int a6, int a7, int a8, int a9, int a10) {
	MyTaskInitialized = 1;
	
	// For use with a logger if/when implemented
	Robot166 *lHandle;
	lHandle = Robot166::getInstance();
	
	while(MyTaskInitialized) {
		// The task ends if it's not initialized
		WaitForNextLoop();
	}
	
	return 0;
}
