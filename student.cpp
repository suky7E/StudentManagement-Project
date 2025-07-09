#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

List* createList() {
    List* ls = new List;
    ls->head = nullptr;
    ls->count = 0;
    return ls;
}

void addStudent(List* ls, int id, const char* name, const char* major, int year, float gpa) {
    Student* s = new Student;
    s->id = id;
    strcpy(s->name, name);
    strcpy(s->major, major);
    s->year = year;
    s->gpa = gpa;
    s->next = ls->head;
    ls->head = s;
    ls->count++;
    cout << "Student added.";
}

void displayStudent(List* ls) {
    if (ls->head == nullptr) {
        cout << "No student records.";
        return;
    }
    Student* current = ls->head;
    while (current) {
        cout << "ID: " << current->id
             << ", Name: " << current->name
             << ", Major: " << current->major
             << ", Year: " << current->year
             << ", GPA: " << current->gpa << endl;
        current = current->next;
    }
}

bool updateStudent(List* ls, int id, const char* newName, const char* newMajor, int newYear, float newGPA) {
    Student* s = ls->head;
    while (s != nullptr) {
        if (s->id == id) {
            strcpy(s->name, newName);
            strcpy(s->major, newMajor);
            s->year = newYear;
            s->gpa = newGPA;
            return true;
        }
        s = s->next;
    }
    return false;
}

bool deleteStudent(List* ls, int id) {
    Student* current = ls->head;
    Student* prev = nullptr;

    while (current) {
        if (current->id == id) {
            if (prev == nullptr)
                ls->head = current->next;
            else
                prev->next = current->next;
            delete current;
            ls->count--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

Student* searchByID(List* ls, int id) {
    Student* temp = ls->head;
    while (temp != nullptr) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

Student* searchByName(List* ls, const char* name) {
    Student* temp = ls->head;
    while (temp != nullptr) {
        if (strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return nullptr;
}

Student* searchByGPA(List* ls, float gpa) {
    Student* temp = ls->head;
    while (temp != nullptr) {
        if (temp->gpa == gpa) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void viewStats(List* ls) {
    if (ls->head == nullptr) {
        cout << "No student data.\n";
        return;
    }

    float totalGPA = 0;
    float minGPA = ls->head->gpa;
    float maxGPA = ls->head->gpa;
    int count = 0;

    Student* current = ls->head;
    while (current) {
        totalGPA += current->gpa;
        if (current->gpa < minGPA) minGPA = current->gpa;
        if (current->gpa > maxGPA) maxGPA = current->gpa;
        count++;
        current = current->next;
    }

    cout << "\n===== Student Statistics =====\n";
    cout << "Total Students: " << count << endl;
    cout << "Average GPA: " << totalGPA / count << endl;
    cout << "Minimum GPA: " << minGPA << endl;
    cout << "Maximum GPA: " << maxGPA << endl;
}



