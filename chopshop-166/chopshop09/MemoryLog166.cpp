#include <memLib.h>
#include "BaeUtilities.h"
#include <string.h>
#include <stdlib.h>
#include "MemoryLog166.h"


// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Memory log constructor
MemoryLog166::MemoryLog166(unsigned int msize, char *f)
{
	
	// Allocate the requested memory
	MemoryBase = (char *)valloc(msize);
	
	// Initialize members
	MemorySize = msize;
	MemoryEnd = &MemoryBase[msize];
	MemoryNext = MemoryBase;
	Next = 0;
	BuffersRequested = 0;
	BuffersObtained = 0;
	
	// Capture name of file
	FileName = (char *)malloc(strlen(f) + 1);
	strcpy(FileName, f);
	
	// Not yet registered
	Registered = 0;
	mlNext = 0;
	
	// Done
	return;
}

// Destructor
MemoryLog166::~MemoryLog166(void)
{
	
	// Done
	return;
}

// Get next buffer
char *MemoryLog166::GetNextBuffer(unsigned int bsize)
{
    char *mptr = MemoryNext;
    
	// Ensure we have something to allocate
    BuffersRequested++;
	if ((!MemoryNext) || (&MemoryNext[bsize] > MemoryEnd))
		return (0);
	
	// Bump next
	BuffersObtained++;
	MemoryNext = &MemoryNext[bsize];
	
	// Back to caller with a link to the memory we just allocated
	return (mptr);
}

// Dump the buffers into a file
int MemoryLog166::DumpToFile(int dnum)
{
	
	char *nptr = MemoryBase;
	char Factual[128];
	FILE *ofile;
	
	// Back out if there is nothing (likely due to allocation failure in constructor
	if (!nptr)
		return (0);
	
	DPRINTF(LOG_DEBUG, "MemoryBase: 0x%x, MemoryNext: 0x%x, nptr: 0x%x\n", MemoryBase, MemoryNext, nptr);
	
	// Create the output file
	Factual[sizeof(Factual) - 1] = 0;
	snprintf(Factual, sizeof(Factual) - 1, "%s%d.csv", FileName, dnum);
	if (ofile = fopen(Factual, "w")) {
	
		// Enter loop to dump out the data into the file
		int l=0;
		while (nptr < MemoryNext) {
			
			// Call a user defined routine to format and dump this out
			nptr += DumpBuffer(nptr, ofile);
			l++;
			DPRINTF(LOG_DEBUG, "Dumped buffer #%d; nptr: 0x%x\n", l, nptr);
		}
		// Done. Close the file
		fclose(ofile);
	}
	
	// Reset what we have logged
	MemoryNext = MemoryBase;
	printf("Completed dump for %s into %s; Requested buffers %d, Obtained buffers %d\n",
			FileName, Factual, BuffersRequested, BuffersObtained);
	BuffersRequested = 0;
	BuffersObtained = 0;
	
	// Back to caller
	return (0);
}
