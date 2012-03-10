/*
* DBCore.cpp
*
*  Created on: Mar 1, 2012
*      Author: Ian
*/
#include "stdafx.h"
#include "DB_Core.h"

namespace CSE360Project {

	DB_Core::DB_Core() {
		record_count = 0;
		lastID = 0;

		benchmark_file = "benchmarks_db_write.txt";
	}

	void DB_Core::Open(ios_base::openmode mode) {
		if (mode == ifstream::in) {
			if (!in.is_open()) {
				in.open(database_file, ios_base::in);
			}
		} else if (mode == ios_base::out) {
			if (!out.is_open()) {
				//ios_base::trunc = overwrite.
				out.open(database_file, ios_base::trunc);
			}
		}
	}

	int DB_Core::getLastID() {
		return lastID;
	}

	int DB_Core::getRecordCount() {
		return record_count;
	}

	void DB_Core::Close() {
		//Does this function want to save 'unsaved' data first or do we want a function do this explicitly?
		if (in.is_open())
			in.close();

		if (in.is_open())
			out.close();
	}

	//Write pertinent data before recording data.
	void DB_Core::dbFileHeader() {
		if (out.is_open())
			out << lastID << DATA_ROW_TERMINATE;
	}

	void DB_Core::readLastID() {
		string lastID = "";

		while (in.good()) {
			input_char = in.get();

			//If terminate character is read we are done reading lastID
			if (input_char == DATA_ROW_TERMINATE)
				break;

			//If terminate character not read, we're still in last id.
			lastID += input_char;
		}
		
		if (!lastID.empty()) {
			//If last id is not empty, cast it to interger and save it!
			this->lastID = atoi(lastID.c_str());
		} else {
			this->lastID = 0;
		}
	}

	void DB_Core::writeBenchmark(int record_count, double time) {
		ofstream out;
		out.open(benchmark_file, ios_base::app);
		if (out.is_open()) {
			out << record_count << '\t' << time << '\n';
			out.close();
		}
	}

	DB_Core::~DB_Core() {
	}

} /* namespace CSE360Project */
