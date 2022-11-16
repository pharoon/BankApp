#include "BankApp.h"

bool BankApp::bool AddClient(string N, string Adr, string Ph, double bal, int choice)
{
    BankAccount *b_ptr;
    if (choice == 2)
    {
        b_ptr = new SavingBankAccount(bal);
    }
    else
        b_ptr = new BankAccount(bal);
    cout << "\nAn account was created with ID " << b_ptr->get_I() << " and Starting Balance " << b_ptr->get_B() << " L.E.\n";
    list.push_back(new Client(N, Adr, Ph, b_ptr));
    return 1;
}

void BankApp::Bank()
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
            AddClient(name, add, phone, balance, AccType);
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
