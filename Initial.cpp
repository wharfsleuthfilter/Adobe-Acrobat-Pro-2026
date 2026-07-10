#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Account {
public:
    Account(const std::string& owner, double balance)
        : owner(owner), balance(balance) {}

    const std::string& getOwner() const {
        return owner;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

private:
    std::string owner;
    double balance;
};

class Bank {
public:
    void addAccount(const std::string& owner, double balance) {
        accounts.emplace_back(owner, balance);
    }

    void depositTo(const std::string& owner, double amount) {
        for (auto& account : accounts) {
            if (account.getOwner() == owner) {
                account.deposit(amount);
            }
        }
    }

    void printAccounts() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Bank Accounts\n";
        std::cout << "=============\n";

        double total = 0.0;

        for (const auto& account : accounts) {
            std::cout << account.getOwner()
                      << " | Balance: $"
                      << account.getBalance()
                      << std::endl;
            total += account.getBalance();
        }

        std::cout << "=============\n";
        std::cout << "Total Funds: $" << total << std::endl;
    }

private:
    std::vector<Account> accounts;
};

int main() {
    Bank bank;

    bank.addAccount("Alice", 1250.00);
    bank.addAccount("Brian", 980.50);
    bank.addAccount("Clara", 2100.75);
    bank.addAccount("David", 640.25);

    bank.depositTo("Brian", 120.00);
    bank.depositTo("David", 350.00);

    bank.printAccounts();

    return 0;
}
