#pragma once
#include "stdafx.h"
#include "DB_Core.h"

namespace CSE360Project {
	class DB_Quizzes: public CSE360Project::DB_Core {
	public:
		DB_Quizzes();

		///BEGIN PUBLIC METHODS THAT MODIFY DATA - "this->Write()" must be added before each method exits."
		void Delete(int qid);
		int Insert(db_quiz_data *quiz_data);
		///END PUBLIC METHODS THAT MODIFY DATA

		vector<db_quiz_data> getCourseQuizzes(int cid);
		db_quiz_data getQuizData(int qid);
		int getOpenDate(int qid);
		int getCloseDate(int qid);
		int getTimeLimit(int qid);
		int getCID(int qid);

		//Debug functions
		void outputAllData();

		virtual ~DB_Quizzes();

	private:
		std::vector<db_quiz_data> quiz_data;

		int getVectorIndex(int qid);

		void Write();
		void ClearData();
	};

} /* namespace CSE360Project */