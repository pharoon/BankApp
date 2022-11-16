#include "SavingBankAccount.h"

SavingBankAccount::SavingBankAccount(double a) : BankAccount(a)
{
    type = "Saving";
    minimum_balance = 1000.0;
    if (a < minimum_balance)
    {
        cout << "invalid balance";
    }
}
SavingBankAccount::SavingBankAccount(double amount, double min) : BankAccount(amount)
{
    type = "Saving";
    minimum_balance = min;
    if (amount < min)
        cout << "invalid balance";
}
void SavingBankAccount::deposit(double b)
{
    if (b >= 100.0)
    {
        balance1 += b;
    }
    else
        cout << "deposit too small" << endl;
}
bool SavingBankAccount::withdraw(double b)
{
    if ((balance1 - b) > minimum_balance)
    {
        balance1 -= b;
        cout << "Thank YOU!\n";
        return true;
    }
    else
    {
        cout << "unsucessful withdrawing\n";
        return false;
    }
}
void SavingBankAccount::display()
{
    cout << "your account ID: " << ID << endl;
    cout << "your account type: " << type << endl;
    cout << "your account balance: " << balance1 << endl;
    cout << "your minimum allowed balance :" << minimum_balance << endl;
}
void SavingBankAccount::set_minbalance(double ewb)
{
    minimum_balance = ewb;
}
double SavingBankAccount::get_minbalance()
{
    return minimum_balance;
}
