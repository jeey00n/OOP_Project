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

Account::Account(const Account& copy)
	: accountID(copy.accountID), leftMoney(copy.leftMoney)
{
	custName = new char[strlen(copy.custName) + 1];
	strcpy_s(custName, sizeof(custName), copy.custName);
}

void Account::ShowAccInfo() const{
	cout << "���¹�ȣ: " << accountID << endl;
	cout << "����: " << custName << endl;
	cout << "�ܾ�: " << leftMoney << endl;
}

int Account::GetAccID() const{
	return accountID;
}

int Account::GetLeftMoney() const{
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