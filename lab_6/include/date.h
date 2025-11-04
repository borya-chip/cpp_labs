#pragma once
#include "myexception.h"
#include "date_format_exception.h"
#include "date_digit_exception.h"
#include "date_range_exception.h"
#include <iostream>
#include <string>

class Date {
private:
  std::string date;

  static constexpr int formatSizeDate = 8;
  static constexpr int maxNumberOfMonth = 12;
  static constexpr int minNumberOfMonth = 1;
  static constexpr int maxNumberOfDay = 31;
  static constexpr int minNumberOfDay = 1;

  static constexpr int firstSeparatorPos = 2;
  static constexpr int secondSeparatorPos = 5;
  static constexpr int firstYearPos = 0;
  static constexpr int secondYearPos = 1;
  static constexpr int firstMonthPos = 3;
  static constexpr int secondMonthPos = 4;
  static constexpr int firstDayPos = 6;
  static constexpr int secondDayPos = 7;

  static constexpr int february = 2;
  static constexpr int leapDaysFebruary = 29;
  static constexpr int notLeapDaysFebruary = 28;
  static constexpr int leapDivisor4 = 4;
  static constexpr int leapDivisor100 = 100;
  static constexpr int leapDivisor400 = 400;

  static constexpr int maxNumberOfDayInSpecialMonth = 30;
  static constexpr int april = 4;
  static constexpr int june = 6;
  static constexpr int september = 9;
  static constexpr int november = 11;

  void isValidDate() const;
  void isTrueFormatDate() const;
  void isTrueDate() const;
  int getMaxTrueDay(int month, int year) const;
  bool isLeapYear(int year) const;

public:
  Date() = default;
  explicit Date(const std::string& newDate);

  friend std::istream& operator>>(std::istream& inputStream, Date& myDate) {
    std::string buffer;
    inputStream >> buffer;

    std::string oldDate = myDate.date;

    myDate.date = buffer;

    try {
      myDate.isValidDate();
    } catch (...) {
      myDate.date = oldDate;
      throw;
    }

    return inputStream;
  }

  friend std::ostream& operator<<(std::ostream& outputStream,
                                  const Date& myDate) {
    if (myDate.date.empty()) {
      outputStream << "The date wasn't set";
      return outputStream;
    }

    outputStream << myDate.date;
    return outputStream;
  }
};