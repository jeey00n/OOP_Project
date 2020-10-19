#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Account.h"

using namespace std;

void _ShowMenu();
void _MakeAccount();
void _Deposit();
void _Withdraw();
void _SearchCust();

Account* accArr[100];       //Account 저장을 위한 배열
int AccCount = 0;           //저장된 Account의 수

int main()
{
    srand((unsigned int)time(NULL));
    int choice;
    while (true) {
        _ShowMenu();
        cin >> choice;

        switch (choice)
        {
		case 1:
            _MakeAccount();
            break;
		case 2:
            _Deposit();
			break;
		case 3:
            _Withdraw();
			break;
		case 4:
            _SearchCust();
			break;
		case 5:
            cout << "프로그램을 종료합니다.";
            for (int i = 0; i < 100; i++) {
                delete accArr[i];
            }
            return 0;
		default:
			cout << "번호를 잘못 입력하셨습니다.\n";
			break;
        }
    }
    return 0;
}


void _ShowMenu() {
    cout << "\n\n\n\n\-----Menu-----\n";
    cout << "1. 계좌개설\n";
    cout << "2. 입 금\n";
    cout << "3. 출 금\n";
    cout << "4. 계좌정보 전체 출력\n";
    cout << "5. 프로그램 종료\n\n";
    cout << "선택 :";
}

void _MakeAccount() {
    cout << "[계좌개설]" << endl;
    int randAccID;
    while (1) {
        bool flag = true;
        randAccID = rand() % 1000;
        for (int i = 0; i < AccCount; i++) {
            if (accArr[i]->GetAccID() == randAccID) {
                flag = false;
            }
        }
        if (flag == true) break;
    }
    cout << "고객명을 입력하세요: ";
    char name[100];
    cin >> name;
    accArr[AccCount] = new Account(randAccID, name, 0);
    cout<< "계좌가 개설되었습니다.\n\n----------계좌 정보----------" << endl;
    accArr[AccCount]->ShowAccInfo();
    AccCount++;
    return;
}

void _Deposit() {
    if (AccCount == 0) {
        cout << "입금 가능한 고객님이 없습니다. 우선 계좌 개설을 해 주세요." << endl;
        return;
    }
    int searchID;
    cout << "[입 금]\n";
    cout << "계좌ID: ";
    searchID;
    cin >> searchID;
    for (int i = 0; i < AccCount; i++) {
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

void _Withdraw() {
    if (AccCount == 0) {
        cout << "출금 가능한 고객님이 없습니다. 우선 계좌 개설을 해 주세요." << endl;
        return;
    }
    int searchID;
    cout << "[출 금]\n";
    cout << "계좌ID: ";
    searchID = 0;
    cin >> searchID;
    for (int i = 0; i < AccCount; i++) {
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

void _SearchCust() {
    if (AccCount == 0) {
        cout << "조회 가능한 고객님이 없습니다. 우선 계좌 개설을 해 주세요." << endl;
        return;
    }
    cout << "계좌ID: ";
    int searchID;
    cin >> searchID;
    for (int i = 0; i < AccCount; i++) {
        if (accArr[i]->GetAccID() == searchID) {
            accArr[i]->ShowAccInfo();
            return;
        }
    }
    cout << "계좌번호와 일치하는 고객님이 없습니다." << endl;
}