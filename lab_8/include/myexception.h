#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <iostream>

class MyException : public std::exception {
 private:
  std::string message;

 public:
  explicit MyException(const std::string& newMessage);
  const char* what() const noexcept override;
};

#endif
