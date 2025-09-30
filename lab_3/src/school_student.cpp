#include "school_student.h"

   SchoolStudent::SchoolStudent(const string &name, const string &school, int grade) : Student(name), school(school), grade(grade) {
    }
   SchoolStudent::SchoolStudent() : Student(""), school(""), grade(0) {
    }

    void SchoolStudent::display() const{
        cout << name << ", " << school << ", grade " << grade << endl;
    }

    void SchoolStudent::inputStudent(){
        Student::inputStudent();

        cout << "Enter school: ";
        getline(cin, school);

        cout << "Enter grade: ";
        cin >> grade;
    }