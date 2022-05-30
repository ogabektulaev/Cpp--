#pragma once
class Account {
private:
    int m_accID;
    int m_balance;
    char* m_cusName;

public:
    Account(const Account& ref);
    Account(int ID, int balance, char* cname);
    ~Account();
    int GetAccID(void);
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo(void) const;
};