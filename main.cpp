#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount
{
protected:
    string type;
    string ID;
    double balance1;

public:
    BankAccount(double b) { balance1 = b, ID = "FCI-001", type = "(basic)"; }
    double get_B() { return balance1; }
    string get_I() { return ID; }
    string get_t() { return type; }
    virtual bool withdraw(double amount) {}
    virtual void deposit(double amount) {}
    void Display_info(){};
};

class SavingBankAccount : public BankAccount
{
public:
    SavingBankAccount(double a) : BankAccount(a) {}
};

class Client
{
    string name, address, phone;
    BankAccount *ptr;

public:
    Client(string n, string a, string p, BankAccount *b) { name = n, address = a, phone = p, ptr = b; }
    string get_name() { return name; }
    string get_add() { return address; }
    string get_phone() { return phone; }
    BankAccount get_BankAcc() { return (*ptr); }
};

class BankApp
{
    vector<Client *> list;

public:
    bool AddClient(string N, string Adr, string Ph, double bal)
    {
        BankAccount *b_ptr;
        b_ptr = new BankAccount(bal);
        cout << "\nAn account was created with ID " << b_ptr->get_I() << " and Starting Balance " << b_ptr->get_B() << " L.E.\n";
        list.push_back(new Client(N, Adr, Ph, b_ptr));
        return 1;
    }

    void Bank()
    {
        int choice;
        while (true)
        {
            cout << "Welcome to FCAI Banking Application" << endl;
            cout << "1. Create a New Account \n2. List Clients and Accounts\n3. Withdraw Money\n4. Deposit Money \n";
            cin >> choice;
            if (choice == 1)
            {
                string name, add, phone;
                double AccType, balance;
                cin.clear();
                cin.ignore();
                cout << "Please Enter Client Name: ";
                getline(cin, name);
                cout << "Please Enter Client Address: ";
                getline(cin, add);
                cout << "Please Enter Client Phone:";
                getline(cin, phone);
            here:
                cout << "What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2: ";
                cin >> AccType;
                if (AccType != 1 && AccType != 2)
                {
                    cout << "Invalid input\n";
                    goto here;
                }
                cout << "Please Enter the Starting Balance: ";
                cin >> balance;
                if (AccType == 2)
                {
                    while (balance < 1000)
                    {
                        cout << "minimum balance is 1000 L.E";
                        cout << " Enter new Balance: ";
                        cin >> balance;
                    }
                }
                AddClient(name, add, phone, balance);
            }
            else if (choice == 2)
            {
                for (int i = 0; i < list.size(); ++i)
                {
                    cout << "--------------------------" << list[i]->get_name() << "--------------------------\n";
                    cout << "Address: " << list[i]->get_add() << " Phone: " << list[i]->get_phone();
                    cout << "\nAccount ID: " << list[i]->get_BankAcc().get_I() << " " << list[i]->get_BankAcc().get_t()
                         << "\nBalance: " << list[i]->get_BankAcc().get_B() << endl;
                }
            }
            else if (choice == 3 || choice == 4)
            {
                string ID;
                int amount;
                Client *c;
                cout << "Please Enter Account ID: ";
                getline(cin, ID);
                for (int i = 0; i < list.size(); ++i)
                {
                    if (list[i]->get_BankAcc().get_I() == ID)
                    {
                        c = list[i];
                        break;
                    }
                }
                if (choice == 3)
                {
                    c->get_BankAcc().Display_info();
                    cout << "Please Enter The Amount to Withdraw: ";
                    cin.clear();
                    cin.ignore();
                    cin >> amount;
                    while (!c->get_BankAcc().withdraw(amount))
                    {
                        cout << "Please Enter The Amount to Withdraw: ";
                        cin >> amount;
                    }
                    cout << "Thank You\n";
                    cout << "Account ID: " << c->get_BankAcc().get_I() << " New Balance: " << c->get_BankAcc().get_B() << "\n";
                }
                else
                {
                    cout << "Please Enter The Amount to deposit: ";
                    cin.clear();
                    cin.ignore();
                    cin >> amount;
                    c->get_BankAcc().deposit(amount);
                    cout << "Thank You\n";
                    cout << "Account ID: " << c->get_BankAcc().get_I() << " New Balance: " << c->get_BankAcc().get_B() << "\n";
                }
            }
            else
            {
                break;
            }
            cout << "-------------------------------------------------------------------\n";
        }
    }
};
int main()
{
    BankApp b;
    b.Bank();
    return 0;
}