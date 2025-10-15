#include "student.h"

using namespace std;

Student::Student(const string &name) : name(name) {
}

string Student::getName() const {
   return name;
}

void Student::inputStudent() {
    cout << "Enter name: ";
    getline(cin, name);
}