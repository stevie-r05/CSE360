#pragma once
#include "stdafx.h"
#include "DB_Core.h"


namespace CSE360Project {
	class DB_Enrolled: public CSE360Project::DB_Core {
	public:
		DB_Enrolled();

		///BEGIN PUBLIC METHODS THAT MODIFY DATA - "this->Write()" must be added before each method exits."
		void DeleteUser(int uid);
		void DeleteCourse(int cid);
		void Unenroll(int uid, int cid);
		int Insert(db_enrolled_data *enrolled_data);
		int Insert(int uid, int cid);
		///END PUBLIC METHODS THAT MODIFY DATA

		vector<db_enrolled_data> getEnrolledUsers(int cid);

		//Debug functions
		void outputAllData();

		virtual ~DB_Enrolled();

	private:
		std::vector<db_enrolled_data> enrolled_data;

		int getVectorIndex(int uid);

		void Write();
		void ClearData();
	};

} /* namespace CSE360Project */