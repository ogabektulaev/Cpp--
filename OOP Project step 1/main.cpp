#include <iostream>
#include "bank.cpp"  //included bank.cpp 
#include "bank.h"
using namespace std;

int main() {
	int choice;

	while (1) {
		ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;
		switch (bank(choice)) {
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
		case bank::TRANSFER:
			MoneyTransfer();
			break;
		case bank::DELACC:  
			DeleteAccount(); //new function call
			break;
		case bank::DELALLACC:
			DeleteAllAccounts(); //new function call
			break;
		case bank::EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}