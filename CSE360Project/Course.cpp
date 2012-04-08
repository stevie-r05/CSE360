// Created by David Newton

// Quiz.h is the header file for the Quiz.cpp file, which will is used to hold information on a specific quiz

// File created on 5 April 2012.

#include "stdafx.h"
#include "core_header.h"
#include "Course.h"


namespace CSE360Project {

	
		Course::Course(){
			
		}

		void Course::setName(string courseName){

		}

		string Course::getName(){
			return "test";
		}

		void Course::setStudents(int studentIDList[]){

		}

		string Course::getStudents(){
			return "test";
		}

		int* Course::getQuizList(){
			int* pointer;
			return pointer;
		}

		// Quiz Course::getQuiz();

		double* Course::getGrades(){
			return NULL;
		}

		//Quiz Course::creatQuiz();

		void Course::deleteQuiz(){

		}

		void Course::deleteStudents(){

		}

		int Course::addCourseData(int userID, string courseName){
			return 1;
		}

}