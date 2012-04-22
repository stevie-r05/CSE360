/*
* DBCourses.cpp
*
*  Created on: Mar 1, 2012
*      Author: Ian
*/
#include "stdafx.h"
#include "DB_Scores.h"
#include "timingClass.h"

namespace CSE360Project {

	DB_Scores::DB_Scores() {
		database_file = "Scores.db";
		database_info_file = database_file+".info";

		//Load Data
		this->LoadData<db_score_data>(score_data);
	}

	void DB_Scores::ReloadData() {
		this->LoadData<db_score_data>(score_data);
	}
	
	void DB_Scores::Update(db_score_data score_data) {
		int vector_index = getVectorIndex(score_data.sid);

		if (vector_index >= 0) {
			this->Delete(score_data.sid);

			this->score_data.push_back(score_data);
			record_change_count++;

			this->Write();
		}
	}
	
	void DB_Scores::Update(vector<db_score_data> score_data) {
		int vector_index;
		for (int i = 0; i < (int) score_data.size(); i++) {
			vector_index = getVectorIndex(score_data[i].sid);

			if (vector_index >= 0) {
				this->Delete(score_data[i].sid);

				this->score_data.push_back(score_data[i]);
				record_change_count++;
			} else {
				this->Insert(score_data);
			}

			this->Write();
		}
	}

	void DB_Scores::Delete(int sid) {
		int vector_index = getVectorIndex(sid);

		if (vector_index >= 0) {
			score_data.erase(score_data.begin()+vector_index);
			record_change_count++;

			this->Write();
		}
	}

	void DB_Scores::DeleteQuiz(int qid) {
		for (int i = 0; i < (int) score_data.size(); i++) {
			if (score_data[i].qid == qid) {
				score_data.erase(score_data.begin()+i);
				record_change_count++;
			}
		}

		this->Write();
	}

	void DB_Scores::DeleteUser(int uid) {
		for (int i = 0; i < (int) score_data.size(); i++) {
			if (score_data[i].uid == uid) {
				score_data.erase(score_data.begin()+i);
				record_change_count++;
			}
		}

		this->Write();
	}

	void DB_Scores::DeleteCourse(int cid) {
		for (int i = 0; i < (int) score_data.size(); i++) {
			if (score_data[i].cid == cid) {
				score_data.erase(score_data.begin()+i);
				record_change_count++;
			}
		}

		this->Write();
	}

	void DB_Scores::Insert(vector<db_score_data> score_data) {
		for (int i = 0; i < (int) score_data.size(); i++) {
			//Auto-assign UID
			score_data[i].sid = ++lastID;
			this->score_data.push_back(score_data[i]);
			record_change_count++;
		}

		//Parameter lets the writ method know this is insertion.
		this->Write();
	}
	
	int DB_Scores::Insert(db_score_data *score_data) {
		score_data->sid = ++lastID;

		this->score_data.push_back(*score_data);
		record_change_count++;

		this->Write();

		return lastID;
	}

	vector<db_score_data> DB_Scores::getQuizScores(int qid) {
		vector<db_score_data> packaged_data;
		for (int i = 0; i < (int) score_data.size(); i++) {
			if (score_data[i].qid == qid) {
				packaged_data.push_back(score_data[i]);
			}
		}

		return packaged_data;
	}

	vector<db_score_data> DB_Scores::getUserScores(int uid) {
		vector<db_score_data> packaged_data;

		for (int i = 0; i < (int) score_data.size(); i++) {
			if (score_data[i].uid == uid) {
				packaged_data.push_back(score_data[i]);
			}
		}

		return packaged_data;
	}

	vector<db_score_data> DB_Scores::getClassScores(int cid) {
		vector<db_score_data> packaged_data;

		for (int i = 0; i < (int) score_data.size(); i++) {
			if (score_data[i].cid == cid) {
				packaged_data.push_back(score_data[i]);
			}
		}

		return packaged_data;
	}

	double DB_Scores::getUserQuizScore(int uid, int qid) {
		for (int i = 0; i < (int) score_data.size(); i++) {
			if (score_data[i].uid == uid && score_data[i].qid == qid) {
				return score_data[i].score;
			}
		}

		return -1;
	}

	void DB_Scores::outputAllData() {
		if (!score_data.empty()) {
			for (int i = 0; i < (int) score_data.size(); i++) {
				cout << i+1 << ") ";
				cout << "sid: " << score_data[i].sid << endl; //Course ID - Autogenerated in this class.
				cout << "uid: " << score_data[i].uid << endl;
				cout << "qid: " << score_data[i].qid << endl;
				cout << "cid: " << score_data[i].cid << endl;
				cout << "score: " << score_data[i].score << endl;
				cout << endl << endl;
			}
		} else {
			cout << "Scores Data is empty." << endl;
		}
	}

	int DB_Scores::getVectorIndex(int cid) {
		for (int i = 0; i < (int) score_data.size(); i++) {
			if (cid == score_data[i].cid) {
				return i;
			}
		}

		//Vector index of < 0 indicates failure to locate record.
		return -1;
	}

	void DB_Scores::Write(bool force_write) {
		if (record_change_count % record_change_mod_value == 0 || force_write)
			this->WriteData<db_score_data>(score_data);	
	}

	void DB_Scores::ClearData() {
		score_data.clear();
	}

	DB_Scores::~DB_Scores() {
		this->Write(true);
		this->ClearData();
	}
} /* namespace CSE360Project */