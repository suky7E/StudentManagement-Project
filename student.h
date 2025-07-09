#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int id;
    char name[50];
    char major[30];
    int year;
    float gpa;
    Student* next;
};

struct List {
    Student* head;
    int count;
};

List* createList();
void addStudent(List*, int, const char*, const char*, int, float);
void displayStudent(List*);
bool updateStudent(List*, int, const char*, const char*, int, float);
bool deleteStudent(List*, int);
Student* searchByID(List*, int);
Student* searchByName(List*, const char*);
Student* searchByGPA(List*, float);
void viewStats(List*);

#endif

