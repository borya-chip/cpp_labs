#include "myexception.h"

DateException::DateException(const std::string& newMessage)
    : message(newMessage) {}

const char* DateException::what() const noexcept { return message.c_str(); }
