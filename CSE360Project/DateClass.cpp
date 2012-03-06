#include "stdafx.h"
#include "DateClass.h"

namespace CSE360Project {
	DateClass::DateClass() {
		//Initialize with current time.
		this->inputTime = time(NULL);
		this->processTimeInput();

	}

	DateClass::DateClass(time_t inputTime) {
		this->inputTime = inputTime;
		this->processTimeInput();
	}

	DateClass::DateClass(int month, int day, int year) {
		getTimeStamp(month, day, year);
	}

	DateClass::DateClass(int month, int day, int year, int hour, int minute, int second) {
		getTimeStamp(month,day,year,hour,minute,second);
	}

	void DateClass::setInputTime(time_t inputTime) {
		this->inputTime = inputTime;
		this->processTimeInput();
	}

	time_t DateClass::getTimeStamp() {
		return this->inputTime;
	}

	time_t DateClass::getTimeStamp(int month, int day, int year) {
		time(&tempTime);
		time_data = localtime (&tempTime);
		time_data->tm_year = year - 1900;
		time_data->tm_mon = month - 1;
		time_data->tm_mday = day;

		//this saves the raw timestamp
		this->inputTime = mktime(time_data);

		//This re-processes the timestamp into a readable time structure
		this->processTimeInput();

		return this->inputTime;
	}

	time_t DateClass::getTimeStamp(int month, int day, int year, int hour, int minute, int second) {
		time(&tempTime);
		time_data = localtime (&tempTime);
		time_data->tm_year = year - 1900;
		time_data->tm_mon = month - 1;
		time_data->tm_mday = day;
		time_data->tm_hour = hour;
		time_data->tm_min = minute;
		time_data->tm_sec = second;

		//this saves the raw timestamp
		this->inputTime = mktime (time_data);

		//This re-processes the timestamp into a readable time structure
		this->processTimeInput();

		return this->inputTime;
	}

	tm *DateClass::getDateData() {
		return time_data;
	}

	void DateClass::processTimeInput() {
		//save the time stamp to the time structure, time_data
		time_data = localtime(&this->inputTime);

		//localtime_s saves the value in some weird ways, correct that here:
		time_data->tm_year += 1900;
		time_data->tm_mon++;
	}

	void DateClass::processTimeInput(time_t inputTime) {
		this->inputTime = inputTime;
		this->processTimeInput();
	}

	/*
	 * Implement comparison checks between two different date objects using operator overloading.
	 */
	bool DateClass::operator > (DateClass param) {
		return this->inputTime > param.inputTime;
	}

	bool DateClass::operator >= (DateClass param) {
		return this->inputTime >= param.inputTime;
	}

	bool DateClass::operator < (DateClass param) {
		return this->inputTime < param.inputTime;
	}

	bool DateClass::operator <= (DateClass param) {
		return this->inputTime <= param.inputTime;
	}

	DateClass::~DateClass() {

	}
}