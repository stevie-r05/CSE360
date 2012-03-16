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

	//DEPRECATED.
	void DB_Core::Open(ios_base::openmode mode) {
		if (mode == ios_base::out || mode == ios_base::app || mode == ios_base::trunc) {
			if (!out.is_open()) {
				//ios_base::trunc = overwrite.
				out.open(database_file, mode);
			}
		} else {
			if (!in.is_open()) {
				in.open(database_file, mode);
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

	void DB_Core::readLastID() {
		ifstream in;
		string lastID;
		char input_char;

		in.open(database_info_file, ios_base::in);

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

		if (in.is_open())
			in.close();
	}

	void DB_Core::writeLastID() {
		ofstream out;
		out.open(database_info_file, ios_base::trunc);
		if (out.is_open()) {
			out << this->lastID << DATA_ROW_TERMINATE;
			out.close();
		}
	}

	/* BACKUP
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
	}*/

	/*
	*This function somply records the time it took to write record_count records to benchmark file.
	*/
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
