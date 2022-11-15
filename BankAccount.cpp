
#include "BankAccount.h"

BankAccount::BankAccount(double b) : balance1(b) {
    if (b < 0){
        throw std::invalid_argument("balance");
    }
    ID = "FCAI." + to_string(++id_count);
    type = "(basic)";
}

bool BankAccount::withdraw(double amount){
    if (amount <= 0){
        cout << "insufficient amount." << endl;
    }
    if (balance1 >= amount){
        cout << "you have successfully withdrew: " << amount << endl;
        balance1 -= amount;
        return true;

    } else{
        cout << "insufficient amount." << endl;
        return false;
    }
}

void BankAccount::deposit(double amount) {
    if (amount <= 0){
        throw std::invalid_argument("amount");
    }
    cout << "you have successfully deposited: " << amount << endl;
    balance1 += amount;
}

void BankAccount::Display_info() {
    cout << "your account ID: " << ID << endl;
    cout << "your account type: " << type << endl;
    cout << "your account balance: " << balance1 << endl;
}
