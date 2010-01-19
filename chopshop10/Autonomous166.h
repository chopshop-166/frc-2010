#ifndef autonomous_h
#define autonomous_h
#include "MemoryLog166.h"

// Sample in memory buffer
struct autobuf166
{
	struct timespec tp;               // Time of snapshot
	float distance_diff;              // Delta of distance seen
	
};

// Sample Memory Log
class AutoLog : public MemoryLog166
{
public:
	AutoLog() : MemoryLog166(128*1024, "autonomous") {return;};
	~AutoLog() {return;};
	unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,               // Buffer that needs to be formatted
			FILE *outputFile);        // and then stored in this file
	unsigned int PutOne(float dd);    // Log the distanace difference
};

// Target location relative to where it has moved since it was last checked by the camera
typedef enum {T166_UNKNOWND=0, T166_CLOSER, T166_AWAY, T166_Constant} T166Target_t;

//the autonomous class: this is where the magic begins
class autonomous166
{
	// methods
	public:
		autonomous166(void);
		void autonomous_main(void);          // the "brain" of autonomous that sets the joystick inputs for drive
		int tracking(void);                  // takes the input from the camera and reports the height difference to the main function
		bool target_acquisition(void);       // if the robot has not found a target trigger a zig-zagging autonomos that gets away from the starting location and helps rotate the camera to find a target
		float ultrasonic (void);             // reads information from the ultrasonic sensor and determines the distance of the target and the speed it is going
	
	// variables	
	private:
        T166Target_t camera_perspective;     // Camera's idea of where the target is
        T166Target_t sonar_perspective;       // Sonar's idea of where the target is
        int archived_image_height;           // the previous height of the target
        float first_time;                    // the first time the image is recorded
        double past_time;                    // the recorded time at the start of avoidance mode 
        float check_time;                    // number of seconds between the reports from the ultrasonic sensor
        float archived_y;                    // the previous y value that we set for the robot
        float archived_distance;             // the current distance to the target
  		float drop_distance;                 // distance at which the dropper can be activated
  		float activate_drop;                 // activates dropping function variable
  		int gyrate;                        	 // activates gyrating action for the motor
  		int score;                           // activates the autonomous scoring
  		AutoLog al;                          // Autonomous log
	
	
};





#endif

