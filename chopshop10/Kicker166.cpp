/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Kicker166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Robot code which controls the kicker
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "Team166Task.h"
#include "Kicker166.h"
#include "MemoryLog166.h"
#include "Robot166.h"
#include "BaeUtilities.h"
#include "Proxy166.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(true)dprintf

// Sample in memory buffer
struct abuf166
{
	struct timespec tp;              // Time of snapshot
	float x_acc;                     // accelarometer x value
	float y_acc;					 //  accelarometer y value
	float acc_vector;
	
};

// Sample Memory Log
class KickerLog : public MemoryLog166
{
public:
	KickerLog() : MemoryLog166(sizeof(struct abuf166), KICKER_CYCLE_TIME, "kicker") {return;};
	~KickerLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float x_acc, float y_acc, float acc_vector);     // Log the x and y values
};

// Write one buffer into memory
unsigned int KickerLog::PutOne(float x_acc, float y_acc, float acc_vector)
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
unsigned int KickerLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct abuf166 *ab = (struct abuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f, %f, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->x_acc, ab->y_acc, ab->acc_vector);
	
	// Done
	return (sizeof(struct abuf166));
}


// task constructor
Team166Kicker::Team166Kicker(void): Kicker_jag(T166_KICKER_CHANNEL),
	Kicker_Limit_Switch(T166_KICKER_LIMIT_SWITCH)
//	Kick_timer()
{
	Start((char *)"166KickerTask", KICKER_CYCLE_TIME);
	Cocked = Kicker_Limit_Switch.Get();
	Firing = false;
};
	
// task destructor
Team166Kicker::~Team166Kicker(void)
{
	return;
};


// Main function of the task
int Team166Kicker::Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10)
{
	// TODO THE VARS LIVE HERE!!!!!!!!!!
	Proxy166 *proxy;	                            // Get handle for joystick
	Robot166 *lHandle;                              // Local handle
	KickerLog sl;                                   // Arm log
	DigitalInput PressureSwitch(5);                 // Pressure switch
	Relay CompressorSpike(2,Relay::kForwardOnly);   // Compressor spike
	int CompressorOn = 0;                           // Compressor state
	AnalogChannel ps(1,5);                          // Pressure sensor
	Solenoid latchSolenoid(4);                      // Latch solenoid
	Solenoid kickerSolenoid(5);                     // Kicker solenoid
	float pressure;                                 // Pressure from a/d converter
	int opressure;                                  // Trimmed to 0.5v to 4.5v
	float ppressure;                                // Pressure converted to psi
	enum {UNKNOWN, FILL, DRAIN} pState = UNKNOWN;   // Pressure state
	enum {WFP, LATCH, LWAIT, LREL, DSREADY, TRIGGER, KWAIT, KREL} sState = WFP;  // Solenoid state
	float low_pressure = 60.0;                     // Low pressure limit
	float high_pressure = 80.0;                    // High pressure limit
	int doprint = 0;
	int lwait;                                      // Latch release wait counter
    int kwait;                                      // Kicker release wait counter
	
	// Let the world know we're in
	DPRINTF(LOG_DEBUG,"In the 166 Kicker task\n");
	
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
		
		// Get limit switch value
		Cocked = Kicker_Limit_Switch.Get();
		
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
    	
		if ((doprint++ %40) == 0)
			DPRINTF(LOG_DEBUG, "Pressure switch value: %d %d \n   Orig: %d Trim: %f Psi: %f\n",
					PressureSwitch.Get(), CompressorOn, opressure, pressure, ppressure);
		
        // Decide what we need to do
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
        
        
        /*
         *  State machine to control the pistons.
         */
        switch (sState)
        {
        
        // Wait for enough pressure to actuate the pistons.
        case WFP:
        {
        	// Is there enough pressure?
        	if (ppressure < 50.0){
        		
        		// There isn't enough pressure.   :(   Try again later.
        		break;
        	}
        	
        	// There is enough pressure!!   :)   We're done here.
        	// Intentionally fall through to LATCH
        	sState = LATCH;
        	printf("LATCH: Draw the piston back into the latch\n");
        }
        
        // Draw the piston back into the latch
        case LATCH:
        {
        	// Apply pressure to the latching piston
        	latchSolenoid.Set(true);
        	
        	// Initialize the latch wait counter
        	lwait = 0;
        	
        	// Done
        	// Intentionally fall through to LWAIT
        	sState = LWAIT;
        	printf("LWAIT: Wait for latch\n");
        }
        
        // Wait for latch
        case LWAIT:
        {
        	// Have we waited enough loops?
        	if (lwait++ < 10){
        		
        		// We haven't waited long enough.   :(   Let's try again later.
        		break;
        		}
        	
        	// We've waited long enough!!   :D   We're done here.
        	// Intentionally fall through to LREL
        	sState = LREL;
        	printf("LREL: Release the latching piston\n");
        }
        
        // Release the latching piston
        case LREL:
        {
        	// Release pressure from the latching piston
        	latchSolenoid.Set(false);
        	
        	// Done
        	// Intentionally fall through to DSREADY
        	sState = DSREADY;
        	printf("DSREADY: Send a signal to the DS that we're ready to kick\n");
        }
        
        // Send a signal to the driver station to tell we're ready to kick
        case DSREADY:
        {
        	// TODO send a real ready signal to DS
        	printf("We're READY TO KICK !!!!!\n");
        	
        	// Done
        	// Intentionally fall through to TRIGGER
        	sState = TRIGGER;
        	printf("TRIGGER: Wait until the trigger (joy 3 - bttn 4) tells us to kick");
        }
        
        // Wait until the trigger tells us to kick
        case TRIGGER:
        {
        	// Is the trigger asking us to kick?
        	if (proxy->GetButton(3,4,true)){
        		
        		//Pressurize the kicker piston
        		kickerSolenoid.Set(true);
        		
            	// Reset the kicker wait counter
            	kwait = 0;
        		
        		// Done
            	// Intentionally fall through to KWAIT
            	sState = KWAIT;
            	printf("KWAIT: Wait for the kicker");
        	}
        	else{
        		// The trigger isn't asking us to kick yet. Let's try again later.
        		break;
        	}
        }
        
        // Wait for kicker
        case KWAIT:
        {
        	// Have we waited long enough?
        	if (kwait++ < 10){
        		
        		// We haven't waited long enough.   :(    Let's try again later.
        		break;
        	}
        	
        	// We've waited long enough!!   :D    We're done here.
        	// Intentionally fall through to KREL
        	sState = KREL;
        	printf("KREL: Release pressure from the kicker piston");
        }
        
        // Release pressure from kicker piston
        case KREL:
        {
        	// Release pressure from the kicker piston
        	kickerSolenoid.Set(false);
        	
        	// Done
        	// Intentionally fall through - return to WFP
        	sState = WFP;
        	printf("Returning to the WFP state.\n  WFP: Wait for pressure");
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

		//Is the kicker cocked, is the trigger pressed?
		if ((proxy->GetButton(3,1) == true) || Cocked == false)
		{

			// Move motor till limit not pressed
			Kicker_jag.Set(1);
			
		    // Should we log this value?
			sl.PutOne(0, 0, 0);
				
			// Wait for our next lap
			WaitForNextLoop();
			continue;
		}
		
		//Stop motor when the limit switch is pressed
		Kicker_jag.Set(0); 

        // Should we log this value?
		sl.PutOne(0, 0, 0);
		
		// Wait for our next lap
		WaitForNextLoop();
	}
	return (0);
	
};
