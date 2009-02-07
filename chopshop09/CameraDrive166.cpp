/********************************************************************************
*  Project   		: Chopshop 2009
*  File Name  		: CameraDrive166.cpp          
*  Contributors   	: ELF
*  Creation Date 	: February 6, 2008
*  Revision History	: Source code & revision history maintained at code.google.com    
*  File Description	: Drive based on Vision166 input
*/
#include "WPILib.h"
#include <math.h>

// 166 include files
#include "Vision166.h"
#include "MemoryLog166.h"

// WPILib include files for vision
#include "AxisCamera.h" 
#include "BaeUtilities.h"
#include "FrcError.h"
#include "Target166.h"

void Robot166::CameraDrive()
{
	
	// Pick up the dispenser command
	switch (RobotMode) {
	case T166_AUTONOMOUS: {
		printf("ameraDrive166: autonomous");
		//Team166Vision::AcquireTarget();
		break;
	}
	case T166_OPERATOR: {
		break;
	    }
	default: {
		break;
	    }
	}
	
	// Done
	return;
}

