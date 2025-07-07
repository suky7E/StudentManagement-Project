#include <iostream>
#include <fstream>
#include <sstream>
#include "auth.h"

using namespace std;

bool login() {
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("users.csv");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string storedUser, storedPass;
        getline(ss, storedUser, ',');
        getline(ss, storedPass, ',');

        if (storedUser == username && storedPass == password) {
            cout << "Login successful.\n";
            return true;
        }
    }

    cout << "Login failed. Incorrect username or password.\n";
    return false;
}

bool signUp() {
    string username, password;
    cout << "Choose a username: ";
    cin >> username;
    cout << "Choose a password: ";
    cin >> password;

    ifstream infile("users.csv");
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string existingUser;
        getline(ss, existingUser, ',');
        if (existingUser == username) {
            cout << "Username already exists. Try a different one.\n";
            return false;
        }
    }

    
    ofstream file("users.csv", ios::app);
    file << username << "," << password << "\n";
    cout << "Sign-up successful.\n";
    return true;
}
