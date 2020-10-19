#include <iostream>
#include <cstring>
#include "Account.h"

using namespace std;

Account::Account(int _accountID, char* _custName, int _leftMoney)
	:accountID(_accountID), leftMoney(_leftMoney)
{
	custName = new char[strlen(_custName) + 1];
	strcpy_s(custName, sizeof(custName), _custName);
}
Account::~Account() {
	delete []custName;
}

void Account::ShowAccInfo() {
	cout << "°èÁÂ¹øÈ£: " << accountID << endl;
	cout << "°í°´¸í: " << custName << endl;
	cout << "ÀÜ¾×: " << leftMoney << endl;
}

int Account::GetAccID() {
	return accountID;
}

int Account::GetLeftMoney() {
	return leftMoney;
}

void Account::Deposit(int money) {
	leftMoney += money;
}

int Account::Withdraw(int money) {
	if (leftMoney - money < 0)
		return 1;
	else{
		leftMoney -= money;
		return 0;
	}

}