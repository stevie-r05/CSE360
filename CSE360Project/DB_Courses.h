#pragma once
#include "stdafx.h"
#include "DB_Core.h"

namespace CSE360Project {
	class DB_Courses: public CSE360Project::DB_Core {
	public:
		DB_Courses();

		void LoadData();
		
		void Delete(int cid);
		void DeleteUser(int uid);

		void Write();

		int Insert(db_course_data *course_data);

		vector<db_course_data> getCourseData(int uid);
		string getCourseName(int cid);

		//Debug functions
		void outputAllCourses();

		virtual ~DB_Courses();

	private:
		std::vector<db_course_data> course_data;

		int getVectorIndex(int cid);

		//consider returning a vector.
		//vector<int> getVectorIndex(int uid);
	};

} /* namespace CSE360Project */