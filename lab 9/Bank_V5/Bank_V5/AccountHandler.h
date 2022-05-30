#pragma once

#include "Account.h"
#include "BankCommon.h"

class AccountHandler
{
private:
    Account* m_accArr[MAX_ACC_NUM];
    int m_accNum = 0;

    int GetAccIdx(int d) const;

public:
    AccountHandler();
    ~AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    void MakeSavingAccount(void);
    void MakeHighCreditAccount(void);
};