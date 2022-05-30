#include <iostream>
#include "SavingAccount.h"
using namespace std;

SavingAccount::SavingAccount(int ID, int balance, char* cname, int rate) : Account{ ID, 0, cname }, m_InterestRate{ rate }
{
    Deposit(balance);
}

void SavingAccount::Deposit(int money)
{
    if (money > 0)
    {
        int fund = money * m_InterestRate / 100;
        Account::Deposit(money + fund);
    }
}