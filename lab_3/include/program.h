#pragma once

#include "student.h"

class Program {
  private:
    static constexpr int DEFAULT_CAPACITY = 10;
    int capacity = DEFAULT_CAPACITY;
    int count = 0;
    Student **students = new Student *[capacity]();

    Student *createStudent();
    void addStudent();
    void displayStudents()const;

  public:
    Program() = default;
    Program(const Program&) = delete;
    Program& operator=(const Program&) = delete;
    ~Program();
    void run();
};