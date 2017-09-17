#include<iostream>
#include<string>
#include"system.h"
using namespace std;
const char*fwname = "D://write.txt";
const char*frname = "D://read.txt";

int main()
{
	/*Arr<Stu>SD;
	SD.readfile(frname);
	cout << SD;*/

	Arr<Stu>SD;
	Stu s1("tom", "151220001");
	//SD.arrinsert(s1);
	//SD.arrdel(s1);
	//cout << SD;
	/*SD.readfile(frname);
	SD.writefile(fwname);
	SD.arrinsert(s1);
	SD.writefile(fwname);
	SD.printdata();*/
	csystem sys;
	sys.readallstu(frname);
	//sys.listallstu();
	Stu G("¹ÈÏþËÉ", "151220033");
	//sys.readsbcourse(G, "D://coursename.txt");
	//sys.listsbcourse(G);
	sys.sortstubyid();
	sys.listallstu();
	return 0;
}