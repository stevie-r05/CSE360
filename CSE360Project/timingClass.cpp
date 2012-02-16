
#include "stdafx.h"
#include "timingClass.h"

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

using namespace std;

timingClass::timingClass()
{
	numOfTimers = 0;

	//Start quick timer from when class was initialized.
	this->tic();
}

/*
 * returns an int value representing the index that this timer is being stored at.
 */
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

/*
 * return time in seconds of timer at current index.
 */
double timingClass::getElapsedTime(int i)
{
	return (double) (time(NULL) - savedTimers[i]);
}

/*
 * start quick timer
 */
void timingClass::tic()
{
	ticValue = clock();
}

/*
 * reset timer at index to current time.
 */
void timingClass::resetTimer(int timer_index)
{
	savedTimers[timer_index] = time(NULL);
}

/*
 * return quick timer
 */
double timingClass::toc()
{
	return (double) (time(NULL) - ticValue);
}
