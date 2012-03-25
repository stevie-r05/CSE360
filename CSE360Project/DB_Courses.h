#pragma once
#include "stdafx.h"
#include "DB_Core.h"

namespace CSE360Project {
	class DB_Courses: public CSE360Project::DB_Core {
	public:
		DB_Courses();

		///BEGIN PUBLIC METHODS THAT MODIFY DATA - "this->Write()" must be added before each method exits."
		void Delete(int cid); //Delete course ID
		void DeleteUser(int uid); //Delete all courses belonging to user UID.
		int Insert(db_course_data *course_data);
		void Update(db_course_data course_data);
		///END PUBLIC METHODS THAT MODIFY DATA

		vector<db_course_data> getTaughtCourses(int uid);
		string getCourseName(int cid);
		vector<db_course_data> getAllCourseData();

		//Debug functions
		void ReloadData();
		void outputAllData();

		virtual ~DB_Courses();

	private:
		std::vector<db_course_data> course_data;

		int getVectorIndex(int cid);

		void Write(bool force_write = false);
		void ClearData();
	};

} /* namespace CSE360Project */