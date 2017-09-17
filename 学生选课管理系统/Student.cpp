#include"Student.h"

#include<iostream>
#include<fstream>
#include<string>
using namespace std;


ostream& operator<<(ostream&os, const Stu& S)
{
	os << "student name: " << S.name_ << " student id " << S.id_ << endl;
	return os;
}
const Stu& Stu:: operator=(const Stu& S)
{
	if (&S == this)
		return *this;

	name_ = S.name_;
	id_ = S.id_;
	return *this;
}
Stu::Stu(const Stu& S)
{
	name_ = S.name_;
	id_ = S.id_;
	p_next = NULL;
}
bool Stu::readfile(ifstream& fin)
{
	if (fin >> name_)
	{
		fin >> id_;
		return true;
	}
	else
		return false;
}
void Stu::writefile(ofstream& fout)
{
	fout << name_ << " " << id_ << endl;
} 

bool stucmpbyname(const Stu&S1, const Stu&S2)
{
	return S1.name_ >= S2.name_;
}
bool stucmpbyid(const Stu&S1, const Stu& S2)
{
	return S1.id_ >= S2.id_;
}
