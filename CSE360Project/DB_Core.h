#pragma once

#include "stdafx.h"

using namespace std;

namespace CSE360Project {

	class DB_Core {
	public:
		DB_Core();

		///BEGIN PUBLIC METHODS THAT MODIFY DATA - "this->Write()" must be added before each method exits."
		virtual void Delete(int)=0;
		///END PUBLIC METHODS THAT MODIFY DATA

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
		char input_char;

		string database_file;
		string database_info_file;
		string benchmark_file;
		
		//this->WriteData<db_users_data>(user_data);
		template <class DB_DATA_TYPE>
		void WriteData(vector<DB_DATA_TYPE> &data_vector) {
			//Create timing class, and tic value.  Tic = start temporary timer variable.
			timingClass timing;
			timing.tic();

			//get number of elements in data vector
			int data_array_size =  (int) data_vector.size();

			//Open data.dat for writing.  ios:binary truncates.
			ofstream os (database_file, ios::binary);

			//Write size of data vector
			os.write(( char*)&data_array_size, 4);

			//Write data structure in one large dump. - if data vector is not empty.
			cout << sizeof(DB_DATA_TYPE) << endl;
			if (data_array_size > 0)
				os.write(( char*)&data_vector[0], data_array_size * sizeof(DB_DATA_TYPE));

			//Close connection
			os.close();

			//Write lastID
			this->writeLastID();

			//write benchmark
			this->writeBenchmark(data_array_size,timing.toc());
		}

		//this->LoadData<vector<db_users_data>>(user_data);
		template <class DB_DATA_TYPE>
		void LoadData(vector<DB_DATA_TYPE> &data_vector) {// Read it back in\
			//Clear Data Array
			this->ClearData();

			//Open data file.dat for reading.
			ifstream is(database_file, ios::binary);

			if (is.good()) {
				//Declare variable to hold size of data vector
				int data_array_size;

				//Read size of data vector
				is.read((char*)&data_array_size, 4);

				//Read lastID
				this->readLastID();

				//If data vector is not empty, read directly into memory space.
				if (data_array_size > 0) {
					data_vector.resize(data_array_size);
					is.read((char*)&data_vector[0], data_array_size * sizeof(DB_DATA_TYPE));
				}

				//Close file.
				is.close();
			}
		}

		void readLastID();
		void writeLastID();
		void writeBenchmark(int record_count, double time);

		//Other classes should never be able to call these functions.
		virtual void Open(ios_base::openmode mode = ios_base::in);
		virtual void Write(bool insert_record = false)=0;
		virtual void ClearData()=0;
		virtual void Close();
	};

} /* namespace CSE360Project */