#include <iostream>
#include <cstring> 
using namespace std;

struct Student{
	int id;
	char name[50];
	float gpa;
	Student* next;
};

struct List{ 
	Student* head;
	int count;
};

List* createList(){
	List* ls = new List;
	ls->head = nullptr;
	ls->count =0;
	return ls;
}

void addStudent(List* ls, int id, const char* namr, float gpa){
	Student* s = new Student;
	s->id = id;
	strcpy(s->name, name); // copy text from name to s->name
	s->gpa =gpa;
	s->next = ls->head;
	ls->head =s;
	ls->count++;
	cout << "Student added";
}

void displayStudent(List* ls){
	if (ls->head==nullptr) {
        cout << "No student records";
        return;
    }
    Student* current = ls->head;
    while (current) {
        cout << "ID: " << current->id << ", Name: " << current->name << ", GPA: " << current->gpa << endl;
        current = current->next;
    }
}

bool updateStudent(List* ls, int id, const char* newName, float newGPA) {
    Student* s = searchByID(ls, id);
    if (!s) return false;
    strcpy(s->name, newName);
    s->gpa = newGPA;
    return true;
}

bool updateStudent(List* ls, int id, char newName[], float newGPA) {
    Student* s = searchByID(ls, id);
    if (s == nullptr) return false;
    
    strcpy(s->name, newName);
    s->gpa = newGPA;

    return true;
}
//detele by id only
bool deleteStudent(List* ls, int id) {
    Student* current =ls->head;
    Student* prev = nullptr;

    while (current) {
        if (current->id==id) {
            if (prev ==nullptr)
                ls->head =current->next;
            else
                prev->next= current->next;

            delete current;
            ls->count--;
            return true;
        }
        prev =current;
        current =current->next;
    }
    return false;
}


void viewStats(List* ls) {
    if (ls->head == nullptr) {
        cout << "No student data"<< endl;
        return;
    }

    Student* current = ls->head;
    cout << "List of Students:";
    while (current) {
        cout << "ID: " << current->id 
             << ", Name: " << current->name 
             << ", GPA: " << current->gpa << endl;
        current = current->next;
    }
}

// Additional function 

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
        if (temp->gpa == gpa) {
            return temp; 
        }
        temp = temp->next;
    }
    return nullptr; 
}





