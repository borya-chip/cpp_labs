#pragma once

class String {
    char *stringData;
    int length;
    int capacity;

  public:
    String();
    String(const String &other);
    String &operator=(const String &other);
    String &operator--();
    bool isEmpty() const;
    String &operator++();
    friend void input(String &string, const char *msg);
    friend void print(const String &string, const char *msg);
    ~String();
};