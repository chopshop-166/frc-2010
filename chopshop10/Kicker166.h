#if !defined(_KICKER166_H)
#define _KICKER166_H
#include "WPILib.h"
#include "Robot166.h"

#define NO_SPEED				 0    //speed to use when there is no input for the treadmill victor

class Team166Kicker : public Team166Task
{
	
public:
	
	// task constructor
	Team166Kicker(void);

	// task destructor
	virtual ~Team166Kicker(void);

	// Main function of the task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
};

#endif // !defined(_KICKER166)
