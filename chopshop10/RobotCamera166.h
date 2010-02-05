/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: RobotCamera166.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for calls to get camera information
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "Vision/AxisCamera2010.h"

#if !defined(_ROBOTCAMERA166_H)
#define _ROBOTFUNCTIONS166_H

void StartPCVideoServer();	
void StartCamera();
void TakeSnapshot(char* imageName);
void SetupCamera(ResolutionT res, RotationT rot);
void DriveTowardsTarget();

//extern AxisCamera camera166;

#endif // !defined(_ROBOTCAMERA166_H)
