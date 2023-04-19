#include "Student.h"

Student::Student(string f, string l, long m)
{
	first = f;
	last = l;
	mnumber = m;
}

Student::Student(Student &s)
{
	first = s.first;
	last = s.last;
	mnumber = s.mnumber;
}

Student::~Student()
{
	
}

string Student::getData(int key)
{
	if (key == 1)
	{
		return first;
	}
	else if (key == 2)
	{
		return last;
	}
	else
	{
		return to_string(mnumber);
	}
}

void Student::Print()
{
	cout << "First Name: " << first << " Last Name: " << last << " MNumber: " << mnumber << endl;
}