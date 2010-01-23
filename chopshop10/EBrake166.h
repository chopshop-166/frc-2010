#if !defined(_EBRAKE166_H)
#define _EBRAKE166_H
#include "WPILib.h"
#include "Robot166.h"

class Team166EBrake : public Team166Task
{
	
public:
	
	// task constructor
	Team166EBrake(void);

	// task destructor
	virtual ~Team166EBrake(void);

	// Main function of the task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
};

#endif // !defined(_EBRAKE166)
