#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Account.h"

using namespace std;

int main()
{
    AccountHandler accHand;
    srand((unsigned int)time(NULL));
    int choice;
    while (true) {
        accHand._ShowMenu();
        cin >> choice;

        switch (choice)
        {
		case 1:
            accHand._MakeAccount();
            break;
		case 2:
            accHand._Deposit();
			break;
		case 3:
            accHand._Withdraw();
			break;
		case 4:
            accHand._SearchCust();
			break;
		case 5:
            cout << "프로그램을 종료합니다.";
            return 0;
		default:
			cout << "번호를 잘못 입력하셨습니다."<<endl;
			break;
        }
    }
    return 0;
}