#pragma once

#include<iostream>
#include<string>

class Student {
  protected:
    string name;

  public:
    explicit Student(const string &name);
    virtual void inputStudent();
    virtual void display() const;
};

