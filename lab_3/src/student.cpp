#include "student.h"
using namespace std;

   Student::Student(const string &name) : name(name) {
    }

   void Student::inputStudent() {
        cout << "Enter name: ";
        getline(cin, name);
    }

    void Student::display() const {
        cout << "Student: " << name;
    }
