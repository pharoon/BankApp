
#ifndef BANK_SAVINGBANKACCOUNT_H
#define BANK_SAVINGBANKACCOUNT_H
#include "BankAccount.h"

class SavingBankAccount : public BankAccount
{
private:
    double minimum_balance;

public:
    SavingBankAccount(double a);
    SavingBankAccount(double amount, double minimum);
    // setters//
    void set_minbalance(double newb);
    // getters//
    double get_minbalance();
    // functions//
    bool withdraw(double out);
    void deposit(double in);
    void display();
};

#endif // BANK_SAVINGBANKACCOUNT_H
