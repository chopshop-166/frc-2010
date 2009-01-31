#if !defined(_MEMORYLOG166_H)
#define _MEMORYLOG166_H
#include <stdio.h>

//
// This class defines an interface to logging to memory and then into
//
class MemoryLog166
{

// Methods	
public:
	MemoryLog166(unsigned int msize);         // Constructor
	virtual ~MemoryLog166(void);              // Destructor
	char *GetNextBuffer(unsigned int bsize);  // Get next buffer to write
	int DumpToFile(char *fname);              // Dump the data into a file
	virtual unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,                       // Buffer that needs to be formatted
			FILE *outputFile) = 0;            // and then stored in this file
	
// Members
private:
	unsigned int MemorySize;                  // Size of the memory we have allocated
	char *MemoryBase;                         // Base pointer to memory just allocated
	char *MemoryEnd;                          // End of allocated memory
	char *MemoryNext;                         // Next
	
};

#endif // !defined(_MEMORYLOG166_H)
