#ifndef IBAN_
#define IBAN_
#include<string>
#include<iostream>
class IBAN
{
private:
	std::string iban;
public:
	// constructors, destructors
	IBAN() : iban("") {};
	~IBAN() = default;
	IBAN(const std::string& new_value);

	// getters, setters
	std::string get_iban() const;
	void set_iban(const std::string& new_iban);

	// operators
	bool operator<(const IBAN& other) const;
	friend std::ostream& operator<<(std::ostream& out, const IBAN& iban);
};

#include "IBAN.cpp"
#endif 

