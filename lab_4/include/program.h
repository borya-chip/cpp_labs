#pragma once

#include "student.h"

class Program {
  private:
    Student **students;
    int capacity = 10;
    int count = 0;
    Student *createStudent();
    void addStudent();
    void Program::displayStudents() const;
    template<typename T>
    void displayStudentType(const string& title)const;

  public:
    Program();
    Program& operator=(const Program&) = delete;
    Program(const Program&) = delete;
    ~Program();
    void run();
};