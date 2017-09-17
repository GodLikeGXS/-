#ifndef _COURSE_H_
#define _COURSE_H_

#include<string>
#include<iostream>
#include<fstream>
#include"Arr.h"
using namespace std;


template<typename T>
class Arr;

class Course
{
private:
	string name_;
	uint credit_;
	Course*p_next;

public:

	friend class Arr<Course>;

	~Course() {};
	Course(const Course&);
	Course(string n = "noclass", int c = 0) :name_(n), credit_(c),p_next(NULL){};
	friend ostream&operator<<(ostream&, const Course&);
	Course& operator = (const Course&);
	
	bool operator==(const Course& c)const { return (name_ == c.name_) && (credit_ == c.credit_); }
	bool operator>(const Course& c) { return credit_ > c.credit_; }
	
	void setname(const string s) { name_ = s; }
	void setcredit(unsigned int c) { credit_ = c; }
	string getname() { return name_; }
	int getcredit()const { return credit_; }
	
	bool readfile(ifstream&);
	void writefile(ofstream&);
	void printhead(ofstream& fout)
	{
		fout << "     Course Data" << endl;
		fout << "course name" << "     " << "course credit" << endl;
	}

	friend bool crscmpbyname(const Course&, const Course&);
	friend bool crscmpbycredit(const Course&, const Course&);
};





#endif
