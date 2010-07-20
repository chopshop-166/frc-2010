/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Lift166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code which controls the banner sensors
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "AxesSensors.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	// Any values that need to be logged go here
};

//  Memory Log
class AxesSensorsLog : public MemoryLog166
{
public:
	AxesSensorsLog() : MemoryLog166(
			sizeof(struct abuf166), AXESSENSORS_CYCLE_TIME, "AxesSensors",
			"Seconds,Nanoseconds,Elapsed Time\n" // Put the names of the values in here, comma-seperated
			) {
		return;
	};
	~AxesSensorsLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(void);     // Log the values needed-add in arguments
};

// Write one buffer into memory
unsigned int AxesSensorsLog::PutOne(void)
{
	struct abuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct abuf166 *)GetNextBuffer(sizeof(struct abuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		// Add any values to be logged here
		return (sizeof(struct abuf166));
	}
	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int AxesSensorsLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u,%u,%4.5f\n",
			ab->tp.tv_sec, ab->tp.tv_nsec,
			((ab->tp.tv_sec - starttime.tv_sec) + ((ab->tp.tv_nsec-starttime.tv_nsec)/1000000000.))
			// Add values here
	);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
AxesSensors166::AxesSensors166(void): Temp_Sensor(T166_Temp), Gyro_Sensor(T166_Gyro), X_Axis(T166_X_AXIS), Y_Axis(T166_Y_AXIS)
{
	Start((char *)"166AxesSensorsTask", AXESSENSORS_CYCLE_TIME);
	// ^^^ Rename those ^^^
	return;
};
	
// task destructor
AxesSensors166::~AxesSensors166(void)
{
	return;
};
float AxesSensors166::GetTemperature(AnalogChannel &TempSensor,char temp) {
	#define CELSIUS_TO_KELVIN (273.15)
	float orig_voltage_temp;
	float Temp_Kelvin;
	//Get Temperature In Kelvin, Celsius, Fahrenheit
	orig_voltage_temp = TempSensor.GetVoltage();
	//Convert Millivolts to kelvin
	Temp_Kelvin = ((orig_voltage_temp * 1000) / 9.8);
	if (temp == 'K') {
		return Temp_Kelvin;
	} else if(temp == 'C') {
		return (Temp_Kelvin - CELSIUS_TO_KELVIN);
	} else if(temp == 'F') {
		return ((9/5) * (Temp_Kelvin - CELSIUS_TO_KELVIN)) + 32;
	} else {
		return 1;
	}
}
	
// Main function of the task
int AxesSensors166::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	Proxy166 *proxy;				// Handle to proxy
	Robot *lHandle;            // Local handle
	AxesSensorsLog sl;                   // log
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 AxesSensors task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot::getInstance();
	lHandle->RegisterLogger(&sl);
	
	// Register the proxy
	proxy = Proxy166::getInstance();

	float orig_voltage_gyro = 0;
	float Gyro_Angle = 0;
	float X_Axis_Accel = 0;
	float Y_Axis_Accel = 0;
	#define Sensitivity_DAA (0.174)
	X_Axis.SetSensitivity(Sensitivity_DAA);
	Y_Axis.SetSensitivity(Sensitivity_DAA);
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
	
		//lHandle->DriverStationDisplay("Temp: %f", orig_voltage_temp);
		Gyro_Angle = Gyro_Sensor.GetAngle();
        //lHandle->DriverStationDisplay("Angle: %f", Gyro_Angle);
		X_Axis_Accel = X_Axis.GetAcceleration();
		Y_Axis_Accel = Y_Axis.GetAcceleration();		
		// Logging any values
		sl.PutOne();
		
		// Wait for our next lap
		WaitForNextLoop();		
	}
	return (0);
	
};
