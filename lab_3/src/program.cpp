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
    std::cout << "Student added successfully!" << std::endl;
}




void Program::displayStudents() const {
    if (count == 0) {
        cout << "No students to display." << endl;
        return;
    }

    cout << "\n=== SCHOOL STUDENTS ===" << endl;
    int schoolCount = 0;
    for (int i = 0; i < count; i++) {
        const auto *schoolStudent = dynamic_cast<SchoolStudent *>(students[i]);
        if (schoolStudent != nullptr) {
            schoolCount++;
            cout << schoolCount << ". ";
            schoolStudent->display();
        }
    }
    if (schoolCount == 0) {
        cout << "No school students found." << endl;
    }

    cout << "\n=== UNIVERSITY STUDENTS ===" << endl;
    int universityCount = 0;
    for (int i = 0; i < count; i++) {
        const auto *universityStudent = dynamic_cast<UniversityStudent *>(students[i]);
        if (universityStudent != nullptr) {
            universityCount++;
            cout << universityCount << ". ";
            universityStudent->display();
        }
    }
    if (universityCount == 0) {
        cout << "No university students found." << endl;
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