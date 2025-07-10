#include <iostream>
#include <iomanip>
#include "auth.h"
#include "menu.h"
#include <windows.h>

using namespace std;

int main() {
    system("cls");
    int choice;

    do {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "           Student Management System   \n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "+---------------------+---------------------+\n";
        cout << "               | 1. Login     |\n";
        cout << "               +--------------+\n";
        cout << "               | 2. Register  |\n";
        cout << "               +--------------+\n";
        cout << "               | 3. Help      |\n";
        cout << "               +--------------+\n";
        cout << "               | 4. Exit      |\n";
        cout << "+---------------------+---------------------+\n\n";
        cout << "Select option: ";
        cin >> choice;
        cout << endl;
        system("cls"); 

        switch (choice) {
            case 1:
                if (login()) {
                    Sleep(500);
                    system("cls"); 
                    studentMenu();
                } else {
                    cout << "Login failed. Please try again.\n";
                    Sleep(500);
                    system("cls");
                }
                break;
            case 2:
                if (signUp()) {
                    Sleep(500);
                    system("cls");
                } else {
                    cout << "Sign-up failed. Please try again.\n";
                    Sleep(500);
                    system("cls");
                }
                break;
            case 3:
                system("cls");
                cout << "\n\t=== HELP & USER GUIDE ===\n";
                cout << "This system helps manage student records securely.\n\n";
                cout << "Available Options:\n";
                cout << "1. Login - Access your student dashboard (requires credentials).\n";
                cout << "2. Sign Up - Register a new student account.\n";
                cout << "3. Help - View this guide.\n";
                cout << "4. Exit - Close the application.\n\n";
                cout << "Tips:\n";
                cout << "- Keep your login details secure.\n";
                cout << "- Contact admin if you forget your password.\n\n";

                cout << "Press Enter to return to the main menu...\n";
                cin.ignore();
                cin.get();
                Sleep(500);
                system("cls");

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
