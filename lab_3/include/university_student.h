#pragma once
#include<iostream>
#include<string>
#include "student.h"

class UniversityStudent : public Student {
    string university;
    int course;

  public:
    UniversityStudent(const string &name, const string &university, int course);
    UniversityStudent();
    void display() const override;
    void inputStudent() override;
};