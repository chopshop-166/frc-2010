#if !defined(_SONAR166_H)
#define _SONAR166_H
#include "WPILib.h"
#include "Robot166.h"
#include "semLib.h"

//
// This defines our sonar task
//
class Team166Sonar : public Team166Task
{
	
// Methods
public:
	
	// Sonar task constructor
	Team166Sonar(void);
	
	// Sonar task destructor
	virtual ~Team166Sonar(void);
	
	// Main function of the Sonar task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);

// Members
public:
	float distance;                         // Distance to the object
	
};
#endif // !defined(_SONAR166_H)
