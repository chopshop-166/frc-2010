/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: SensorTest166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code which accesses various sensors
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "SensorTest166.h"

// Sensor test constructor
Team166SensorTest::Team166SensorTest(void)
{
	Start((char *)"166SensorTestTask", SENSORTEST_CYCLE_TIME);	
};
	
// Sensor test task destructor
Team166SensorTest::~Team166SensorTest(void)
{		
	return;
};
	
// Main function of the sensor test task
int Team166SensorTest::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	Robot166 *lHandle;  // Local handle
	
	

#if 0	
	AnalogChannel ac4(1,1);       // Ultrasound sensor
	AnalogChannel ac5(1,3);       // Pot
#endif	
	
	
#define UMAX (10)
#if 0
	INT16 gval[2];                // Gyro value
	INT16 csensor;                // Current sensor
	INT16 uval[UMAX];             // Ultrasound value
	int uidx = 0;                 // Index into array
	float dist;                   // Distance
	unsigned int aavg;
	int al;
	float cvolt;
	INT16 pot;                    // Pot value
#endif
	
	// Let the world know we're in
	printf("In the 166 sensor test task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	
    // General main loop (while in Autonomous or Tele mode)
	printf("Sensor test task is getting ready...\n");
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		
		lHandle->GetBatteryVoltage();
#if 0		
		// Pick up the value of the pot
		pot = ac5.GetValue();
		printf("Current pot value: %d\n", pot);
#endif
		
		
#if 0
		
        // Pick up Ultrasound values
        uval[(uidx++ % UMAX)] = ac4.GetValue();
        
        // Compute an average
        aavg = 0;
        for (al=0; al<UMAX; al++)
        	aavg += uval[al];
        dist = (((aavg / UMAX) * (20.0 / 4.096)) / 10.0) * 2.54;
        if (!(uidx % UMAX))
        	printf("Current Ultrasound value: %f\n", dist);
#endif
		
		// Wait for our next lap
		WaitForNextLoop();		
	}
	return (0);
}
