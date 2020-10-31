#include <iostream>
#include <cstring>

#pragma once
class Account
{
public:
    Account(int _accountID, char* _custName, int _leftMoney);
    ~Account();

    Account(const Account& copy);

private:
    int accountID;
    char* custName;
    int leftMoney;

public:
    void ShowAccInfo() const;
    int GetAccID() const;
    int GetLeftMoney() const;
    void Deposit(int money);
    int Withdraw(int money);
};

class AccountHandler {
private:
    Account* accArr[100];       //Account 저장을 위한 배열
    int accCount = 0;           //저장된 account의 수
public:
    AccountHandler();
    ~AccountHandler();

    void _ShowMenu();
    void _MakeAccount();
    void _Deposit();
    void _Withdraw();
    void _SearchCust();
};