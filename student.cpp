#include <iostream>
#include <fstream>
#include <sstream> 
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

void loadFromCSV(List* ls, const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file: " << filename << "\n";
        return;
    }

    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, major, yearStr, gpaStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, major, ',');
        getline(ss, yearStr, ',');
        getline(ss, gpaStr, ',');

        int id = stoi(idStr);
        int year = stoi(yearStr);
        float gpa = stof(gpaStr);

        addStudent(ls, id, name.c_str(), major.c_str(), year, gpa);
    }

    file.close();
    cout << "Loaded students from CSV.\n";
}

// merge sort
Student* mergeSorted(Student* a, Student* b, int mode) {
    if (!a) return b;
    if (!b) return a;

    bool useA;
    if (mode == 1) useA = (a->id < b->id);
    else if (mode == 2) useA = (strcmp(a->name, b->name) < 0);
    else useA = (a->gpa > b->gpa);  // GPA descending

    if (useA) {
        a->next = mergeSorted(a->next, b, mode);
        return a;
    } else {
        b->next = mergeSorted(a, b->next, mode);
        return b;
    }
}

void splitList(Student* source, Student** frontRef, Student** backRef) {
    Student* slow = source;
    Student* fast = source->next;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

Student* mergeSortList(Student* head, int mode) {
    if (!head || !head->next)
        return head;

    Student* a;
    Student* b;
    splitList(head, &a, &b);

    a = mergeSortList(a, mode);
    b = mergeSortList(b, mode);

    return mergeSorted(a, b, mode);
}

void sortStudents(List* ls, int mode) {
    ls->head = mergeSortList(ls->head, mode);
    cout << "Sorted successfully.\n";
    displayStudent(ls);
}





