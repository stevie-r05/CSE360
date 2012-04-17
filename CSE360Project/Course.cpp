// Created by David Newton

// Quiz.h is the header file for the Quiz.cpp file, which will is used to hold information on a specific quiz

// File created on 5 April 2012. 

#include "stdafx.h"
#include "core_header.h"
#include "Course.h"


namespace CSE360Project {

	
		Course::Course(int userID, string courseName){//overloaded constructor to create a course called from teacher class
			
			this->courseName = courseName;
			db_course_data *newCourse = new db_course_data;
			newCourse->uid=userID;
			WriteStructValue(newCourse->courseName, courseName, false);
			courseID = db->courses->Insert(newCourse);
		}

		Course::Course(int courseID)
		{
			this->courseID = courseID;
			this->courseName = db->courses->getCourseName(courseID);
			this->quizList = db->quizzes->getCourseQuizzes(courseID);	// EDITED: Changed quizList to a vector<db_quiz_data> to typematch gCQ method.
		}

		void Course::setName(string courseName){
			this->courseName = courseName;
		}

		string Course::getName(){
			return courseName;
		}

		void Course::setStudents(int studentIDList[]){

			for (int i=0;i<sizeof studentIDList/sizeof(int); i++){

				db->enrolled->Insert(studentIDList[i], courseID);
			}

		}

		vector<db_enrolled_data>  Course::getStudents(){
			vector<db_enrolled_data> enrolled;
			return enrolled;
		}

		vector<db_quiz_data> Course::getQuizList(){			
			vector<db_quiz_data> updatedQuizList = db->quizzes->getCourseQuizzes(courseID);//get quiz list from db
			this->quizList = updatedQuizList;//update quizlist instance variable in course object
			return updatedQuizList;//return quizlist
		}

		Quiz* Course::getQuiz(int quizID,int uid, int cid){

			Quiz *selectedQuiz = new Quiz(quizID,uid,cid);
			return selectedQuiz;
		}

		vector<db_score_data> Course::getGrades(){
			vector<db_score_data> classScores;
			classScores = db->scores->getClassScores(courseID);
			return classScores;
		}

		Quiz* Course::creatQuiz(){

			Quiz* newQuiz = new Quiz(courseID);
			return newQuiz;
		}

		void Course::deleteQuiz(int qid){

			db->DeleteQuiz(qid);//delete quiz
			this->quizList = db->quizzes->getCourseQuizzes(courseID);//update quizlist instance variable in course object
		}

		void Course::deleteStudents(int uid[]){

			for (int i=0;i<sizeof uid/sizeof(int); i++){//delete students from DB
			db->enrolled->Unenroll(uid[i], courseID);
			}

		}

		/*int Course::addCourseData(int userID, string courseName){
			return 1;
		}*///this is taken care of by the constructor and is no longer needed


}