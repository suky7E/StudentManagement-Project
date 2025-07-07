#include <iostream>
#include "auth.h"
#include "menu.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "=== Welcome ===\n";
        cout << "1. Login\n2. Sign Up\n3. Help\n4. Exit\n";
        cout << "Select option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (login()) 
                studentMenu();
                break;
            case 2:
                if (signUp()) 
                cout << "Sign-up successful.\n";
                break;
            case 3:
                cout << "\n=== HELP & USER GUIDE ===\n";
                cout << "This system helps manage student records securely.\n\n";
                cout << "Available Options:\n";
                cout << "1. Login - Access your student dashboard (requires credentials).\n";
                cout << "2. Sign Up - Register a new student account.\n";
                cout << "3. Help - View this guide.\n";
                cout << "4. Exit - Close the application.\n\n";
                cout << "Tips:\n";
                cout << "- Keep your login details secure.\n";
                cout << "- Contact admin if you forget your password.\n";
                cout << "=========================\n";
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 4);

    return 0;
}
