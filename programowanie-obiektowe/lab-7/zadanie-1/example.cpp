#include "example.h"

Base::Base(int _x, bool _p)
{
	std::cout << "Creating Base object with values: " << _x << " and " << _p << "\n";
	x = new int(_x);
	p = _p;
}

Base::~Base()
{
	std::cout << "Destroying a Base object with values: " << *x << " and " << p << "\n";
	delete x;
}

Base::Base(const Base& other)
{
	x = new int(*(other.x));
	p = other.p;
}

Base& Base::operator=(const Base& a)
{
	if (&a == this) return *this;
	delete x;
	x = new int(*a.x);
	p = a.p;

	return *this;
}

void Base::print() const
{
	std::cout << "Object of class Base: " << this << " with values: " << *x << " and " << p << "\n";
}

Child::Child(int _x, bool _p, int _n) : Base(_x, _p)
{
	std::cout << "Creating object Child: " << this << " with values: " << _n << "\n";
	n = _n;
	tab = new int[_n];
	for (int i = 0; i < _n; i++) tab[i] = i;
}

Child::~Child()
{
	std::cout << "Destroying Child object: " << this << "\n";
	delete[] tab;
}

Child& Child::operator=(const Child& other)
{
	if (&other == this) return *this;
	(Base&)(*this) = (Base&)other;
	delete[] tab;
	n = other.n;
	tab = new int[n];
	for (int i = 0; i < n; i++) tab[i] = i;

	return *this;
}

Child::Child(const Child& other) : Base(other)
{
	n = other.n;
	tab = new int[n];
	for (int i = 0; i < n; i++) tab[i] = i;
}

void Child::print() const
{
	std::cout << "Object of class Child " << this << "\n";
	for (int i = 0; i < n; i++) std::cout << tab[i] << " ";
	std::cout << "\n";
	std::cout << "The base class of: " << this << ":\n";
	Base::print();
}
