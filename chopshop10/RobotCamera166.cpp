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
#include "AxisCamera2010.h" 
#include "FrcError.h"
#include "PCVideoServer.h"
#include "nivision.h" 

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Create storage space for camera
AxisCamera *camera166 = 0;
// Camera setup parameters go here
// Image size (larger images take longer to process)
ResolutionT resolution = k160x120;  // k640x480, k640x360, k320x240, k160x120
// Use rotation of 180 if camera is mounted updside down
RotationT rotation = k0;   // k0, k180

/** 
 * start the CameraTask 
 **/
void StartCamera()	
{	 
	/* read a configuration file and send it to the camera	 */
	char *imageName = "166StartPic.png";

	//camera166 = AxisCamera::getInstance();
	camera166 = &AxisCamera::getInstance();
	if ( !camera166->isInstance() ) {
		DPRINTF( LOG_DEBUG,"Failed to spawn camera task; exiting. Error code %s", 
				GetVisionErrorText(GetLastVisionError()) );	
	} else {
        SetupCamera(resolution, rotation);
		TakeSnapshot(imageName);
	}
}


/** 
 * Get an image from camera and store it on the cRIO 
 * @param imageName stored on home directory of cRIO ( "/" )
 **/
void TakeSnapshot(char* imageName)	
{	
	/* allow writing to vxWorks target */
	Priv_SetWriteFileAllowed(1);   	
	
	DPRINTF(LOG_DEBUG, "taking a SNAPSHOT ");
	Image* cameraImage = frcCreateImage(IMAQ_IMAGE_HSL);
	if (!cameraImage) {
		DPRINTF (LOG_INFO,"frcCreateImage failed - errorcode %i",GetLastVisionError()); 
	}
	
	if ( !camera166->GetImage(cameraImage) ) {
		DPRINTF (LOG_INFO,"\nImage Acquisition from camera failed %i", GetLastVisionError());
	} else { 
		DPRINTF (LOG_DEBUG, "calling frcWriteImage for %s", imageName);
		if (!frcWriteImage(cameraImage, imageName) ) { 
			int errCode = GetLastVisionError();
			DPRINTF (LOG_INFO,"frcWriteImage failed - errorcode %i", errCode);
			char *errString = GetVisionErrorText(errCode);
			DPRINTF (LOG_INFO,"errString= %s", errString);
		} else { 
			DPRINTF (LOG_INFO,"\n>>>>> Saved image to %s", imageName);	
			// always dispose of image objects when done
			frcDispose(cameraImage);
		}
	}
}


/** 
 * Pass to the camera the configuration settings and store an image on the cRIO 
 * @param ResolutionT camera resolution 
 * @param RotationT camera rotation (k0, k180) 
 **/
void SetupCamera(ResolutionT res, RotationT rot)	
{
	camera166->writeResolution(res);
	camera166->writeRotation(rot);
}

void DriveTowardsTarget() {
	
}

