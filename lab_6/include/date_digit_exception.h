#pragma once
#include "myexception.h"
#include <string>

class DateDigitException : public DateException {
public:
    explicit DateDigitException(const std::string& message) 
        : DateException(message) {}
};

class YearDigitException : public DateDigitException {
public:
    YearDigitException() 
        : DateDigitException("YY - should be digits") {}
};

class MonthDigitException : public DateDigitException {
public:
    MonthDigitException() 
        : DateDigitException("MM - should be digits") {}
};

class DayDigitException : public DateDigitException {
public:
    DayDigitException() 
        : DateDigitException("DD - should be digits") {}
};