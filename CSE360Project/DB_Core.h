#pragma once

#include "stdafx.h"

using namespace std;

namespace CSE360Project {

	class DB_Core {
	public:
		DB_Core();

		virtual void Open(ios_base::openmode mode = ios_base::in);
		virtual void LoadData()=0;
		virtual void Write()=0;
		virtual void Close();

		int getLastID();
		int getRecordCount();

		virtual ~DB_Core();

		template<class dataType>
		void clearDataArray(vector<dataType> &data_array) {
			data_array.clear();
		}

	protected:
		ofstream out;
		ifstream in;

		int lastID;
		int record_count;

		string database_file;
	};

} /* namespace CSE360Project */