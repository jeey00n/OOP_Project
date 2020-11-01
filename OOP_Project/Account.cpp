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

}

int Account::GetAccID() const{
	return accountID;
}

int Account::GetLeftMoney() const{
	return leftMoney;
}

void Account::Deposit(int money) {
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
	cout << "1. ���°���\n";
	cout << "2. �� ��\n";
	cout << "3. �� ��\n";
	cout << "4. �������� ��ü ���\n";
	cout << "5. ���α׷� ����\n\n";
	cout << "���� :";
}
void AccountHandler::_MakeAccount(){
	while (true) {
		int accChoice;

		cout << "[���� ���� ����]" << endl;
		cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
		cout << "����: ";
		cin >> accChoice;

		if (accChoice == 1) {
			cout << "[���뿹�ݰ��� ����]" << endl;
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
			cout << "������ �Է��ϼ���: ";
			char name[100];
			cin >> name;

			int money;
			while (true) {
				cout << "�Աݾ��� �Է��ϼ���: ";
				cin >> money;
				if (money < 0)
					cout << "0 �̻��� ���ڸ� �Է��� �ּ���." << endl;
				else break;
			}

			double rate;
			while (true) {
				cout << "������: ";
				cin >> rate;
				if (rate < 0)
					cout << "0 �̻��� ���ڸ� �Է��� �ּ���." << endl;
				else break;
			}

			accArr[accCount] = new NormalAccount(randAccID, name, money, rate);

			cout << "���°� �����Ǿ����ϴ�.\n\n----------���� ����----------" << endl;
			accArr[accCount]->ShowAccInfo();
			accCount++;
			return;
		}
		else if (accChoice == 2) {
			cout << "[�ſ�ŷڰ��� ����]" << endl;
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
			cout << "������ �Է��ϼ���: ";
			char name[100];
			cin >> name;

			int money;
			while (true) {
				cout << "�Աݾ��� �Է��ϼ���: ";
				cin >> money;
				if (money < 0)
					cout << "0 �̻��� ���ڸ� �Է��� �ּ���." << endl;
				else break;
			}

			double rate;
			while (true) {
				cout << "������: ";
				cin >> rate;
				if (rate < 0)
					cout << "0 �̻��� ���ڸ� �Է��� �ּ���." << endl;
				else break;
			}

			int classRate;
			while (true) {
				cout << "�ſ���(1toA, 2toB, 3toC): ";
				cin >> classRate;
				if (((classRate == 1)||(classRate == 2))||(classRate==3))
					break;
				else
					cout<< "�˸��� ���ڸ� �Է��� �ּ���." <<endl;
			}

			accArr[accCount] = new HighCreditAccount(randAccID, name, money, rate, classRate);
			cout << "���°� �����Ǿ����ϴ�."<< endl;
			accArr[accCount]->ShowAccInfo();
			accCount++;
			return;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			cout << "���� �輳�� �����մϴ�." << endl;
			return;
		}
	}
}
void AccountHandler::_Deposit(){
	if (accCount == 0) {
		cout << "�Ա� ������ ������ �����ϴ�. �켱 ���� ������ �� �ּ���." << endl;
		return;
	}
	int searchID;
	cout << "[�� ��]\n";
	cout << "����ID: ";
	searchID;
	cin >> searchID;
	for (int i = 0; i < accCount; i++) {
		if (accArr[i]->GetAccID() == searchID) {
			cout << "�Աݾ�: ";
			int inputMoney;
			while (true) {
				cin >> inputMoney;
				if (inputMoney > 0)
					break;
				else
					cout << "0���� ū �ݾ׸� �Ա��� �� �ֽ��ϴ�.\n�Աݾ�: " << endl;
			}
			accArr[i]->Deposit(inputMoney);
			cout << "�ԱݿϷ�\n���� �ܰ�: " << accArr[i]->GetLeftMoney() << endl;
			return;
		}
	}
	cout << "��ġ�ϴ� ����ID�� �����ϴ�." << endl;
}
void AccountHandler::_Withdraw(){
	if (accCount == 0) {
		cout << "��� ������ ������ �����ϴ�. �켱 ���� ������ �� �ּ���." << endl;
		return;
	}
	int searchID;
	cout << "[�� ��]\n";
	cout << "����ID: ";
	searchID = 0;
	cin >> searchID;
	for (int i = 0; i < accCount; i++) {
		if (accArr[i]->GetAccID() == searchID) {
			while (1) {
				cout << "��ݾ�: ";
				int putoutMoney = 0;
				cin >> putoutMoney;
				int flag = accArr[i]->Withdraw(putoutMoney);
				if (flag == 1) {
					cout << "�ܰ� �����մϴ�.\n���� �ܰ�: " << accArr[i]->GetLeftMoney() << endl;
					if (accArr[i]->GetLeftMoney() <= 0) {
						cout << "����� �� �ִ� �ݾ��� ���� ������ ��� ���α׷��� �����մϴ�." << endl;
						return;
					}
					else
						continue;
				}
				else if (flag == 0) {
					cout << "��ݿϷ�\n���� �ܰ�: " << accArr[i]->GetLeftMoney() << endl;
					return;
				}
			}
			break;
		}
	}
	cout << "���¹�ȣ�� ��ġ�ϴ� ������ �����ϴ�." << endl;
}
void AccountHandler::_SearchCust(){
	if (accCount == 0) {
		cout << "��ȸ ������ ������ �����ϴ�. �켱 ���� ������ �� �ּ���." << endl;
		return;
	}
	cout << "����ID: ";
	int searchID;
	cin >> searchID;
	for (int i = 0; i < accCount; i++) {
		if (accArr[i]->GetAccID() == searchID) {
			accArr[i]->ShowAccInfo();
			return;
		}
	}
	cout << "���¹�ȣ�� ��ġ�ϴ� ������ �����ϴ�." << endl;
}

NormalAccount::NormalAccount(int _accountID, char* _custName, int _leftMoney, double _rate)
	:Account(_accountID, _custName, _leftMoney), rate(_rate)
{}
NormalAccount::~NormalAccount() {}

void NormalAccount::ShowAccInfo() const{
	cout << "----------���� ����----------" << endl;
	cout << "���¹�ȣ: " << accountID << endl;
	cout << "����: " << custName << endl;
	cout << "�ܾ�: " << leftMoney << endl;
	cout << "������: " << rate << endl;
}

void NormalAccount::Deposit(int money) {
	leftMoney += money;
	leftMoney = (int)leftMoney * ((rate + 100) / 100);
}

HighCreditAccount::HighCreditAccount(int _accountID, char* _custName, int _leftMoney, double _rate, int _classRate)
: Account(_accountID, _custName, _leftMoney), rate(_rate), classRate(_classRate)
{}
HighCreditAccount::~HighCreditAccount() {}

void HighCreditAccount::ShowAccInfo() const{
	cout << "----------���� ����----------" << endl;
	cout << "���¹�ȣ: " << accountID << endl;
	cout << "����: " << custName << endl;
	cout << "�ܾ�: " << leftMoney << endl;
	cout << "�ſ���: ";
	if (classRate == 1)
		cout << 'A' << endl;
	else if (classRate == 2)
		cout << 'B' << endl;
	else if (classRate == 3)
		cout << 'C' << endl;
	cout << "������: ";
	if (classRate == 1)
		cout << rate + 7 << '%' << endl;
	else if (classRate == 2)
		cout << rate + 4 << '%' << endl;
	else if (classRate == 3)
		cout << rate + 2 << '%' << endl;
}

void HighCreditAccount::Deposit(int money) {
	leftMoney += money;
	if (classRate == 1)
		leftMoney = (int)leftMoney * (((rate + 7) + 100) / 100);
	else if (classRate == 2)
		leftMoney = (int)leftMoney * (((rate + 4) + 100) / 100);
	else if (classRate == 3)
		leftMoney = (int)leftMoney * (((rate + 2) + 100) / 100);
}