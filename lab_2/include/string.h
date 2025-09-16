#pragma once

class String {
    char *stringData;
    int length;
    int capacity;

  public:
    String();
    explicit String(const char *str);
    String(const String &other);
    String &operator=(const String &other);
    void input(const char *msg);
    void print(const char *msg) const;
    String intersection(const String &other) const;
    bool isEmpty() const;
    friend void input(String &string, const char *msg);
    friend void print(const String &string, const char *msg);
    ~String();
};