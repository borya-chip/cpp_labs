#include "my_string.h"
#include "utils.h"
#include <iostream>

using namespace std;

String::String() : stringData(nullptr), length(0), capacity(0) {
}

String::String(const char *str) :length(myStrlen(str)), capacity(length + 1) {
    if (str == nullptr) {
        length = 0;
        capacity = 1;
        return;
    }

   stringData = new char[capacity];

    for (int i = 0; i < length && str[i] != '\0'; i++) {
        stringData[i] = str[i];
    }

    stringData[length] = '\0';
}

String::String(const String &other)
    : stringData(new char[other.capacity]), length(other.length), capacity(other.capacity) {

    for (int i = 0; i < length; i++) {
        stringData[i] = other.stringData[i];
    }

    stringData[length] = '\0';
}

String &String::operator=(const String &other) {
    length = other.length;
    capacity = length + 1;

    if (stringData != nullptr) {
        delete[] stringData;
    }
    stringData = new char[other.capacity];

    for (int i = 0; i < other.length; i++) {
        stringData[i] = other.stringData[i];
    }

    return *this;
}

void String::input(const char *msg) {
    delete[] stringData;
    stringData = getString(msg);
    length = myStrlen(stringData);
    capacity = length + 1;
}

void String::print(const char *msg) const {
    cout << msg;
    if (stringData)
        cout << stringData;
    else
        cout << "Empty string";
}

String String::intersection(const String &other) const {
    if (!stringData || !other.stringData) {
        return String();
    }

    auto *buffer = new char[length + 1];
    int resultIndex = 0;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < other.length; j++) {
            if (stringData[i] == other.stringData[j] && resultIndex < length) {
                buffer[resultIndex++] = stringData[i];

                break;
            }
        }
    }

    buffer[resultIndex] = '\0';
    String result(buffer);
    delete[] buffer;

    return result;
}

bool String::isEmpty() const {
    return (stringData == nullptr || length == 0);
}

String::~String() {
    delete[] stringData;
}