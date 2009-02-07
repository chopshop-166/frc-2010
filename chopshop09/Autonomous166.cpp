#include "WPILib.h" 
#include "Autonomous166.h"
#include "Timer.h"
#include "BaeUtilities.h"
#include "Vision166.h"
#include "Robot166.h"
#include "Sonar166.h"


// Get access to vision related things
#if 1
extern Team166Vision Team166VisionObject;
#else //this doesn't work yet
class Team166Vision
{
public:
	Team166Vision(void)
	{
		bearing = 0.0;
		return;
	};
	~Team166Vision(void) {return;};
     // target bearing
    float bearing;
};
 Team166VisionObject;
 	Team166Vision(void)
 	{
 		return bearing;
 	}
#endif




autonomous166::autonomous166(void):
	first_time(0),
	past_time(0),
	check_time(.025),
	archived_y(0),
	archived_distance(0),
	drop_distance(0),
	activate_drop(0)
	
{
	
	// Initialize key members
	camera_perspective = T166_UNKNOWND;
	sonar_perspectve = T166_UNKNOWND;
	

	
}

void autonomous166::autonomous_main(void)
{
	Robot166 *lhandle;
	lhandle=Robot166::getInstance();
	int difference_camera;        // difference between last picture's height and current picutre's height
	float difference_ultrasonic;  // difference between last ultrasonic value and current ultrasonic value
	float y;                      // the wishing speed for the robot
	float x;                      // the wishing bearing for the robot
	
	
	
	
	
  if(Team166VisionObject.IsTargetAcquired())
  {
	  
	
	  difference_camera=tracking();
	if(difference_camera>0)
		{
			camera_perspective = T166_AWAY;
		}
	else if(difference_camera<=0)
		{
			camera_perspective=T166_CLOSER;
		}
	
	difference_ultrasonic=ultrasonic();
	
	if(difference_ultrasonic<=0)
			{
				sonar_perspectve=T166_AWAY;
			}
		else if(difference_ultrasonic>0)
			{
				sonar_perspectve=T166_CLOSER;
			}
	if(camera_perspective != sonar_perspectve)
		{
			if(camera_perspective==T166_AWAY)
				{
					y = y+(y*.10);
				}
			else if(camera_perspective==T166_CLOSER)
				{
					y = y-(y*.10);
				}
		}
	else
		{
			y = (difference_ultrasonic/check_time);
			if((archived_y <= y) && (archived_distance > drop_distance))
			{
				y = y+((difference_ultrasonic/check_time)*.10);
				activate_drop=0;
				
			}
			else if(archived_distance <= drop_distance)
			{
				activate_drop=1;
			}
			archived_y = y;
		}
			
			
				
	  x = Team166VisionObject.GetBearing(); //gets the position of the servo from the vision task
	  lhandle->SetJoyStick(x,y);
				
  }	
  else
  {
	  if(target_acquisition())
	  {
		  x = -0.5;
		  y = 0.5;
		  lhandle->SetJoyStick(x,y);
	  }
	  else
	  {
		  x = 0.5;
		  y = 0.5;
		  lhandle->SetJoyStick(x,y);
	  }
  }
			
			
}
	

int autonomous166::tracking(void)
{
	int current_image_height=0;    // the new height of the target
	int difference_camera;         // the difference between the target's previous height and its current height
	if(first_time==0)                // if the camera has not submitted a target yet      
		{
			archived_image_height = Team166VisionObject.GetTargetHeight();   // get the first archived image height
			difference_camera = archived_image_height;                 // set the difference as positive
			first_time=1;                                              // end the first time call
		}
	else
		{
			current_image_height = Team166VisionObject.GetTargetHeight();           // get the latest image height 
			difference_camera = archived_image_height-current_image_height;   // find the difference between the old height and the lastest height
			archived_image_height = current_image_height;                     // set the new base height
		}
	return difference_camera;                                                 // return the difference value
	
}

bool autonomous166::target_acquisition(void)
{
	double current_time=0;
	bool direction;
	
	current_time = GetTime();
	
	if(past_time==0)
	{
		past_time=current_time;
	}
	
	if(past_time-current_time>=5)
	{
		if(past_time-current_time>=10)
		{
			past_time=current_time;
		}
		else
		{
			direction = 1;
		}
	}
	else
	{
		direction=0;
	}
	
	return direction;
}

float autonomous166::ultrasonic (void)
{
	float current_distance=0;                                // the distance the target is from the robot
	float ultra_differance;                                  // the differance between the last distance and the current distance
	
	//current_distance = GetDistance();                        // get the distance from the ultrasonic class
	ultra_differance = archived_distance-current_distance;   // calculate the differance 
	archived_distance = current_distance;                    // reset the archived distance
	
	return ultra_differance;                                 // return the differance
}
	
	
