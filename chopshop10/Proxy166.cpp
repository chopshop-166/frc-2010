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
		button[i]=press_count[i]=track_press_count[i]=false;
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
	//semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].X = value;
	//semGive(JoystickLocks[joy_id]);
}

/**
 * @brief Sets the cached Y axis value of a joystick.
 * @param joy_id Which joystick to set the cached Y axis value for.
 * @param value What to set the cached value as.
 */
void Proxy166::SetJoystickY(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	//semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].Y = value;
	//semGive(JoystickLocks[joy_id]);
}

/**
 * @brief Sets the cached Z axis value of a joystick.
 * @param joy_id Which joystick to set the cached Z axis value for.
 * @param value What to set the cached value as.
 */
void Proxy166::SetJoystickZ(int joy_id, float value) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	//semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].Z = value;
	//semGive(JoystickLocks[joy_id]);
}


/**
 * @brief Gets the cached X axis value of a joystick.
 * @param joy_id Which joystick to get the cached X axis value for.
 * @return Float equal to the cached X axis value.
 */
float Proxy166::GetJoystickX(int joy_id) {
	float value = 0;
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	//semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id].X;
	//semGive(JoystickLocks[joy_id]);
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
	//semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id].Y;
	//semGive(JoystickLocks[joy_id]);
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
	//semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id].Z;
	//semGive(JoystickLocks[joy_id]);
	return value;
}


/**
 * @brief Sets the cached value for a switch.
 * @param switch_id Which switch to cache the value for.
 * @param value The value to cache.
 */
void Proxy166::SetSwitch(int switch_id, int value) {
	wpi_assert(switch_id < NUMBER_OF_SWITCHES && switch_id >= 0);
	//semTake(SwitchLocks[switch_id], WAIT_FOREVER);
	Switches[switch_id] = value;
	//semGive(SwitchLocks[switch_id]);
}

/**
 * @brief Gets a cached switch value.
 * @param switch_id Which switch to retrieve the cached value of.
 * @return The int value of the cached switch value.
 */
int Proxy166::GetSwitch(int switch_id) {
	int value = 0;
	wpi_assert(switch_id < NUMBER_OF_SWITCHES && switch_id >= 0);
	//semTake(SwitchLocks[switch_id], WAIT_FOREVER);
	value = Switches[switch_id];
	//semGive(SwitchLocks[switch_id]);
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
	//semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	value = Joysticks[joy_id];
	//semGive(JoystickLocks[joy_id]);
	return value;
}

/**
 * @brief Sets a cached joystick value.
 * @param joy_id Which joystick to set the cached value for.
 * @param stick A Joystick object with the X, Y, and Z axes set, as well as each of the buttons.
 */
void Proxy166::SetJoystick(int joy_id, Joystick & stick)
{
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	//semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].X = stick.GetX();
	Joysticks[joy_id].Y = stick.GetY();
	Joysticks[joy_id].Z = stick.GetZ();
	Joysticks[joy_id].throttle = stick.GetThrottle();
	for(unsigned i=0;i<NUMBER_OF_JOY_BUTTONS;i++) {
		Joysticks[joy_id].button[i] = stick.GetRawButton(i);
	}
	//semGive(JoystickLocks[joy_id]);
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
	//semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	Joysticks[joy_id].button[button_id] = newval;
	//semGive(JoystickLocks[joy_id]);
}

/**
 * @brief Gets the cache value of a button on a joystick. 
 * @param joy_id Which joystick to retrieve the button status for.
 * @param button_id Which button on the joystick to retrieve the status for.
 * @param reset Whether to reset the button's value after being called.
 * @return The button's value
 */
bool Proxy166::GetButton(int joy_id, int button_id, bool reset)
{
	bool button;
	wpi_assert(joy_id < NUMBER_OF_JOY_BUTTONS && joy_id >= 0);
	//semTake(JoystickLocks[joy_id], WAIT_FOREVER);
	button = Joysticks[joy_id].button[button_id];
	//semGive(JoystickLocks[joy_id]);
	
	// reset the button so actions are triggered only once
	if (reset) {
		SetButton(joy_id, button_id, 0);
	}
	return button;
}

/**
 * @brief Sets the cache value of a joystick throttle.
 * @param joy_id Which joystick to set the throttle status for.
 * @param newval What to set the value to.
 */
void Proxy166::SetThrottle(int joy_id, float newval) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	//semTake(JoystickLocks[switch_id], WAIT_FOREVER);
	Joysticks[joy_id].throttle=newval;
	//semGive(JoystickLocks[switch_id]);
}

/**
 * @brief Gets the cache value of a throttle on a joystick. 
 * @param joy_id Which joystick to retrieve the throttle status for.
 * @return The button's value
 */
float Proxy166::GetThrottle(int joy_id) {
	wpi_assert(joy_id < NUMBER_OF_JOYSTICKS && joy_id >= 0);
	//semTake(JoystickLocks[switch_id], WAIT_FOREVER);
	return Joysticks[joy_id].throttle;
	//semGive(JoystickLocks[switch_id]);
}

/**
 * @brief Sets the cache value of the trigger (button 1) on a joystick.
 * @param joy_id Which joystick to set the trigger status for.
 * @param newval What to set the value to.
 */
void Proxy166::SetTrigger(int joy_id, bool newval) { SetButton(joy_id, 1, newval); }
/**
 * @brief Gets the cache value of the trigger (button 1) of a joystick. 
 * @param joy_id Which joystick to retrieve the trigger status for.
 * @param reset Whether to reset the button's value after being called.
 * @return The last read current value
 */
bool Proxy166::GetTrigger(int joy_id, bool reset) { 
	bool bid = GetButton(joy_id,1); 
	// reset the button so actions are triggered only once
	if (reset) {
		SetButton(joy_id, 1, 0);
	}
	return bid;
}

/**
 * @brief Sets the cache value of the banner sensor.
 * @param newval What to set the value to.
 */
void Proxy166::SetBannerProxy(int newval) { BannerProxy = newval; }
/**
 * @brief Gets the cache value of the banner sensor. 
 * @return The last value set by the banner sensor task
 */
int Proxy166::GetBannerProxy() { return BannerProxy; }

/**
 * @brief Initializes semaphores for joysticks and switches, and starts the Proxy166 task.
 */
Proxy166::Proxy166(void):
	driveStickRight(T166_USB_STICK_1),        // USB port for 1st stick
	driveStickLeft(T166_USB_STICK_2),        // USB port for 2nd stick
	driveStickCopilot(T166_USB_STICK_3)
{
	ProxyHandle=this;
	// initialize memory for banner
	BannerProxy = 0;
	// note use of semaphores are commented out for now
	// they are not required for atomic actions 
	// and they appeared to be causing tasks to crash
	for(unsigned i=0;i<NUMBER_OF_JOYSTICKS;i++) {
		// Initializing semaphores for joysticks
		JoystickLocks[i] = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
		Joysticks[i] = ProxyJoystick();
	}
	for(unsigned i=0;i<NUMBER_OF_SWITCHES;i++) {
		// Initializing semaphores for switches
		SwitchLocks[i] = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
	}
	
	// Set the initial distance
	SonarDistance = 0.0;
	
	// Start the actual task
	Start((char *)"166ProxyTask", PROXY_CYCLE_TIME);
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
 * @brief Gets the cached image.
 * @return The cached image.
 */
ColorImage *Proxy166::GetImage() {
	return image;
}

/**
 * @brief Sets the cached image.
 */
void Proxy166::SetImage(ColorImage *img) {
	image = img;
}


/**
 * @brief Deletes the cached image.
 */
void Proxy166::DeleteImage() {
	delete image;
}


/**
 * @brief Gets the pending amount of times a button was pressed and released since last call.
 * @param joystick_id Which joystick to check
 * @param button_id Which button on the joystick to check
 * @return How many times the button was pressed and released since last call.
 */
int Proxy166::GetPendingCount(int joystick_id, int button_id) {
	wpi_assert(joystick_id < NUMBER_OF_JOYSTICKS && joystick_id >= 0);
	wpi_assert(button_id < NUMBER_OF_JOY_BUTTONS && button_id >= 0);
	wpi_assert(Joysticks[joystick_id].track_press_count[button_id]);
	
	int press_count = Joysticks[joystick_id].press_count[button_id];
	Joysticks[joystick_id].press_count[button_id] = 0;
	return press_count;
}

/**
 * @brief Register a button to track the number of times it was pressed.
 * @param joystick_id Which joystick to track a button on
 * @param button_idd Which button on the joystick to track
 */
void Proxy166::RegisterCounter(int joystick_id, int button_id) {
	wpi_assert(joystick_id < NUMBER_OF_JOYSTICKS && joystick_id >= 0);
	wpi_assert(button_id < NUMBER_OF_JOY_BUTTONS && button_id >= 0);
	
	Joysticks[joystick_id].track_press_count[button_id] = 1;
}

/**
 * @brief Unregister a button to track the number of times it was pressed.
 * @param joystick_id Which joystick to track a button on
 * @param button_idd Which button on the joystick to track
 */
void Proxy166::UnregisterCounter(int joystick_id, int button_id) {
	wpi_assert(joystick_id < NUMBER_OF_JOYSTICKS && joystick_id >= 0);
	wpi_assert(button_id < NUMBER_OF_JOY_BUTTONS && button_id >= 0);
	
	Joysticks[joystick_id].track_press_count[button_id] = 0;
}

bool Proxy166::IsRegistered(int joystick_id, int button_id) {
	wpi_assert(joystick_id < NUMBER_OF_JOYSTICKS && joystick_id >= 0);
	wpi_assert(button_id < NUMBER_OF_JOY_BUTTONS && button_id >= 0);
	
	return Joysticks[joystick_id].track_press_count[button_id];
}

/**
 * @brief Set distance from sonar object in front of it
 * @param Distance in inches
 */
void Proxy166::SetSonarDistance(float dist)
{
	
	SonarDistance = dist;
}

/**
 * @brief Obtain distance seen by the sonar task
 */
float Proxy166::GetSonarDistance(void)
{
	return (SonarDistance);
}

/**
 * @brief Main thread function for Proxy166.
 * Runs forever, until MyTaskInitialized is false. 
 * 
 * @todo Update DS switch array
 */
int Proxy166::Main(	int a2, int a3, int a4, int a5,
					int a6, int a7, int a8, int a9, int a10) {

	Robot166 *lHandle;            // Local handle

	DPRINTF(LOG_DEBUG, "Proxy166 main task entered.");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();

   // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
	    // In autonomous, the Autonomous166 task will update relevant values
		bool old_buttons[NUMBER_OF_JOYSTICKS][NUMBER_OF_JOY_BUTTONS];
		for(int joy_id = 0;joy_id < NUMBER_OF_JOYSTICKS;joy_id++) {
			for(int button_id = 0;button_id < NUMBER_OF_JOY_BUTTONS; button_id++) {
				old_buttons[joy_id][button_id] = GetButton(joy_id, button_id);
			}
		}
		if(lHandle->IsOperatorControl()) {
			SetJoystick(1, driveStickRight);
			SetJoystick(2, driveStickLeft);
			SetJoystick(3, driveStickCopilot);
		}
		/* Loop through each button on each joystick, and check whether its state has changed
		 * (GetButton(...) != old_joysticks[...]) means that the state has changed since the last loop ran
		 * If the button has been released (GetButton(...) == 0) and it was changed, increment the press count.
		 */
		
		for(int joy_id = 0;joy_id < NUMBER_OF_JOYSTICKS;joy_id++) {
			for(int button_id = 0;button_id < NUMBER_OF_JOY_BUTTONS; button_id++) {
				if(IsRegistered(joy_id, button_id)) {
					if(GetButton(joy_id, button_id) == 0 && GetButton(joy_id, button_id) != old_buttons[joy_id][button_id]) {
						Joysticks[joy_id].press_count[button_id]++;
					}
				}
			}
		}
		
		// The task ends if it's not initialized
		WaitForNextLoop();
	}
	
	return 0;
}
