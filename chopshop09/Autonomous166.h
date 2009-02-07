#ifndef autonomous_h
#define autonomous_h

// Target location
typedef enum {T166_UNKNOWND=0, T166_CLOSER, T166_AWAY} T166Target_t;

class autonomous166
{
	// methods
	public:
		autonomous166(void);
		void autonomous_main(void);
		int tracking(void);
		bool target_acquisition(void);
		float ultrasonic (void);
	
	// variables	
	private:
        T166Target_t camera_perspective;     // Camera's idea of where the target is
        T166Target_t sonar_perspectve;       // Sonar's idea of where the target is
        int archived_image_height;           // the previous height of the target
        float first_time;                    // the first time the image is recorded
        double past_time;                    // the recorded time at the start of avoidance mode 
        float check_time;                    // number of seconds between the reports from the ultrasonic sensor
        float archived_y;                    // the previous y value that we set for the robot
        float archived_distance;             // the current distance to the target
  		float drop_distance;                 // distance at which the dropper can be activated
  		float activate_drop;                  // activates dropping function variable
	
	
};





#endif

