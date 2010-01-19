#include "WPILib.h" 
#include "Autonomous166.h"
#include "Timer.h"
#include "BaeUtilities.h"
#include "Vision166.h"
#include "Robot166.h"
#include "Sonar166.h"
#include <math.h>

// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf


// Write one buffer into memory
unsigned int AutoLog::PutOne(float dd)
{
	struct autobuf166 *ob;               // Output buffer
	
	// Get output buffer
	if ((ob = (struct autobuf166 *)GetNextBuffer(sizeof(struct autobuf166)))) {
		
		// Fill it in.
		clock_gettime(CLOCK_REALTIME, &ob->tp);
		ob->distance_diff = dd;
		return (sizeof(struct autobuf166));
	}
	
	// Did not get a buffer. Return a zero length
	return (0);
}

// Format the next buffer for file output
unsigned int AutoLog::DumpBuffer(char *nptr, FILE *ofile)
{
	struct autobuf166 *ab = (struct autobuf166 *)nptr;
	
	// Output the data into the file
	fprintf(ofile, "%u, %u, %f\n", ab->tp.tv_sec, ab->tp.tv_nsec, ab->distance_diff);
	
	// Done
	return (sizeof(struct autobuf166));
}

// Get access to vision related things
#if 1
extern Team166Vision Team166VisionObject;
extern Team166Sonar Team166SonarObject;
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

//constructor for autonomous166 class
autonomous166::autonomous166(void):
	first_time(0),
	past_time(0),
	check_time(.025),
	archived_y(0),
	archived_distance(0),
	drop_distance(35),
	activate_drop(0),
	gyrate(0),
	score(0)
	
{
	
	// Initialize key members
	camera_perspective = T166_UNKNOWND;
	sonar_perspective = T166_UNKNOWND;
	

	
}
// the "brain" of autonomous that sets the joystick inputs for drive

void autonomous166::autonomous_main(void)
{
	Robot166 *lhandle;
	lhandle=Robot166::getInstance();  // gets the lhandle tag that allows autonomos to grab from the Robot166 main task runner
	int difference_camera;            // difference between last picture's height and current picutre's height
	float difference_ultrasonic;      // difference between last ultrasonic value and current ultrasonic value
	float x;                          // initializes the local variable for the bearing of the robot
	float y;                          // sets the local variable for the speed of the robot to what it was set to in the last iteration of the autonomous function
    
	lhandle->RegisterLogger(&al);
while(lhandle->IsAutonomous())
{
	y = archived_y;               // sets the local variable for the speed of the robot to what it was set to in the last iteration of the autonomous function
	
  if(Team166VisionObject.IsTargetAcquired())   // sees if the camera has aquired a target or not 
  {
	  DPRINTF(LOG_INFO,"TARGET AQUIRED\n");
	
	  difference_camera=tracking();
	  DPRINTF(LOG_INFO,"the difference is %i \n", difference_camera);
	if(difference_camera > 0)
		{
			camera_perspective = T166_AWAY;    // camera sees the target moving away
		}
	else if(difference_camera < 0)
		{
			camera_perspective = T166_CLOSER;  // camera sees the target moving closer
		}
	else if(difference_camera == 0)
		{
			camera_perspective = T166_Constant; // target height has not changed
		}
	
	difference_ultrasonic=ultrasonic();
	 al.PutOne(difference_ultrasonic);
	
	if(difference_ultrasonic > 0)
			{
				sonar_perspective=T166_AWAY;   // sonar sensor sees the target moving away
			}
		else if(difference_ultrasonic < 0)
			{
				sonar_perspective=T166_CLOSER; // sonar sensor sees the target moving toward the robot
			}
		else if(difference_ultrasonic == 0)
			{
				sonar_perspective=T166_Constant; // target has not varied its distance
			}
	if(camera_perspective != sonar_perspective)
		{
			y = y+(y*.01);       // speeds the robot up until the sonar sensor agrees with the camera on the location of the target 
		}
	else if(camera_perspective == sonar_perspective)
		{
			DPRINTF(LOG_INFO,"ENTERED AREA 111111111111111111\n");
			difference_ultrasonic = fabs(difference_ultrasonic);
			if(difference_ultrasonic == 0)
			{
				y = archived_y;
			}
			else
			{
				y = (difference_ultrasonic/check_time);                    // sets the y value to the current speed of the target
			}			
			
		}
	
	
			
		DPRINTF(LOG_INFO,"Set with algorithems\n");	
	  archived_y = y;		                // keeps track of the y value tat was last set
	  x = Team166VisionObject.GetBearing(); // gets the position of the servo from the vision task
	  lhandle->SetJoyStick(x,y);            // sets the joystick values for drive
				
  }	
  else
  	{
	  if(target_acquisition())              // checks which direction to angle the robot in when a target hasn't been acquired
	  {
		  x = -0.25;                        // sets the bearing to 25 degrees to te left
		  y = 0.75;                         // sets the speed to 75 percent of maximum
		  lhandle->SetJoyStick(x,y);        // sets the Joystick input values
	  }
	  else
	  {
		  x = 0.25;                         // sets the bearing to 25 degrees to te left
		  y = 0.75;                         // sets the speed to 75 percent of maximum
		  lhandle->SetJoyStick(x,y);        // sets the Joystick input values
	  }
	  DPRINTF(LOG_INFO,"Set without algorithems\n"); 
  	} 
		
  // allow other processes to run
  Wait(0.05);
			
   }
}
	

int autonomous166::tracking(void)
{
	int current_image_height=0;    // the new height of the target
	int difference_camera;         // the difference between the target's previous height and its current height
	DPRINTF(LOG_INFO,"the first time variable = %f", first_time);
	if(first_time==0)                // if the camera has not submitted a target yet      
		{
			archived_image_height = Team166VisionObject.GetTargetHeight();   // get the first archived image height
			DPRINTF(LOG_INFO,"first image height = %i \n", archived_image_height);
			difference_camera = archived_image_height;                 // set the difference as positive
			first_time=1;                                              // end the first time call
		}
	else
		{
			current_image_height = Team166VisionObject.GetTargetHeight();           // get the latest image height 
			DPRINTF(LOG_INFO,"image height = %i \n",current_image_height);
			difference_camera = archived_image_height-current_image_height;   // find the difference between the old height and the lastest height
			archived_image_height = current_image_height;                     // set the new base height
		}
	return difference_camera;                                                 // return the difference value
	
}

// if the robot has not found a target trigger a zig-zagging autonomos that gets away from the starting location and helps rotate the camera to find a target

bool autonomous166::target_acquisition(void)
{
	double current_time=0;           // the local variable for the current time 
	bool direction;                  // arbitrary direction setting for the robot while it is zig-zagging
	
	current_time = GetTime();        // gets the current system time
	
	if(past_time==0)                 // sees if this is the robot's first time in the function
	{
		past_time=current_time;      // sets the starting time for the function
	}
	
	if(current_time-past_time>=5)
	{
		if(current_time-past_time>=10)
		{
			past_time=current_time; // if 10 seconds have past then reset the direction of the robot
		}
		else
		{
			direction = 1;          // if 5 seconds have past change the direction of the robot from left to right
		}
	}
	else
	{
		direction=0;                // set the direction of the robot to the left
	}
	
	return direction;               // return the direction of the robot to the main function
}

// reads information from the ultrasonic sensor and determines the distance of the target and the speed it is going

float autonomous166::ultrasonic (void)
{
	float current_distance=0;                                // the distance the target is from the robot
	float ultra_differance;                                  // the differance between the last distance and the current distance
	
	current_distance = Team166SonarObject.distance;          // get the distance from the ultrasonic class
	ultra_differance = archived_distance-current_distance;   // calculate the differance 
	archived_distance = current_distance;                    // reset the archived distance
	
	return ultra_differance;                                 // return the differance
}
	
	
