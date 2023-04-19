#include "Student.h"

Student::Student(string first, string last, int mnumber)
{
	first = first;
	last = last;
	mnumber = mnumber;
}
Student::~Student()
{
	
}

string Student::getData(int key)
{
	if (key == 0)
	{
		return first;
	}
	else if (key == 1)
	{
		return last;
	}
	else
	{
		return to_string(mnumber);
	}
}