#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int id_count{100};

class BankAccount
{
protected:
    string type;
    string ID;
    double balance1;

public:
    double get_B() { return balance1; }
    string get_I() { return ID; }
    string get_t() { return type; }
    void Display_info()
    {
        cout << "your account ID: " << ID << endl;
        cout << "your account type: " << type << endl;

        cout << "your account balance: " << balance1 << endl;
    };

    BankAccount(double b) : balance1(b)
    {
        if (b < 0)
        {
            throw std::invalid_argument("balance");
        }
        ID = "FCAI." + to_string(++id_count);
        type = "(basic)";
    }

    virtual bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "insufficient amount." << endl;
            return false;
        }
        else if (balance1 >= amount)
        {
            cout << "you have successfully withdrew: " << amount << endl;
            balance1 -= amount;
            return true;
        }
        else
        {
            cout << "insufficient amount." << endl;
            return false;
        }
    }

    virtual void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw std::invalid_argument("amount");
        }
        cout << "you have successfully deposited: " << amount << endl;
        balance1 += amount;
    }
};

class SavingBankAccount : public BankAccount
{
    double minimum_balance;

public:
    SavingBankAccount(double a) : BankAccount(a)
    {
        type = "Saving";
        minimum_balance = 1000.0;
        if (a < minimum_balance)
        {
            cout << "invalid balance";
        }
    }
    SavingBankAccount(double amount, double min) : BankAccount(amount)
    {
        type = "Saving";
        minimum_balance = min;
        if (amount < min)
            cout << "invalid balance";
    }
    void deposit(double b)
    {
        if (b >= 100.0)
        {
            balance1 += b;
        }
        else
            cout << "deposit too small" << endl;
    }
    bool withdraw(double b)
    {
        if ((balance1 - b) > minimum_balance)
        {
            balance1 -= b;
            return true;
        }
        else
            return false;
    }
    void display()
    {
        cout << "your account ID: " << ID << endl;
        cout << "your account type: " << type << endl;
        cout << "your account balance: " << balance1 << endl;
        cout << "your minimum allowed balance :" << minimum_balance << endl;
    }
    void set_minbalance(double ewb)
    {
        minimum_balance = ewb;
    }
    double get_minbalance()
    {
        return minimum_balance;
    }
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
    BankAccount &get_BankAcc() { return (*ptr); }
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
                cin.clear();
                cin.ignore();
                string ID;
                int amount = 0, x = 0;
                cout << "Please Enter Account ID: ";
                getline(cin, ID);
                Client *c;
                for (int i = 0; i < list.size(); ++i)
                {
                    if (list[i]->get_BankAcc().get_I() == ID)
                    {
                        x = 1;

                        if (choice == 3)
                        {
                            list[i]->get_BankAcc().Display_info();
                            cout << "Please Enter The Amount to Withdraw: ";
                            cin >> amount;
                            while (!list[i]->get_BankAcc().withdraw(amount))
                            {
                                cout << "Please Enter The Amount to Withdraw: ";
                                cin >> amount;
                            }
                            cout << "Thank You\n";
                            cout << "Account ID: " << list[i]->get_BankAcc().get_I() << " New Balance: " << list[i]->get_BankAcc().get_B() << "\n";
                        }
                        else
                        {
                            cout << "Please Enter The Amount to deposit: ";
                            cin >> amount;
                            list[i]->get_BankAcc().deposit(amount);
                            cout << "Thank You\n";
                            cout << "Account ID: " << list[i]->get_BankAcc().get_I() << " New Balance: " << list[i]->get_BankAcc().get_B() << "\n";
                        }
                    }
                }
                if (!x)
                    cout << "invalid ID\n";
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