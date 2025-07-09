#include <iostream>
#include <cstring>
#include <cstdlib>
#include "student.h"

using namespace std;

void printBanner() {
    cout << "==========================================\n";
    cout << "        STUDENT MANAGEMENT SYSTEM         \n";
    cout << "==========================================\n";
}

int main() {
    List* myList = createList();
    int choice;

    while (true) {
        printBanner();
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Update Student Info\n";
        cout << "4. Delete Student by ID\n";
        cout << "5. View Statistics\n";
        cout << "6. Search by ID\n";
        cout << "7. Search by Name\n";
        cout << "8. Search by GPA\n";
        cout << "0. Exit Program\n";
        cout << "------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        system("cls"); 

        if (choice == 1) {
            int id, year;
            char name[50], major[30];
            float gpa;
            cout << "Enter ID: "; cin >> id; cin.ignore();
            cout << "Enter Name: "; cin.getline(name, 50);
            cout << "Enter Major: "; cin.getline(major, 30);
            cout << "Enter Year: "; cin >> year;
            cout << "Enter GPA: "; cin >> gpa;
            addStudent(myList, id, name, major, year, gpa);
        }

        else if (choice == 2) {
            displayStudent(myList);
        }

        else if (choice == 3) {
            int id, year;
            char name[50], major[30];
            float gpa;
            cout << "Enter ID to update: "; cin >> id; cin.ignore();
            cout << "Enter new Name: "; cin.getline(name, 50);
            cout << "Enter new Major: "; cin.getline(major, 30);
            cout << "Enter new Year: "; cin >> year;
            cout << "Enter new GPA: "; cin >> gpa;
            if (updateStudent(myList, id, name, major, year, gpa))
                cout << "Student updated.\n";
            else
                cout << "Student not found.\n";
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID to delete: "; cin >> id;
            if (deleteStudent(myList, id))
                cout << "Student deleted.\n";
            else
                cout << "Student not found.\n";
        }

        else if (choice == 5) {
            viewStats(myList);
        }

        else if (choice == 6) {
            int id;
            cout << "Enter ID to search: "; cin >> id;
            Student* s = searchByID(myList, id);
            if (s)
                cout << "Found: ID=" << s->id << ", Name=" << s->name << ", GPA=" << s->gpa << endl;
            else
                cout << "Student not found.\n";
        }

        else if (choice == 7) {
            char name[50];
            cout << "Enter Name to search: "; cin.ignore(); cin.getline(name, 50);
            Student* s = searchByName(myList, name);
            if (s)
                cout << "Found: ID=" << s->id << ", Name=" << s->name << ", GPA=" << s->gpa << endl;
            else
                cout << "Student not found.\n";
        }

        else if (choice == 8) {
            float gpa;
            cout << "Enter GPA to search: "; cin >> gpa;
            Student* s = searchByGPA(myList, gpa);
            if (s)
                cout << "Found: ID=" << s->id << ", Name=" << s->name << ", GPA=" << s->gpa << endl;
            else
                cout << "Student not found.\n";
        }

        else if (choice == 0) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "Invalid choice. Please try again.\n";
        }

        cout << "\n"; 
        system("pause");
        system("cls");
    }

    return 0;
}

