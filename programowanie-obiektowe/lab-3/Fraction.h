#ifndef FRACTION
#define FRACTION

#include<iostream>

class Fraction
{
private:
	int numerator, denominator;
	int GCD(int a, int b);
public:
	// constructors, destructors
	explicit Fraction(int num = 0, int den = 1);

	~Fraction() = default;

	// output input
	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
	friend std::istream& operator>>(std::istream& in, Fraction& fraction);

	// addition, subtraction
	Fraction operator+(const Fraction& other) const;
	Fraction operator-(const Fraction& other) const;

	// unary operators
	Fraction operator-() const;
	Fraction operator!() const;

	// multiplication, division
	Fraction operator*(const int& k) const;
	friend Fraction operator*(const int& k, const Fraction& fraction);

	Fraction operator/(const int& k) const;
	friend Fraction operator/(const int& k, const Fraction& fraction);

	// simplifying
	void simplify();

	// conversion
	operator double() { return 1.0 * numerator / denominator; };
};


#endif