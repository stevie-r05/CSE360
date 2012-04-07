// Created by David Newton

// Quiz.h is the header file for the Quiz.cpp file, which will is used to hold information on a specific quiz

// File created on 4 April 2012.

#pragma once
#include "stdafx.h"
#include "Quiz.h"

using namespace std;

namespace CSE360Project{

		Quiz::Quiz(int quizID){
			this->quizID = quizID;
		}

		void Quiz::setOpenDate(time_t openDate){
		}

		time_t Quiz::getOpenDate(){
			time_t placeholder = NULL;
			return placeholder;
		}

		void Quiz::setCloseDate(time_t closeDate){
		}

		time_t Quiz::getCloseDate(){
			time_t placeholder = NULL;
			return placeholder;
		}

		void Quiz::setTimeLimit(int timeLimit){
		}

		int Quiz::getTimeLimit(){

			return 1;
		}

		void Quiz::setQuestions(string questions[]){
		}

		string* Quiz::getQuestions(){
			string placeholder = "test";
			string* test = &placeholder;
			return test;
		}

		void Quiz::setAnswers(string answers[]){
		}

		string* Quiz::getAnswers(){

			string placeholder = "test";
			string* test = &placeholder;
			return test;
		}

		bool Quiz::submitAnswers(int quizID, int answerData []){

			return 1;
		}

		void Quiz::addQuestion(string question){
		}
		
		bool Quiz::saveQuiz(){
			return 1;
		}

		void Quiz::gradeQuiz(){
		}
}