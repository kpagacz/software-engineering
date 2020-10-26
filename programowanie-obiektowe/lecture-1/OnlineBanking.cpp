#include "OnlineBanking.h"
#include<string>
#include<stdexcept>
#include<iostream>

OnlineBanking::OnlineBanking(unsigned int accounts_number)
{
	max_accounts_count = accounts_number;
	accounts = new Account[max_accounts_count];
	current_accounts_count = 0;
}

OnlineBanking::~OnlineBanking()
{
	delete [] accounts;
}

void OnlineBanking::open_account(std::string new_name, std::string new_surname, std::string new_no)
{
	if (current_accounts_count >= max_accounts_count) {
		throw std::runtime_error("Cannot open more accounts. Upgrade your plan XD\n");
	}
	accounts[current_accounts_count] = Account(new_name, new_surname, new_no);
	current_accounts_count++;
}

void OnlineBanking::close_account(unsigned int id)
{
	if (id >= current_accounts_count) {
		throw std::out_of_range("Out of range of accounts");
	}
	else {
		Account empty;
		accounts[id] = empty;
		current_accounts_count--;
	}
}

void OnlineBanking::print_accounts() const
{
	for (unsigned int i = 0; i < current_accounts_count; i++) {
		std::cout << "Account id: " << i << "\n";
		accounts[i].print();
		std::cout << "====================\n";
	}
}

void OnlineBanking::print_account(unsigned int id) const
{
	if (id >= current_accounts_count) {
		throw std::out_of_range("Out of range of accounts");
	}
	else {
		accounts[id].print();
	}
}

void OnlineBanking::withdraw(double amount, unsigned int id)
{
	if (id >= current_accounts_count) {
		throw std::out_of_range("Out of range of accounts");
	}
	else {
		accounts[id].withdraw_money(amount);
	}
}

void OnlineBanking::deposit(double amount, unsigned int id)
{
	if (id >= current_accounts_count) {
		throw std::out_of_range("Out of range of accounts");
	}
	else {
		accounts[id].deposit_money(amount);
	}
}
