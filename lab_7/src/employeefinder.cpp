#include "employeefinder.h"

void EmployeeFinder::findEmployeeByHoursWorked(int targetHours) {
  delete[] names;
  names = nullptr;
  count = 0;

  std::ifstream file("data.txt");

  if (!file.is_open()) {
    std::cout << "Error in opening file" << std::endl;
    return;
  }

  Employee myEmployee;

  while (file >> myEmployee) {
    if (myEmployee.getHoursWorkedPerMonth() == targetHours) {
      auto temp = new std::string[count + 1];
      for (size_t i = 0; i < count; i++) {
        temp[i] = names[i];
      }
      temp[count++] = myEmployee.getFullName();
      delete[] names;
      names = temp;
    }
  }

  if (file.bad()) {
    std::cout << "Error in reading file" << std::endl;
    return;
  }
}

void EmployeeFinder::seeFullNamesOfEmployeeByHoursWorked(int targetHours) {
  findEmployeeByHoursWorked(targetHours);

  if (count == 0) {
    std::cout << "No need employees" << std::endl;
    return;
  }

  for (int i = 0; i < count; i++) {
    std::cout << "#" << (i + 1) << ":" << names[i] << std::endl;
  }
}

EmployeeFinder::~EmployeeFinder() { delete[] names; }
