/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: MemoryLog166.h     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Header for general memory logger on chopshop robot
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

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
	struct timespec starttime;					// Time the
	MemoryLog166(unsigned int msize, unsigned int ltime, char *f);// Constructor
	virtual ~MemoryLog166(void);				// Destructor
	char *GetNextBuffer(unsigned int bsize);	// Get next buffer to write
	int DumpToFile(int dnum);					// Dump the data into a file
	virtual unsigned int DumpBuffer(			// Dump the next buffer into the file
			char *nptr,							// Buffer that needs to be formatted
			FILE *outputFile) = 0;				// and then stored in this file
	static void DetermineLogHiLow(int *hi, int *lo, size_t *tspace); // Determine hi/low values for log-files
	static int DetermineGen(char *fname);		// Determine generation of file
	static void TrimGeneration(int gen);		// Trim a generation of logfiles
	static int PruneLogs(size_t maxsize);		// Prune the log files down to a aggregate size
	
// Members
public:
	int Registered;								// This handler has been registered with Robot166
	MemoryLog166 *mlNext;						// Link to the next block

private:
	unsigned int MemorySize;					// Size of the memory we have allocated
	char *MemoryBase;							// Base pointer to memory just allocated
	char *MemoryEnd;							// End of allocated memory
	char *MemoryNext;							// Next
	class MemoryLog166 *Next;					// Link to next log structure
	char *FileName;								// Filename
	int BuffersRequested;						// Buffers requested
	int BuffersObtained;						// Buffers obtained
};

#endif // !defined(_MEMORYLOG166_H)
