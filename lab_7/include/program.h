#pragma once 
#include "employee.h"
#include "employeefinder.h"
#include "menu.h"
#include "utils.h"
#include<iostream>

class Program {
    Employee myEmployee;
    EmployeeFinder myEmployeeFinder;
   void addEmployeeToFile();
   void readDataFromFile() ;
   void findNamesBasedOnTheNumberOfHoursWorked();
   void deleteDataFromFile();
    public:
    Program() = default;
    ~Program() = default;
    void run();
};