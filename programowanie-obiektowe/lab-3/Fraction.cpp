#include "Fraction.h"

#include<iostream>
#include<math.h>

int Fraction::GCD(int a, int b)
{
	a = abs(a);
	b = abs(b);
	int temp;
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

Fraction::Fraction(int num, int den)
{
	if (den == 0) {
		std::cout << "Denominator should not be 0!\n";
	}

	numerator = num;
	denominator = den;
}

Fraction Fraction::operator+(const Fraction& other) const
{
	return Fraction(this->numerator * other.denominator + other.numerator * this->denominator,
		this->denominator * other.denominator);
}

Fraction Fraction::operator-(const Fraction& other) const
{
	return *this + (-other);
}

Fraction Fraction::operator-() const
{
	return Fraction(-1 * this->numerator, this->denominator);
}

Fraction Fraction::operator!() const
{
	return Fraction(this->denominator, this->numerator);
}

Fraction Fraction::operator*(const int& k) const
{
	return Fraction(k * this->numerator, this->denominator);
}

Fraction Fraction::operator/(const int& k) const
{
	return Fraction(this->numerator, this->denominator * k);
}

void Fraction::simplify()
{
	int gcd = GCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	out << fraction.numerator << " / " << fraction.denominator << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction)
{
	in >> fraction.numerator;
	in >> fraction.denominator;

	return in;
}

Fraction operator*(const int& k, const Fraction& fraction)
{
	return fraction * k;
}

Fraction operator/(const int& k, const Fraction& fraction)
{
	return k * (!fraction);
}
