#pragma once

#include<iostream>
#include<string>

class Student {
    std::string name;

  public:
    explicit Student(const std::string &name);
    virtual void inputStudent();
    virtual void display() const;
    std::string getName() const;
    Student(const Student&) = delete;
    virtual ~Student() = default;
};

