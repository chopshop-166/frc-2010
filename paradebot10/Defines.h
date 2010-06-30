/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Vision166.h    
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code header which handles vision of camera
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#ifndef _T166_DEFINES_H
#define _T166_DEFINES_H


// Place any #defines for things you want to enable in multiple tasks, simply, here

// Code version number
#define T166_CODE_VERSION ("CODE: BATTLECRY-05")

//
// Analog Pin layout
// _MOD refers to cRIO module (1 or 2)
// If module 2 is used, make sure you have 2 sidecars
// Other stuff is the channel in the module
//
#define T166_ANALOG_MODULE_1 (1)
#define T166_ANALOG_MODULE_2 (2)

// first analog module
#define T166_BAT_MOD (T166_ANALOG_MODULE_1) // Module for battery sensor
#define T166_BAT_VOLT (8)                   // Channel for battery voltage

//
// Digital Pin layout
//
// Place #defines for the digital pins here
// Autonomous Jumper Port: This enables the autonomous if it's in
#define PSI_SWITCH (1)
#define T166_AUTONOMOUS_JUMPER (7)

//
// PWM layout
//
// Place #defines for the PWMs here

//
// Relay Layout
//
/** Channels for Compressor */
#define COMPRESSOR_RELAY (1)


//
// Pneumatics */
//
/** Low pressure limit */
#define T166_PNEU_LOW (110.0)
/** High pressure limit */
#define T166_PNEU_HIGH (120.0)
/** Open cylinder */
#define SOLENOID_OPEN (1)
/** Close cylinder */
#define SOLENOID_CLOSE (2)


//
// CAN bus layout
//
/** Maximum Jaguar number plus one */
#define T166_NUM_JAGS (11)
#define T166_LEFT_MOTOR_CAN (7)
/** channel for the Right Motor */
#define T166_RIGHT_MOTOR_CAN (6)


//
// USB port layout
//
/** Left driver stick is in USB port #1 */
#define T166_DRIVER_STICK_LEFT (1)
/** Right driver stick is in USB port #2 */
#define T166_DRIVER_STICK_RIGHT (2)
/** Copilot stick is in USB port #3 */
#define T166_COPILOT_STICK (3)

//
// Joystick buttons
//
// Place #defines for the button layout here

#endif // !defined(_T166_DEFINES_H)
