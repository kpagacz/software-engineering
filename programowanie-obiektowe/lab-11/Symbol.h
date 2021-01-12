#ifndef SYMBOL
#define SYMBOL
#include<iostream>
class Symbol
{
public:
	Symbol(char _symbol = '.') : symbol(_symbol) {}
	~Symbol() = default;
	friend std::ostream& operator<<(std::ostream&, const Symbol&);

private:
	virtual void print(std::ostream&) const = 0;
	char symbol;
};

class Kolko : public Symbol {
public:
	Kolko() : Symbol('o') {}
	~Kolko() = default;
private:
	void print(std::ostream&) const;
};

class Krzyzyk : public Symbol {
public:
	Krzyzyk() : Symbol('x') {}
	~Krzyzyk() = default;
private:
	void print(std::ostream&) const;
};
#endif // SYMBOL