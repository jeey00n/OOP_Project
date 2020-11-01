#include <iostream>
#include <cstring>

#pragma once
class Account
{
public:
    Account(int _accountID, char* _custName, int _leftMoney);
    ~Account();

    Account(const Account& copy);

protected:
    int accountID;
    char* custName;
    int leftMoney;

public:
    virtual void ShowAccInfo() const;
    int GetAccID() const;
    int GetLeftMoney() const;
    virtual void Deposit(int money);
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

class NormalAccount :public Account {
    //보통예금계좌 - 최소한의 이자, 자율 입출금
private:
    double rate;

public:
    NormalAccount(int _accountID, char* _custName, int _leftMoney, double _rate);
    ~NormalAccount();
    void ShowAccInfo() const override;
    void Deposit(int money) override;
};

class HighCreditAccount :public Account {
    //신용도 높은 고객에게만 개설허용 - 높은 이율의 계좌
private:
    double rate;
    int classRate;  //1toA, 2toB, 3toC
public:
    HighCreditAccount(int _accountID, char* _custName, int _leftMoney, double _rate, int _classRate);
    ~HighCreditAccount();
    void ShowAccInfo() const override;
    void Deposit(int money) override;
};