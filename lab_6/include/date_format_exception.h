#pragma once
#include "myexception.h"
#include <string>
#include <format>

class DateFormatException : public DateException {
public:
    explicit DateFormatException(const std::string& message) 
        : DateException(message) {}
};

class DateLengthException : public DateFormatException {
public:
    explicit DateLengthException(int expectedLength)
        : DateFormatException(std::format("Invalid format. Should be {} symbols - YY/MM/DD", 
                                        expectedLength)) {}
};

class DateSeparatorException : public DateFormatException {
public:
    DateSeparatorException() 
        : DateFormatException("Invalid format. Should be - YY/MM/DD") {}
};