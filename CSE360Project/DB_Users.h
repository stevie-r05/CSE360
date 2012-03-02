#include "stdafx.h"
#include "DB_Core.h"

namespace CSE360Project {

class DB_Users: public CSE360Project::DB_Core {
public:
	DB_Users();

	void Open();
	void LoadData();
	void Write();
	void Close();

	virtual ~DB_Users();
};

} /* namespace CSE360Project */