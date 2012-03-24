#pragma once
#include "stdafx.h"
#include "DB_Core.h"


namespace CSE360Project {
	class DB_QuizQuestions: public CSE360Project::DB_Core {
	public:
		DB_QuizQuestions();

		///BEGIN PUBLIC METHODS THAT MODIFY DATA - "this->Write()" must be added before each method exits."
		void Delete(int question_id);
		void DeleteQuiz(int qid);
		int Insert(db_question_data *question_data);
		void Insert(vector<db_question_data> question_data);
		///END PUBLIC METHODS THAT MODIFY DATA

		db_question_data getQuestionData(int question_id);
		vector<db_question_data> getQuestions(int qid);
		int getCorrectAnswer(int question_id);
		int getQID(int question_id);

		/*
		 * Add this overloaded method so it would called "orderQuestions()"
		 */
		template <class DB_DATA_TYPE>
		void LoadData(vector<DB_DATA_TYPE> &data_vector) {
			//Call parent's load data to actually load the data
			DB_Core::LoadData<DB_DATA_TYPE>(data_vector);

			//Order the questions based on Order field.
			this->orderQuestions();
		}
		//Debug functions
		void ReloadData();
		void outputAllData();


		virtual ~DB_QuizQuestions();

	private:
		std::vector<db_question_data> question_data;

		int getVectorIndex(int question_id);

		void Write(bool force_write = false);
		void ClearData();
		void orderQuestions();
	};

} /* namespace CSE360Project */