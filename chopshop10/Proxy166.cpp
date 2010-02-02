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
#include "wpilib.h"
#include "Proxy166.h"
#include "Robot166.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(true)dprintf

/**
 * @brief Initializes the joystick axes to 0 and the buttons to unset.
 */
ProxyJoystick::ProxyJoystick(void)
{
	X=Y=Z=0;
	for(unsigned i=0;i<NUMBER_OF_JOY_BUTTONS;i++) {
		button[i]=false;
	}
}

// Initialiezs the ProxyHandle. 
Proxy166 *Proxy166::ProxyHandle = 0;

/**
 * @brief Sets the cached X axis value of a joystick.
 * @param joy_id Which joystick to set the cached X axis value for.
 * @param value What to set the cached value as.
 */
void Proxy166::SetJoystickX(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].X = value;
	semGive(JoystickLocks[joy_id]);
}

/**
 * @brief Sets the cached Y axis value of a joystick.
 * @param joy_id Which joystick to set the cached Y axis value for.
 * @param value What to set the cached value as.
 */
void Proxy166::SetJoystickY(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].Y = value;
	semGive(JoystickLocks[joy_id]);
}

/**
 * @brief Sets the cached Z axis value of a joystick.
 * @param joy_id Which joystick to set the cached Z axis value for.
 * @param value What to set the cached value as.
 */
void Proxy166::SetJoystickZ(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].Z = value;
	semGive(JoystickLocks[joy_id]);
}


/**
 * @brief Gets the cached X axis value of a joystick.
 * @param joy_id Which joystick to get the cached X axis value for.
 * @return Float equal to the cached X axis value.
 */
float Proxy166::GetJoystickX(int joy_id) {
	float value = 0;
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
//	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id].X;
//	semGive(JoystickLocks[joy_id]);
	return value;
}

/**
 * @brief Gets the cached Y axis value of a joystick.
 * @param joy_id Which joystick to get the cached Y axis value for.
 * @return Float equal to the cached Y axis value.
 */
float Proxy166::GetJoystickY(int joy_id) {
	float value = 0;
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
//	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id].Y;
//	semGive(JoystickLocks[joy_id]);
	return value;
}

/**
 * @brief Gets the cached Z axis value of a joystick.
 * @param joy_id Which joystick to get the cached Z axis value for.
 * @return Float equal to the cached Z axis value.
 */
float Proxy166::GetJoystickZ(int joy_id) {
	float value = 0;
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
//	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id].Z;
//	semGive(JoystickLocks[joy_id]);
	return value;
}


/**
 * @brief Sets the cached value for a switch.
 * @param switch_id Which switch to cache the value for.
 * @param value The value to cache.
 */
void Proxy166::SetSwitch(int switch_id, int value) {
	wpi_assert(switch_id < NUMBER_OF_SWITCHES && switch_id >= 0);
	semTake(SwitchLocks[switch_id], WAIT_FOREVER);
	Switches[switch_id] = value;
	semGive(SwitchLocks[switch_id]);
}

/**
 * @brief Gets a cached switch value.
 * @param switch_id Which switch to retrieve the cached value of.
 * @return The int value of the cached switch value.
 */
int Proxy166::GetSwitch(int switch_id) {
	int value = 0;
	wpi_assert(switch_id < NUMBER_OF_SWITCHES && switch_id >= 0);
//	semTake(SwitchLocks[switch_id], WAIT_FOREVER);
	value = Switches[switch_id];
//	semGive(SwitchLocks[switch_id]);
	return value;
}

/**
 * @brief Gets a cached joystick value.
 * @param joy_id Which joystick to retrieve the cached value of.
 * @return ProxyJoystick object with the joystick axes values and buttons set.
 */
ProxyJoystick Proxy166::GetJoystick(int joy_id)
{
	ProxyJoystick value;
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
//	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id];
//	semGive(JoystickLocks[joy_id]);
	return value;
}


/**
 * @brief Sets a cached joystick value.
 * @param joy_id Which joystick to set the cached value for.
 * @param stick A Joystick object with the X, Y, and Z axes set, as well as each of the buttons.
 */
void Proxy166::SetJoystick(int joy_id, Joystick stick)
{
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].X = stick.GetX();
	Joysticks[joy_id].Y = stick.GetY();
	Joysticks[joy_id].Z = stick.GetZ();
	for(unsigned i=0;i<NUMBER_OF_JOY_BUTTONS;i++) {
		Joysticks[joy_id].button[i] = stick.GetRawButton(i);
	}
	semGive(JoystickLocks[joy_id]);
}

/**
 * @brief Sets the cache value of a button on a joystick.
 * @param joy_id Which joystick to set the button status for.
 * @param button_id Which button on the joystick to set the status for.
 * @param newval What to set the button's value to.
 */
void Proxy166::SetButton(int joy_id, int button_id, bool newval)
{
	wpi_assert(joy_id < NUMBER_OF_JOY_BUTTONS && joy_id >= 0);
	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].button[button_id] = newval;
	semGive(JoystickLocks[joy_id]);
}

/**
 * @brief Gets the cache value of a button on a joystick. 
 * @param joy_id Which joystick to retrieve the button status for.
 * @param button_id Which button on the joystick to retrieve the status for.
 * @return The button's value
 */
bool Proxy166::GetButton(int joy_id, int button_id)
{
	bool button;
	wpi_assert(joy_id < NUMBER_OF_JOY_BUTTONS && joy_id >= 0);
//	semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	button = Joysticks[joy_id].button[button_id];
//	semGive(JoystickLocks[joy_id]);

	// TODO: make reset an optional calling parameter, but reset it by default
	
	// reset the button so actions are triggered only once
	SetButton(joy_id, button_id, 0);
	
	return button;
}

/**
 * @brief Initializes semaphores for joysticks and switches, and starts the Proxy166 task.
 */
Proxy166::Proxy166(void):
	driveStickRight(T166_USB_STICK_1),        // USB port for 1st stick
	driveStickLeft(T166_USB_STICK_2),        // USB port for 2nd stick
	driveStickCopilot(T166_USB_STICK_3)
{
	ProxyHandle=this;
	for(unsigned i=0;i<NUMBER_OF_JOYSTICKS;i++) {
		// Initializing semaphores for joysticks
		JoystickLocks[i] = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
	}
	for(unsigned i=0;i<NUMBER_OF_SWITCHES;i++) {
		// Initializing semaphores for switches
		SwitchLocks[i] = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
	}
	Start((char *)"166ProxyTask", 25);
}

Proxy166::~Proxy166(void)
{
	return;
}
/**
 * @brief Gets the singleton instance of Proxy166.
 * @return The instance of Proxy166
 */
Proxy166 *Proxy166::getInstance(void)
{
	return ProxyHandle;
}

/**
 * @brief Main thread function for Proxy166.
 * Runs forever, until MyTaskInitialized is false. 
 */
int Proxy166::Main(	int a2, int a3, int a4, int a5,
					int a6, int a7, int a8, int a9, int a10) {
	MyTaskInitialized = 1;
	
	// For use with a logger if/when implemented
	Robot166 *lHandle;
	lHandle = Robot166::getInstance();
	printf("in proxy\n");
	while(MyTaskInitialized) {

		//TODO: do this update of joystick values only in Operator Control mode
		//TODO: add update of bottom joystick control
		
		//TODO: update DS Switch array
		
		SetJoystickX(1, driveStickRight.GetX());
		SetJoystickY(1, driveStickRight.GetY());
		SetJoystickZ(1, driveStickRight.GetZ());		
		//Initialize each button
		for (int i=1;i<=11;i++) {
			SetButton(1, i, driveStickRight.GetRawButton(i));
		}
		
		SetJoystickX(2, driveStickLeft.GetX());
		SetJoystickY(2, driveStickLeft.GetY());
		SetJoystickZ(2, driveStickLeft.GetZ());		
		//Initialize each button
		for (int i=1;i<=11;i++) {
			SetButton(2, i, driveStickLeft.GetRawButton(i));
		}

		SetJoystickX(3, driveStickCopilot.GetX());
		SetJoystickY(3, driveStickCopilot.GetY());
		SetJoystickZ(3, driveStickCopilot.GetZ());		
		//Initialize each button
		for (int i=1;i<=11;i++) {
			SetButton(3, i, driveStickCopilot.GetRawButton(i));
		}

		// The task ends if it's not initialized
		WaitForNextLoop();
	}
	
	return 0;
}
