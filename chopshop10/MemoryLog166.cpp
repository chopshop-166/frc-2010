/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: MemoryLog166.cpp    
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: General memory logger on chopshop robot
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include <memLib.h>
#include "BaeUtilities.h"
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <stat.h>
#include "MemoryLog166.h"


// To locally enable debug printing: set true, to disable false
#define DPRINTF if(false)dprintf

// Memory log constructor
MemoryLog166::MemoryLog166(unsigned int msize, unsigned int ltime, char *f)
{
	unsigned int ms;  // Size of memory that we need
	
	// Compute the size that we need for 1 item per loop during 2m15s + 5s padding
	ms = ((1000*((2*60) + 15 + 5)) / ltime) * msize;
	
	// Allocate the requested memory
	MemoryBase = (char *)valloc(ms);
	
	// Initialize members
	MemorySize = ms;
	MemoryEnd = &MemoryBase[ms];
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
	snprintf(Factual, sizeof(Factual) - 1, "%s__%d.csv", FileName, dnum);
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
	printf("Completed dump for %s into %s;\n", FileName, Factual);
	printf("  Requested buffers %d, Obtained buffers %d\n",
			BuffersRequested, BuffersObtained);
	BuffersRequested = 0;
	BuffersObtained = 0;
	
	// Back to caller
	return (0);
}

// Determine generation of a particular file
int MemoryLog166::DetermineGen(char *fname)
{
	
	size_t nl;                    // Length of filename string
	int generation = -1;          // Generation number
	int digits_seen;              // Digits we've seen so far
	size_t nl_temp;               // Temnporary offset within file name
		
	// Is this possibly a log file that we wrote?
	nl = strlen(fname);
	if ((nl > 4) && (!strcmp(".csv", &fname[nl - 4]))) {
			
		// Might be. At least it ends with ".csv". Digits before that?
		generation = 0;
		digits_seen = 0;
		nl_temp = nl - 5;
		while (fname[nl_temp] >= '0' && fname[nl_temp] <= '9') {
			generation *= 10;
			generation += (fname[nl_temp] - '0');
			digits_seen++;
				if (!nl_temp--) {
					generation = -1;
					break;
				}
		}

		// Still possibly Ok?
		if ((generation >= 0) && (digits_seen)) {
				
			// At least one digit and we've got space for a '__'?
			if ((!digits_seen) || (nl_temp <= 2) ||
					(fname[nl_temp--] != '_') ||
					(fname[nl_temp--] != '_'))
					
				// No.
				generation = -1;
			}
	}
	
	// Done, back to caller with generation
	return (generation);
}

// Determine hi/low generation values for log-files
void MemoryLog166::DetermineLogHiLow(int *hi, int *lo, size_t *tspace)
{

	DIR *dhandle;                 // Handle to directory
	struct dirent *de;            // Next file we're examining
	struct stat se;               // File information block
	int generation;               // Generation number
	int highest_gen = -1;         // Highest generation we know about
	int lowest_gen = 0x7fffffff;  // Lowest generation we know about
	size_t total_space = 0;       // Total space (bytes) of files

	// Open the current working directory
	dhandle = opendir(".");
	
	// Walk through the complete list of files in this directory
	while ((de = readdir(dhandle))) {

		// Get possible generation number
		generation = DetermineGen(de->d_name);

		// If this is a generation, display it
		if (generation >= 0) {

			// Collect status information about the file
			stat(de->d_name, &se);
			
			// Add space used
			total_space += se.st_size;
			
			// Is this generation lower than what we've seen?
			if (generation < lowest_gen)
				lowest_gen = generation;
				
			// Is this the highest generation we've seen?
			if (generation > highest_gen)
				highest_gen = generation;
		}
	}
	
	// Done, close it
	closedir(dhandle);
	
	// Done
	*tspace = total_space;
	*hi = highest_gen;
	*lo = lowest_gen;
	return;
}

// Trim a generation of logfiles
void MemoryLog166::TrimGeneration(int gen)
{
	
	DIR *dhandle;                 // Handle to directory
	struct dirent *de;            // Next file we're examining
	int generation;               // Generation number

	// Open the current working directory
	dhandle = opendir(".");
	
	// Walk through the complete list of files in this directory
	while ((de = readdir(dhandle))) {

		// Get possible generation number
		generation = DetermineGen(de->d_name);

		// Is this the generation we're looking for?
		if (gen == generation) {
			
			// Yes. Get rid of the file
			remove(de->d_name);
		}
	}
	
	// Done, close it
	closedir(dhandle);
	
	// Done
	return;
}

// Prune the log files down to a aggregate size
int MemoryLog166::PruneLogs(size_t maxsize)
{
	int lo;         // Low generation number
	int hi;         // High generation number
	size_t lsize;   // Combined size of logs
	
	// Enter loop to trim things down
	while (1) {
		
		// Determine how many generations we have out there and their size
		DetermineLogHiLow(&hi, &lo, &lsize);
		printf("Logfiles. High Gen=%d, Low Gen=%d, Total space: %u\n", hi, lo, lsize);
		
		// Are we ok for space?
		if (lsize <= maxsize)
			break; // Yes.
		
		// Trim low generation
		printf("Trimming log generation %d...\n", lo);
		TrimGeneration(lo);
	}
	
	// Done
	return (hi);
}
