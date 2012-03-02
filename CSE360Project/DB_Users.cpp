/*
* DBUsers.cpp
*
*  Created on: Mar 1, 2012
*      Author: Ian
*/
#include "stdafx.h"
#include "DB_Users.h"

namespace CSE360Project {

	DB_Users::DB_Users() {
		database_file = "Users.db";

		this->LoadData();
	}

	void DB_Users::LoadData() {
		//Clear data in preparation for loading data.  If it's empty, will have no effect
		clearDataArray<db_users_data>(user_data);

		//Open File
		this->Open();

		//Load Data


		//Close Data
		this->Close();
	}

	void DB_Users::Write() {

	}

	int DB_Users::Insert(db_users_data *user_data) {

		return 0;
	}

	bool DB_Users::checkPassword(string username, string password) {

		return false;
	}

	bool DB_Users::checkSecurityAnswer(string username, string answer) {
		return false;
	}

	user_roles_t DB_Users::getUserRole(int uid) {
		return student;
	}

	string DB_Users::getUsername(int uid) {
		return "default";
	}

	string DB_Users::getFirstname(int uid) {
		return "First";
	}

	string DB_Users::getLastname(int uid) {
		return "Last";
	}

	string DB_Users::getSecurityQuestion(string username) {
		return "Test?";
	}

	DB_Users::~DB_Users() {
		// TODO Auto-generated destructor stub
	}

} /* namespace CSE360Project */