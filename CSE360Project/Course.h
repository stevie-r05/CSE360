
// Created by David Newton

// Quiz.h is the header file for the Quiz.cpp file, which will is used to hold information on a specific quiz

// File created on 5 April 2012.

#pragma once
#include "stdafx.h"
#include "core_header.h"

using namespace std;

namespace CSE360Project {
	class Course {
	public:
		Course();
		void setName(string courseName);
		string getName();
		void setStudents(int studentIDList[]);
		string getStudents();
		int* getQuizList();
		// Quiz getQuiz();
		double* getGrades();
		//Quiz creatQuiz();
		void deleteQuiz();
		void deleteStudents();
		int addCourseData(int userID, string courseName);

	protected:
		int courseID;
		string courseName;
		int *quizList;

	};
}