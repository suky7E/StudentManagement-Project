#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <windows.h>
using namespace std;

struct Student {
    int id;
    char name[50];
    float gpa;
    Student* next;
};

struct List {
    Student* head;
    int count;
};

List* createList() {
    List* ls = new List;
    ls->head = nullptr;
    ls->count = 0;
    return ls;
}

Student* searchByID(List* ls, int id);
Student* searchByName(List* ls, const char* name);
Student* searchByGPA(List* ls, float gpa);

void saveStudents(List* ls) {
    ofstream file("students.csv");
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    Student* current = ls->head;
    while (current) {
        file << current->id << "," 
             << current->name << "," 
             << current->gpa << "\n";
        current = current->next;
    }

    file.close();

}

void addStudent(List* ls, int id, const char* name, float gpa) {
    Student* s = new (nothrow) Student;  
    if (!s) {
        cerr << "Error: Memory allocation failed!" << endl;
        return;
    }

    s->id = id;
    strncpy(s->name, name, sizeof(s->name) - 1);  
    s->name[sizeof(s->name) - 1] = '\0';  
    s->gpa = gpa;

    s->next = ls->head;  
    ls->head = s;        
    ls->count++;     

    saveStudents(ls);

}

void loadStudents(List* ls) {
    ifstream file("students.csv");
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        stringstream ss(line);
        string idStr, name, gpaStr;

        try {
            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, gpaStr, ',');

            int id = stoi(idStr);
            float gpa = stof(gpaStr);

            addStudent(ls, id, name.c_str(), gpa);
        } catch (...) {
            cerr << "Error parsing line: " << line << endl;
        }
    }
    file.close();
}

void displayStudent(List* ls) {
    if (ls->head == nullptr) {
        cout << "No student records." << endl << endl;
        return;
    }

    cout << "=== Student List ===" << endl;
    cout << "Total: " << ls->count << " students" << endl;
    cout << "---------------------" << endl;

    Student* current = ls->head;
    int max_iterations = ls->count + 2; // Prevent infinite loops

    while (current && max_iterations--) {
        cout << "ID: " << current->id
             << ", Name: " << current->name
             << ", GPA: " << current->gpa << endl;
        current = current->next;
    }

    if (max_iterations <= 0) {
        cerr << "WARNING: Possible infinite loop (cycle in list)!" << endl;
    }

    cout << "---------------------" << endl;
    cout << endl;
}

bool updateStudent(List* ls, int id, const char* newName, float newGPA) {
    Student* s = searchByID(ls, id);
    if (!s) return false;
    strcpy(s->name, newName);
    s->gpa = newGPA;
    return true;
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

// Optional: similar to displayStudent
// void viewStats(List* ls) {
//     if (ls->head == nullptr) {
//         cout << "No student data." << endl;
//         return;
//     }

//     Student* current = ls->head;
//     cout << "List of Students:" << endl;
//     while (current) {
//         cout << "ID: " << current->id
//              << ", Name: " << current->name
//              << ", GPA: " << current->gpa << endl;
//         current = current->next;
//     }
// }

Student* searchByID(List* ls, int id) {
    Student* temp = ls->head;
    while (temp != nullptr) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

Student* searchByName(List* ls, const char* name) {
    Student* temp = ls->head;
    while (temp != nullptr) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

Student* searchByGPA(List* ls, float gpa) {
    Student* temp = ls->head;
    while (temp != nullptr) {
        if (fabs(temp->gpa - gpa) < 0.0001) {
            return temp;  // Return first match
        }
        temp = temp->next;
    }
    return nullptr;
}

