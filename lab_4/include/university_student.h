#pragma once
#include<iostream>
#include<string>
#include "student.h"

class UniversityStudent : public Student {
    std::string university;
    int course;

  public:
    UniversityStudent(const std::string &name, const std::string &university, int course);
    UniversityStudent();
    void display() const override;
    void inputStudent() override;
};