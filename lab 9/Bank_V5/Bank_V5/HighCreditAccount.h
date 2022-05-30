#pragma once

#include <iostream>
#include "Account.h"
using namespace std;

class HighCreditAccount : public Account {
private:
    int m_InterestRate;
    int m_credit;
public:
    HighCreditAccount(int ID, int balance, char* cname, int rate, int credit);
    virtual void Deposit(int money);
};