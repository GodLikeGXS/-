#ifndef _COURSE_DATA_H_
#define _COURSE_DATA_H_


#include"Student.h"
#include"Course.h"
#include<iostream>
using namespace std;

template<typename T>
class Arr;

class CourseData
{
private:
	Course course_;
	Arr<Stu>stulist_;
	CourseData*p_next;
public:

	friend Arr<CourseData>;

	CourseData(const string name = "nocourse", int credit = 0) :course_(name, credit) { p_next = NULL; };
	~CourseData() {};
	CourseData(const CourseData&C) :course_(C.course_), stulist_(C.stulist_) { p_next = NULL; }

	/*用于arr的接口*/
	bool operator==(const CourseData&);
	CourseData& operator=(const CourseData&);
	friend ostream& operator<<(ostream&, const CourseData&);
	bool readfile(ifstream&);
	void writefile(ofstream&);

	/*用于system的接口*/
	bool addstudent(const Stu&);
	bool dropstudent(const Stu&);
	void printstulist();
	void readstulist(const string&);
	void writestulist(const string&);
	friend bool coursecmpbyname(const CourseData&C1, const CourseData&C2)
	{
		return crscmpbyname(C1.course_, C2.course_);
	}
	friend bool coursecmpbycredit(const CourseData&C1, const CourseData& C2)
	{
		return crscmpbycredit(C1.course_, C2.course_);
	}
	/*还需要改进*/
	const Course& getcourseinfo()
	{
		return course_;
	}
	void printhead(ofstream& fout)
	{
		fout << "     Course Data" << endl;
		fout << "course name" << "     " << "course credit" << endl;
	}
};




#endif
