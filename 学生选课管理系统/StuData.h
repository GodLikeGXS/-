#ifndef _STU_DATA_H_
#define _STU_DATA_H_


#include"Course.h"
#include"Student.h"
#include<iostream>
using namespace std;

template<typename T>
class Arr;


class StuData
{
private:
	Stu person_;
	Arr<Course> courselist_;
	StuData*p_next;

public:

	friend Arr<StuData>;
	StuData(const string&name = "nobody", const string&id = "0") :person_(name, id) { p_next = NULL; };
	~StuData() {};
	StuData(const StuData& S) :person_(S.person_), courselist_(S.courselist_) { p_next = NULL; }

	/*用于arr的接口*/
	bool operator==(const StuData&);
	StuData& operator=(const StuData&);
	friend ostream& operator<<(ostream&, const StuData&);
	bool readfile(ifstream&);
	void writefile(ofstream&);

	/*用于system的接口*/
	bool takecourse(const Course&);
	bool dropcourse(const Course&);
	void printcourselist();
	void readcourselist(const string&);
	void writecourselist(const string&);
	friend bool stucmpbyname_studata(const StuData&S1, const StuData&S2)
	{
		return stucmpbyname(S1.person_, S2.person_);
	}
	friend bool stucmpbyid_studata(const StuData&S1, const StuData&S2)
	{
		return stucmpbyid(S1.person_, S2.person_);
	}

	/*还需要改进*/
	const Stu& getstuinfo()
	{
		return person_;
	}
	void printhead(ofstream& fout)
	{
		fout << "     Student Data" << endl;
		fout << "student name" << "     " << "student id" << endl;
	}
};




#endif