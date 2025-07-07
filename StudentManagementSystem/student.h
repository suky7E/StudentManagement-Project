#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

struct Student {
    string id;
    string name;
    string major;
    int year;
    float gpa;
};

void loadStudents();
void saveStudents();
void displayStudents();
void addStudent();
void updateStudent();
void deleteStudent();
void viewStats();

extern vector<Student> studentList;

#endif
