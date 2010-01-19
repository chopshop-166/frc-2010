#if !defined(_ARM166_H)
#define _ARM166_H
#include "WPILib.h"
#include "Robot166.h"

#define TREADMILL_REVERSE_SPEED  1.0  //forward speed for the treadmill victor
#define TREADMILL_FORWARD_SPEED -1.0  //reverse speed for the treadmill victor
#define NO_SPEED				 0    //speed to use when there is no input for the treadmill victor

class Team166Arm : public Team166Task
{
	
public:
	
	// task constructor
	Team166Arm(void);

	// task destructor
	virtual ~Team166Arm(void);

	// Main function of the task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
};

#endif // !defined(_ARM166)
