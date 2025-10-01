#include "university_student.h"

using namespace std;

   UniversityStudent::UniversityStudent(const string &name, const string &university, int course)
        : Student(name), university(university), course(course) {
    }
   UniversityStudent::UniversityStudent() : Student(""), university(""), course(0) {
    }

    void UniversityStudent::display() const{
        cout << getName() << ", " << university << ", course " << course << endl;
    }

    void UniversityStudent::inputStudent(){
        Student::inputStudent();

        cout << "Enter university: ";
        getline(cin, university);

        cout << "Enter course: ";
        cin >> course;
    }