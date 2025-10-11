#include "student.h"

using namespace std;

Student::Student(const string &name) : name(name) {
}

void Student::inputStudent() {
    cout << "Enter name: ";
    getline(cin, name);
}

string Student::getName() const {
   return name;
}