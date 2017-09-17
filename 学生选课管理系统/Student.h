#ifndef _STU_H_ 
#define _STU_H_

#include<iostream>
#include<fstream>
#include<string>
#include"Arr.h"

using namespace std;

template<typename T>//在使用模板友元类之前一定要先声明
class Arr;

class Stu
{
private:
	string name_;
	string id_;
	Stu*p_next;

public:

	friend class Arr<Stu>;//这样写

	Stu(string name = "nobody", string number = "0") :name_(name), id_(number),p_next(NULL){};
	Stu(const Stu&);
	~Stu() {};
	friend ostream& operator<<(ostream&, const Stu&);
	const Stu&operator=(const Stu&);
	bool operator ==(const Stu& s)const { return (name_ == s.name_) && (id_ == s.id_); }
	bool operator>(const Stu& s) { return name_ > s.name_; }

	void setname(const string s) { name_ = s; }
	void setnumber(const string s) { id_ = s; }
	string getname() { return name_; }
	string getid() { return id_; }

	bool readfile(ifstream&);
	void writefile(ofstream&);
    void printhead(ofstream& fout)
	{
		fout << "     Student Data" << endl;
		fout << "student name" << "     " << "student id" << endl;
	}
	friend bool stucmpbyname(const Stu&, const Stu&);
	friend bool stucmpbyid(const Stu&, const Stu&);
};
#endif
