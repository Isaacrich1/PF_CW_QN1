#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class ATM {
private:
    unordered_map<string, string> accounts;
    unordered_map<string, double> balances;
    string currentUser;

public:
    void createAccount() {
        string userId, password;
        cout << "Please enter your user id: ";
        cin >> userId;
        cout << "Please enter your password: ";
        cin >> password;
        accounts[userId] = password;
        balances[userId] = 0.0;
        cout << "Thank You! Your account has been created!" << endl;
    }

    bool login() {
        string userId, password;
        cout << "Please enter your user id: ";
        cin >> userId;
        cout << "Please enter your password: ";
        cin >> password;

        if (accounts.find(userId) != accounts.end() && accounts[userId] == password) {
            currentUser = userId;
            cout << "Access Granted!" << endl;
            return true;
        } else {
            cout << "* LOGIN FAILED! *" << endl;
            return false;
        }
    }

    void withdraw() {
        double amount;
        cout << "Amount of withdrawal: $";
        cin >> amount;
        if (balances[currentUser] >= amount) {
            balances[currentUser] -= amount;
            cout << "Withdrawal successful!" << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void deposit() {
        double amount;
        cout << "Amount of deposit: $";
        cin >> amount;
        balances[currentUser] += amount;
        cout << "Deposit successful!" << endl;
    }

    void requestBalance() {
        cout << "Your balance is $" << balances[currentUser] << "." << endl;
    }

    void mainMenu() {
        char option;
        do {
            cout << "d -> Deposit Money" << endl;
            cout << "w -> Withdraw Money" << endl;
            cout << "r -> Request Balance" << endl;
            cout << "q -> Quit" << endl;
            cout << "> ";
            cin >> option;

            switch (option) {
                case 'd':
                    deposit();
                    break;
                case 'w':
                    withdraw();
                    break;
                case 'r':
                    requestBalance();
                    break;
                case 'q':
                    cout << "Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid option!" << endl;
            }
        } while (option != 'q');
    }

    void introductionMenu() {
        char option;
        do {
            cout << "Hi! Welcome to the ATM Machine!" << endl;
            cout << "Please select an option from the menu below:" << endl;
            cout << "l -> Login" << endl;
            cout << "c -> Create New Account" << endl;
            cout << "q -> Quit" << endl;
            cout << "> ";
            cin >> option;

            switch (option) {
                case 'l':
                    if (login()) {
                        mainMenu();
                    }
                    break;
                case 'c':
                    createAccount();
                    break;
                case 'q':
                    cout << "Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid option!" << endl;
            }
        } while (option != 'q');
    }
};

int main() {
    ATM atm;
    atm.introductionMenu();
    return 0;
}
