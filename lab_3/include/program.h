#pragma once

#include "student.h"

class Program {
  private:
    Student **students;
    int capacity = 10;
    int count = 0;

    Student *createStudent();
    void addStudent();
    void displayStudents()const;

  public:
    Program();
    Program(const Program&) = delete;
    Program& operator=(const Program&) = delete;
    ~Program();
    void run();
};