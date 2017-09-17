#ifndef _SYS_H_
#define _SYS_H_

#include"StuData.h"
#include"CourseData.h"
#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
class Arr;


class csystem
{
private:
	Arr<StuData>SS_;
	Arr<CourseData>CS_;
	int searchstu(const Stu&)const;//stu应该声明为const
	int searchcourse(const Course&)const;
public:
	csystem() {};
	~csystem() {};
	void add(const Stu&, const Course&);
	void del(const Stu&, const Course&);
	void readallstu(const string&);
	void writeallstu(const string&)const;
	void readallcourse(const string&);
	void writeallcourse(const string&)const;
	void listallcourse()const;
	void listallstu()const;
	void listsbcourse(const Stu&)const;
	void listcoursestu(const Course&)const;
	void readsbcourse(const Stu&, const string&);
	void writesbcourse(const Stu&, const string&)const;
	void readcoursestu(const Course&, const string&);
	void writecursestu(const Course&, const string&)const;
	void sortstubyname();
	void sortstubyid();
	void sortcoursebycredit();
	void sortcoursebyname();
};
#endif