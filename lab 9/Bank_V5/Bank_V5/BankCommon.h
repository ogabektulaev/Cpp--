#pragma once

enum class bank
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};
enum class account
{
    SAVING = 1,
    CREDIT
};
enum class credit
{
    LEVEL_A = 7,
    LEVEL_B = 4,
    LEVEL_C = 2
};

const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

