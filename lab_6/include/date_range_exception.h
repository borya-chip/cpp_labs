#pragma once
#include "myexception.h"
#include <string>
#include <format>

class DateRangeException : public DateException {
public:
    explicit DateRangeException(const std::string& message) 
        : DateException(message) {}
};

class MonthRangeException : public DateRangeException {
public:
    MonthRangeException(int maxMonth, int minMonth)
        : DateRangeException(std::format("The number of months cannot exceed {} or be less than {}", 
                                       maxMonth, minMonth)) {}
};

class DayRangeException : public DateRangeException {
public:
    DayRangeException(int minDay, int maxDay)
        : DateRangeException(std::format("The day number for this month must be between {} and {}", 
                                       minDay, maxDay)) {}
};