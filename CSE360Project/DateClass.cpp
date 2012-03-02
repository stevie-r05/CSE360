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

	void DateClass::setInputTime(time_t inputTime) {
		this->inputTime;
		this->processTimeInput();
	}

	void DateClass::processTimeInput() {

	}

	void DateClass::processTimeInput(time_t inputTime) {
		this->inputTime = inputTime;
		this->processTimeInput();
	}

	DateClass::~DateClass() {

	}
}