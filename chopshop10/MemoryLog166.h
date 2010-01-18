#if !defined(_MEMORYLOG166_H)
#define _MEMORYLOG166_H
#include <stdio.h>
#include <time.h>

//
// This class defines an interface to logging to memory and then into
//
class MemoryLog166
{

// Methods	
public:
	MemoryLog166(unsigned int msize, char *f);// Constructor
	virtual ~MemoryLog166(void);              // Destructor
	char *GetNextBuffer(unsigned int bsize);  // Get next buffer to write
	int DumpToFile(int dnum);                 // Dump the data into a file
	virtual unsigned int DumpBuffer(          // Dump the next buffer into the file
			char *nptr,                       // Buffer that needs to be formatted
			FILE *outputFile) = 0;            // and then stored in this file
	
// Members
public:
	int Registered;                           // This handler has been registered with Robot166
	MemoryLog166 *mlNext;                     // Link to the next block

private:
	unsigned int MemorySize;                  // Size of the memory we have allocated
	char *MemoryBase;                         // Base pointer to memory just allocated
	char *MemoryEnd;                          // End of allocated memory
	char *MemoryNext;                         // Next
	class MemoryLog166 *Next;                 // Link to next log structure
	char *FileName;                           // Filename
	int BuffersRequested;                     // Buffers requested
	int BuffersObtained;                      // Buffers obtained
};

#endif // !defined(_MEMORYLOG166_H)
