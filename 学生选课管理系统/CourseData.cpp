#include"CourseData.h"

#include<iostream>
#include<fstream>
using namespace std;

bool CourseData::operator==(const CourseData& C)
{
	return course_ == C.course_;
}
CourseData& CourseData::operator=(const CourseData& C)
{
	if (this == &C)
		return *this;
	course_ = C.course_;
	stulist_ = C.stulist_;
	return *this;
}
ostream& operator<<(ostream&os, const CourseData& C)
{
	os << C.course_;
	return os;
}
bool CourseData::readfile(ifstream& fin)
{		
	return course_.readfile(fin);
}
void CourseData::writefile(ofstream& fout)
{
	course_.writefile(fout);
}
bool CourseData::addstudent(const Stu& S)
{
	return stulist_.arrinsert(S);
}
bool CourseData::dropstudent(const Stu& S)
{
	return stulist_.arrdel(S);
}
void CourseData::printstulist()
{
	cout << course_;
	cout << "STUDENTS TAKING THE COURSE" << endl;
	stulist_.printdata();
}
void CourseData::readstulist(const string& fname)
{
	stulist_.readfile(fname);
}
void CourseData::writestulist(const string& fpath)
{
	string fname = fpath + ' ' +course_.getname() + " student list.txt";
	stulist_.writefile(fname);
}