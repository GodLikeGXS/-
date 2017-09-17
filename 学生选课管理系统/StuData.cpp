#include"StuData.h"

#include<iostream>
#include<fstream>
using namespace std;


bool StuData::operator==(const StuData& C)
{
	return (person_ == C.person_);
}
StuData& StuData::operator=(const StuData& S)
{
	if (this == &S)
		return *this;
	person_ = S.person_;
	courselist_ = S.courselist_;
	return *this;
}
ostream& operator<<(ostream&os,const StuData& S)
{
	os << S.person_;
	return os;
}
bool StuData::readfile(ifstream& fin)
{
	return person_.readfile(fin);
}
void StuData::writefile(ofstream& fout)
{
	person_.writefile(fout);
}


bool StuData::takecourse(const Course& C)
{
	return courselist_.arrinsert(C);
}
bool StuData::dropcourse(const Course& C)
{
	return courselist_.arrdel(C);
}
void StuData::printcourselist()
{
	cout << person_;
	cout << "COURSE LIST" << endl;
	courselist_.printdata();
}
void StuData::readcourselist(const string& fname)
{
	courselist_.readfile(fname);
}
void StuData::writecourselist(const string& fpath)
{
	string fname;
	fname =fpath+ person_.getname() + ' ' + person_.getid()+ " course list.txt";
	courselist_.writefile(fname);
}