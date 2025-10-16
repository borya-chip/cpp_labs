#include "program.h"
#include "menus.h"
#include "school_student.h"
#include "student.h"
#include "university_student.h"
#include "utils.h"
#include <iostream>
#include <string>

using namespace std;

Student *Program::createStudent() {
    showStudentMenu();
    int choice = getDigit();

    if (choice == 0)
        return nullptr;

    Student *student = nullptr;

    if (choice == 1) {
        student = new SchoolStudent();
    } else if (choice == 2) {
        student = new UniversityStudent();
    } else {
        cout << "Invalid choice!" << endl;
        return nullptr;
    }

    student->inputStudent();
    return student;
}



void Program::addStudent() {
    Student *newStudent = createStudent();
    if (newStudent == nullptr) {
        return;
    }

    if (count >= capacity) {
        int requiredCapacity = count + 1;
        int newCapacity = capacity * 2;
        if (newCapacity < requiredCapacity) {
            newCapacity = requiredCapacity;
        }

        auto **newStudents = new Student *[newCapacity]();

        for (int i = 0; i < count; i++) {
            newStudents[i] = students[i];
        }

        delete[] students;
        students = newStudents;
        capacity = newCapacity;
    }

    students[count] = newStudent;
    count++;
    cout << "Student added successfully!" << endl;
}

void Program::displayStudents() const {
    if (count == 0) {
        cout << "No students to display." << endl;
        return;
    }

    displayStudentType<SchoolStudent>("SCHOOL STUDENTS");
    displayStudentType<UniversityStudent>("UNIVERSITY STUDENTS");
}

template<typename T>
void Program::displayStudentType(const string& title) const {
    cout << "\n=== " << title << " ===" << endl;
    int typeCount = 0;
    
    for (int i = 0; i < count; i++) {
        const auto* student = dynamic_cast<const T*>(students[i]);
        if (student != nullptr) {
            typeCount++;
            cout << typeCount << ". ";
            student->display();
        }
    }
    
    if (typeCount == 0) {
        cout << "No " << title << " found." << endl;
    }
}

Program::Program(){
   students = new Student *[capacity];   
}

Program::~Program() {
    for (int i = 0; i < count; i++) {
        delete students[i];
    }
    delete[] students;
}

void Program::run() {
    while (true) {
        showTaskMenu();

        int choice = 0;
        choice = getDigit();

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            system("cls");
            displayStudents();
            break;
        case 3:
            cout << "\nYou have successfully exited the program." << endl;
            return;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}