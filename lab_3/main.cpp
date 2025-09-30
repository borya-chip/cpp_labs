#include <iostream>
#include <string>

using namespace std;

int getDigit() {
    int check = 0;

    while (true) {
        check = cin.get();

        if (check != '\n' && check != EOF) {
            if (isdigit(check) == 1 && cin.get() == '\n') {
                return check - '0';
            }

            while (cin.get() != '\n' && !cin.eof())
                ;
        }
    }
}

class Student {
  protected:
    string name;

  public:
    Student(const string &name) : name(name) {
    }

    virtual void inputStudent() {
        cout << "Enter name: ";
        getline(cin, name);
    }

    virtual void display() const {
        cout << "Student: " << name;
    }
};

class SchoolStudent : public Student {
    string school;
    int grade;

  public:
    SchoolStudent(const string &name, const string &school, int grade) : Student(name), school(school), grade(grade) {
    }
    SchoolStudent() : Student(""), school(""), grade(0) {
    }

    void display() const override {
        cout << name << ", " << school << ", grade " << grade << endl;
    }

    void inputStudent() override {
        Student::inputStudent();

        cout << "Enter school: ";
        getline(cin, school);

        cout << "Enter grade: ";
        cin >> grade;
    }
};

class UniversityStudent : public Student {
    string university;
    int course;

  public:
    UniversityStudent(const string &name, const string &university, int course)
        : Student(name), university(university), course(course) {
    }
    UniversityStudent() : Student(""), university(""), course(0) {
    }

    void display() const override {
        cout << name << ", " << university << ", course " << course << endl;
    }

    void inputStudent() override {
        Student::inputStudent();

        cout << "Enter university: ";
        getline(cin, university);

        cout << "Enter course: ";
        cin >> course;
    }
};

void showStudentMenu() {
    cout << "\nChoose student type:" << endl;
    cout << "1 - School student" << endl;
    cout << "2 - University student" << endl;
    cout << "0 - Back to menu" << endl;
    cout << "Your choice: ";
}
/*dssfsfsfdsfdsfsdfsdfdsfsd*/

class Program {
  private:
    Student **students;
    int capacity;
    int count;

    Student *createStudent() {
        showStudentMenu();
        int choice = 0;
        choice = getDigit();

        if (choice == 0)
            return nullptr;

        Student *student = nullptr;

        if (choice == 1) {
            SchoolStudent *schoolStudent = new SchoolStudent();
            schoolStudent->inputStudent();
            student = schoolStudent;
        } else if (choice == 2) {
            UniversityStudent *universityStudent = new UniversityStudent();
            universityStudent->inputStudent();
            student = universityStudent;
        } else {
            cout << "Invalid choice!" << endl;
        }

        return student;
    }

    void addStudent() {
        if (count >= capacity) {
            capacity *= 2;
            Student **newStudents = new Student *[capacity];

            for (int i = 0; i < count; i++) {
                newStudents[i] = students[i];
            }

            delete[] students;
            students = newStudents;
        }

        Student *newStudent = createStudent();
        if (newStudent != nullptr) {
            students[count] = newStudent;
            count++;
            cout << "Student added successfully!" << endl;
        }
    }

    void displayStudents() {
        if (count == 0) {
            cout << "No students to display." << endl;
            return;
        }

        cout << "\n=== SCHOOL STUDENTS ===" << endl;
        int schoolCount = 0;
        for (int i = 0; i < count; i++) {
            SchoolStudent *schoolStudent = dynamic_cast<SchoolStudent *>(students[i]);
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
            UniversityStudent *universityStudent = dynamic_cast<UniversityStudent *>(students[i]);
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

    void showTaskMenu() {
        cout << "\n=== STUDENT MANAGEMENT SYSTEM ===" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose option: ";
    }

  public:
    Program() : capacity(10), count(0) {
        students = new Student *[capacity];
    }

    ~Program() {
        for (int i = 0; i < count; i++) {
            delete students[i];
        }
        delete[] students;
    }

    void run() {
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
};

int main() {
    Program program;
    program.run();
    return 0;
}