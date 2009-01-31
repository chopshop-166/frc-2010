#if !defined(_VISION166_H)
#define _VISION166_H
#include "WPILib.h"
#include "Robot166.h"
#include "semLib.h"

//
// This defines a sample vision task
//
class Team166Vision : public Team166Task
{
	
// Methods
public:
	
	// Vision task constructor
	Team166Vision(void);
	
	// Vision task destructor
	virtual ~Team166Vision(void);
	
	// Main function of the vision task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);

// Members
public:
	float bearing;                       // Current target bearing
	
};
#endif // !defined(_VISION166_H)
