#include <iostream>
#include "AccountHandler.h"
#include "SavingAccount.h"
#include "HighCreditAccount.h"
using namespace std;

int AccountHandler::GetAccIdx(int id) const
{
    for (int i = 0; i < m_accNum; i++)
    {
        if (m_accArr[i]->GetAccID() == id)
        {
            return i;
        }
    }
    return -1;
}

void AccountHandler::ShowMenu(void) const
{
    cout << "------Menu------" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdrawal" << endl;
    cout << "4. Display all Accounts" << endl;
    cout << "5. Exit program" << endl;
}

void AccountHandler::MakeAccount(void)
{
    int choice;

    if (m_accNum >= MAX_ACC_NUM)
    {
        cout << "Sorry, cannot make an account anymore. " << endl;
        return;
    }

    cout << "[Select Account Type]" << endl;
    cout << " 1. Saving accout " << endl;
    cout << " 2. High Credit Account" << endl;
    cout << "Select: ";
    cin >> choice;

    switch (account(choice))
    {
    case account::SAVING:
        MakeSavingAccount();
        break;
    case account::CREDIT:
        MakeHighCreditAccount();
        break;
    default:
        break;
        cout << "Error: Unknown input." << endl;
    }
}

void AccountHandler::MakeSavingAccount(void)
{
    int id;
    int balance;
    char name[NAME_LEN];
    int rate;

    cout << "[Make Saving Account]" << endl;
    cout << "Account ID: ";
    cin >> id;

    if (GetAccIdx(id) != -1)
    {
        cout << "Error: Existing account ID" << endl;
        return;
    }

    cout << "Customer Name: ";
    cin >> name;
    cout << "Deposit Amount: $";
    cin >> balance;
    cout << "Interest Rate: ";
    cin >> rate;
    cout << endl;
    m_accArr[m_accNum] = new SavingAccount{ id, balance, name, rate };
    m_accNum++;
}

void AccountHandler::MakeHighCreditAccount(void) {
    int id;
    int balance;
    char name[NAME_LEN];
    int rate;
    int credit;

    cout << "[Make High Credit Account" << endl;
    cout << "Account ID: ";
    cin >> id;

    if (GetAccIdx(id) != -1)
    {
        cout << "Error: Existing account ID" << endl;
        return;
    }

    cout << "Customer Name: ";
    cin >> name;
    cout << "Deposit Amount: $";
    cin >> balance;
    cout << "Interest Rate: ";
    cin >> rate;
    cout << "Credit Rating(A:1, B:2, C:3): ";
    cin >> credit;
    if (credit < 0 || credit>3) {
        cout << "Error: Invalid Credit Rating." << endl << endl;
        return;
    }
    cout << endl;

    m_accArr[m_accNum] = new HighCreditAccount{ id, balance, name, rate, credit };
    m_accNum++;
}

void AccountHandler::DepositMoney(void)
{
    int money;
    int id;

    cout << "[Deposit]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit Amount: ";
    cin >> money;

    int idx = GetAccIdx(id);
    if (idx != -1)
    {
        m_accArr[idx]->Deposit(money);
        cout << "Deposit Completed." << endl;
        return;
    }
    cout << "This ID is not valid." << endl;
}

void AccountHandler::WithdrawMoney(void)
{
    int money;
    int id;

    cout << "[Withdrawal]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Withdrawal Amount: ";
    cin >> money;

    int idx = GetAccIdx(id);

    if (idx != -1)
    {
        if (m_accArr[idx]->Withdraw(money) < 0)
        {
            cout << "Not enough balance." << endl
                << endl;
        }
        else
        {
            cout << "Withdrawal completed" << endl
                << endl;
        }
        return;
    }
    cout << "This ID is not valid." << endl
        << endl;
}

void AccountHandler::ShowAllAccInfo(void) const
{
    for (int i = 0; i < m_accNum; i++)
    {
        m_accArr[i]->ShowAccInfo();
    }
}

AccountHandler::AccountHandler() : m_accNum{ 0 } {}

AccountHandler::~AccountHandler()
{
    int i;
    for (i = 0; i < m_accNum; i++)
    {
        delete m_accArr[i];
    }
}