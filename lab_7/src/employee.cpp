#include "employee.h"

Employee::Employee()
    : fullName("Undefined"),
      serviceNumber(0),
      hoursWorkedPerMonth(0),
      hourlyRate(0) {}

Employee::Employee(const std::string& newFullName, int newServiceNumber,
                   int newHoursWorkedPerMonth, int newHourlyRate)
    : fullName(newFullName),
      serviceNumber(newServiceNumber),
      hoursWorkedPerMonth(newHoursWorkedPerMonth),
      hourlyRate(newHourlyRate) {}

std::string Employee::getFullName() const { return fullName; }

int Employee::getServiceNumber() const { return serviceNumber; }

int Employee::getHoursWorkedPerMonth() const { return hoursWorkedPerMonth; }

int Employee::getHourlyRate() const { return hourlyRate; }

void Employee::setFullName(const std::string_view newFullName) {
  fullName = newFullName;
}

void Employee::setServiceNumber(int newServiceNumber) {
  serviceNumber = newServiceNumber;
}

void Employee::setHoursWorkedPerMonth(int newHoursWorkedPerMonth) {
  hoursWorkedPerMonth = newHoursWorkedPerMonth;
}

void Employee::setHourlyRate(int newHourlyRate) { hourlyRate = newHourlyRate; }
