// Name: ±i®Ñ»Ê B10615025
// Date: 2018/6/12
// Last Update: 2018/6/12
// Problem statement: ATM
#pragma once
#include <iostream>
class NegativeDeposit {};
class InsufficientFunds {};

using namespace std;

class Account
{
private:
	double balance;
public:
	Account()
	{
		balance = 0;
	}
	Account(double initialDeposit)
	{
		balance = initialDeposit;
	}
	double getBalance()
	{
		return balance;
	}
	//returns new balance or -1 if error
	double deposit(double amount)
	{
		if (amount <= 0)
			throw NegativeDeposit();

		balance += amount;
		return balance;
	}
	//return new balance or -1 if invalid amount
	double withdraw(double amount) throw(InsufficientFunds)
	{
		if ((amount > balance) || (amount < 0))
			throw InsufficientFunds();
		
		balance -= amount;

		return balance;
	}
};