#include <iostream>
#include "HighCreditAccount.h"
using namespace std;

HighCreditAccount::HighCreditAccount(int ID, int balance, char* cname, int rate, int credit) : Account{ ID, 0, cname }, m_InterestRate{ rate }, m_credit{ credit } {
    Deposit(balance);
}

void HighCreditAccount::Deposit(int money) {
    int fund = 0;

    if (m_credit == 1)
        fund = money * (m_InterestRate + 7) / 100;
    else if (m_credit == 2)
        fund = money * (m_InterestRate + 4) / 100;
    else if (m_credit == 3)
        fund = money * (m_InterestRate + 2) / 100;

    Account::Deposit(money + fund);
}