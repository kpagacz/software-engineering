#pragma once
#include<iostream>

class Object
{
public:
	Object() = default;
	virtual ~Object() = default;
	virtual void print() = 0;
};

class A : public Object {
public:
	A() = default;
	~A() = default;
	void print() { std::cout << "A"; }
};

class B : public Object {
public:
	B() = default;
	~B() = default;
	void print() { std::cout << "B"; }
};

class C : public Object {
public:
	C() = default;
	~C() = default;
	void print() { std::cout << "C"; }
};

class D : public Object {
public:
	D() = default;
	~D() = default;
	void print() { std::cout << "D"; }
};
