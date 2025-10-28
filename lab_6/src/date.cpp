#include "date.h"
#include <sstream>
#include <iomanip>
#include <cctype>

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
    throw DateException(std::string("Invalid format. Should be ") +
                        std::to_string(formatSizeDate) +
                        " symbols - YY/MM/DD");
  }
  if (date[firstSeparatorPos] != '/' || date[secondSeparatorPos] != '/') {
    throw DateException("Invalid format.Should be - YY/MM/DD");
  }

  if (!(isdigit(date[firstYearPos]) && isdigit(date[secondYearPos]))) {
    throw DateException("YY - should be digits");
  }

  if (!(isdigit(date[firstMonthPos]) && isdigit(date[secondMonthPos]))) {
    throw DateException("MM - should be digits");
  }

  if (!(isdigit(date[firstDayPos]) && isdigit(date[secondDayPos]))) {
    throw DateException("DD - should be digits");
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
    throw DateException(std::string("The number of months cannot exceed ") +
                        std::to_string(maxNumberOfMonth) +
                        " or be less than " + std::to_string(minNumberOfMonth));
  }

  int maxTrueDayInMonth = getMaxTrueDay(month, year);

  if (day < minNumberOfDay || day > maxTrueDayInMonth) {
    throw DateException(
        std::string("The day number for this month must be between ") +
        std::to_string(minNumberOfDay) + " and " +
        std::to_string(maxTrueDayInMonth));
  }
}
