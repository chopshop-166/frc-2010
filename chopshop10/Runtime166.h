/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Runtime166.h  
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for class that generates runtime statistics
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include <vector>
using namespace std;

class Runtime166 {
	Timer t;
	vector<float> loop_times;
	unsigned int limit;
	
public:
	Runtime166();
	Runtime166(unsigned int);
	/**
	 * Starts tracking time.
	 */
	void Stop();
	/**
	 * Starts tracking time.
	 */
	void Start();
	/**
	 * Generates statistics based on the times designed by stop and start.
	 */
	char* GetStats();
	/**
	 * Gets the number of times it's been stopped.
	 */
	unsigned int Loops();
};
