
#include "stdafx.h"
#include "timingClass.h"

using namespace std;

timingClass::timingClass()
{
	numOfTimers = 0;
}

int timingClass::startNewTimer()
{
	//Find current level of array, expand by 1
	++numOfTimers;

	//Create temporary array to hold old values.
	time_t *newArray = new time_t[numOfTimers];

	//Save old timers into temporary array.
	if (numOfTimers > 1)
	{
		for (int i = 0; i < numOfTimers-1; i++)
		{
			newArray[i] = savedTimers[i];
		}
	}

	//Dynmically resize to fit new index.
	if (numOfTimers > 1) {
		delete []savedTimers;
	}
	savedTimers = new time_t[numOfTimers];

	//Save old timers in new from temporary array
	for (int i = 0; i < numOfTimers; i++)
	{
		savedTimers[i] = newArray[i];
	}

	//Preserve memory, delete temporary array.
	delete []newArray;

	//Finally Initialize Time for this index.;
	savedTimers[numOfTimers-1] = time(NULL);

	//return index of timer
	return numOfTimers-1;
}

double timingClass::getElapsedTime(int i)
{
	return (double) (time(NULL) - savedTimers[i]);
}

void timingClass::tic()
{
	ticValue = clock();
}

void timingClass::resetTimer(int timer_index)
{
	savedTimers[timer_index] = time(NULL);
}

double timingClass::toc()
{
	return (double) (time(NULL) - ticValue);
}
