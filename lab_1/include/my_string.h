#pragma once

class String {
    char *stringData = nullptr;
    int length = 0;
    int capacity = 0;

  public:
    String() = default;
    explicit String(const char *str);
    String(const String &other);
    String &operator=(const String &other);
    void input(const char *msg);
    void print(const char *msg) const;
    String intersection(const String &other) const;
    bool isEmpty() const;
    ~String();
};