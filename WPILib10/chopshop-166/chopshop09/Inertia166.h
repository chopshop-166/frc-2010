#if !defined(_INERTIA166_H)
#define _INERTIA166_H
#include "WPILib.h"
#include "Robot166.h"
#include "semLib.h"

//
// This defines a sample intertia task
//
class Team166Inertia : public Team166Task
{
	
// Methods
public:
	
	// Inertia task constructor
	Team166Inertia(void);
	
	// Inertia task destructor
	virtual ~Team166Inertia(void);
	
	// Main function of the inertia task
	virtual int Main(int a2, int a3, int a4, int a5,
			int a6, int a7, int a8, int a9, int a10);

// Members
public:
	float acc_vector;                       // Current acceleration vector
	
};
#endif // !defined(_INERTIA166_H)
