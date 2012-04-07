// Created by David Newton

// Quiz.h is the header file for the Quiz.cpp file, which will is used to hold information on a specific quiz

// File created on 4 April 2012.

#pragma once

#include "stdafx.h"


using namespace std;

namespace CSE360Project {

	class Quiz {
	public:
		Quiz(int quizID);
		void setOpenDate(time_t openDate);
		time_t getOpenDate();
		void setCloseDate(time_t closeDate);
		time_t getCloseDate();
		void setTimeLimit(int timeLimit);
		int getTimeLimit();
		void setQuestions(string questions[]); 
		string* getQuestions();
		void setAnswers(string answers[]);
		string* getAnswers();
		bool submitAnswers(int quizID, int answerData []);
		void addQuestion(string question);
		bool saveQuiz();

	protected:
		int quizID;
		vector<db_question_data> questionData;
		int timeLimit;
		time_t openDate;
		time_t closedate;

		void gradeQuiz();

			}; // end User class
}