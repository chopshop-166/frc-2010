/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Kicker166.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for robot code which controls the kicker
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#if !defined(_KICKER166_H)
#define _KICKER166_H
#include "WPILib.h"
#include "Robot166.h"

#define NO_SPEED				 0    //speed to use when there is no input for the treadmill victor
#define SPIN_SPEED    			 1    //speed used when kicker is spinning 

class Team166Kicker : public Team166Task
{
	
public:
	
	// task constructor
	Team166Kicker(void);

	// task destructor
	virtual ~Team166Kicker(void);

	// Main function of the task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
};

#endif // !defined(_KICKER166)
