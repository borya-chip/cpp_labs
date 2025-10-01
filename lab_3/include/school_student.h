#pragma once

#include<iostream>
#include<string>
#include "student.h"

class SchoolStudent : public Student {
    std::string school;
    int grade;

  public:
    SchoolStudent(const std::string &name, const std::string &school, int grade);
    SchoolStudent();
    void display() const override;
    void inputStudent() override;
};