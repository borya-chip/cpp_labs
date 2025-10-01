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
    Program(const Student&) = delete;
    Program& operator=(const Student&) = delete;
    ~Program();
    void run();
};