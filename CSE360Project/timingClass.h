
#pragma once
#include "stdafx.h"

using namespace std;

class timingClass
{
public:
	timingClass();

	//Benchmarking Functions
	int startNewTimer(); //returns index of timer
	double getElapsedTime(int); //int is index of timer.
	void resetTimer(int);
	void tic();
	double toc();

	//Time Functions
	char formatHumanProcessedTime(double totalSeconds);


protected:
	int numOfTimers;
	int ticValue;

	time_t *savedTimers;

};
