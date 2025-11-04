#include "date.h"
#include <sstream>
#include <iomanip>
#include <cctype>
#include <format>

Date::Date(const std::string& newDate) : date(newDate) { isValidDate(); }

void Date::isValidDate() const {
  if (date.empty()) {
    return;
  }
  isTrueFormatDate();
  isTrueDate();
}

void Date::isTrueFormatDate() const {
  if (date.length() != formatSizeDate) {
    throw DateLengthException(formatSizeDate);
  }
  if (date[firstSeparatorPos] != '/' || date[secondSeparatorPos] != '/') {
    throw DateSeparatorException();
  }
  if (!(isdigit(date[firstYearPos]) && isdigit(date[secondYearPos]))) {
    throw YearDigitException();
  }
  if (!(isdigit(date[firstMonthPos]) && isdigit(date[secondMonthPos]))) {
    throw MonthDigitException();
  }
  if (!(isdigit(date[firstDayPos]) && isdigit(date[secondDayPos]))) {
    throw DayDigitException();
  }
}

int Date::getMaxTrueDay(int month, int year) const {
  switch (month) {
    case february:
      return isLeapYear(year) ? leapDaysFebruary : notLeapDaysFebruary;
    case april:
    case june:
    case september:
    case november:
      return maxNumberOfDayInSpecialMonth;
    default:
      return maxNumberOfDay;
  }
}

bool Date::isLeapYear(int year) const {
  const int baseYear = 2000;
  int fullYear = baseYear + year;
  return (fullYear % leapDivisor4 == 0 && fullYear % leapDivisor100 != 0) ||
         (fullYear % leapDivisor400 == 0);
}

void Date::isTrueDate() const {
  static const int decimalBase = 10;
  int year =
      (date[firstYearPos] - '0') * decimalBase + (date[secondYearPos] - '0');
  int month =
      (date[firstMonthPos] - '0') * decimalBase + (date[secondMonthPos] - '0');
  int day =
      (date[firstDayPos] - '0') * decimalBase + (date[secondDayPos] - '0');
  
  if (month > maxNumberOfMonth || month < minNumberOfMonth) {
    throw MonthRangeException(maxNumberOfMonth, minNumberOfMonth);
  }
  
  int maxTrueDayInMonth = getMaxTrueDay(month, year);
  if (day < minNumberOfDay || day > maxTrueDayInMonth) {
    throw DayRangeException(minNumberOfDay, maxTrueDayInMonth);
  }
}