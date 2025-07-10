#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <windows.h>
#include "menu.h"
#include "test.h"

using namespace std;

void displayMenu();
void handleAddStudent(List* list);
void handleDisplayStudent(List* list);
void handleUpdateStudent(List* list);
void handleDeleteStudent(List* list);
void handleSearchStudent(List* list);
void handlePressExit();

void studentMenu() {
    List* studentList = createList();
    int choice;
    loadStudents(studentList);

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        Sleep(500);
        system("cls"); 

        switch (choice) {
            case 1:
                Sleep(500);
                system("cls");
                handleAddStudent(studentList);
                break;
            case 2:
                Sleep(500);
                system("cls");
                handleDisplayStudent(studentList);
                break;
            case 3:
                Sleep(500);
                system("cls");
                handleUpdateStudent(studentList);
                break;
            case 4:
                Sleep(500);
                system("cls");
                handleDeleteStudent(studentList);
                break;
            case 5:
                Sleep(500);
                system("cls");
                handleSearchStudent(studentList);
                break;
            case 6:
                Sleep(500);
                system("cls");
                break;
            default:
                cout << "Invalid choice. Please try again." << endl << endl;
        }
    } while (choice != 6);

    delete studentList; // Clean up memory
}

void handlePressExit() {
    cout << "Press Enter to return to the main menu...\n";
    cin.ignore();
    cin.get();
    Sleep(500);
    system("cls");
}

void displayMenu() {
    cout << endl;
    cout << "==============================\n";
    cout << "Student Management System Menu:\n\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Update Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Search Student\n";
    cout << "6. Exit\n\n";
    cout << "------------------------------\n";
    cout << "Please select an option (1-6): \n";
    cout << "------------------------------\n\n";
}

void handleAddStudent(List* list) {
    int id;
    char name[50];
    float gpa;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Student Name: ";
    cin.getline(name, 50);

    cout << "Enter Student GPA: ";
    cin >> gpa;

    addStudent(list, id, name, gpa);
    cout << "Student added successfully." << endl << endl;
    handlePressExit();
}

void handleDisplayStudent(List* list) {
    if (list->head == nullptr) {
        cout << "==============================\n";
        cout << "No student records available." << endl;
        cout << "==============================\n" << endl;
        return;
    } 

    cout << "\nList of students:" << endl << endl;
    displayStudent(list);
    handlePressExit();
   
}

void handleUpdateStudent(List* list) {
    int id;
    char newName[50];
    float newGpa;

    cout << "Enter Student ID to update: ";
    cin >> id;
    cin.ignore();

    cout << "Enter new Student Name: ";
    cin.getline(newName, 50);

    cout << "Enter new Student GPA: ";
    cin >> newGpa;

    if (updateStudent(list, id, newName, newGpa)) {
        cout << "Student updated successfully." << endl << endl;
    } else {
        cout << "Student with ID " << id << " not found." << endl << endl;
    }
    handlePressExit();
}

void saveListToCSV(List* ls, const string& filename) {
    ofstream file(filename);
    for (Student* cur = ls->head; cur; cur = cur->next)
        file << cur->id << "," << cur->name << "," << cur->gpa << "\n";
}


void handleDeleteStudent(List* list) {
    int id;

    cout << "==============================\n";
    displayStudent(list);
    cout << "==============================\n";

    cout << "Enter Student ID to delete: ";
    cin >> id;

    if (deleteStudent(list, id)) {
        cout << "Student deleted successfully." << endl << endl;
        saveListToCSV(list, "students.csv");
    } else {
        cout << "Student with ID " << id << " not found." << endl << endl;
    }
    handlePressExit();
}

void printAllWithGPA(List* ls, float gpa) {
    Student* temp = ls->head;
    bool found = false;
    
    cout << "Students with GPA " << gpa << ":\n";
    while (temp != nullptr) {
        if (fabs(temp->gpa - gpa) < 0.0001) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << endl;
            found = true;
        }
        temp = temp->next;
    }
    
    if (!found) {
        cout << "No students found.\n";
    }
    cout << endl;
}

void handleSearchStudent(List* list) {
    int searchChoice;
    cout << "Search by:\n";
    cout << "1. ID\n";
    cout << "2. Name\n";
    cout << "3. GPA\n";
    cout << "Enter your choice: ";
    cin >> searchChoice;
    cout << endl;

    switch (searchChoice) {
        case 1: {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            cout << endl;

            Student* result = searchByID(list, id);
            if (result != nullptr) {
                cout << "Student found:\n"
                     << "ID: " << result->id << endl
                     << "Name: " << result->name << endl
                     << "GPA: " << result->gpa << endl << endl;
            } else {
                cout << "No student found with ID " << id << ".\n\n";
            }
            handlePressExit();
            break;
        }

        case 2: {
            char name[50];
            cout << "Enter Name to search: ";
            cin.ignore();
            cin.getline(name, 50);
            cout << endl;

            Student* result = searchByName(list, name);
            if (result != nullptr) {
                cout << "Student found:\n"
                     << "ID: " << result->id << endl
                     << "Name: " << result->name << endl
                     << "GPA: " << result->gpa << endl << endl;
            } else {
                cout << "No student found with name \"" << name << "\".\n\n";
            }
            handlePressExit();
            break;
        }

        case 3: {
            float gpa;
            cout << "Enter GPA to search: ";
            cin >> gpa;

            Student* result = searchByGPA(list, gpa);
            if (result) {
                cout << "First match: " << result->name << endl;
            } else {
                cout << "No student found.\n";
            }

            printAllWithGPA(list, gpa);
            handlePressExit();
            break;
        }


        default:
            cout << "Invalid choice.\n\n";
            handlePressExit();
            break;
    }
}


