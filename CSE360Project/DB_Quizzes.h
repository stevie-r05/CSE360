#pragma once
#include "stdafx.h"
#include "DB_Core.h"

namespace CSE360Project {
	class DB_Quizzes: public CSE360Project::DB_Core {
	public:
		DB_Quizzes();

		///BEGIN PUBLIC METHODS THAT MODIFY DATA - "this->Write()" must be added before each method exits."
		void Delete(int qid);
		void DeleteCourse(int cid);
		int Insert(db_quiz_data *quiz_data);
		///END PUBLIC METHODS THAT MODIFY DATA

		time_t getOpenDate(int qid);
		time_t getCloseDate(int qid);
		int getTimeLimit(int qid);
		int getCID(int qid);

		vector<db_quiz_data> getCourseQuizzes(int cid);
		db_quiz_data getQuizData(int qid);

		//Debug functions
		void ReloadData();
		void outputAllData();

		virtual ~DB_Quizzes();

	private:
		std::vector<db_quiz_data> quiz_data;

		int getVectorIndex(int qid);

		void Write();
		void ClearData();
	};

} /* namespace CSE360Project */