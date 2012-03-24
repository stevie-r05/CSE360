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
	
	void DB_Answered::DeleteQuiz(int qid) {
		for (int i = 0; i < (int) answered_data.size(); i++) {
			if (answered_data[i].qid == qid) {
				answered_data.erase(answered_data.begin()+i);
				i++;
			}
		}

		this->Write();
	}

	void DB_Answered::DeleteQuestion(int question_id) {
		for (int i = 0; i < (int) answered_data.size(); i++) {
			if (answered_data[i].question_id == question_id) {
				answered_data.erase(answered_data.begin()+i);
				i++;
			}
		}

		this->Write();
	}

	void DB_Answered::DeleteUser(int uid) {
		for (int i = 0; i < (int) answered_data.size(); i++) {
			if (answered_data[i].uid == uid) {
				answered_data.erase(answered_data.begin()+i);
				i++;
			}
		}

		this->Write();
	}

	int DB_Answered::Insert(db_answered_data *answered_data) {
		//Auto-assign UID
		answered_data->aid = ++lastID;

		this->answered_data.push_back(*answered_data);

		//Parameter lets the writ method know this is insertion.
		this->Write();
		
		return lastID;
	}
	
	int DB_Answered::getUserAnswer(int uid, int question_id) {
		for (int i = 0; i < (int) answered_data.size(); i++) {
			if (uid == answered_data[i].uid && question_id == answered_data[i].question_id) {
				return i;
			}
		}

		//Vector index of < 0 indicates failure to locate record.
		return -1;
	}

	vector<db_answered_data> DB_Answered::getUsersAnswers(int uid) {
		vector<db_answered_data> packaged_data;

		for (int i = 0; i < (int) answered_data.size(); i++) {
			if (answered_data[i].uid == uid) {
				packaged_data.push_back(answered_data[i]);
			}
		}

		return packaged_data;
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

	void DB_Answered::Write() {
		this->WriteData<db_answered_data>(answered_data);	
	}

	void DB_Answered::ClearData() {
		answered_data.clear();
	}

	DB_Answered::~DB_Answered() {
		this->ClearData();
	}
} /* namespace CSE360Project */