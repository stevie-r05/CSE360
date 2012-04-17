
// Created by David Newton

// Quiz.h is the header file for the Quiz.cpp file, which will is used to hold information on a specific quiz

// File created on 5 April 2012. 

#pragma once
#include "stdafx.h"
#include "core_header.h"
#include "Quiz.h"
using namespace std;

namespace CSE360Project {
	class Course {
	public:
		Course(int userID, string courseName);//overloaded constructor to create a course called from teacher class
		Course(int courseID); // Overloaded constructor for creating local object from DB_Courses
		void setName(string courseName);
		string getName();
		void setStudents(int studentIDList[]);
		vector<db_enrolled_data> getStudents();
		vector<db_quiz_data> getQuizList();
		Quiz* Course::getQuiz(int quizID,int uid, int cid);
		vector<db_score_data> getGrades();
		Quiz* creatQuiz();
		void deleteQuiz(int qid);
		void deleteStudents(int uid[]);
		//int addCourseData(int userID, string courseName);//this is taken care of by the constructor and is no longer needed

	protected:
		int courseID;
		string courseName;
		vector<db_quiz_data> quizList;

	};
}