#pragma once

#include<iostream>
#include<string>

class Student {
    std::string name;

  public:
    explicit Student(const std::string &name);
    virtual void inputStudent();
    virtual void display() const = 0;
    std::string getName() const;
    virtual ~Student() = default;
};

