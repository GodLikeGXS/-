#ifndef _ARR_H_
#define _ARR_H_

typedef unsigned int uint;
#include<iostream>
#include<fstream>
#include<string>

using namespace std;



template<typename T>
class Arr
{
private:
	T*head_;
	T*tail_;
	uint total_;
	void arrqksort(int first, int last,bool (*cmp)(const T&,const T&));
public:
	Arr() :head_(NULL), tail_(NULL), total_(0) {};
	Arr(const Arr&);
	~Arr();
	bool arrinsert(const T&);
	bool arrdel(const T&);
	//friend ostream& operator<< (ostream&, const Arr<T>&);//存在编译问题 不明白为什么
	void printdata()const;
	const Arr& operator=(const Arr&);
	T& operator[](uint)const;
	int arrsearch(const T&);
	void readfile(const string&);
	void writefile(const string&)const;
	void sort(bool (*cmp)(const T&,const T&));
	uint getnum()const { return total_; }// 为什么加const就出问题 因为const加在声明后 不是定义后
};



template<typename T>
Arr<T>::~Arr()
{
	T*p = head_;
	while (p!=NULL)
	{
		T*tem = p;
		p = p->p_next;
		delete tem;
	}
}
template<typename T>
Arr<T>:: Arr(const Arr<T>& A)
{
	T*pa = A.head_;
	while (pa)
	{
		arrinsert(*pa);
		pa = pa->p_next;
	}
}
template<typename T>
const Arr<T>& Arr<T>::operator=(const Arr<T>& A)
{
	if (&A == this)
		return *this;
	this->~Arr();
	T*pa = A.head_;
	while (pa)
	{
		this->arrinsert(*pa);
		pa = pa->p_next;
	}
	return *this;
}
template<typename T>
bool Arr<T>::arrinsert(const T& tem)
{
	if (!head_)
	{
		head_ = new T(tem);
		tail_ = head_;
		total_++;
		return true;
	}

	T*p = head_;
	while (p != NULL)
	{
		if (*p == tem)
		{
			cout << "inset error;object already exists" << endl;
			return false;
		}
		p = p->p_next;
	}

	p = new T(tem);
	tail_->p_next = p;
	tail_ = p;
	total_++;
	return true;
}

template<typename T>
bool Arr<T>::arrdel(const T& tem)
{
	if (!head_)
	{
		cout << "array is empty!" << endl;
		return false;
	}
	T*p = head_;
	if (*p == tem)
	{
		T*p_tem = head_;
		head_ = head_->p_next;
		delete p_tem;
		total_--;
		return true;
	}
	T*q = head_;
	p = p->p_next;

	while (p)
	{
		if (*p == tem)
		{
			q->p_next = p->p_next;
			delete p;
			total_--;
			return true;
		}
		q = p;
		p = p->p_next;
	}
	cout << "object is not in the array!" << endl;
	return false;
}
/*
template<typename T> 
ostream& operator<<(ostream& os, const Arr<T>& A)
{
	T*p = A.head_;
	while (p)
	{
		os << (*p);
		p = p->p_next;
	}
	return os;
}
*/
template<typename T>
void Arr<T>::printdata()const
{
	T*p = head_;
	while (p!=NULL)
	{
		cout << (*p);
		p = p->p_next;
	}
}
template<typename T>
T& Arr<T>::operator[](uint index)const
{
	if (index >= total_)
	{
		cout << "index exceed" << endl;
		exit(1);
	}

	T*p = head_;int count = 0;
	while (p != NULL)
	{
		if (index == count)
			return *p;
		p = p->p_next;
		count++;
	}
}
template<typename T>
int Arr<T>:: arrsearch(const T& tem)
{
	T*p = head_;int count = 0;
	while (p)
	{
		if (*p == tem)
			return count;
		count++;
		p = p->p_next;
	}
	return -1;
}
template<typename T>
void Arr<T>::readfile(const string& fname)
{
	ifstream fin(fname, ios_base::in);
	if (!fin.is_open())
	{
		cerr << "open file " << fname << " fails" << endl;
		exit(EXIT_FAILURE);
	}

	char tem[50];
	fin.getline(tem, 50);
	fin.getline(tem, 50);

	T t;
	while (t.readfile(fin))
		arrinsert(t);
	fin.close();
}
template<typename T>
void Arr<T>::writefile(const string& fname)const
{
	ofstream fout(fname, ios_base::out | ios_base::ate);
	if (!fout.is_open())
	{
		cerr << "open file " << fname << " fails" << endl;
		exit(EXIT_FAILURE);
	}

	T*p = head_;
	if (p)
		p->printhead(fout);
	while (p)
	{
		p->writefile(fout);
		p = p->p_next;
	}
	fout.close();
}
template<typename T>
void Arr<T>::sort(bool (*cmp)(const T&,const T&))
{
	arrqksort(0, total_ - 1,cmp);
}
template<typename T>
void Arr<T>::arrqksort(int first, int last,bool (*cmp)(const T&,const T&))
{
	if (first >= last)
		return;
	T tem = (*this)[first];int i = first, j = last;
	while (j > i)
	{
		while (j > i&&cmp((*this)[j], tem))
			j--;
		(*this)[i] = (*this)[j];
		while (j > i&&cmp(tem,(*this)[i]))
			i++;
		(*this)[j] = (*this)[i];
	}
	(*this)[i] = tem;
	arrqksort(first, i - 1, cmp);
	arrqksort(i + 1, last, cmp);
}

/*显示具体化*/
//template class Arr<Stu>;
//template class Arr<Course>;

#endif
