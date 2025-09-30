#pragma once

#include<iostream>
#include<string>
#include "student.h"

using namespace std;

class SchoolStudent : public Student {
    string school;
    int grade;

  public:
    SchoolStudent(const string &name, const string &school, int grade);
    SchoolStudent();
    void display() const override;
    void inputStudent() override;
};