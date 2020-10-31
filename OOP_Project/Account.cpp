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
	cout << "계좌번호: " << accountID << endl;
	cout << "고객명: " << custName << endl;
	cout << "잔액: " << leftMoney << endl;
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

AccountHandler::AccountHandler(){}
AccountHandler::~AccountHandler(){
	for (int i = 0; i < accCount; i++) {
		delete accArr[i];
	}
}

void AccountHandler::_ShowMenu(){
	cout << "\n\n\n\n\-----Menu-----\n";
	cout << "1. 계좌개설\n";
	cout << "2. 입 금\n";
	cout << "3. 출 금\n";
	cout << "4. 계좌정보 전체 출력\n";
	cout << "5. 프로그램 종료\n\n";
	cout << "선택 :";
}
void AccountHandler::_MakeAccount(){
	cout << "[계좌개설]" << endl;
	int randAccID;
	while (1) {
		bool flag = true;
		randAccID = rand() % 1000;
		for (int i = 0; i < accCount; i++) {
			if (accArr[i]->GetAccID() == randAccID) {
				flag = false;
			}
		}
		if (flag == true) break;
	}
	cout << "고객명을 입력하세요: ";
	char name[100];
	cin >> name;
	accArr[accCount] = new Account(randAccID, name, 0);
	cout << "계좌가 개설되었습니다.\n\n----------계좌 정보----------" << endl;
	accArr[accCount]->ShowAccInfo();
	accCount++;
	return;
}
void AccountHandler::_Deposit(){
	if (accCount == 0) {
		cout << "입금 가능한 고객님이 없습니다. 우선 계좌 개설을 해 주세요." << endl;
		return;
	}
	int searchID;
	cout << "[입 금]\n";
	cout << "계좌ID: ";
	searchID;
	cin >> searchID;
	for (int i = 0; i < accCount; i++) {
		if (accArr[i]->GetAccID() == searchID) {
			cout << "입금액: ";
			int inputMoney;
			while (true) {
				cin >> inputMoney;
				if (inputMoney > 0)
					break;
				else
					cout << "0보다 큰 금액만 입금할 수 있습니다.\n입금액: " << endl;
			}
			accArr[i]->Deposit(inputMoney);
			cout << "입금완료\n현재 잔고: " << accArr[i]->GetLeftMoney() << endl;
			return;
		}
	}
	cout << "일치하는 계좌ID가 없습니다." << endl;
}
void AccountHandler::_Withdraw(){
	if (accCount == 0) {
		cout << "출금 가능한 고객님이 없습니다. 우선 계좌 개설을 해 주세요." << endl;
		return;
	}
	int searchID;
	cout << "[출 금]\n";
	cout << "계좌ID: ";
	searchID = 0;
	cin >> searchID;
	for (int i = 0; i < accCount; i++) {
		if (accArr[i]->GetAccID() == searchID) {
			while (1) {
				cout << "출금액: ";
				int putoutMoney = 0;
				cin >> putoutMoney;
				int flag = accArr[i]->Withdraw(putoutMoney);
				if (flag == 1) {
					cout << "잔고가 부족합니다.\n현재 잔고: " << accArr[i]->GetLeftMoney() << endl;
					if (accArr[i]->GetLeftMoney() <= 0) {
						cout << "출금할 수 있는 금액이 없기 때문에 출금 프로그램을 종료합니다." << endl;
						return;
					}
					else
						continue;
				}
				else if (flag == 0) {
					cout << "출금완료\n현재 잔고: " << accArr[i]->GetLeftMoney() << endl;
					return;
				}
			}
			break;
		}
	}
	cout << "계좌번호와 일치하는 고객님이 없습니다." << endl;
}
void AccountHandler::_SearchCust(){
	if (accCount == 0) {
		cout << "조회 가능한 고객님이 없습니다. 우선 계좌 개설을 해 주세요." << endl;
		return;
	}
	cout << "계좌ID: ";
	int searchID;
	cin >> searchID;
	for (int i = 0; i < accCount; i++) {
		if (accArr[i]->GetAccID() == searchID) {
			accArr[i]->ShowAccInfo();
			return;
		}
	}
	cout << "계좌번호와 일치하는 고객님이 없습니다." << endl;
}