/********************************************************************************
*  Project   		: FIRST Motor Controller
*  File Name  		: CameraDemo.cpp        
*  Contributors 	: ELF
*  Creation Date 	: Jan 20, 2009
*  Revision History	: Source code & revision history maintained at sourceforge.WPI.edu   
*  File Description	: Demo program showing color tracking
*/                         
/*----------------------------------------------------------------------------*/
/*        Copyright (c) FIRST 2008.  All Rights Reserved.                     */
/*  Open Source Software - may be modified and shared by FRC teams. The code  */
/*  must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib. */
/*----------------------------------------------------------------------------*/

#include <iostream.h>
#include "math.h"

#include "AxisCamera.h" 
#include "BaeUtilities.h"
#include "FrcError.h" 
#include "VisionAPI.h"
#include "WPILib.h"

// To locally enable debug printing: set true, to disable set false
#define DPRINTF if(true)dprintf

/**
 * This is a demo program showing how to set and retrieve settings on the camera.
 * It uses the SimpleRobot class as a base and executes the requested camera 
 * configuration commands as selected by "va" in the Autonomous state.

Possible values for va:
SNAPSHOT;
    Takes an image from the camera with its current configuration. 
    It is stored as "defalut.png" file on the root directory of 
    the cRIO. You can retrieve it using ftp, and use an image 
    viewer or the NI Vision Assistant to analyze the color values.
RESET; 	
	Set camera settings back to a known default. You should 
	run this after playing with the camera settings. If you 
	want to change the defaults you can modify the values here. 
	The defaults provided here are the same	as the out-of-the-box 
	camera defaults with the exception of white balance	which is 
	changed from auto to fixed fluorescent 1, and brightness which 
	is changed from 50 to 35. These are values which work well in 
	many school environments. 
CONFIG_BRIGHTNESS; 	
	Set camera brightness to several values in the brightness  
	range (0-100) and take a snapshot of each one.
CONFIG_WHITEBALANCE; 
	Set camera white balance to each possible value 
	and take a snapshot of each one.
CONFIG_EXPOSURE; 
	Set camera exposure to each possible value 
	and take a snapshot of each one.
CONFIG_EXPOSURE_PRIORITY; 
	Set camera exposure priority to each possible value 
	and take a snapshot of each one.
CONFIG_COLOR_LEVEL; 
	Set camera color level to several values in the color level  
	range (0-100) and take a snapshot of each one.
CONFIG_SHARPNESS; 
	Set camera sharpness to several values in the sharpness 
	range (0-100) and take a snapshot of each one.
GET_CAMERA_CONFIG; 	
	This queries the camera and prints to the console 
	the following properties of the camera:
	Sensor Properties: Brightness, White Balance, Exposure, 
		Exposure Priority, Color Level, Sharpness
	Image Properties: Resolution, Compression, Rotation	
READ_FILE; 		
	Uses the utility ProcessFile to obtain camera configuration settings
	from a file called "cameraConfig.txt" on the cRIO. This configuration 
	is then set on the camera. To verify, the configuration is queried 
	and an image is taken.
	
	ProcessFile is called the first time with 0 lineNumber to get the 
	number of lines to read. On subsequent calls each lineNumber is requested
	to get one camera parameter. There should be one property=value entry on 
	each line, i.e. "exposure=auto"	
	
	A sample cameraConfig.txt file is included with this project. Note that
	it must be ftp'd to the root directory of the cRIO for this feature to work.

 */
class CameraDemo : public SimpleRobot
{
	RobotDrive *myRobot;			// robot drive system
	Joystick *rightStick;			// joystick 1 (arcade stick or right tank stick)
	Joystick *leftStick;			// joystick 2 (tank left stick)
	DriverStation *ds;				// driver station object
	float mySpeed;					// drive tasking
	float driveDirection;			// drive tasking
	float driveSpeed;				// drivedrive tasking	
	
	/** Possible white balance values that you can set on the camera.	*/
	enum WhiteBalance {
	    kAutoWhiteBalance,
	    kFixedIndoor,
	    kFixedOutdoor1,
	    kFixedOutdoor2,
	    kFixedFluo1,
	    kFixedFluor2,
	    kHoldWhiteBalance
	};

    /** Possible exposure values that you can set on the camera.    */
    enum Exposure {
        kAutoExposure,
        kFlickerFree50,
        kFlickerFree60,
        kManual,
        kHoldExposure,
    };

	enum visionAction {	RESET,					// set to known good paramteters
						CONFIG_BRIGHTNESS, 
						CONFIG_WHITEBALANCE, 
						CONFIG_EXPOSURE,
						CONFIG_EXPOSURE_PRIORITY,
						CONFIG_COLOR_LEVEL,
						CONFIG_SHARPNESS,
						READ_FILE, 				// TODO: read a camera settings file
						GET_CAMERA_CONFIG,
						SNAPSHOT};
	
	enum							// Driver Station jumpers to control program operation
	{ ARCADE_MODE = 1,				// Tank/Arcade jumper is on DS Input 1 (Jumper present is arcade)
	  ENABLE_AUTONOMOUS = 2,		// Autonomous/Teleop jumper is on DS Input 2 (Jumper present is autonomous)
	} jumpers;	                            

public:
	/**
	 * Constructor for this robot subclass.
	 * Create an instance of a RobotDrive with left and right motors plugged into PWM
	 * ports 1 and 2 on the first digital module.
	 */
	CameraDemo(void) 
	{
		ds = DriverStation::GetInstance();
		myRobot = new RobotDrive(1, 2, 0.5);	// robot will use PWM 1-2 for drive motors
		rightStick = new Joystick(1);			// create the joysticks
		leftStick = new Joystick(2);
		/* drive paramters */
		mySpeed = 1.0;							// this may be fast - watch where you stand!
		driveDirection = 0.0;					// tasking
		driveSpeed = 0.0;						// tasking	

		/* set up debug output: 
		 * DEBUG_OFF, DEBUG_MOSTLY_OFF, DEBUG_SCREEN_ONLY, DEBUG_FILE_ONLY, DEBUG_SCREEN_AND_FILE 
		 */
		SetDebugFlag ( DEBUG_SCREEN_ONLY  ) ;		
		/* allow writing to vxWorks target */
		Priv_SetWriteFileAllowed(1);   	
		/* stop the watchdog - there are long delays here to allow for camera reset  */
		GetWatchdog().SetEnabled(false);
	}

	/** 
	 * Store an image on the cRIO 
	 * @param imageName stored on home directory of cRIO ( "/" )
	 **/
	void snapshot(char* imageName)	
	{
		/* this will take one picture and save it to a file
		 */
		DPRINTF(LOG_DEBUG, "taking a SNAPSHOT ");
		Image* cameraImage = frcCreateImage(IMAQ_IMAGE_HSL);
		if (!cameraImage) {
			dprintf (LOG_INFO,"frcCreateImage failed - errorcode %i",GetLastVisionError()); 
		}
		Wait(1.0);
		if ( !GetImage (cameraImage,NULL) ) {
			  dprintf (LOG_INFO,"\nCamera Acquisition failed %i", GetLastVisionError());
		} else { 
			  if (!frcWriteImage(cameraImage, imageName) ) { 
					dprintf (LOG_INFO,"frcWriteImage failed - errorcode %i",GetLastVisionError());
			  } else { 
				  	dprintf (LOG_INFO,"\n>>>>> Saved image to %s", imageName);	
					// always dispose of image objects when done
					frcDispose(cameraImage);
			  }
		}
	}

	/** 
	 * Pass to the camera the configuration string and store an image on the cRIO 
	 * @param configString camera configuration string 
	 * @param imageName stored on home directory of cRIO ( "/" )
	 **/
	void configureCameraAndTakeSnapshot(char* configString, char* imageName)	
	{
		StopCameraTask();	
		ConfigureCamera(configString);
		Wait(0.5);
		/* start the CameraTask	 */
		if (StartCameraTask(10, 0, k160x120, ROT_0) == -1) {
			dprintf( LOG_ERROR,"Failed to spawn camera task; Error code %i", 
					GetVisionErrorText(GetLastVisionError()) );
		} 
		Wait(4.0);
		snapshot(imageName);
	}
	
	void Autonomous(void)
	{
		DPRINTF(LOG_DEBUG, "start Autonomous");	

		/* Here is where to select the action you want, 
		 * as documented in the header */
		visionAction va = RESET; 		
		//visionAction va = CONFIG_BRIGHTNESS; 	
		//visionAction va = CONFIG_WHITEBALANCE; 
		//visionAction va = CONFIG_EXPOSURE; 
		//visionAction va = CONFIG_EXPOSURE_PRIORITY; 
		//visionAction va = CONFIG_COLOR_LEVEL; 
		//visionAction va = CONFIG_SHARPNESS; 
		//visionAction va = READ_FILE; 		
		//visionAction va = GET_CAMERA_CONFIG; 
		
		// parameters for taking a snapshot
		// Puts image a root directory. If another directory is used
		// it must exist on the cRIO.
		char* imageName = "/default.png"; 

		// file name for the camera configuration file on the cRIO
		char* cameraConfigFile = "cameraConfig.txt"; 
		char outputString[1024]; 
		
		// data for testing camera settings		
		int testCount = 0;
		char configString[1024];
		char responseString[1024];

		int numBrightnessValues = 5;				// number of settings for brightness
		//int brightness[] = {95,80,65,35,15,5};		// brightness ranges from 0-100
		int brightness[] = {0,25,50,75,99};		// brightness ranges from 0-100 default 50

		int numWhiteBalanceValues = 7;			// number of settings for white balance
		char *whiteBalanceValueNames[] = {		// Possible white balance values - default auto
			"fixed_indoor",
			"fixed_outdoor1",
			"fixed_outdoor2",
			"fixed_fluor1",
			"fixed_fluor2",
			"hold",
			"auto"
		};

		int numExposureValues = 5;				// number of settings for exposure
		char *exposureValueNames[] = {			// Possible exposure values - default auto
			"flickerfree50",
			"flickerfree60",
			"manual",
			"hold",
			"auto"
		};

		int numExposurePriorityValues = 5;				// number of settings for exposure priority
		int exposurePriorityValues[] = {0,25,50,75,100};// range 1-100 default 50

		int numColorLevelValues = 5;					// number of settings for color level
		int colorLevelValues[] = {0,25,50,75,100};		// range 1-100 default 50
		
		int numSharpnessValues = 5;						// number of settings for sharpness
		int sharpnessValues[] = {100,75,50,25,0};		// range 1-100 default 0
		
		int lineCountMax;
		int index;
				
		int cont = 1;
		while( 	(IsAutonomous()) && cont )	
		{		
		 	switch (va) {

		 		case RESET:
		 			// set sensor properties to a specific configuration
		 			// (image appearance properties are set 
		 			//  when StartCameraTask() is called)
					StopCameraTask();	
					
					DPRINTF(LOG_INFO, "setting BRIGHTNESS to 35 ");
					ConfigureCamera("brightness=35");
					DPRINTF(LOG_INFO, "setting WHITE BALANCE to fixed_fluor1 ");
					ConfigureCamera("whitebalance=fixed_fluor1");
					DPRINTF(LOG_INFO, "setting EXPOSURE to auto ");
					ConfigureCamera("exposure=auto");
					DPRINTF(LOG_INFO, "setting EXPOSURE PRIORITY to auto ");
					ConfigureCamera("exposurepriority=50");
					DPRINTF(LOG_INFO, "setting COLOR LEVEL to 50 ");
					ConfigureCamera("colorlevel=50");
					DPRINTF(LOG_INFO, "setting SHARPNESS to 0 ");
					ConfigureCamera("sharpness=0");
					cont = 0;
		 			break;
		 			
				case CONFIG_BRIGHTNESS:
					// Reconfigure camera for next test
					if (testCount < numBrightnessValues)  {
						sprintf(imageName, "cam_brightness_%i.png",brightness[testCount]);
						sprintf (configString, "brightness=%i",	brightness[testCount]);
						configureCameraAndTakeSnapshot(configString, imageName);
						testCount++;
						cont = 1;
					} else {	cont = 0;		}
					break;

				case CONFIG_WHITEBALANCE:
					if (testCount < numWhiteBalanceValues)  {
						sprintf(imageName, "cam_whtbal_%s.png",whiteBalanceValueNames[testCount]);
						sprintf(configString, "whitebalance=%s",whiteBalanceValueNames[testCount]);						
						configureCameraAndTakeSnapshot(configString, imageName);
						testCount++;
						cont = 1;
					} else {	cont = 0;		}
					break;		

				case CONFIG_EXPOSURE:
					if (testCount < numExposureValues)  {
						sprintf(imageName, "cam_exposure_%s.png",exposureValueNames[testCount]);
						sprintf(configString, "exposure=%s",exposureValueNames[testCount]);						
						configureCameraAndTakeSnapshot(configString, imageName);
						testCount++;
						cont = 1;
					} else {	cont = 0;		}
					break;		

				case CONFIG_EXPOSURE_PRIORITY:
					if (testCount < numExposurePriorityValues)  {
						sprintf(imageName, "cam_exposurepriority_%i.png",exposurePriorityValues[testCount]);
						sprintf(configString, "exposurepriority=%i",exposurePriorityValues[testCount]);						
						configureCameraAndTakeSnapshot(configString, imageName);
						testCount++;
						cont = 1;
					} else {	cont = 0;		}
					break;		

				case CONFIG_COLOR_LEVEL:
					if (testCount < numColorLevelValues)  {
						sprintf(imageName, "cam_colorlevel_%i.png",colorLevelValues[testCount]);
						sprintf(configString, "colorlevel=%i",colorLevelValues[testCount]);						
						configureCameraAndTakeSnapshot(configString, imageName);
						testCount++;
						cont = 1;
					} else {	cont = 0;		}
					break;			

				case CONFIG_SHARPNESS:
					if (testCount < numSharpnessValues)  {
						sprintf(imageName, "cam_sharpness_%i.png",sharpnessValues[testCount]);
						sprintf(configString, "sharpness=%i",sharpnessValues[testCount]);						
						configureCameraAndTakeSnapshot(configString, imageName);
						testCount++;
						cont = 1;
					} else {	cont = 0;		}
					break;			

				case GET_CAMERA_CONFIG:			
					bzero(responseString,1024);
					
					// get camera sensor properties
					DPRINTF(LOG_INFO, "Axis - what's BRIGHTNESS ? ");	
					if (GetCameraSetting("brightness", responseString) == -1) {
						dprintf( LOG_ERROR,"Failed to get camera settings; Error code %i", 
								GetVisionErrorText(GetLastVisionError()) );
					} else {DPRINTF(LOG_INFO, "response from Axis: %s", responseString);	}
					
					DPRINTF(LOG_INFO, "Axis - what's WHITE BALANCE ? ");	
					if (GetCameraSetting("whitebalance", responseString) == -1) {
						dprintf( LOG_ERROR,"Failed to get camera settings; Error code %i", 
								GetVisionErrorText(GetLastVisionError()) );
					} else {	DPRINTF(LOG_INFO, "response from Axis: %s", responseString);}
					
					DPRINTF(LOG_INFO, "Axis - what's EXPOSURE ? ");	
					if (GetCameraSetting("exposure", responseString) == -1) {
						dprintf( LOG_ERROR,"Failed to get camera settings; Error code %i", 
								GetVisionErrorText(GetLastVisionError()) );
					} else {DPRINTF(LOG_INFO, "response from Axis: %s", responseString);}

					DPRINTF(LOG_INFO, "Axis - what's EXPOSURE PRIORITY ? ");	
					if (GetCameraSetting("exposurepriority", responseString) == -1) {
						dprintf(LOG_ERROR,"Failed to get camera settings; Error code %i", 
								GetVisionErrorText(GetLastVisionError()) );
					} else {DPRINTF(LOG_INFO, "response from Axis: %s", responseString);}
					
					DPRINTF(LOG_INFO, "Axis - what's COLOR LEVEL ? ");	
					if (GetCameraSetting("colorlevel", responseString) == -1) {
						dprintf( LOG_ERROR,"Failed to get camera settings; Error code %i", 
								GetVisionErrorText(GetLastVisionError()) );
					} else {DPRINTF(LOG_INFO, "response from Axis: %s", responseString);	}

					DPRINTF(LOG_INFO, "Axis - what's SHARPNESS ? ");	
					if (GetCameraSetting("sharpness", responseString) == -1) {
						dprintf( LOG_ERROR,"Failed to get camera settings; Error code %i", 
								GetVisionErrorText(GetLastVisionError()) );
					} else {DPRINTF(LOG_INFO, "response from Axis: %s", responseString);	}

					// get image properties
					DPRINTF(LOG_INFO, "Axis - what's IMAGE SIZE ? ");	
					if (GetImageSetting("resolution", responseString) == -1) {
						dprintf( LOG_ERROR,"Failed to get camera settings; Error code %i", 
								GetVisionErrorText(GetLastVisionError()) );
					} else {DPRINTF(LOG_INFO, "response from Axis: %s", responseString);	}					

					DPRINTF(LOG_DEBUG, "Axis - what's COMPRESSION ? ");	
					if (GetImageSetting("compression", responseString) == -1) {
						dprintf( LOG_ERROR,"Failed to get camera settings; Error code %i", 
								GetVisionErrorText(GetLastVisionError()) );
					} else {DPRINTF(LOG_DEBUG, "response from Axis: %s", responseString);	}					
					
					DPRINTF(LOG_INFO, "Axis - what's ROTATION ? ");	
					if (GetImageSetting("rotation", responseString) == -1) {
						dprintf( LOG_ERROR,"Failed to get camera settings; Error code %i", 
								GetVisionErrorText(GetLastVisionError()) );
					} else {DPRINTF(LOG_INFO, "response from Axis: %s", responseString);	}
					
					cont = 0;					
					break;
										
				case READ_FILE:
					/* read a configuration file and send it to the camera	 */
					imageName = "configImage.png";

					/* Calling processFile with 3rd argument 0 returns number of configuration lines */
					lineCountMax = processFile(cameraConfigFile, outputString,0);
					if (lineCountMax == -1) {
						DPRINTF (LOG_DEBUG, "error reading %s",cameraConfigFile);
					} else {
						for (index = 1;index <= lineCountMax;index++)
						{
							/* calling processFile with line number returns that configuration line */
							if (processFile(cameraConfigFile, outputString, index) != -1) {
								DPRINTF (LOG_DEBUG, "OUTPUT STRING:%s\n",outputString);
								configureCameraAndTakeSnapshot(outputString, imageName);
							}
						}
						va = GET_CAMERA_CONFIG; // display new configuration
					}
					break;

				case SNAPSHOT:
					/* this will take one picture and save it to a file */					
					DPRINTF(LOG_DEBUG, "taking a SNAPSHOT ");
					snapshot(imageName);
					cont = 0;
					break;
					
				default:	
					break;

			}  // end switch
		  
			Wait(0.05);	
			
			
		}  // end while
		
		myRobot->Drive(0.0, 0.0);		// stop robot
		DPRINTF(LOG_DEBUG, "end Autonomous");
		
	}  // end autonomous

	/**
	 * Runs the motors under driver control with either tank or arcade steering selected
	 * by a jumper in DS Digin 0. 
	 */
	void OperatorControl(void)
	{
		DPRINTF(LOG_DEBUG, "OperatorControl");
		//GetWatchdog().Feed();
 
		while ( IsOperatorControl() )
		{
			// determine if tank or arcade mode; default with no jumper is for tank drive
			if (ds->GetDigitalIn(ARCADE_MODE) == 0) {	
				myRobot->TankDrive(leftStick, rightStick);	 // drive with tank style
			} else{
				myRobot->ArcadeDrive(rightStick);	         // drive with arcade style (use right stick)
			}			
		}  
	} // end operator control
	
}; 

// entry point is FRC_UserProgram_StartupLibraryInit
START_ROBOT_CLASS(CameraDemo);

