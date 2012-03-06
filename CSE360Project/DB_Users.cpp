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
	}

	void DB_Users::LoadData() {
		//Clear data in preparation for loading data.  If it's empty, will have no effect
		clearDataArray<db_users_data>(user_data);

		//Open if not already open
		this->Open();

		//Load Data


		//Close
		this->Close();
	}

	void DB_Users::Write() {

	}

	int DB_Users::Insert(db_users_data *user_data) {

		return 0;
	}

	bool DB_Users::validateUser(string username, string password) {
		int vector_index = getVectorIndex(username);

		if (vector_index >= 0 && password.compare(user_data[vector_index].password) == 0) {
			return true;
		}

		return false;
	}

	bool DB_Users::checkSecurityAnswer(string username, string answer) {
		int vector_index = getVectorIndex(username);

		if (vector_index >= 0 && answer.compare(user_data[vector_index].answer) == 0) {
			return true;
		}

		return false;
	}

	user_roles_t DB_Users::getUserRole(int uid() {
		return user_data[getVectorIndex(uid)].userRole;
	}

	string DB_Users::getUsername(int uid) {
		return user_data[ getVectorIndex(uid) ].username;
	}

	string DB_Users::getFirstname(int uid) {
		return user_data[ getVectorIndex(uid) ].firstName;
	}

	string DB_Users::getLastname(int uid) {
		return user_data[ getVectorIndex(uid) ].lastName;
	}

	string DB_Users::getSecurityQuestion(string username) {
		int vector_index = getVectorIndex(username);

		if (vector_index >= 0)
			return user_data[ vector_index ].securityQuestion;

		return "invalid";
	}

	int DB_Users::getUID(string username) {
		int vector_index = getVectorIndex(username);
		
		if (vector_index >= 0)
			return user_data[vector_index].uid;

		return 0;
	}

	int DB_Users::getVectorIndex(string username) {
		for (int i = 0; i < user_data.size(); i++) {
			if (username.compare(user_data[i].username) == 0) {
				return i;
			}
		}

		return -1;
	}

	int DB_Users::getVectorIndex(int uid) {
		for (int i = 0; i < user_data.size(); i++) {
			if (uid == user_data[i].uid) {
				return i;
			}
		}

		return -1;
	}

	DB_Users::~DB_Users() {
		// TODO Auto-generated destructor stub
	}

} /* namespace CSE360Project */