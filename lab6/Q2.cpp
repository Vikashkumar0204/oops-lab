#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Base ledger class: holds balance and transaction history
class Ledger {
protected:
    string accountHolder;
    double balance;
    vector<string> history;

    void record(const string& entry) {
        history.push_back(entry);
    }

public:
    Ledger(string name, double initial)
        : accountHolder(name), balance(initial) {
        record("Account opened with " + to_string(initial));
    }

    virtual ~Ledger() {}

    virtual void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }
        balance += amount;
        record("Deposit: +" + to_string(amount));
    }

    virtual bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Withdrawal failed.\n";
            return false;
        }
        balance -= amount;
        record("Withdraw: -" + to_string(amount));
        return true;
    }

    // Specialized behaviour is defined by derived classes
    virtual void monthEnd() = 0;

    void showHistory() const {
        cout << "--- Ledger for " << accountHolder << " ---\n";
        for (const auto& h : history)
            cout << h << "\n";
        cout << "Balance: " << fixed << setprecision(2) << balance << "\n\n";
    }
};

// Savings account: earns interest, limited withdrawals
class SavingsAccount : public Ledger {
    double interestRate;   // annual %
    int withdrawalCount;
    static const int MAX_WITHDRAWALS = 3;

public:
    SavingsAccount(string name, double initial, double rate)
        : Ledger(name, initial), interestRate(rate), withdrawalCount(0) {}

    bool withdraw(double amount) override {
        if (withdrawalCount >= MAX_WITHDRAWALS) {
            cout << "Withdrawal limit reached for savings account.\n";
            return false;
        }
        if (Ledger::withdraw(amount)) {
            withdrawalCount++;
            return true;
        }
        return false;
    }

    void monthEnd() override {
        double interest = balance * (interestRate / 100) / 12;
        balance += interest;
        record("Interest credited: +" + to_string(interest));
        withdrawalCount = 0;  // reset monthly counter
    }
};

// Checking account: overdraft allowed, monthly fee
class CheckingAccount : public Ledger {
    double overdraftLimit;
    double monthlyFee;

public:
    CheckingAccount(string name, double initial, double overdraft, double fee)
        : Ledger(name, initial), overdraftLimit(overdraft), monthlyFee(fee) {}

    bool withdraw(double amount) override {
        if (amount <= 0 || amount > balance + overdraftLimit) {
            cout << "Overdraft limit exceeded.\n";
            return false;
        }
        balance -= amount;
        record("Withdraw: -" + to_string(amount));
        return true;
    }

    void monthEnd() override {
        balance -= monthlyFee;
        record("Monthly fee charged: -" + to_string(monthlyFee));
    }
};

int main() {
    SavingsAccount sav("Alice", 10000, 6.0);
    CheckingAccount chk("Bob", 2000, 1000, 50);

    // Polymorphic use through base class pointers
    vector<Ledger*> accounts = { &sav, &chk };

    sav.deposit(2000);
    sav.withdraw(500);

    chk.deposit(500);
    chk.withdraw(3000);   // uses overdraft
    chk.withdraw(1000);   // exceeds overdraft, fails

    for (Ledger* acc : accounts) {
        acc->monthEnd();
        acc->showHistory();
    }

    return 0;
}
