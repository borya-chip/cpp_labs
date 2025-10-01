#pragma once

#include "student.h"

class Program {
  private:
    Student **students = new Student *[10];
    int capacity = 10;
    int count = 0;
    

    Student *createStudent();
    void addStudent();
    void displayStudents()const;

  public:
    Program() = default;
    Program& operator=(const Program&) = delete;
    Program(const Program&) = delete;
    ~Program();
    void run();
};