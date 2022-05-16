#include <iostream>
#include <cstring>
using namespace std;

enum class bank
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	EXIT
};
const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

class Account
{
private:
	int m_accID;
	int m_balance;
	char *m_cusName;

public:
	Account(const Account& ref);
    Account(int ID, int balance, char* cname);
    ~Account();
    int GetAccID(void) const;
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo(void) const;
};

Account::Account(const Account& ref) : m_accID{ref.m_accID}, m_balance{ref.m_balance}
{
	int len = strlen(ref.m_cusName) + 1;
	m_cusName = new char[len];
	strcpy_s(m_cusName, len, ref.m_cusName);
};
Account::Account(int ID, int balance, char *cname) : m_accID{ID}, m_balance{balance}
{
	int len = strlen(cname) + 1;
	m_cusName = new char[len];
	strcpy_s(m_cusName, len, cname);
};
Account::~Account() { delete[] m_cusName; };

int Account::GetAccID(void) const
{
    return this->m_accID;
};

void Account::Deposit(int money)
{
    m_balance += money;
};

int Account::Withdraw(int money)
{
	m_balance -= money;
	return m_balance;
};

void Account::ShowAccInfo(void) const
{
	cout << "Accout info: " << endl;
	cout << "ID: " << this->m_accID << endl;
	cout << "Customer name: " << this->m_cusName << endl;
	cout << "Balance: " << this->m_balance << endl;
};

class AccountHandler {
private:
    Account* m_accArr[MAX_ACC_NUM];     
    int m_accNum = 0;

    int GetAccIdx(int id) const;
public:
    AccountHandler();
    ~AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
};
AccountHandler::AccountHandler(){};
AccountHandler::~AccountHandler(){
    for (int i = 0; i < m_accNum; i++)
		delete m_accArr[i];
}

int AccountHandler::GetAccIdx(int id) const {
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
	cout << "-----Menu------" << endl;
	cout << "1. Make Accout" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawal" << endl;
	cout << "4. Display all" << endl;
	cout << "5. Exit program" << endl;
};

void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	if (m_accNum >= MAX_ACC_NUM)
	{
		cout << "Sorry! cannot make an accout anymore." << endl;
		return;
	}

	cout << "[Make Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit amount: ";
	cin >> balance;
	cout << endl;

	if (GetAccIdx(id) != -1)
	{
		cout << "Error: Existing account ID" << endl;
		return;
	}

	m_accArr[m_accNum] = new Account{id, balance, name};

	m_accNum++;
	cout << "Account is successfully created!" << endl
		 << endl;
};

void AccountHandler::DepositMoney()
{
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	

	for (int i = 0; i < m_accNum; i++)
	{
		if (m_accArr[i]->GetAccID() == id)
		{
			cout << "Deposit amount: $";
			cin >> money;
			m_accArr[i]->Deposit(money);
			cout << "Deposit completed."<< endl
				 << endl;
			return;
		}
	}

	cout << "This ID is not valid! " << endl;
}

void AccountHandler::WithdrawMoney()
{
	int money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	

	for (int i = 0; i < m_accNum; i++)
	{
		if (m_accArr[i]->GetAccID() == id)
		{
			cout << "Withdrawal amount: $";
			cin >> money;
			if (m_accArr[i]->Withdraw(0) < money)
			{
				cout << "Not enough balance" << endl
					 << endl;
				return;
			}

			m_accArr[i]-> Withdraw(money);
			cout << "Withdrawal completed."<< endl
				 << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl
		 << endl;
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < m_accNum; i++)
	{
		m_accArr[i]->ShowAccInfo();
		cout << endl;
	}

	if (m_accNum == 0)
		cout << "No Accounts!" << endl
			 << endl;
}


int main(void) {
    AccountHandler manager;
    int choice;
    bool run = true;

    while (run) {
        manager.ShowMenu();
        cout << "Select menu: ";
        cin >> choice;
        cout << endl;

        switch (bank(choice)) {
        case bank::MAKE:
            manager.MakeAccount();
            break;
        case bank::DEPOSIT:
			manager.DepositMoney();
			break;
		case bank::WITHDRAW:
			manager.WithdrawMoney();
			break;
		case bank::INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case bank::EXIT:
			return 0;

        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}