#include"system.h"



int csystem::searchstu( const Stu& S)const
{
	uint i;
	for (i = 0;i < SS_.getnum();i++)
		if (S == (SS_[i].getstuinfo()))
			return  i;

	return -1;
}
int csystem::searchcourse(const Course& C)const
{
	uint i;
	for (i = 0;i < CS_.getnum();i++)
		if (C == (CS_[i].getcourseinfo()))
			return i;
	return -1;
}
void csystem::add(const Stu&S,  const Course& C)
{
	int i = searchstu(S);
	if (i == -1)
	{
		cout << "student not find" << endl;
		return;
	}
	int j = searchcourse(C);
	if (j == -1)
	{
		cout << "course not find" << endl;
		return;
	}
	SS_[i].takecourse(C);
	CS_[j].addstudent(S);
}
void csystem::del(const Stu&S, const Course& C)
{
	int i = searchstu(S);
	if (i == -1)
	{
		cout << "student not find" << endl;
		return;
	}
	int j = searchcourse(C);
	if (j == -1)
	{
		cout << "course not find" << endl;
		return;
	}
	SS_[i].dropcourse(C);
	CS_[j].dropstudent(S);
}
void csystem::readallstu(const string&fname)
{
	SS_.readfile(fname);
}
void csystem::writeallstu(const string&fname)const
{
	SS_.writefile(fname);
}
void csystem::readallcourse(const string&fname)
{
	CS_.readfile(fname);
}
void csystem::writeallcourse(const string&fname)const
{
	CS_.writefile(fname);
}
void csystem::listallstu()const
{
	SS_.printdata();
}
void csystem::listallcourse()const
{
	CS_.printdata();
}
void csystem::listsbcourse(const Stu& S)const
{
	int i = searchstu(S);
	if (i == -1)
		return;
	SS_[i].printcourselist();
}
void csystem::listcoursestu(const Course&C)const
{
	int i = searchcourse(C);
	if (i == -1)
		return;
	CS_[i].printstulist();
}
void csystem::readsbcourse(const Stu&S, const string& fname)
{
	int i = searchstu(S);
	if (i == -1)
		return;
	SS_[i].readcourselist(fname);
}
void csystem::writesbcourse(const Stu&S, const string& fname)const
{
	int i = searchstu(S);
	if (i == -1)
		return;
	SS_[i].writecourselist(fname);
}
void csystem::readcoursestu(const Course&C, const string& fname)
{
	int i = searchcourse(C);
	if (i == -1)
		return;
	CS_[i].readstulist(fname);
}
void csystem::writecursestu(const Course&C, const string& fname)const
{
	int i = searchcourse(C);
	if (i == -1)
		return;
	CS_[i].writestulist(fname);
}
void csystem::sortstubyname()
{
	SS_.sort(stucmpbyname_studata);
}
void csystem::sortstubyid()
{
	SS_.sort(stucmpbyid_studata);
}
void csystem::sortcoursebyname()
{
	CS_.sort(coursecmpbyname);
}
void csystem::sortcoursebycredit()
{
	CS_.sort(coursecmpbycredit);
}