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
    void ShowAccInfo();
    int GetAccID();
    int GetLeftMoney();
    void Deposit(int money);
    int Withdraw(int money);
};

