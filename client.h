#ifndef BANK_BANKACCOUNT_H
#define BANK_BANKACCOUNT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Client
{
    string name, address, phone;
    BankAccount *ptr;

public:
    Client(string n, string a, string p, BankAccount *b);
    string get_name();
    string get_add();
    string get_phone();
    BankAccount &get_BankAcc();
};

#endif // BANK_BANKACCOUNT_H