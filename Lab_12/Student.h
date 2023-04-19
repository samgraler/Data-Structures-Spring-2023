#include <string>


using namespace std;

class Student {
public:
	string first;
	string last;
	int mnumber;

	// Constructor / destructor
	Student(string first = "test", string last = "name", int mnumber = 0);
	~Student();

	string getData(int key);
};