#pragma once
#include "stdafx.h"

namespace CSE360Project {

	class DateClass {
	public:

		DateClass();
		DateClass(time_t inputTime);
		DateClass(int month, int day, int year);
		DateClass(int month, int day, int year, int hour, int minute, int second);

		void setInputTime(time_t inputTime);

		time_t getTimeStamp();
		time_t getTimeStamp(int month, int day, int year);
		time_t getTimeStamp(int month, int day, int year, int hour, int minute, int second);

		tm *getDateData();
		void processTimeInput();
		void processTimeInput(time_t inputTime); //Automatically replace current time with this one

		bool operator > (DateClass);
		bool operator >= (DateClass);
		bool operator < (DateClass);
		bool operator <= (DateClass);

		bool hasTimeElapsed(time_t targetTime, time_t testTime);

		virtual ~DateClass();
		
	private:
		time_t inputTime;
		time_t tempTime;

		struct tm *time_data;
		/*
			Tm->tm_wday, // Days since Sunday.  [1] Mon - Sun
			Tm->tm_mday,
			Tm->tm_mon+1, = add 1 to get actual month
			Tm->tm_year+1900, = add 1900 to get actual year
			Tm->tm_hour,
			Tm->tm_min,
			Tm->tm_sec
		*/
	};
}