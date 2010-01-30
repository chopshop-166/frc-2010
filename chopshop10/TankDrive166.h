#if !defined(_TANKDRIVE166_H)
#define _TANKDRIVE166_H
#include "WPILib.h"
#include "Robot166.h"

class Team166TankDrive : public Team166Task, public RobotDrive
{
	
public:
	
	// task constructor
	Team166TankDrive(void);

	// task destructor
	virtual ~Team166TankDrive(void);

	// Main function of the task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
};

#endif // !defined(_TANKDRIVE166)
