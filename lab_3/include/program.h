#pragma once

#include "student.h"

class Program {
  private:
    int capacity = 10;
    int count = 0;
    Student **students = new Student *[capacity];

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