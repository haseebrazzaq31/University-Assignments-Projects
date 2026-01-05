#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
struct Account {
    string name;
    int pin;
    double balance;
    double loan;
    bool isActive;
};
vector<Account> accounts;
int currentSessionIndex = -1;
void printHeader(string title) {
    cout << "\n-----------------------------\n";
    cout << "   " << title << "\n";
    cout << "-----------------------------\n";
}
void createAccount() {
    printHeader("CREATE NEW ACCOUNT");
    string newName;
    int newPin;
    double initialDeposit;
    cout << "Enter Name: ";
    cin >> newName;
    cout << "Set PIN: ";
    cin >> newPin;
    cout << "Initial Deposit: ";
    cin >> initialDeposit;
    if (initialDeposit < 0) {
        cout << "Invalid deposit amount.\n";
        return;
    }
    accounts.push_back({newName, newPin, initialDeposit, 0.0, true});
    cout << "Account created successfully! Please login.\n";
}
void adminView() {
    printHeader("Admin check");
    if (accounts.empty()) {
        cout << "No accounts Registered\n";
        return;
    }
    cout << left << setw(10) << "Name" << setw(8) << "PIN" << setw(15) << "Balance" << setw(10) << "Loan" << setw(10) << "Status" << endl;
    cout << "---------------------------------------------------\n";
    for (const auto& acc : accounts) {
        cout << left << setw(10) << acc.name 
             << setw(8) << acc.pin 
             << setw(15) << acc.balance 
             << setw(10) << acc.loan 
             << setw(10) << (acc.isActive ? "Active" : "Closed") << endl;
    }
    cout << "\nTotal Accounts: " << accounts.size() << endl;
}
int login() {
    string inName;
    int inPin;
    printHeader("Login");
    cout << "Enter Name: ";
    cin >> inName;
    cout << "Enter PIN: ";
    cin >> inPin;
// Admin login checl
    if (inName == "Haseeb" && inPin == 1234) {
        return -2; 
    }
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].isActive && accounts[i].name == inName && accounts[i].pin == inPin) {
            return i;
        }
    }
    return -1;
}
void showBalance() {
    printHeader("ACCOUNT STATEMENT");
    cout << "Account Holder: " << accounts[currentSessionIndex].name << endl;
    cout << "Current Balance: " << fixed << setprecision(2) << accounts[currentSessionIndex].balance << endl;
    cout << "Outstanding Loan: " << accounts[currentSessionIndex].loan << endl;
}
void closeAccount() {
    printHeader("Closing Account");
    char confirm;
    if (accounts[currentSessionIndex].loan > 0) {
        cout << "Error: Cannot close account with outstanding loan.\n";
        return;
    }
    cout << "Are you sure you want to close your account? (y/n): ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        accounts[currentSessionIndex].isActive = false;
        cout << "Account closed \n";
        currentSessionIndex = -1;
    }
}
void accountManagement() {
    int choice;
    do {
        if (currentSessionIndex == -1) return;
        printHeader("ACCOUNT MANAGEMENT");
        cout << "1. Show Balance & Statement\n";
        cout << "2. Close Account\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: showBalance(); break;
            case 2: closeAccount(); break;
            case 3: return;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3 && currentSessionIndex != -1);
}
void depositMoney() {
    printHeader("Money Deposit");
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid amount. Must be positive.\n";
    } else {
        accounts[currentSessionIndex].balance += amount;
        cout << "Deposit successful.\n";
        cout << "New Balance: " << accounts[currentSessionIndex].balance << endl;
    }
}
void withdrawMoney() {
    printHeader("WITHDRAWAL");
    double amount;
    cout << "Current Balance: " << accounts[currentSessionIndex].balance << endl;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount <= 0) cout << "Invalid amount.\n";
    else if (amount > accounts[currentSessionIndex].balance) cout << "Insufficient funds.\n";
    else {
        accounts[currentSessionIndex].balance -= amount;
        cout << "Please collect your cash.\n";
        cout << "New Balance: " << accounts[currentSessionIndex].balance << endl;
    }
}
void transactions() {
    int choice;
    do {
        printHeader("Transaction");
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: depositMoney(); break;
            case 2: withdrawMoney(); break;
            case 3: return;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);
}
void availLoan() {
    printHeader(""Avail Loan);
    if (accounts[currentSessionIndex].loan > 0) {
        cout << "Please clear existing loan first.\n";
        return;
    }
    double amount;
    double maxLoan = accounts[currentSessionIndex].balance * 2; 
    cout << "Max loan limit: " << maxLoan << endl;
    cout << "Enter loan amount: ";
    cin >> amount;
    if (amount > 0 && amount <= maxLoan) {
        accounts[currentSessionIndex].loan += amount;
        accounts[currentSessionIndex].balance += amount;
        cout << "Loan approved and credited.\n";
    } else {
        cout << "Invalid amount or limit exceeded.\n";
    }
}
void returnLoan() {
    printHeader("RETURN LOAN");
    double loanAmt = accounts[currentSessionIndex].loan;
    if (loanAmt == 0) {
        cout << "No outstanding loans.\n";
        return;
    }
    cout << "Outstanding Loan: " << loanAmt << endl;
    cout << "Pay full amount? (y/n): ";
    char confirm;
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        if (accounts[currentSessionIndex].balance >= loanAmt) {
            accounts[currentSessionIndex].balance -= loanAmt;
            accounts[currentSessionIndex].loan = 0;
            cout << "Loan repaid \n";
        } else {
            cout << "Insufficient balance\n";
        }
    }
}
void loanManagement() {
    int choice;
    do {
        printHeader("Loan Management");
        cout << "1. Avail Loan\n";
        cout << "2. Return Loan\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: availLoan(); break;
            case 2: returnLoan(); break;
            case 3: return;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);
}
void sessionMenu() {
    int choice;
    while (currentSessionIndex != -1) {
        printHeader("User");
        cout << "Welcome " << accounts[currentSessionIndex].name << "!\n";
        cout << "1. Account Management\n";
        cout << "2. Transactions\n";
        cout << "3. Loan Management\n";
        cout << "4. Logout\n";
        cin >> choice;
        switch (choice) {
            case 1: accountManagement(); break;
            case 2: transactions(); break;
            case 3: loanManagement(); break;
            case 4: 
                currentSessionIndex = -1; 
                cout << "Logged out \n";
                break;
            default: cout << "Invalid choice\n";
        }
    }
}
int main() {
    cout << fixed << setprecision(2);
    int choice;
    while (true) {
        printHeader("Banking System Start");
        cout << "1. Create New Account\n";
        cout << "2. Login\n";
        cout << "3. Exit System\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: createAccount(); break;
            case 2: 
                currentSessionIndex = login();
                if (currentSessionIndex == -2) {
                    adminView();
                    currentSessionIndex = -1; 
                }
                else if (currentSessionIndex != -1) sessionMenu();
                else cout << "Invalid Credentials \n";
                break;
            case 3: 
                cout << "System Closed\n";
                return 0;
            default: cout << "Invalid choice.\n";
        }
    }
    return 0;
}