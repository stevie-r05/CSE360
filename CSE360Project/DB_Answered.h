#pragma once
#include "stdafx.h"
#include "DB_Core.h"

namespace CSE360Project {
	class DB_Answered: public CSE360Project::DB_Core {
	public:
		DB_Answered();

		///BEGIN PUBLIC METHODS THAT MODIFY DATA - "this->Write()" must be added before each method exits."
		void Delete(int aid);
		void DeleteQuiz(int qid);
		void DeleteQuestion(int question_id);
		void DeleteUser(int primary_id);
		void Insert(vector<db_answered_data> answered_data);
		int Insert(db_answered_data *answered_data) ;
		///END PUBLIC METHODS THAT MODIFY DATA
		
		int getUserAnswer(int uid, int question_id);
		vector<db_answered_data> getUsersQuizAnswers(int uid, int qid);
		int getQID(int aid);
		int getUID(int aid);

		//Debug functions
		void ReloadData();
		void outputAllData();

		virtual ~DB_Answered();

	private:
		std::vector<db_answered_data> answered_data;

		void Write();
		void ClearData();
		int getVectorIndex(int aid);
	};

} /* namespace CSE360Project */