#if !defined(_DISPENSER166_H)
#define _DISPENSER166_H
#include "WPILib.h"
#include "Robot166.h"

#define TREADMILL_REVERSE_SPEED  1.0  //forward speed for the treadmill victor
#define TREADMILL_FORWARD_SPEED -1.0  //reverse speed for the treadmill victor
#define NO_SPEED				 0    //speed to use when there is no input for the treadmill victor

//
// This defines a sample dispenser task
//
class Team166Dispenser : public Team166Task
{
	
public:
	
	// Dispenser task constructor
	Team166Dispenser(void);

	// Dispenser task destructor
	virtual ~Team166Dispenser(void);

	// Main function of the dispenser task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);
};

#endif // !defined(_DISPENSER166)
