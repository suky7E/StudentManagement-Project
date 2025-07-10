#ifndef TEST_H
#define TEST_H

#include <iostream>

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

List* createList();

void addStudent(List* ls, int id, const char* name, float gpa);
void displayStudent(List* ls);
bool updateStudent(List* ls, int id, const char* newName, float newGPA);
bool deleteStudent(List* ls, int id);

Student* searchByID(List* ls, int id);
Student* searchByName(List* ls, const char* name);
Student* searchByGPA(List* ls, float gpa);

void saveStudents(List* ls);
void loadStudents(List* ls);

#endif

