#include <iostream>
#include <string>
using namespace std;

// Base class for BankAccount
class BankAccount {
protected:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        } else {
            cout << "Invalid or insufficient funds.\n";
        }
    }

    virtual void calculateInterest() const = 0; 

    virtual void displayBalance() const {
        cout << "Balance: " << balance << "\n";
    }

    virtual ~BankAccount() {}
};


class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate)
        : BankAccount(initialBalance), interestRate(rate) {}

    void calculateInterest() const override {
        cout << "Savings Account Interest: " << (balance * interestRate / 100) << "\n";
    }
};

class CurrentAccount : public BankAccount {
private:
    double minimumBalance;

public:
    CurrentAccount(double initialBalance, double minBalance)
        : BankAccount(initialBalance), minimumBalance(minBalance) {}

    void withdraw(double amount) override {
        if (amount > 0 && (balance - amount) >= minimumBalance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        } else {
            cout << "Insufficient funds or minimum balance required.\n";
        }
    }

    void calculateInterest() const override {
        cout << "Current Account does not earn interest.\n";
    }
};

void displayMenu() {
    cout << "\n=== Bank Account Management ===\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Display Balance\n";
    cout << "4. Calculate Interest\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    double amount;
    int accountType;

   
    cout << "Choose Account Type:\n";
    cout << "1. Savings Account\n";
    cout << "2. Current Account\n";
    cout << "Enter account type (1 or 2): ";
    cin >> accountType;

    BankAccount* account = nullptr;
    if (accountType == 1) {
        account = new SavingsAccount(1000.0, 5.0);  
    } else if (accountType == 2) {
        account = new CurrentAccount(500.0, 100.0);  
    } else {
        cout << "Invalid account type.\n";
        return 1;
    }

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter deposit amount: ";
            cin >> amount;
            account->deposit(amount);
            break;
        }
        case 2: {
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            account->withdraw(amount);
            break;
        }
        case 3:
            account->displayBalance();
            break;
        case 4:
            account->calculateInterest();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 5);

    
    delete account;
    return 0;

}