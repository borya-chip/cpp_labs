#include "myexception.h"

MyException::MyException(const std::string& newMessage) : message(newMessage) {}

const char* MyException::what() const noexcept { return message.c_str(); }
