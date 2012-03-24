#pragma once
#include "stdafx.h"
#include "DB_Core.h"


namespace CSE360Project {
	class DB_Template: public CSE360Project::DB_Core {
	public:
		DB_Template();

		///BEGIN PUBLIC METHODS THAT MODIFY DATA - "this->Write()" must be added before each method exits."
		void Delete(int primary_id);
		int Insert(DB_TEMPLATE_DATA *template_data);
		///END PUBLIC METHODS THAT MODIFY DATA

		vector<DB_TEMPLATE_DATA> getTemplateData(int some_id);

		//Debug functions
		void outputAllData();

		virtual ~DB_Template();

	private:
		std::vector<DB_TEMPLATE_DATA> template_data;

		int getVectorIndex(int primary_id);

		void Write(bool force_write = false);
		void ClearData();
	};

} /* namespace CSE360Project */