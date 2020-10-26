#include "account.h"
#include<iostream>
#include<iomanip>
#include<stdexcept>

Account& Account::operator=(Account other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->account_no = other.account_no;
	this->balance = other.balance;

	return *this;
}

void Account::print() const
{
	std::cout << "Account no: " << account_no << "\n" <<
		"Name: " << name << "\n" <<
		"Surname: " << surname << "\n" <<
		"Balance: " << std::setprecision(2) << std::fixed << balance << "\n";
}

void Account::deposit_money(double deposit)
{
	if (deposit < 0) {
		throw std::runtime_error("Cannot deposit a negative amount of money\n");
	}
	balance += deposit;
}

void Account::withdraw_money(double withdrawal)
{
	if (withdrawal < 0) {
		throw std::runtime_error("Cannot withdraw negative amount of money\n");
	}
	if (withdrawal > balance) {
		throw std::runtime_error("Not enough funds\n");
	}

	balance -= withdrawal;
}
