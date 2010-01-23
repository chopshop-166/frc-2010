#if !defined(_CANDRIVE166_H)
#define _CANDRIVE166_H
#include "WPILib.h"
#include "Robot166.h"

#define NO_SPEED				 0    //speed to use when there is no input

class Team166CANDrive : public Team166Task
{
	
public:
	
	// task constructor
	Team166CANDrive(void);

	// task destructor
	virtual ~Team166CANDrive(void);

	// Main function of the task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
};

#endif // !defined(_CANDRIVE166)
