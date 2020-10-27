#include "Wzor.h"
#include<iostream>

Wzor::~Wzor()
{
	std::cout << "Obiekt (" << length << ", " << sign << ") usuniêty\n";
}

void Wzor::opis() const
{
	std::cout << length << " x '" << sign << "'\n";
}

void Wzor::drukuj() const
{
	for (int i = 0; i < length; i++) {
		std::cout << sign;
	}

	std::cout << "\n";
}

void Wzor::ustaw(const char& _sign, const unsigned int& _length)
{
	length = _length;
	sign = _sign;
}
