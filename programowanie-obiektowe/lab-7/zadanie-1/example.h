#ifndef EXAMPLE_
#define EXAMPLE_

#include<iostream>
class Base
{
private:
	int* x;
	bool p;
public:
	Base(int _x, bool _p);
	virtual ~Base();
	Base(const Base&);
	Base& operator=(const Base&);
	virtual void print() const;
};


class Child : public Base {
private:
	int* tab;
	int n;
public:
	Child(int _x, bool _p, int _n = 1);
	~Child();
	Child& operator=(const Child&);
	Child(const Child&);
	void print() const;
};

#endif // EXAMPLE_