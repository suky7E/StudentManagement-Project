#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "student.h"
#include "utils.h"

using namespace std;

vector<Student> studentList;

//using single or double linked list for manage student records

void loadStudents() {
    ifstream file("students.csv");
    string line;
    studentList.clear();

    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        string yearStr, gpaStr;

        getline(ss, s.id, ',');
        getline(ss, s.name, ',');
        getline(ss, s.major, ',');
        getline(ss, yearStr, ',');
        getline(ss, gpaStr, ',');

        s.year = stoi(yearStr);
        s.gpa = stof(gpaStr);

        studentList.push_back(s);
    }
    file.close();
}

void saveStudents() {
    ofstream file("students.csv");
    for (const auto& s : studentList) {
        file << s.id << "," << s.name << "," << s.major << ","
             << s.year << "," << s.gpa << "\n";
    }
    file.close();
}

void displayStudents() {
    if (studentList.empty()) {
        cout << "No students available.\n";
        return;
    }

    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Major"
         << setw(5)  << "Year"
         << setw(5)  << "GPA\n";
    cout << "------------------------------------------------------------\n";

    for (const auto& s : studentList) {
        cout << setw(10) << s.id
             << setw(20) << s.name
             << setw(15) << s.major
             << setw(5)  << s.year
             << setw(5)  << s.gpa << "\n";
    }
}

void addStudent() {
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Major: ";
    getline(cin, s.major);
    cout << "Enter Year: ";
    cin >> s.year;
    cout << "Enter GPA: ";
    cin >> s.gpa;

    studentList.push_back(s);
    saveStudents();
    cout << "Student added successfully.\n";
}

void updateStudent() {
    string id;
    cout << "Enter student ID to update: ";
    cin >> id;

    for (auto& s : studentList) {
        if (s.id == id) {
            cout << "Updating student: " << s.name << "\n";
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter new major: ";
            getline(cin, s.major);
            cout << "Enter new year: ";
            cin >> s.year;
            cout << "Enter new GPA: ";
            cin >> s.gpa;
            saveStudents();
            cout << "Update successful.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    string id;
    cout << "Enter student ID to delete: ";
    cin >> id;

    for (size_t i = 0; i < studentList.size(); ++i) {
        if (studentList[i].id == id) {
            studentList.erase(studentList.begin() + i);
            saveStudents();
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void viewStats() {
    if (studentList.empty()) {
        cout << "No data for stats.\n";
        return;
    }

    float totalGPA = 0;
    for (const auto& s : studentList) {
        totalGPA += s.gpa;
    }

    cout << "Total Students: " << studentList.size() << "\n";
    cout << "Average GPA: " << totalGPA / studentList.size() << "\n";
}
