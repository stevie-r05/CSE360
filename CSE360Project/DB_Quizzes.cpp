/*
* DBCourses.cpp
*
*  Created on: Mar 1, 2012
*      Author: Ian
*/
#include "stdafx.h"
#include "DB_Quizzes.h"
#include "timingClass.h"

namespace CSE360Project {

	DB_Quizzes::DB_Quizzes() {
		database_file = "Quizzes.db";
		database_info_file = database_file+".info";

		//Load Data
		this->LoadData<db_quiz_data>(quiz_data);
	}

	void DB_Quizzes::ReloadData() {
		this->LoadData<db_quiz_data>(quiz_data);
	}
	
	void DB_Quizzes::Update(db_quiz_data quiz_data) {
		int vector_index = getVectorIndex(quiz_data.qid);

		if (vector_index >= 0) {
			this->Delete(quiz_data.qid);

			this->quiz_data.push_back(quiz_data);
			record_change_count++;

			this->Write();
		}
	}

	void DB_Quizzes::Delete(int qid) {
		int vector_index = getVectorIndex(qid);

		if (vector_index >= 0) {
			quiz_data.erase(quiz_data.begin()+vector_index);
			record_change_count++;
		}

		this->Write();
	}

	void DB_Quizzes::DeleteCourse(int cid) {
		for (int i = 0; i < (int) quiz_data.size(); i++) {
			if (quiz_data[i].cid == cid) {
				quiz_data.erase(quiz_data.begin()+i);
				record_change_count++;
			}
		}

		this->Write();
	}

	int DB_Quizzes::Insert(db_quiz_data *quiz_data) {
		//Auto-assign UID
		quiz_data->qid = ++lastID;

		this->quiz_data.push_back(*quiz_data);
		record_change_count++;

		//Parameter lets the writ method know this is insertion.
		this->Write();
		
		return lastID;
	}
	
	vector<db_quiz_data> DB_Quizzes::getCourseQuizzes(int cid) {
		vector<db_quiz_data> packaged_data;

		for (int i = 0; i < (int) quiz_data.size(); i++) {
			if (quiz_data[i].cid == cid) {
				packaged_data.push_back(quiz_data[i]);
			}
		}

		return packaged_data;
	}

	db_quiz_data DB_Quizzes::getQuizData(int qid) {
		int vector_index = getVectorIndex(qid);

		return quiz_data[vector_index];
	}

	time_t DB_Quizzes::getOpenDate(int qid) {
		int vector_index = getVectorIndex(qid);

		if (vector_index >= 0)
			return quiz_data[vector_index].openDate;

		return -1;
	}

	time_t DB_Quizzes::getCloseDate(int qid) {
		int vector_index = getVectorIndex(qid);

		if (vector_index >= 0)
			return quiz_data[vector_index].closeDate;

		return -1;
	}

	int DB_Quizzes::getTimeLimit(int qid) {
		int vector_index = getVectorIndex(qid);

		if (vector_index >= 0)
			return quiz_data[vector_index].timeLimit;

		return -1;
	}

	int DB_Quizzes::getCID(int qid) {
		int vector_index = getVectorIndex(qid);

		if (vector_index >= 0)
			return quiz_data[vector_index].cid;

		return -1;
	}

	void DB_Quizzes::outputAllData() {
		if (!quiz_data.empty()) {
			for (int i = 0; i < (int) quiz_data.size(); i++) {
				cout << i+1 << ") ";
				cout << "cid: " << quiz_data[i].cid << endl; //Course ID - Autogenerated in this class.
				cout << "uid: " << quiz_data[i].qid << endl;
				cout << "open date: " << quiz_data[i].openDate << endl;
				cout << "close date: " << quiz_data[i].closeDate << endl;
				cout << "time limit (in seconds): " << quiz_data[i].timeLimit << endl;
				cout << endl << endl;
			}
		} else {
			cout << "Quiz Data is empty." << endl;
		}
	}

	int DB_Quizzes::getVectorIndex(int qid) {
		for (int i = 0; i < (int) quiz_data.size(); i++) {
			if (qid == quiz_data[i].qid) {
				return i;
			}
		}

		//Vector index of < 0 indicates failure to locate record.
		return -1;
	}

	void DB_Quizzes::Write(bool force_write) {
		if (record_change_count % record_change_mod_value == 0 || force_write)
			this->WriteData<db_quiz_data>(quiz_data);	
	}

	void DB_Quizzes::ClearData() {
		quiz_data.clear();
	}

	DB_Quizzes::~DB_Quizzes() {
		this->Write(true);
		this->ClearData();
	}
} /* namespace CSE360Project */