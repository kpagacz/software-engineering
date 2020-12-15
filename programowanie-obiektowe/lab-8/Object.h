#ifndef OBJECTS
#define OBJECTS

#include<iostream>

class Object
{
public:
	Object() = default;
	virtual ~Object() = default;
	virtual void print(std::ostream&) = 0;
};

class A : public Object {
public:
	A() = default;
	~A() = default;
	void print(std::ostream& out) { out << "A"; }
};

class B : public Object {
public:
	B() = default;
	~B() = default;
	void print(std::ostream& out) { out << "B"; }
};

class C : public Object {
public:
	C() = default;
	~C() = default;
	void print(std::ostream& out) { out << "C"; }
};

class D : public Object {
public:
	D() = default;
	~D() = default;
	void print(std::ostream& out) { out << "D"; }
};

#endif // OBJECTS