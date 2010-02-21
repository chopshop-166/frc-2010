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

/**
 * Basic runtime class for basic statistics, debugging help. 
 * Usage: Declare an instance of this class, then call Start() when you want to begin
 * tracking, then Stop() when you want to stop tracking. This class will keep
 * track of the amount of time between these two calls, and store them in a list
 * of the last (N) "loop" times. GetStats() returns a string containing some stats
 * about this list - max, median, min, average, and standard deviation. 
 * 
 * This class should be useful if you want to know whether a task is running too slowly
 * or erratically. 
 */
class Runtime166 {
	//! Timer (WPILib) that keeps track of the time between Stop and Start calls.
	Timer t;
	//! Vector that keeps track of the loop times
	vector<float> loop_times;
	//! How many times to keep track of
	int limit;
	
public:
	Runtime166();
	/**
	 * Makes a new instance of Runtime166.
	 * @param limit How many loop times to keep track of before unshifting the old ones
	 */
	Runtime166(int limit);
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
	/**
	 * Clears tracking time.
	 */
	void Reset();
};
