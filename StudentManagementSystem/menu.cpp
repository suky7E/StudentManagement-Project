#include <iostream>
#include "menu.h"
#include "student.h"

using namespace std;

void studentMenu() {
    int choice;
    loadStudents();  

    do {
        cout << "\n--- Student Menu ---\n";
        cout << "1. Display All Students\n";
        cout << "2. Add Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. View Statistics\n";
        cout << "6. Back to Main Menu\n";
        cout << "Select option: ";
        cin >> choice;

        switch (choice) {
            case 1: displayStudents(); break;
            case 2: addStudent(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: viewStats(); break;
            case 6: cout << "Returning to Main Menu...\n"; break;
            default: cout << "Invalid option.\n"; break;
        }
    } while (choice != 6);
}
