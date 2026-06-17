// Slide 18: static class members and friend access.

#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string owner;
    double balance;
    static int accountCount;

public:
    Account(string accountOwner, double openingBalance)
        : owner(accountOwner), balance(openingBalance) {
        ++accountCount;
    }

    static int getAccountCount() {
        return accountCount;
    }

    friend void printPrivateBalance(const Account& account);
    friend class AccountAuditor;
};

int Account::accountCount = 0;

void printPrivateBalance(const Account& account) {
    cout << account.owner << " has balance " << account.balance << '\n';
}

class AccountAuditor {
public:
    void audit(const Account& account) const {
        cout << "Auditor sees owner=" << account.owner << ", balance=" << account.balance << '\n';
    }
};

int main() {
    Account first("Rafi", 1500.0);
    Account second("Nora", 2200.5);

    cout << "Accounts created: " << Account::getAccountCount() << '\n';
    printPrivateBalance(first);

    AccountAuditor auditor;
    auditor.audit(second);

    return 0;
}
