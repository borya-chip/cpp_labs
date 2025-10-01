#pragma once

#include "student.h"

class Program {
  private:
    static constexpr int DEFAULT_CAPACITY = 10;
    int capacity = DEFAULT_CAPACITY;
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