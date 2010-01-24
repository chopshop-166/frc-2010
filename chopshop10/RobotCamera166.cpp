/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: RobotCamera166.cpp     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Calls to get camera information
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "BaeUtilities.h"
#include "RobotCamera166.h"

// needed for Camera Init
#include "AxisCamera.h" 
#include "FrcError.h"
#include "PCVideoServer.h"
#include "VisionAPI.h"

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf
	
/** 
 * start the CameraTask 
 **/
void StartPCVideoServer()	
{	 
	/* start the PCVideoServer to use the dashboard video */
	//PCVideoServer pc;
}

/** 
 * start the CameraTask 
 **/
void StartCamera()	
{	 
	/* read a configuration file and send it to the camera	 */
	char *imageName = "166StartPic.png";
	char* cameraConfigFile = "166Camera.txt"; 
	char outputString[1024]; 
	
	if (StartCameraTask(15, 0, k160x120, ROT_180) == -1) {
		DPRINTF( LOG_ERROR,"Failed to spawn camera task; exiting. Error code %s", 
				GetVisionErrorText(GetLastVisionError()) );	
	}
		
	/* Calling processFile with 3rd argument 0 returns number of configuration lines */
	int lineCountMax = processFile(cameraConfigFile, outputString,0);
	if (lineCountMax == -1) {
			DPRINTF (LOG_DEBUG, "error reading %s",cameraConfigFile);
	} else {
		for (int index = 1;index <= lineCountMax;index++)
		{
			/* calling processFile with line number returns that configuration line */
			if (processFile(cameraConfigFile, outputString, index) != -1) {
				DPRINTF (LOG_DEBUG, "OUTPUT STRING:%s\n",outputString);
				SetupCamera(outputString);
			}
		}
	}
	TakeSnapshot(imageName);
}


/** 
 * Pass to the camera the configuration string and store an image on the cRIO 
 * @param imageName stored on home directory of cRIO ( "/" )
 **/
void TakeSnapshot(char* imageName)	
{	
	DPRINTF(LOG_DEBUG, "taking a SNAPSHOT ");
	Image* cameraImage = frcCreateImage(IMAQ_IMAGE_HSL);
	if (!cameraImage) {
		DPRINTF (LOG_INFO,"frcCreateImage failed - errorcode %i",GetLastVisionError()); 
	}
	Wait(1.0);
	if ( !GetImage (cameraImage,NULL) ) {
		DPRINTF (LOG_INFO,"\nCamera Acquisition failed %i", GetLastVisionError());
	} else { 
		  if (!frcWriteImage(cameraImage, imageName) ) { 
			  DPRINTF (LOG_INFO,"frcWriteImage failed - errorcode %i",GetLastVisionError());
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
 **/
void SetupCamera(char* configString)	
{
	StopCameraTask();	
	ConfigureCamera(configString);
	Wait(0.5);
	/* start the CameraTask -keep this here for now, maybe move to Vision166 later  */
	if (StartCameraTask(15, 0, k160x120, ROT_180) == -1) {
		DPRINTF( LOG_ERROR,"Failed to spawn camera task; exiting. Error code %s", 
				GetVisionErrorText(GetLastVisionError()) );
	}
	Wait(2.0);
	/* this will take one picture and save it to a file
	 */
	DPRINTF(LOG_DEBUG, "taking a SNAPSHOT ");
	TakeSnapshot("Startup");
}


