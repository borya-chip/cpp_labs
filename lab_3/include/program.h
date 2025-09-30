#pragma once

#include "student.h"

class Program {
  private:
    Student **students;
    int capacity;
    int count;

    Student *createStudent();
    void addStudent();
    void displayStudents();

  public:
    Program();
    ~Program();
    void run();
};