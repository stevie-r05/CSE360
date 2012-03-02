using namespace std;

namespace CSE360Project {

class DB_Core {
public:
	DB_Core();

	virtual void Open()=0;
	virtual void LoadData()=0;
	virtual void Write()=0;
	virtual void Close()=0;

	int getLastID();
	int getRecordCount();

	virtual ~DB_Core();

protected:
	ofstream out;
	ifstream in;

	int lastID;
	int record_count;

};

} /* namespace CSE360Project */