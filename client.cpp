#include "client.h"

Client::Client(string n, string a, string p, BankAccount *b) { name = n, address = a, phone = p, ptr = b; }

string Client::get_name() { return name; }
string Client::get_add() { return address; }
string Client::get_phone() { return phone; }

BankAccount &Client::get_BankAcc()
{
    return (*ptr);
}