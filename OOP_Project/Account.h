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
    Account* accArr[100];       //Account ������ ���� �迭
    int accCount = 0;           //����� account�� ��
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
    //���뿹�ݰ��� - �ּ����� ����, ���� �����
private:
    double rate;

public:
    NormalAccount(int _accountID, char* _custName, int _leftMoney, double _rate);
    ~NormalAccount();
    void ShowAccInfo() const override;
    void Deposit(int money) override;
};

class HighCreditAccount :public Account {
    //�ſ뵵 ���� �����Ը� ������� - ���� ������ ����
private:
    double rate;
    int classRate;  //1toA, 2toB, 3toC
public:
    HighCreditAccount(int _accountID, char* _custName, int _leftMoney, double _rate, int _classRate);
    ~HighCreditAccount();
    void ShowAccInfo() const override;
    void Deposit(int money) override;
};