#pragma once

#include "student.h"

class Program {
  private:
    int capacity;
    int count;
    Student **students;

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