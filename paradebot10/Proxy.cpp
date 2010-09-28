/*******************************************************************************
*  Project   		: Framework
*  File Name  		: Proxy166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  File Description	: Code for Proxy class to hold shared variables
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "wpilib.h"
#include "Robot.h"

// Enable proxy logging?
#define LoggingProxy (0)

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

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
Proxy *Proxy::ProxyHandle = 0;

/**
 * @brief Starts the Proxy166 task.
 */
Proxy::Proxy(void):
	stick1(0), stick2(1), stick3(2), stick4(3),
	areSettingJoysticks(true)
{
	ProxyHandle = this;
	for(unsigned i=0;i<NUMBER_OF_SWITCHES;i++) {
		Switches[i] = 0;
	}
	
	// Start the actual task
	Start((char *)"166ProxyTask", PROXY_CYCLE_TIME);
}

Proxy::~Proxy(void)
{
	return;
}
/**
 * @brief Main thread function for Proxy166.
 * Runs forever, until MyTaskInitialized is false. 
 * 
 * @todo Update DS switch array
 */
int Proxy::Main(	int a2, int a3, int a4, int a5,
					int a6, int a7, int a8, int a9, int a10) {

	Robot *lHandle = NULL;
#if LoggingProxy
	ProxyLog sl;
#endif
	WaitForGoAhead();
	
	lHandle = Robot::getInstance();
#if LoggingProxy
	lHandle->RegisterLogger(&sl);
#endif
	
	Timer debugTimer;
	debugTimer.Start();
	
	ProxyJoystick old_sticks[NUMBER_OF_JOYSTICKS+1];
	
	while(MyTaskInitialized) {
		if(lHandle->IsOperatorControl() && true == AreSettingJoysticks()) {
			for(int x = 0;x<NUMBER_OF_JOYSTICKS;x++) {
				old_sticks[x] = GetJoystick(x);
			}
			SetJoystick(0, stick1);
			SetJoystick(1, stick2);
			SetJoystick(2, stick3);
			SetJoystick(3, stick4);
			
			if(tracker.size() > 0) {
				vector<int>::iterator it = tracker.begin();
				while(it != tracker.end()) {
					int joy_id = *it;
					int button_id = *(it+1);
					
					bool old_button = old_sticks[joy_id].button[button_id];
					bool new_button = GetButton(joy_id, button_id);
					
					if(old_button == 1 && new_button == 0) {
						// The button was previously pressed, but is now released
						(*(it+2))++; // Increase the counter
					}
					it += 3;
				}
			}
			if(debugTimer.HasPeriodPassed(1.0)) {
				// Debug info
			}
		}
		// The task ends if it's not initialized
		WaitForNextLoop();
	}
	
	return 0;
}

/*
 * User defined functions are located in this file
 */
#include "ProxyFunctions.h"

/**
 * @brief Sets the cached X axis value of a joystick.
 * @param joy_id Which joystick to set the cached X axis value for.
 * @param value What to set the cached value as.
 */

void Proxy::SetJoystickX(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	Joysticks[joy_id].X = value;
}

/**
 * @brief Sets the cached Y axis value of a joystick.
 * @param joy_id Which joystick to set the cached Y axis value for.
 * @param value What to set the cached value as.
 */
void Proxy::SetJoystickY(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	Joysticks[joy_id].Y = value;
}

/**
 * @brief Sets the cached Z axis value of a joystick.
 * @param joy_id Which joystick to set the cached Z axis value for.
 * @param value What to set the cached value as.
 */
void Proxy::SetJoystickZ(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	Joysticks[joy_id].Z = value;
}


/**
 * @brief Gets the cached X axis value of a joystick.
 * @param joy_id Which joystick to get the cached X axis value for.
 * @return Float equal to the cached X axis value.
 */
float Proxy::GetJoystickX(int joy_id) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	float value = 0;
	value = Joysticks[joy_id].X;
	return value;
}

/**
 * @brief Gets the cached Y axis value of a joystick.
 * @param joy_id Which joystick to get the cached Y axis value for.
 * @return Float equal to the cached Y axis value.
 */
float Proxy::GetJoystickY(int joy_id) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	float value = 0;
	value = Joysticks[joy_id].Y;
	return value;
}

/**
 * @brief Gets the cached Z axis value of a joystick.
 * @param joy_id Which joystick to get the cached Z axis value for.
 * @return Float equal to the cached Z axis value.
 */
float Proxy::GetJoystickZ(int joy_id) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	float value = 0;
	value = Joysticks[joy_id].Z;
	return value;
}


/**
 * @brief Sets the cached value for a switch.
 * @param switch_id Which switch to cache the value for.
 * @param value The value to cache.
 */
void Proxy::SetSwitch(int switch_id, int value) {
	wpi_assert(switch_id < NUMBER_OF_SWITCHES && switch_id >= 0);
	Switches[switch_id] = value;
}

/**
 * @brief Gets a cached switch value.
 * @param switch_id Which switch to retrieve the cached value of.
 * @return The int value of the cached switch value.
 */
int Proxy::GetSwitch(int switch_id) {
	wpi_assert(switch_id < NUMBER_OF_SWITCHES && switch_id >= 0);
	int value = 0;
	value = Switches[switch_id];
	return value;
}

/**
 * @brief Gets a cached joystick value.
 * @param joy_id Which joystick to retrieve the cached value of.
 * @return ProxyJoystick object with the joystick axes values and buttons set.
 */
ProxyJoystick Proxy::GetJoystick(int joy_id)
{
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	ProxyJoystick value;
	value = Joysticks[joy_id];
	return value;
}

/**
 * @brief Sets a cached joystick value.
 * @param joy_id Which joystick to set the cached value for.
 * @param stick A Joystick object with the X, Y, and Z axes set, as well as each of the buttons.
 */
void Proxy::SetJoystick(int joy_id, Joystick & stick)
{
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	Joysticks[joy_id].X = stick.GetX();
	Joysticks[joy_id].Y = stick.GetY();
	Joysticks[joy_id].Z = stick.GetZ();
	Joysticks[joy_id].throttle = stick.GetThrottle();
	for(unsigned i=0;i<NUMBER_OF_JOY_BUTTONS;i++) {
		Joysticks[joy_id].button[i] = stick.GetRawButton(i);
	}
	for(unsigned i=0;i<NUMBER_OF_JOY_BUTTONS;i++) {
		Joysticks[joy_id].newpress[i] ^= stick.GetRawButton(i);
	}
}

/**
 * @brief Sets the cache value of a button on a joystick.
 * @param joy_id Which joystick to set the button status for.
 * @param button_id Which button on the joystick to set the status for.
 * @param newval What to set the button's value to.
 */
void Proxy::SetButton(int joy_id, int button_id, bool newval)
{
	wpi_assert(joy_id < NUMBER_OF_JOY_BUTTONS && joy_id >= 0);
	Joysticks[joy_id].button[button_id] = newval;
	Joysticks[joy_id].newpress[button_id] ^= newval;
}

/**
 * @brief Gets the cache value of a button on a joystick. 
 * @param joy_id Which joystick to retrieve the button status for.
 * @param button_id Which button on the joystick to retrieve the status for.
 * @param reset Whether to reset the button's value after being called.
 * @return The button's value
 */
bool Proxy::GetButton(int joy_id, int button_id, bool reset)
{
	wpi_assert(joy_id < NUMBER_OF_JOY_BUTTONS && joy_id >= 0);
	bool button;
	button = Joysticks[joy_id].button[button_id];
	
	// reset the button so actions are triggered only once
	if (reset) {
		SetButton(joy_id, button_id, 0);
	}
	return button;
}

/**
 * @brief Gets whether the button is newly pressed this loop 
 * @param joy_id Which joystick to retrieve the button status for.
 * @param button_id Which button on the joystick to retrieve the status for.
 * @return The button's value
 */
bool Proxy::GetNewpress(int joy_id, int button_id)
{
	wpi_assert(joy_id < NUMBER_OF_JOY_BUTTONS && joy_id >= 0);
	return Joysticks[joy_id].newpress[button_id];
}

/**
 * @brief Sets the cache value of a joystick throttle.
 * @param joy_id Which joystick to set the throttle status for.
 * @param newval What to set the value to.
 */
void Proxy::SetThrottle(int joy_id, float newval) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	Joysticks[joy_id].throttle=newval;
}

/**
 * @brief Gets the cache value of a throttle on a joystick. 
 * @param joy_id Which joystick to retrieve the throttle status for.
 * @return The button's value
 */
float Proxy::GetThrottle(int joy_id) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	return Joysticks[joy_id].throttle;
}

/**
 * @brief Sets the cache value of the trigger (button 1) on a joystick.
 * @param joy_id Which joystick to set the trigger status for.
 * @param newval What to set the value to.
 */
void Proxy::SetTrigger(int joy_id, bool newval) { 
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	SetButton(joy_id, 1, newval); 
}
/**
 * @brief Gets the cache value of the trigger (button 1) of a joystick. 
 * @param joy_id Which joystick to retrieve the trigger status for.
 * @param reset Whether to reset the button's value after being called.
 * @return The last read current value
 */
bool Proxy::GetTrigger(int joy_id, bool reset) { 
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	bool bid = GetButton(joy_id,1); 
	// reset the button so actions are triggered only once
	if (reset) {
		SetButton(joy_id, 1, 0);
	}
	return bid;
}
/**
 * @brief Gets the singleton instance of Proxy166.
 * @return The instance of Proxy166
 */
Proxy *Proxy::getInstance(void)
{
	return ProxyHandle;
}


/**
 * @brief Gets the pending amount of times a button was pressed and released since last call.
 * @param joystick_id Which joystick to check
 * @param button_id Which button on the joystick to check
 * @return How many times the button was pressed and released since last call.
 */
int Proxy::GetPendingCount(int joystick_id, int button_id) {
	wpi_assert(joystick_id < NUMBER_OF_JOYSTICKS && joystick_id >= 0);
	wpi_assert(button_id < NUMBER_OF_JOY_BUTTONS && button_id >= 0);
	
	if(tracker.size() == 0)
		wpi_assertWithMessage(false, "Tried to fetch pending count for a non-registered button.");
	vector<int>::iterator it = tracker.begin();
	while(it != tracker.end())
	{
		if(*it == joystick_id && *(it+1) == button_id) {
			return *(it+2);
		}
		it += 3;
	}
	wpi_assertWithMessage(false, "Tried to fetch pending count for a non-registered button.");
	return 0;
}

/**
 * @brief Register a button to track the number of times it was pressed.
 * @param joystick_id Which joystick to track a button on
 * @param button_idd Which button on the joystick to track
 */
void Proxy::RegisterCounter(int joystick_id, int button_id) {
	wpi_assert(joystick_id < NUMBER_OF_JOYSTICKS && joystick_id >= 0);
	wpi_assert(button_id < NUMBER_OF_JOY_BUTTONS && button_id >= 0);
	
	if(tracker.size() != 0) {
		vector<int>::iterator it = tracker.begin();
		while(it >= tracker.end())
		{
			if(*it == joystick_id && *(it+1) == button_id) {
				return;
			}
			it+=3;
		}
	}
	tracker.push_back(joystick_id);
	tracker.push_back(button_id);
	tracker.push_back(0);
}

/**
 * @brief Unregister a button to track the number of times it was pressed.
 * @param joystick_id Which joystick to track a button on
 * @param button_idd Which button on the joystick to track
 */
void Proxy::UnregisterCounter(int joystick_id, int button_id) {
	wpi_assert(joystick_id < NUMBER_OF_JOYSTICKS && joystick_id >= 0);
	wpi_assert(button_id < NUMBER_OF_JOY_BUTTONS && button_id >= 0);
	
	if(tracker.size() == 0)
		return;
	vector<int>::iterator it = tracker.begin();
	while(it >= tracker.end())
	{
		if(*it == joystick_id && *(it+1) == button_id) {
			tracker.erase(it, it+2);
		}
		it+=3;
	}
}
/**
 * @brief Whether a joystick is registered for tracking
 * @param joystick_id What joystick to check
 * @param button_id What button on the joystick to check.
 * @return Whether it is registered.
 */
bool Proxy::IsRegistered(int joystick_id, int button_id) {
	wpi_assert(joystick_id < NUMBER_OF_JOYSTICKS && joystick_id >= 0);
	wpi_assert(button_id < NUMBER_OF_JOY_BUTTONS && button_id >= 0);
	
	if(tracker.size() == 0)
		return false;
	vector<int>::iterator it = tracker.begin();
	while(it >= tracker.end())
	{
		if(*it == joystick_id && *(it+1) == button_id) {
			return true;
		}
		it+=3;
	}
	return false;
}

bool Proxy::AreSettingJoysticks() {
	return areSettingJoysticks;
}
void Proxy::ToggleSettingJoysticks(bool in) {
	in = areSettingJoysticks;
}

void DumpJoystick(ProxyJoystick j) {
	for(int x = 0;x<=NUMBER_OF_JOY_BUTTONS;x++) {
		printf("[%d=%d] ", x, j.button[x]);
	}
	printf("\n");
}
