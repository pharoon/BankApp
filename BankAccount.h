
#ifndef BANK_BANKACCOUNT_H
#define BANK_BANKACCOUNT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
static int id_count{100};


class BankAccount {
    //variables
protected:
    string type;
    string ID;
    double balance1{};

public:
    //constructors
    BankAccount() = default;
    BankAccount(double b);
    //getters
    double get_B(){
        return balance1; }

    string get_I(){
        return ID; }

    string get_t(){
        return type; }
        //methods
    virtual bool withdraw(double amount);
    virtual void deposit(double amount);
    void Display_info();
};


#endif //BANK_BANKACCOUNT_H
