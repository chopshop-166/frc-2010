/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: HealthMon166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 23, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Code which monitors health of system
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "Team166Task.h"
#include "HealthMon166.h"
#include "MemoryLog166.h"
#include "Robot166.h"
#include "BaeUtilities.h"
#include "CANJaguar.h"
#include "Vision166.h"
#include "CANDrive166.h"



// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	float x_acc;                     // accelarometer x value
	float y_acc;					//  accelarometer y value
	float acc_vector;
	
};

//  Memory Log
class HealthMonLog : public MemoryLog166
{
public:
	HealthMonLog() : MemoryLog166(sizeof(struct abuf166), HEALTHMON_CYCLE_TIME, "health_monitor") {return;};
	~HealthMonLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float x_acc, float y_acc, float acc_vector);     // Log the x and y values
};

// Write one buffer into memory
unsigned int HealthMonLog::PutOne(float x_acc, float y_acc, float acc_vector)
{
	struct abuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct abuf166 *)GetNextBuffer(sizeof(struct abuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		ob->x_acc = x_acc;
		ob->y_acc = y_acc;
		ob->acc_vector = acc_vector;
		return (sizeof(struct abuf166));
	}
	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int HealthMonLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f, %f, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->x_acc, ab->y_acc, ab->acc_vector);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166HealthMon::Team166HealthMon(void)
{
	Start((char *)"166HealthMonTask", HEALTHMON_CYCLE_TIME);
	MyTaskIsEssential=false;
	return;
};
	
// task destructor
Team166HealthMon::~Team166HealthMon(void)
{
	return;
};
	
// Main function of the task
int Team166HealthMon::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
		
	bool CameraStatus;
	//bool BannerStatus;
	//bool Health_CameraStatus;
	bool Health_InclinometerStatus;
	
	
	
	Robot166 *lHandle;            // Local handle
	Proxy166 *proxy;              // Local proxy handle
	HealthMonLog sl;                   // log
	Team166CANDrive *canDrive;
	
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 HealthMon task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register the Proxy
	proxy = Proxy166::getInstance();
	
	CameraStatus = Team166VisionObject.IsActive();
	string healthErrors;
	canDrive = Team166CANDrive::getInstance();
	
	float JaguarCurrentStatus3;
	
	float JoystickPosition;
	float SonarStatus;
	int Health_Status;
	bool Health_SonarStatus;
	int InclinometerStatus;
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);
	char* buffer = new char[DASHBOARD_BUFFER_MAX];
	
	/*if(CameraStatus==true){
		lHandle->Robot166::DriverStationDisplay("Camera Active");
		Health_CameraStatus = true;
	} else {
		lHandle->Robot166::DriverStationDisplay("Camera not Active");
		Health_CameraStatus = false;
	}
	*/
	
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {

		
		//getting new statuses every time
		
		SonarStatus = proxy->GetSonarDistance();
		
		InclinometerStatus = proxy->GetInclinometer();
		
		JaguarCurrentStatus3 = proxy->GetCurrent(3);
		
		JoystickPosition = proxy->GetJoystickY(2);
		
		//Determining Inclinometer Status
		//Reserved for if we need it
		
		/*
		 * if(InclinometerStatus==0){
			// lHandle->Robot166::DriverStationDisplay("Inclinometer is 0");
			Health_InclinometerStatus = true;
		}
		else if(InclinometerStatus!=0){
			// lHandle->Robot166::DriverStationDisplay("Inclinometer changed");
			Health_InclinometerStatus = false;
			
		}
		*/
		
		//Determining the Sonar Health
		
		if(SonarStatus>5){
			Health_SonarStatus = true;
		}
		
		else if(SonarStatus<1){
			Health_SonarStatus = false;
		}

		
		//Total Health Status things
		Health_Status = Health_SonarStatus;
		
		
		
		/*if(Health_Status==2){
			lHandle->Robot166::DriverStationDisplay("Hlth: 100%%");
		}
		*/
		if(Health_Status==1){
			lHandle->Robot166::DriverStationDisplay("Hlth: 100%%");
			
			
			
			/*
			if(Health_SonarStatus==false){
				healthErrors += "no sonar, ";
			}
			if(Health_InclinometerStatus==false){
				healthErrors += "incline, ";
			}
			sprintf(buffer,"Errors: %s",healthErrors.c_str());
			lHandle->DriverStationDisplay(buffer);
			
			
			*/
		}
		else if(Health_Status==0){
			lHandle->DriverStationDisplay("Hlth: 0%%");
			
			if(Health_SonarStatus==false){
							healthErrors += "no sonar, ";
						}
			if(Health_InclinometerStatus==false){
							healthErrors += "incline, ";
						}
			sprintf(buffer,"Errors: %s",healthErrors.c_str());
			lHandle->DriverStationDisplay(buffer);
		}
		else{
			lHandle->DriverStationDisplay("HealthMon error");
		}
		
		DPRINTF(LOG_DEBUG,"%f",JaguarCurrentStatus3);
		
		// do stuff
		sl.PutOne(0, 0, 0);
		WaitForNextLoop();
	}
	return (0);
	
};
