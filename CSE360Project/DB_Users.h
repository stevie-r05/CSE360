#pragma once
#include "stdafx.h"
#include "DB_Core.h"

namespace CSE360Project {
	class DB_Users: public CSE360Project::DB_Core {
	public:
		DB_Users();

		void LoadData();
		void Write();

		int Insert(db_users_data *user_data);

		bool validateUser(string username, string password);
		bool checkSecurityAnswer(string username, string answer);

		user_roles_t getUserRole(int uid);
		string getUsername(int uid);
		string getFirstname(int uid);
		string getLastname(int uid);
		string getSecurityQuestion(string username);
		int getUID(string username);


		virtual ~DB_Users();

	private:
		std::vector<db_users_data> user_data;

		int getVectorIndex(string username);
		int getVectorIndex(int uid);
	};

} /* namespace CSE360Project */