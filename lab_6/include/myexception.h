#pragma once
#include <exception>
#include <iostream>
#include <string>

class DateException : public std::exception {
 private:
  std::string message;

 public:
  explicit DateException(const std::string& newMessage);
  const char* what() const noexcept override;
};
