#include"Course.h"
#include"Student.h"
#include<iostream>
using namespace std;


ostream& operator<<(ostream& os, const Course& C)
{
	os << "course name: " << C.name_ << " credit: " << C.credit_ << endl;
	return os;
}
Course& Course::operator=(const Course& C)
{
	if (this == &C)
		return *this;
	name_ = C.name_;
	credit_ = C.credit_;
	p_next = NULL;
	return *this;
}
Course::Course(const Course& C)
{
	name_ = C.name_;
	credit_ = C.credit_;
	p_next = NULL;
}
bool Course::readfile(ifstream& fin)
{
	if (fin >> name_)
	{
		fin >> credit_;
		return true;
	}
	else
		return false;
}
void Course::writefile(ofstream& fout)
{
	fout << name_ << " " << credit_<< endl;
}

bool crscmpbyname(const Course& C1, const Course& C2)
{
	return C1.name_ >= C2.name_;
}
bool crscmpbycredit(const Course&C1, const Course& C2)
{
	return C1.credit_ >= C2.credit_;
}