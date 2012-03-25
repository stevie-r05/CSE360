/*
* DBCourses.cpp
*
*  Created on: Mar 1, 2012
*      Author: Ian
*/
#include "stdafx.h"
#include "DB_Answered.h"
#include "timingClass.h"

namespace CSE360Project {

	DB_Answered::DB_Answered() {
		database_file = "Answered.db";
		database_info_file = database_file+".info";

		//Load Data
		this->LoadData<db_answered_data>(answered_data);
	}

	void DB_Answered::ReloadData() {
		this->LoadData<db_answered_data>(answered_data);
	}
	
	void DB_Answered::Update(db_answered_data answered_data) {
		int vector_index = getVectorIndex(answered_data.aid);

		if (vector_index >= 0) {
			this->Delete(answered_data.aid);

			this->answered_data.push_back(answered_data);
			record_change_count++;

			this->Write();
		}
	}
	
	void DB_Answered::Update(vector<db_answered_data> answered_data) {
		int vector_index;
		for (int i = 0; i < (int) answered_data.size(); i++) {
			vector_index = getVectorIndex(answered_data[i].aid);

			if (vector_index >= 0) {
				this->Delete(answered_data[i].aid);

				this->answered_data.push_back(answered_data[i]);
				record_change_count++;
			} else {
				this->Insert(answered_data);
			}

			this->Write();
		}
	}
	
	void DB_Answered::Delete(int aid) {
		int vector_index = getVectorIndex(aid);

		if (vector_index >= 0) {
			answered_data.erase(answered_data.begin()+vector_index);
			record_change_count++;
		}

		this->Write();
	}
	
	void DB_Answered::DeleteQuiz(int qid) {
		for (int i = 0; i < (int) answered_data.size(); i++) {
			if (answered_data[i].qid == qid) {
				answered_data.erase(answered_data.begin()+i);
				record_change_count++;
			}
		}

		this->Write();
	}

	void DB_Answered::DeleteQuestion(int question_id) {
		for (int i = 0; i < (int) answered_data.size(); i++) {
			if (answered_data[i].question_id == question_id) {
				answered_data.erase(answered_data.begin()+i);
				record_change_count++;
			}
		}

		this->Write();
	}

	void DB_Answered::DeleteUser(int uid) {
		for (int i = 0; i < (int) answered_data.size(); i++) {
			if (answered_data[i].uid == uid) {
				answered_data.erase(answered_data.begin()+i);
				record_change_count++;
			}
		}

		this->Write();
	}

	int DB_Answered::Insert(db_answered_data *answered_data) {
		answered_data->aid = ++lastID;

		this->answered_data.push_back(*answered_data);
		record_change_count++;

		//Parameter lets the writ method know this is insertion.
		this->Write();
		
		return lastID;
	}

	void DB_Answered::Insert(vector<db_answered_data> answered_data) {
		for (int i = 0; i < (int) answered_data.size(); i++) {
			answered_data[i].aid = ++lastID;
			this->answered_data.push_back(answered_data[i]);
			record_change_count++;
		}

		//Parameter lets the writ method know this is insertion.
		this->Write();
	}
	
	int DB_Answered::getUserAnswer(int uid, int question_id) {
		for (int i = 0; i < (int) answered_data.size(); i++) {
			if (uid == answered_data[i].uid && question_id == answered_data[i].question_id) {
				return answered_data[i].answer;
			}
		}

		//Vector index of < 0 indicates failure to locate record.
		return -1;
	}

	vector<db_answered_data> DB_Answered::getUsersQuizAnswers(int uid, int qid) {
		vector<db_answered_data> packaged_data;

		for (int i = 0; i < (int) answered_data.size(); i++) {
			if (answered_data[i].uid == uid && answered_data[i].qid == qid) {
				packaged_data.push_back(answered_data[i]);
			}
		}

		return packaged_data;
	}

	int DB_Answered::getQID(int aid) {
		int vector_index = getVectorIndex(aid);

		if (vector_index >= 0)
			return answered_data[vector_index].qid;

		return -1;
	}

	int DB_Answered::getUID(int aid) {
		int vector_index = getVectorIndex(aid);

		if (vector_index >= 0)
			return answered_data[vector_index].uid;

		return -1;
	}

	int DB_Answered::getVectorIndex(int aid) {
		for (int i = 0; i < (int) answered_data.size(); i++) {
			if (aid == answered_data[i].aid) {
				return i;
			}
		}

		//Vector index of < 0 indicates failure to locate record.
		return -1;
	}

	void DB_Answered::outputAllData() {
		if (!answered_data.empty()) {
			for (int i = 0; i < (int) answered_data.size(); i++) {
				cout << i+1 << ") ";
				cout << "aid: " << answered_data[i].aid << endl;
				cout << "uid: " << answered_data[i].uid << endl;
				cout << "qid: " << answered_data[i].qid << endl;
				cout << "question_id: " << answered_data[i].question_id << endl;
				cout << "answer: " << answered_data[i].answer << endl;
				cout << endl << endl;
			}
		} else {
			cout << "Course Data is empty." << endl;
		}
	}

	void DB_Answered::Write(bool force_write) {
		if (record_change_count % record_change_mod_value == 0 || force_write)
			this->WriteData<db_answered_data>(answered_data);	
	}

	void DB_Answered::ClearData() {
		answered_data.clear();
	}

	DB_Answered::~DB_Answered() {
		this->Write(true);
		this->ClearData();
	}
} /* namespace CSE360Project */