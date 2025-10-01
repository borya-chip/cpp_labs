#pragma once

#include<iostream>
#include<string>

class Student {
  protected:
    std::string name;

  public:
    explicit Student(const std::string &name);
    virtual void inputStudent();
    virtual void display() const;
    virtual ~Student() = default;
};

