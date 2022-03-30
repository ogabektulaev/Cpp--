#include <iostream>
#include "bank.h"
using namespace std;

Account accArr[MAX_ACC_NUM]; // Account array
int accNum = 0; // # of accounts

//function parameter void is removed
void ShowMenu() {
	cout << "-----Menu------" << endl;
	cout << "1. Make Account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawal" << endl;
	cout << "4. Display all" << endl;
	cout << "5. Transfer" << endl;
	cout << "6. Delete an account" << endl;
	cout << "7. Delete all accounts" << endl;
	cout << "8. Exit program" << endl;
}

void MakeAccount() {
	int id;
	char name[NAME_LEN];
	int balance;
	if (accNum >= MAX_ACC_NUM) {
		cout << "Sorry! cannot make an account anymore." << endl;
		return;
	}

	cout << "[Make Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit amount: $";
	cin >> balance;
	cout << endl;

	if (GetAccIdx(id) != -1) {
		cout << "Error: Existing account ID" << endl << endl;
		return;
	}

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;

	cout << "Account is successfully created." << endl << endl;
}


void DepositMoney() {
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Deposit amount: $";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "Deposit completed. Current balance: $" << accArr[i].balance << endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl
	     << endl;
}

void WithdrawMoney() {
	int money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Withdrawal amount: $";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			if (accArr[i].balance < money) {
				cout << "Not enough balance" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "Withdrawal completed. Current balance: $" << accArr[i].balance << endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl << endl;
}

void ShowAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		cout << "Account ID: " << accArr[i].accID << endl;
		cout << "Name: " << accArr[i].cusName << endl;
		cout << "Balance: $" << accArr[i].balance << endl << endl;
	}
	if(accNum == 0)
		cout << "No Accounts!"<<endl<<endl;
}

int GetAccIdx(int id) {
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			return i;
		}
	}
	return -1;
}

//New added functions
void DeleteAccount() {
	int delid;
	cout <<"Enter account ID which will be deleted: ";
	cin >> delid;

	for(int i=0; i<=accNum; i++) {
		if(accArr[i].accID == delid) { //finds id of account

			cout <<accArr[i].cusName<<"'s account is deleted successfully. " << endl;
			cout <<"$"<<accArr[i].balance<<" is available, you can withdraw now." << endl<<endl;

			for(i; i<=accNum; i++) { //deletes account with array shifting method
				accArr[i] = accArr[i+1];
			}
			accNum = accNum-1;
			break;
		}
	}
}

void DeleteAllAccounts() {
	accNum=0;  //deletes all the accounts
	cout << "All accounts are deleted."<<endl<<endl;
}

int MoneyTransfer() {

	while(1) {
		int firstID, secondID, money, num1=101, num2=101;
		cout << "Enter your ID (-1 to exit): ";
		cin >> firstID;

		if (firstID == -1)
			return -1;

		cout << "Enter ID of account which you want to transfer to: ";
		cin >> secondID;

		for(int i=0; i<=accNum; i++) {
			if(accArr[i].accID == firstID) {
				num1 = i;
			} else if(accArr[i].accID == secondID) {
				num2 = i;
			}
		}

		if(num1 == 101) {
			cout << "Your ID = " << firstID << " isn't found." << endl;
			cout << "Please, enter valid ID or -1 to exit." << endl << endl;
			continue;
		} else if(num2 == 101) {
			cout << "ID = " << secondID << " isn't found." << endl;
			cout << "Please, enter valid ID or -1 to exit." << endl << endl;
			continue;
		}

		cout << "Your balance: $" << accArr[num1].balance <<endl;
		cout << "How much money you want to transfer: $";
		cin >> money;

		if(money <= accArr[num1].balance) {
			accArr[num1].balance -= money;
			accArr[num2].balance += money;
			cout << "$" <<money<<" is transferred successfully! " << endl << endl;
			return 1;
		} else {
			cout << "You don't have enough money for transfering." << endl << endl;
			continue;
		}
	}
	return 0;
}
