#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include "auth.h"

using namespace std;

string getPassword() {
    string password;
    char ch;

    while ((ch = getch()) != '\r') { // '\r' is Enter
        if (ch == '\b') { // Backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password += ch;
            cout << "*";
        }
    }
    return password;
}

bool login() {
    string username;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    string password = getPassword();
    cout << endl << endl;

    ifstream file("users.csv");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string storedUser, storedPass;
        getline(ss, storedUser, ',');
        getline(ss, storedPass, ',');

        if (storedUser == username && storedPass == password) {
            cout << "Login successful.\n";
            cout << endl;
            return true;
        }
    }

    cout << "Login failed. Incorrect username or password.\n";
    system("cls");
    return false;
}

bool signUp() {
    string username;
    cout << "Choose a username: ";
    cin >> username;
    cout << "Choose a password: ";
    string password = getPassword();
    cout << endl;

    ifstream infile("users.csv");
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string existingUser;
        getline(ss, existingUser, ',');
        if (existingUser == username) {
            cout << "Username already exists. Try a different one.\n";
            system("cls");
            return false;
        }
    }

    
    ofstream file("users.csv", ios::app);
    file << username << "," << password << "\n";
    cout << "Sign-up successful.\n";
    cout << endl;
    return true;
}
