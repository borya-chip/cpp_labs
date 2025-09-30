#pragma once

#include<iostream>
#include<string>

using namespace std;

class Student {
  protected:
    string name;

  public:
    Student(const string &name);
    virtual void inputStudent();
    virtual void display() const;
};

