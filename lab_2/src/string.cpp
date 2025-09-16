#include "string.h"
#include "utils.h"
#include <iostream>

using namespace std;

String::String() : stringData(nullptr), length(0), capacity(0) {
}

String::String(const String &other) : stringData(new char[capacity]),length(other.length), capacity(other.capacity) {

    
    for (int i = 0; i < length; i++) {
        stringData[i] = other.stringData[i];
    }
    
    stringData[length] = '\0';
}

String &String::operator=(const String &other) {
    if (stringData != nullptr) {
        delete[] stringData;
    }

    stringData = new char[other.capacity];
    length = other.length;
    capacity = length + 1;

    for (int i = 0; i < other.length; i++) {
        stringData[i] = other.stringData[i];
    }

    stringData[length] = '\0';

    return *this;
}

String &String::operator++() {

    for (int i = 0; i < length; i++) {
        stringData[i]++;
    }

    return *this;
}

String &String::operator--() {

    for (int i = 0; i < length; i++) {
        stringData[i]--;
    }

    return *this;
}

bool String::isEmpty() const {
    return (stringData == nullptr || length == 0);
}

String::~String() {
    delete[] stringData;
}

void input(String &string, const char *msg) {
    delete[] string.stringData;
    string.stringData = getString(msg);
    string.length = myStrlen(string.stringData);
    string.capacity = string.length + 1;
}

void print(const String &string, const char *msg) {
    cout << msg;
    if (string.stringData)
        cout << string.stringData;
    else
        cout << "Empty string";
}