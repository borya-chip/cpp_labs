#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Employee {
 private:
  std::string fullName;
  int serviceNumber;
  int hoursWorkedPerMonth;
  int hourlyRate;

 public:
  Employee();
  Employee(const std::string& newFullName, int newServiceNumber,
           int newHoursWorkedPerMonth, int newHourlyRate);

  std::string getFullName() const;
  int getServiceNumber() const;
  int getHoursWorkedPerMonth() const;
  int getHourlyRate() const;

  void setFullName(const std::string_view newFullName);
  void setServiceNumber(int newServiceNumber);
  void setHoursWorkedPerMonth(int newHoursWorkedPerMonth);
  void setHourlyRate(int newHourlyRate);

  friend std::ostream& operator<<(std::ostream& os,
                                  const Employee& myEmployee) {
    os << myEmployee.getFullName() << '\n';
    os << myEmployee.getServiceNumber() << " "
       << myEmployee.getHoursWorkedPerMonth() << " "
       << myEmployee.getHourlyRate() << "\n";
    return os;
  }

  friend std::istream& operator>>(std::istream& is, Employee& myEmployee) {
    std::string name;
    int hoursWorked;
    int number;
    int rate;
    std::getline(is, name);
    myEmployee.setFullName(name);
    is >> number >> hoursWorked >> rate;
    is.ignore();
    myEmployee.setServiceNumber(number);
    myEmployee.setHoursWorkedPerMonth(hoursWorked);
    myEmployee.setHourlyRate(rate);
    return is;
  }
};
