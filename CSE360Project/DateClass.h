#pragma once
#include "stdafx.h"

namespace CSE360Project {

	class DateClass {
	public:

		DateClass();
		DateClass(time_t inputTime);

		void setInputTime(time_t inputTime);

		void processTimeInput();
		void processTimeInput(time_t inputTime); //Automatically replace current time with this one

		virtual ~DateClass();

	private:
		time_t inputTime;
		int day;
		int month;
		int year;

		int minute;
		int second;
		int hour;
	};
}