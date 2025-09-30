#include "menus.h"
#include<iostream>

using namespace std;

void showTaskMenu() {
    cout << "\n=== STUDENT MANAGEMENT SYSTEM ===" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose option: ";
}

void showStudentMenu() {
    cout << "\nChoose student type:" << endl;
    cout << "1 - School student" << endl;
    cout << "2 - University student" << endl;
    cout << "0 - Back to menu" << endl;
    cout << "Your choice: ";
}