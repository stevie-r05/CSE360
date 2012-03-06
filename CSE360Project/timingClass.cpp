#include "stdafx.h"
#include "timingClass.h"

using namespace std;

/*
 * Created by Ian Coast
 *
 * Tic/Toc Usage example:
 *	void some_function() {
 *		//Begin timer
 *		timing->tic();
 *		
 *		while (continueCalculation) {
 *			//Do something
 *		}
 *		
 *		cout << "This calculation took " << timing->toc() << " seconds to complete." << endl;
 *	}
 *
 * Timer Usage Example:
 *	void some_function2() {
 *		int timer_index = timing->startNewTimer();
 *		int loop_index = timing->startNewTimer();;
 *		
 *		while (continueCalculation) {
 *			//Keep track of this loop
 *			timing->resetTimer(loop_index);
 *
 *			//Do something
 *
 *			cout << "Loop time:  " << timing->getElapsedTimer(loop_index) << endl;
 *		}
 *
 *		cout << "This calculation took " << timing->getElapsedTimer(timer_index) << " seconds to complete." << endl;
 *
 */
timingClass::timingClass()
{
	numOfTimers = 0;
}

int timingClass::startNewTimer()
{
	//Find current level of array, expand by 1
	++numOfTimers;

	//Create temporary array to hold old values.
	elapsed_time_t *newArray = new elapsed_time_t[numOfTimers];

	//Save old timers into temporary array.
	if (numOfTimers > 1)
	{
		//copy old array into new array.  memcpy is used due to speed/efficiency.
		memcpy(newArray, savedTimers, sizeof(elapsed_time_t) * (numOfTimers-1));

		//Delete the current timers in preparing to restore list.
		delete []savedTimers;
	}

	//Dynmically resize to fit new index.
	savedTimers = new elapsed_time_t[numOfTimers];

	//Save old timers in new from temporary array
	//copy old array into new array.  memcpy is used due to speed/efficiency.
	memcpy(savedTimers,newArray, sizeof(elapsed_time_t) * (numOfTimers-1));

	//Preserve memory, delete temporary array.
	delete []newArray;

	//Finally Initialize Time for this index.;
	savedTimers[numOfTimers-1].cpu_time = clock();
	savedTimers[numOfTimers-1].elapsed_time = time(NULL);
	savedTimers[numOfTimers-1].saved = false;

	//return index of timer
	return numOfTimers-1;
}

//Returns elapsed time (real time).
double timingClass::getElapsedTime(int i)
{
	if (savedTimers[i].saved) {
		return (double) (savedTimers[i].elapsed_time_saved - savedTimers[i].elapsed_time);
	} else {
		return (double) (time(NULL) - savedTimers[i].elapsed_time);
	}
}

double timingClass::getCPUTime(int i)
{
	if (savedTimers[i].saved) {
		return ( savedTimers[i].cpu_time_saved - savedTimers[i].cpu_time ) / (double) CLOCKS_PER_SEC;
	} else {
		return ( clock() - savedTimers[i].cpu_time ) / (double) CLOCKS_PER_SEC;
	}
}

void timingClass::saveCurrentTime(int timer_index) {
	savedTimers[timer_index].cpu_time_saved = clock();
	savedTimers[timer_index].elapsed_time_saved = time(NULL);
	savedTimers[timer_index].saved = true;
}

void timingClass::tic()
{
	ticValue = clock();
}

double timingClass::toc()
{
	return ( clock() - ticValue ) / (double)CLOCKS_PER_SEC;

}

void timingClass::resetTimer(int timer_index)
{
	savedTimers[timer_index].cpu_time = clock();
	savedTimers[timer_index].elapsed_time = time(NULL);
	savedTimers[timer_index].saved = false;
}