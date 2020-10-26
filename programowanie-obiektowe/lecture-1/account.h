#ifndef __account
#define __acount
#include<string>

class Account
{
private:
	std::string name;
	std::string surname;
	std::string account_no;
	double balance;

public:
	// constructors, destructors
	Account() : name(""), surname(""), account_no(""), balance(0) {};
	Account(std::string _name, std::string _surname, std::string _account_no) : name(_name), surname(_surname), account_no(_account_no), balance(0) {};
	Account& operator=(const Account other);

	~Account() = default;


	// other functions
	void print() const;

	void deposit_money(double deposit);
	void withdraw_money(double withdrawal);

};

#endif

