#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;

Account::Account(const Account& ref) : m_accID{ ref.m_accID }, m_balance{ ref.m_balance }
{
    int len = strlen(ref.m_cusName) + 1;
    m_cusName = new char[len];
    strcpy_s(m_cusName, len, ref.m_cusName);
}

Account::Account(int ID, int balance, char* cname) : m_accID{ ID }, m_balance{ balance }
{
    int len = strlen(cname) + 1;
    m_cusName = new char[len];
    strcpy_s(m_cusName, len, cname);
}

Account::~Account() { delete[] m_cusName; }

int Account::GetAccID(void) { return m_accID; }

void Account::Deposit(int money)
{
    if (money > 0)
        m_balance += money;
}

int Account::Withdraw(int money)
{
    if ((money < 0) || (money > m_balance)) {
        return -1;
    }
    m_balance -= money;
    return money;
}

void Account::ShowAccInfo(void) const
{
    cout << "Account ID: " << m_accID << endl;
    cout << "Name: " << m_cusName << endl;
    cout << "Balance: $" << m_balance << endl << endl;
}