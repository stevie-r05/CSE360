/*
* DBCourses.cpp
*
*  Created on: Mar 1, 2012
*      Author: Ian
*/
#include "stdafx.h"
#include "DB_Enrolled.h"
#include "timingClass.h"

namespace CSE360Project {

	DB_Enrolled::DB_Enrolled() {
		database_file = "Enrolled.db";
		database_info_file = database_file+".info";

		//Load Data
		this->LoadData<db_enrolled_data>(enrolled_data);
	}

	void DB_Enrolled::ReloadData() {
		this->LoadData<db_enrolled_data>(enrolled_data);
	}
	
	void DB_Enrolled::Update(db_enrolled_data enrolled_data) {
		int vector_index = getVectorIndex(enrolled_data.eid);

		if (vector_index >= 0) {
			this->Delete(enrolled_data.eid);

			this->enrolled_data.push_back(enrolled_data);
			record_change_count++;

			this->Write();
		}
	}

	void DB_Enrolled::Delete(int eid) {
		int vector_index = getVectorIndex(eid);

		if (vector_index >= 0) {
			enrolled_data.erase(enrolled_data.begin()+vector_index);
			record_change_count++;

		this->Write();
		}
	}

	void DB_Enrolled::DeleteUser(int uid) {
		for (int i = 0; i < (int) enrolled_data.size(); i++) {
			if (enrolled_data[i].uid == uid) {
				enrolled_data.erase(enrolled_data.begin()+i);
				record_change_count++;
			}
		}

		this->Write();
	}

	void DB_Enrolled::DeleteCourse(int cid) {
		for (int i = 0; i < (int) enrolled_data.size(); i++) {
			if (enrolled_data[i].cid == cid) {
				enrolled_data.erase(enrolled_data.begin()+i);
				record_change_count++;
			}
		}

		this->Write();
	}

	void DB_Enrolled::Unenroll(int eid) {
		int vector_index = getVectorIndex(eid);

		if (vector_index >= 0) {
			enrolled_data.erase(enrolled_data.begin()+vector_index);
			record_change_count++;
		}

		this->Write();
	}

	void DB_Enrolled::Unenroll(int uid, int cid) {
		for (int i = 0; i < (int) enrolled_data.size(); i++) {
			if (enrolled_data[i].cid == cid && enrolled_data[i].uid == uid) {
				enrolled_data.erase(enrolled_data.begin()+i);
				record_change_count++;
				break;
			}
		}

		this->Write();
	}

	int DB_Enrolled::Insert(db_enrolled_data *enrolled_data) {
		//Auto-assign UID
		enrolled_data->eid = ++lastID;

		this->enrolled_data.push_back(*enrolled_data);
		record_change_count++;

		//Parameter lets the writ method know this is insertion.
		this->Write();

		return lastID;
	}

	int DB_Enrolled::Insert(int uid, int cid) {
		enrolled_data.push_back(*(new db_enrolled_data));
		enrolled_data.back().eid = ++lastID;
		enrolled_data.back().uid = uid;
		enrolled_data.back().cid = cid;
		record_change_count++;

		//Parameter lets the writ method know this is insertion.
		this->Write();

		return lastID;
	}

	vector<db_enrolled_data> DB_Enrolled::getEnrolledUsers(int cid) {
		vector<db_enrolled_data> packaged_data;

		for (int i = 0; i < (int) enrolled_data.size(); i++) {
			if (enrolled_data[i].cid == cid) {
				packaged_data.push_back(enrolled_data[i]);
			}
		}

		return packaged_data;
	}

	vector<db_enrolled_data> DB_Enrolled::getEnrolledCourses(int uid) {
		vector<db_enrolled_data> packaged_data;

		for (int i = 0; i < (int) enrolled_data.size(); i++) {
			if (enrolled_data[i].uid == uid) {
				packaged_data.push_back(enrolled_data[i]);
			}
		}

		return packaged_data;
	}

	void DB_Enrolled::outputAllData() {
		if (!enrolled_data.empty()) {
			for (int i = 0; i < (int) enrolled_data.size(); i++) {
				cout << i+1 << ") ";
				cout << "cid: " << enrolled_data[i].cid << endl; //Course ID - Autogenerated in this class.
				cout << "uid: " << enrolled_data[i].uid << endl;
				cout << "eid: " << enrolled_data[i].eid << endl;
				cout << endl << endl;
			}
		} else {
			cout << "Enrolled Data is empty." << endl;
		}
	}

	int DB_Enrolled::getVectorIndex(int uid) {
		for (int i = 0; i < (int) enrolled_data.size(); i++) {
			if (uid == enrolled_data[i].uid) {
				return i;
			}
		}

		//Vector index of < 0 indicates failure to locate record.
		return -1;
	}

	void DB_Enrolled::Write(bool force_write) {
		if (record_change_count % record_change_mod_value == 0 || force_write)
			this->WriteData<db_enrolled_data>(enrolled_data);	
	}

	void DB_Enrolled::ClearData() {
		enrolled_data.clear();
	}

	DB_Enrolled::~DB_Enrolled() {
		this->Write(true);
		this->ClearData();
	}
} /* namespace CSE360Project */