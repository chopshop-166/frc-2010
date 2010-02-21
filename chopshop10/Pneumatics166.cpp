/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Pneumatics166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code which controls the pneumatics
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "Team166Task.h"
#include "Proxy166.h"
#include "Pneumatics166.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;               // Time of snapshot
	// Any values that need to be logged go here
};

//  Memory Log
class PneumaticsLog : public MemoryLog166
{
public:
	PneumaticsLog() : MemoryLog166(sizeof(struct abuf166), PNEUMATICS_CYCLE_TIME, "pneumatics") {return;};
	~PneumaticsLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(void);        // Log the values needed-add in arguments
};

// Write one buffer into memory
unsigned int PneumaticsLog::PutOne(void)
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
unsigned int PneumaticsLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u\n", ab->tp.tv_sec, ab->tp.tv_nsec); // Add values here
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Pneumatics166::Pneumatics166(void)
{
	Start((char *)"166PneumaticsTask", PNEUMATICS_CYCLE_TIME);
	return;
};
	
// task destructor
Pneumatics166::~Pneumatics166(void)
{
	return;
};
	
// Main function of the task
int Pneumatics166::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	// TODO: THE VARS LIVE HERE!!!!!!!!!!
	Proxy166 *proxy;	                            // Get handle for joystick
	Robot166 *lHandle;                              // Local handle
	PneumaticsLog sl;                               // Pneumatics log
	DigitalInput PressureSwitch(T166_PNEUMATIC_PRESSURE_SWITCH); // Pressure switch
	Relay CompressorSpike(T166_COMPRESSOR_RELAY_CHANNEL,Relay::kForwardOnly);   // Compressor spike
	int CompressorOn = 0;                           // Compressor state
	AnalogChannel ps(T166_PNEU_MOD,TI66_PNEU_PRESS);// Pressure sensor
	float pressure;                                 // Pressure from a/d converter
	int opressure;                                  // Trimmed to 0.5v to 4.5v
	float ppressure;                                // Pressure converted to psi
	enum {UNKNOWN, FILL, DRAIN} pState = UNKNOWN;   // Pressure state
	float low_pressure = T166_PNEU_LOW;             // Low pressure limit
	float high_pressure = T166_PNEU_HIGH;           // High pressure limit
	int doprint = 0;
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 Pneumatics task\n");
	
	// Wait for Robot go-ahead (e.g. entering Autonomous or Tele-operated mode)
	WaitForGoAhead();
	
	// Register our logger
	lHandle = Robot166::getInstance();
	lHandle->RegisterLogger(&sl);	


	// Get handle to main Proxy166
	proxy = Proxy166::getInstance();
	
	//int printstop=0;
    // General main loop (while in Autonomous or Tele mode)
	while ((lHandle->RobotMode == T166_AUTONOMOUS) || 
			(lHandle->RobotMode == T166_OPERATOR)) {
		

		// Capture the pressure as seen by the A/D converter
		pressure = opressure = ps.GetValue();
		
		// If the value is below acceptable range, assume minimum value
		if (pressure < 102.4) {  // Below 0.5V?
			pressure = 102.4;    // Yes, set to 0.5V
		} else {
			if (pressure >= 921.6) // 4.5V or greater?
				pressure = 921.6;
		}
		
		// Adjust for a base of 0.5v
		pressure -= 102.4;
		
		// Convert a/d input to psi measurement
        ppressure = (pressure*256)/819.2;
        
        // Update the pressure value in the proxy
        proxy->SetPressure(ppressure);
    	
        // Print various values for debugging
		if ((doprint++ %40) == 0)
			DPRINTF(LOG_DEBUG, "Pressure switch value: %d %d \n   Orig: %d Trim: %f Psi: %f\n",
					PressureSwitch.Get(), CompressorOn, opressure, pressure, ppressure);
		
        // Decide what we need to do now
        switch (pState) {
        
        // We do not know what the pressure is yet. Figure that out first.
        case UNKNOWN:
        {
        	// Do we have enough pressure already?
        	if (ppressure < high_pressure) {
        		
        		// No, we need to start by filling the tank(s)
        		pState = FILL;
        	} else {
        		
        		// Yes, we're good to go right away
        		pState = DRAIN;
        	}
        	
        	// We're done
        	break;
        }
        
        // We need more pressure. Keep filling.
        case FILL:
        {
        	
        	// We need to fill the tank(s). Is the compressor on already?
			if (!CompressorOn)
			{
				// The compressor is off, now let's turn it on
				// Say we are turning on the compressor
				DPRINTF(LOG_DEBUG, "Turning on the compressor!!\n");
				
				// Turn the compressor on
				CompressorSpike.Set(Relay::kOn);
				
				// Remember that the compressor is on
				CompressorOn = 1;
			}
			
			// Have we reached our target pressure?
			if (ppressure >= high_pressure) {
				
				// Yes. We can let it drain now
				pState = DRAIN;
			}
			
			// Done
			break;
        }
        
        // We have enough pressure. Just keep using it.
        case DRAIN:
        {
			// Is the compressor on?
			if (CompressorOn){
				
				DPRINTF(LOG_DEBUG, "Turning off the compressor!!\n");
				
				// Yes compressor is on: turn it off
				CompressorSpike.Set(Relay::kOff);
				
				// Remember we have turned off the compressor
				CompressorOn = 0;
			}
			
			// Have we gone down too far?
			if (ppressure <= low_pressure) {
				
				// Yes. We need more air
				pState = FILL;
			}
			
			// Done
			break;
        }
        }
        
                
#if 0	
		if ((doprint++ %40) == 0)
			DPRINTF(LOG_DEBUG, "Pressure switch value: %d %d \n   Orig: %d Trim: %d Psi: %f\n", PressureSwitch.Get(), CompressorOn, opressure, pressure, ppressure);
		
		// Should we turn off the compressor?
		if (!PressureSwitch.Get())
		{
			//The pressure is low: turn on the compressor if it isn't on already
			//DPRINTF(LOG_DEBUG, "The pressure is low.\n");
			
			// Is the compressor off?
			if (!CompressorOn)
			{
				// The compressor is off, now let's turn it on
				// Say we are turning on the compressor
				DPRINTF(LOG_DEBUG, "Turning on the compressor!!\n");
				
				// Turn the compressor on
				CompressorSpike.Set(Relay::kOn);
				
				// Remember that the compressor is on
				CompressorOn = 1;
			}
		}
		else
		{
			//The pressure is fine: turn off the compressor if it isn't on already
			//DPRINTF(LOG_DEBUG, "The pressure is fine.\n");
						
			// Is the compressor on?
			if (CompressorOn){
				
				DPRINTF(LOG_DEBUG, "Turning off the compressor!!\n");
				
				// Yes compressor is on: turn it off
				CompressorSpike.Set(Relay::kOff);
				
				// Remember we have turned off the compressor
				CompressorOn = 0;
			}
		}
		
		if ((++printstop)%(1000/KICKER_CYCLE_TIME)==0)
		{
			DPRINTF(LOG_DEBUG, "%d, %d", Cocked, proxy->GetButton(3,1));
		}
#endif	
		
        // Logging any values
		sl.PutOne();
		
		// Wait for our next lap
		WaitForNextLoop();		
	}
	return (0);
	
};
