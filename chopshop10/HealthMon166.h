#if !defined(_HEALTH166_H)
#define _HEALTH166_H
#include "WPILib.h"
#include "Robot166.h"

class Team166HealthMon : public Team166Task
{
	
public:
	
	// task constructor
	Team166HealthMon(void);

	// task destructor
	virtual ~Team166HealthMon(void);

	// Main function of the task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
};

#endif // !defined(_CANHEALTH166)
