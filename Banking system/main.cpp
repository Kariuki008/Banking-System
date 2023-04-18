#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
public:
    string name;
    double balance;

    Account(string n, double b) {
        name = n;
        balance = b;
    }
};

class Bank {
public:
    vector<Account> accounts;

    void addAccount(Account account) {
        accounts.push_back(account);
        cout << "Account added successfully." << endl;
    }

    void deposit(string name, double amount) {
        for (Account& account : accounts) {
            if (account.name == name) {
                account.balance += amount;
                cout << "Deposit successful. New balance is " << account.balance << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void withdraw(string name, double amount) {
        for (Account& account : accounts) {
            if (account.name == name) {
                if (account.balance < amount) {
                    cout << "Insufficient funds." << endl;
                }
                else {
                    account.balance -= amount;
                    cout << "Withdrawal successful. New balance is " << account.balance << endl;
                }
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void displayBalance(string name) {
        for (Account& account : accounts) {
            if (account.name == name) {
                cout << "Account balance is " << account.balance << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }
};

int main() {
    Bank bank;
    int choice;
    string name;
    double balance;
    double amount;

    do {
        cout << "Select an option:" << endl;
        cout << "1. Add account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display balance" << endl;
        cout << "5. Quit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account name: ";
                cin >> name;
                cout << "Enter starting balance: ";
                cin >> balance;
                bank.addAccount(Account(name, balance));
                break;
            case 2:
                cout << "Enter account name: ";
                cin >> name;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.deposit(name, amount);
                break;
            case 3:
                cout << "Enter account name: ";
                cin >> name;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.withdraw(name, amount);
                break;
            case 4:
                cout << "Enter account name: ";
                cin >> name;
                bank.displayBalance(name);
                break;
            case 5:
                cout << "Goodbye." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
