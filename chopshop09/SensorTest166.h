#if !defined(_SENSORTEST166_H)
#define _SENSORTEST166_H
#include "WPILib.h"
#include "Robot166.h"
#include "semLib.h"

//
// This defines a sample sensor test task
//
class Team166SensorTest : public Team166Task
{
	
public:
	
	// Sensor test task constructor
	Team166SensorTest(void);
	
	// Sensor Test task destructor
	virtual ~Team166SensorTest(void);
	
	// Main function of the sensor testtask
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
	
};
#endif // !defined(_SENSORTEST166_H)
