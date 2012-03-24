#pragma once
#include "stdafx.h"
#include "DB_Core.h"

namespace CSE360Project {
	class DB_Users: public CSE360Project::DB_Core {
	public:
		DB_Users();

		
		///BEGIN PUBLIC METHODS THAT MODIFY DATA - "this->Write()" must be added before each method exits."
		void Delete(int);
		int Insert(db_users_data *user_data);
		///END PUBLIC METHODS THAT MODIFY DATA

		bool validateUser(string username, string password);
		bool checkSecurityAnswer(string username, string answer);

		user_roles_t getUserRole(int uid);
		string getUsername(int uid);
		string getFirstname(int uid);
		string getLastname(int uid);
		string getSecurityQuestion(string username);
		int getUID(string username);
		db_users_data getUserData(int uid);

		//Debug functions
		void ReloadData();
		void outputAllData();

		virtual ~DB_Users();

	private:
		std::vector<db_users_data> user_data;

		int getVectorIndex(string username);
		int getVectorIndex(int uid);

		void Write(bool force_write = false);
		void ClearData();
	};

} /* namespace CSE360Project */