#ifndef __OnlineBanking
#define __OnlineBanking
#include "account.h"
#include<string>

class OnlineBanking
{
private:
	Account* accounts;
	unsigned int max_accounts_count, current_accounts_count;

public:
	// constructors destructors
	OnlineBanking() : accounts(new Account[100]), max_accounts_count(100), current_accounts_count(0) {};
	OnlineBanking(unsigned int accounts_number);
	~OnlineBanking();

	// open account, close account
	void open_account(std::string, std::string, std::string);
	void close_account(unsigned int id);

	// print current accounts
	void print_accounts() const;
	void print_account(unsigned int) const;

	// withdrawals, deposits
	void withdraw(double, unsigned int);
	void deposit(double, unsigned int);
};

#endif