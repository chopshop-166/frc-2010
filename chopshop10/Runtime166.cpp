/*******************************************************************************
*  Project   		: chopshop10 - 2010 Chopshop Robot Controller Code
*  File Name  		: Runtime166.cpp
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: January 18, 2010
*  Revision History	: From Explorer with TortoiseSVN, Use "Show log" menu item
*  File Description	: Class that generates runtime statistics
*******************************************************************************/ 
/*----------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/

#include "Runtime166.h"
#include <math.h>
#include <string>
using namespace std;

Runtime166::Runtime166() {
	limit = 50;
}

Runtime166::Runtime166(int lim) {
	limit = lim;
}

void Runtime166::Stop() {
	t.Stop();
	loop_times.push_back(t.Get());
	t.Reset();
	while(limit > 0 && loop_times.size() > limit) {
		loop_times.erase(loop_times.begin(), loop_times.begin()+(loop_times.size() - limit));
	}
}

void Runtime166::Start() {
	t.Start();
}

unsigned int Runtime166::Loops() {
	return loop_times.size();
}

char* Runtime166::GetStats() {
	if(loop_times.size() == 0)
		return "";
	char* r = new char[500];
	
	vector<float>::iterator it = loop_times.begin();
	float max = *it;
	float min = *it;
	float sx = 0;
	int n = loop_times.size();
	float avg = 0;
	
	do {
		if(max < *it)
			max = *it;
		if(min > *it)
			min = *it;
		
		avg += *it;
	} while((++it) != loop_times.end());
	avg /= n;
	
	it = loop_times.begin();
	do {
		sx += pow((avg - *it), 2);
	} while((++it) != loop_times.end());
	
	sx = sqrt(sx / (n-1));
	
	sprintf(r, "[n %d] [max %f] [min %f] [avg %f] [sx %f]", n, max, min, avg, sx);
	return r;
}

void Runtime166::Reset() {
	loop_times.erase(loop_times.begin(), loop_times.end());
}
