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
	Account(const Account &ref) : m_accID{ref.m_accID}, m_balance{ref.m_balance}
	{
		int len = strlen(ref.m_cusName) + 1;
		m_cusName = new char[len];
		strcpy_s(m_cusName, len, ref.m_cusName);
	}
	Account(int ID, int balance, char *cname) : m_accID{ID}, m_balance{balance}
	{
		int len = strlen(cname) + 1;
		m_cusName = new char[len];
		strcpy_s(m_cusName, len, cname);
	}
	~Account() { delete[] m_cusName; }

	int GetAccID(void) const
	{
		return this->m_accID;
	}

	void Deposit(int money)
	{
		m_balance += money;
	}

	int Withdraw(int money)
	{
		m_balance -= money;
		return m_balance;
	}

	void ShowAccInfo(void)
	{
		cout << "Accout info: " << endl;
		cout << "ID: " << this->m_accID << endl;
		cout << "Customer name: " << this->m_cusName << endl;
		cout << "Balance: " << this->m_balance << endl;
	}
};

Account *accArr[MAX_ACC_NUM];
int accNum = 0;

// Account class handling functions
int GetAccIdx(int);

void ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. Make Accout" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawal" << endl;
	cout << "4. Display all" << endl;
	cout << "5. Exit program" << endl;
};

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	if (accNum >= MAX_ACC_NUM)
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
	// Account acc {id, balance, name};
	accArr[accNum] = new Account{id, balance, name};
	// accArr[accNum].accID = id;
	// accArr[accNum].balance = balance;
	// strcpy(accArr[accNum].cusName, name);
	// acc.ShowAccInfo();
	accNum++;
	cout << "Account is successfully created!" << endl
		 << endl;
};

void DepositMoney()
{
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			cout << "Deposit amount: $";
			cin >> money;
			accArr[i]->Deposit(money);
			cout << "Deposit completed."<< endl
				 << endl;
			return;
		}
	}

	cout << "This ID is not valid! " << endl;
}

void WithdrawMoney()
{
	int money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			cout << "Withdrawal amount: $";
			cin >> money;
			if (accArr[i]->Withdraw(0) < money)
			{
				cout << "Not enough balance" << endl
					 << endl;
				return;
			}

			accArr[i]-> Withdraw(money);
			cout << "Withdrawal completed."<< endl
				 << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl
		 << endl;
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}

	if (accNum == 0)
		cout << "No Accounts!" << endl
			 << endl;
}

int GetAccIdx(int id)
{
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			return i;
		}
	}
	return -1;
}

int main(void)
{
	int choice, i;
	while (1)
	{
		ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;
		switch (bank(choice))
		{
		case bank::MAKE:
			MakeAccount();
			break;
		case bank::DEPOSIT:
			DepositMoney();
			break;
		case bank::WITHDRAW:
			WithdrawMoney();
			break;
		case bank::INQUIRE:
			ShowAllAccInfo();
			break;
		case bank::EXIT:
			for (i = 0; i < accNum; i++)
				delete accArr[i];
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}