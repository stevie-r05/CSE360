#pragma once

#include "stdafx.h"

using namespace std;

namespace CSE360Project {

	class DB_Core {
	public:
		DB_Core();

		virtual void Open(ios_base::openmode mode);
		virtual void LoadData()=0;
		virtual void Delete(int)=0;
		virtual void Write()=0;
		virtual void Close();

		int getLastID();
		int getRecordCount();

		virtual ~DB_Core();

	protected:
		ofstream out;
		ifstream in;

		//Do not edit lastID or record count from outside the class.
		//-These will be automatically updated into your structure and 
		//  incremented properly.
		int lastID;
		int record_count;

		string database_file;
		string benchmark_file;
		
		void writeBenchmark(int record_count, double time);
	};

} /* namespace CSE360Project */