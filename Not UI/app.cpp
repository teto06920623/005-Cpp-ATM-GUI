#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class BaseAccount
{
protected:
    string userID, password, type;
    double balance;

public:
    BaseAccount(string id, string pass, double bal, string t) : userID(id), password(pass), balance(bal), type(t) {}
    virtual ~BaseAccount() = default;
    string getID() const { return userID; }
    string getPassword() const { return password; }
    string getType() const { return type; }
    double getBalance() const { return balance; }
    bool checkPassword(const string &pass) const { return password == pass; }
    virtual void deposit(double amount)
    {
        if (amount > 0)
            balance += amount;
    }
    virtual bool withdraw(double amount) { return false; }
};

class CheckingAccount : public BaseAccount
{
public:
    CheckingAccount(string id, string pass, double bal) : BaseAccount(id, pass, bal, "Checking") {}
    bool withdraw(double amount) override
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            return true;
        }
        return false;
    }
};

class SavingsAccount : public BaseAccount
{
public:
    SavingsAccount(string id, string pass, double bal) : BaseAccount(id, pass, bal, "Savings") {}
};

class SystemATM
{
private:
    vector<shared_ptr<BaseAccount>> accounts;
    shared_ptr<BaseAccount> loggedInAccount = nullptr;

    void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void pauseScreen()
    {
        cout << "\nPress Enter to continue...";
        cin.ignore(10000, '\n');
        cin.get();
    }

    void printHeader(const string &title)
    {
        clearScreen();
        cout << "=================================================\n";
        cout << "           " << title << "\n";
        cout << "=================================================\n\n";
    }

public:
    SystemATM()
    {
        accounts.push_back(make_shared<CheckingAccount>("user1", "1234", 5000));
        accounts.push_back(make_shared<SavingsAccount>("ahmed", "0000", 15000));
    }

    void run()
    {
        while (true)
        {
            printHeader("MODERN CYBERBANK TERMINAL");
            cout << "Enter User ID (or 'admin'): ";
            string id;
            cin >> id;
            cout << "Enter Password: ";
            string pass;
            cin >> pass;

            if (id == "admin" && pass == "admin")
            {
                adminMenu();
            }
            else
            {
                bool found = false;
                for (auto &acc : accounts)
                {
                    if (acc->getID() == id && acc->checkPassword(pass))
                    {
                        loggedInAccount = acc;
                        customerMenu();
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "\n[!] Error: Invalid ID or Password.";
                    pauseScreen();
                }
            }
        }
    }

private:
    void adminMenu()
    {
        while (true)
        {
            printHeader("ADMINISTRATOR DASHBOARD");
            cout << "1. Add New Customer\n";
            cout << "2. View All Customers Database\n";
            cout << "3. Logout\n\n";
            cout << "Select an option: ";
            int choice;
            cin >> choice;

            if (choice == 1)
            {
                string nId, nPass;
                double bal;
                int t;
                cout << "\n--- CREATE NEW ACCOUNT ---\n";
                cout << "New User ID: ";
                cin >> nId;
                cout << "New Password: ";
                cin >> nPass;
                cout << "Initial Balance ($): ";
                cin >> bal;
                cout << "Account Type (1 for Checking, 2 for Savings): ";
                cin >> t;

                if (t == 1)
                    accounts.push_back(make_shared<CheckingAccount>(nId, nPass, bal));
                else
                    accounts.push_back(make_shared<SavingsAccount>(nId, nPass, bal));

                cout << "\n[+] Account created successfully!";
                pauseScreen();
            }
            else if (choice == 2)
            {
                printHeader("REGISTERED CUSTOMERS DATABASE");
                cout << left << setw(15) << "USER ID" << setw(15) << "PASSWORD" << setw(15) << "TYPE" << "BALANCE\n";
                cout << "-------------------------------------------------\n";
                for (const auto &acc : accounts)
                {
                    cout << left << setw(15) << acc->getID()
                         << setw(15) << acc->getPassword()
                         << setw(15) << acc->getType()
                         << "$" << fixed << setprecision(2) << acc->getBalance() << "\n";
                }
                pauseScreen();
            }
            else if (choice == 3)
            {
                break;
            }
        }
    }

    void customerMenu()
    {
        while (true)
        {
            printHeader("CUSTOMER DASHBOARD");
            cout << "Welcome, " << loggedInAccount->getID() << "\n";
            cout << "Account Type: " << loggedInAccount->getType() << "\n";
            cout << "Current Balance: $" << fixed << setprecision(2) << loggedInAccount->getBalance() << "\n";
            cout << "-------------------------------------------------\n";
            cout << "1. Deposit Funds\n";

            if (loggedInAccount->getType() == "Checking")
            {
                cout << "2. Withdraw Funds\n";
            }

            cout << "3. Logout\n\n";
            cout << "Select an action: ";

            int choice;
            cin >> choice;

            if (choice == 1)
            {
                cout << "\nEnter amount to deposit: $";
                double amount;
                cin >> amount;
                if (amount > 0)
                {
                    loggedInAccount->deposit(amount);
                    cout << "\n[+] Successfully deposited $" << amount;
                }
                else
                {
                    cout << "\n[!] Invalid amount.";
                }
                pauseScreen();
            }
            else if (choice == 2 && loggedInAccount->getType() == "Checking")
            {
                cout << "\nEnter amount to withdraw: $";
                double amount;
                cin >> amount;
                if (loggedInAccount->withdraw(amount))
                {
                    cout << "\n[+] Successfully withdrew $" << amount;
                }
                else
                {
                    cout << "\n[!] Failed: Insufficient funds or invalid amount.";
                }
                pauseScreen();
            }
            else if (choice == 3 || (choice == 2 && loggedInAccount->getType() != "Checking"))
            {
                loggedInAccount = nullptr;
                break;
            }
        }
    }
};

int main()
{
    SystemATM atm;
    atm.run();
    return 0;
}