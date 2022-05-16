#ifndef _BANK_H_
#define _BANK_H_

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllAccInfo();
int GetAccIdx(int);
void DeleteAllAccount();
void DeleteAccount();
int MoneyTransfer();

enum class bank { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, TRANSFER, DELACC, DELALLACC, EXIT };
const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

typedef struct
{
	int accID;
	int balance;
	char cusName[NAME_LEN];
} Account;
#endif // _BANK_H_