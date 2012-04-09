// Created by David Newton

// Quiz.h is the header file for the Quiz.cpp file, which will is used to hold information on a specific quiz

// File created on 4 April 2012.


#include "stdafx.h"
#include "core_header.h"
#include "Quiz.h"


using namespace std;

namespace CSE360Project{

		Quiz::Quiz(){
			this->quizID = -1;
			timeLimit = -1;//initialize variables
			openDate  = -1;
			closeDate = -1;
		}
		//overloaded constructor #1 for taking a quiz sequence - pass it a quID and it will initialize its variables with all the data on a specific quiz 
		Quiz::Quiz(int quizID){
			this->quizID = quizID;
			db_quiz_data quizData = db->quizzes->getQuizData(quizID);//get info on quiz from quiz DB
			timeLimit = quizData.timeLimit;//initialize variables
			openDate  = quizData.openDate;
			closeDate = quizData.closeDate;
		}

		void Quiz::setOpenDate(time_t openDate){
			this->openDate = openDate;
		}

		time_t Quiz::getOpenDate(){		
			return openDate;
		}

		void Quiz::setCloseDate(time_t closeDate){
			this->closeDate = closeDate;
		}

		time_t Quiz::getCloseDate(){
			return closeDate;
		}

		void Quiz::setTimeLimit(int timeLimit){
			this->timeLimit = timeLimit;
		}

		int Quiz::getTimeLimit(){
			return timeLimit;
		}

		void Quiz::setQuestions(vector<string> questions){

			for(int i = 0; i<questions.size(); i++){

				char newQ[MAX_MEMO_FIELD_SIZE];//define temp char array to store question
				strcpy (newQ, questions[i].c_str());//convert question to char array
				db_question_data newQuestion;// = {0,0,"test","0","0","0","0",0,0,"0"};
				//char test[10] = "test";
				//for(int i = 0; i<7; i++){
				//test[2] = {;
				//}
				//newQuestion.question = newQ;//add question to new db_question struct
				/*questionData.push_back(newQ);//add question struct to vector of questions*/
			}

		}

		string* Quiz::getQuestions(){
			string placeholder = "test";
			string* test = &placeholder;
			return test;
		}

		void Quiz::setAnswers(vector<string> answers){
			
			for(int i = 0; i<questionData.size(); i=i+4){
								
					/*char* newA1 = char[answers[i].size()+1];//define temp char array to store answer
					strcpy (newA1, answers[i].c_str());//convert answer to char array
					questionData[i].answer1 = newA1;//add answer to existing db_question struct
					
					char* newA2 = char[answers[i+1].size()+1];//define temp char array to store answer
					strcpy (newA2, answers[i+1].c_str());//convert answer to char array
					questionData[i].answer2 = newA2;//add answer to existing db_question struct
					
					char* newA3 = char[answers[i+2].size()+1];//define temp char array to store answer
					strcpy (newA3, answers[i+2].c_str());//convert answer to char array
					questionData[i].answer3 = newA3;//add answer to existing db_question struct

					char* newA4 = char[answers[i+3].size()+1];//define temp char array to store answer
					strcpy (newA4, answers[i+3].c_str());//convert answer to char array
					questionData[i].answer4 = newA4;//add answer to existing db_question struct*/
			
			}
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