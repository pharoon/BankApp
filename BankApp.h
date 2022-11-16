#ifndef BANK_BANKACCOUNT_H
#define BANK_BANKACCOUNT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
static int id_count{100};

class BankApp
{
    vector<Client *> list;

public:
    bool AddClient(string N, string Adr, string Ph, double bal, int choice);

    void Bank();
};

#endif // BANK_BANKACCOUNT_H
