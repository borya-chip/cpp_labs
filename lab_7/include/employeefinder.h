#pragma once

#include "employee.h"

class EmployeeFinder {
 private:
	 std::string* names = nullptr;
	 int count = 0;

  void findEmployeeByHoursWorked(int targetHours);

 public:
	 EmployeeFinder() = default;
	 EmployeeFinder(const EmployeeFinder& other) = delete;
	 EmployeeFinder& operator=(const EmployeeFinder& other) = delete;
  void seeFullNamesOfEmployeeByHoursWorked(int targetHours);

  ~EmployeeFinder();
};
