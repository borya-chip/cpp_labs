#include <iostream>

using namespace std;

int myStrlen(const char *str) {
    if (!str) {
        return 0;
    }

    int length = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }

    return length;
}

char *resizeString(char *&str, const int len) {
    auto *new_str = new char[len];

    for (int ind = 0; ind < len; ind++) {
        new_str[ind] = '\0';
    }

    for (int ind = 0; str[ind] != '\0'; ind++) {
        new_str[ind] = str[ind];
    }

    delete[] str;
    str = nullptr;

    return new_str;
}

char *getString(const char *msg) {
    cout << msg;

    int cap = 1;
    auto *str = new char[cap];
    int check = 0;
    int len = 0;
    str[len] = '\0';

    while (true) {
        check = cin.get();
        if ((char)check == '\n') {
            break;
        }
        if (len + 1 == cap) {
            cap *= 2;
            str = resizeString(str, cap);
        }

        str[len] = char(check);
        len++;

        if (str[0] == '\0') {
            cout << "\nError, the string cannot be empty.Please try again: ";
            len = 0;
            cap = 1;
        }
    }

    str[len] = '\0';
    return str;
}

class String {

    char *stringData;
    int length;
    int capacity;

  public:
    String() : stringData(nullptr), length(0), capacity(0) {
    }

    String(const String &other) : stringData(new char[other.capacity]), length(other.length), capacity(length + 1) {

        for (int i = 0; i < length; i++) {
            stringData[i] = other.stringData[i];
        }
        stringData[length] = '\0';
    }

    String &operator=(const String &other) {
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

    String &operator++() {

        for (int i = 0; i < length; i++) {
            stringData[i]++;
        }

        return *this;
    }

    String &operator--() {

        for (int i = 0; i < length; i++) {
            stringData[i]--;
        }

        return *this;
    }
    friend void input(String &string, const char *msg);
    friend void print(const String &string, const char *msg);

    ~String() {
        delete[] stringData;
    }
};

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

int main() {
    String fStr;
    input(fStr, "\nEnter string:");
    print(fStr, "\nSource string: ");
    ++fStr;
    print(fStr, "\nCoded string: ");
    --fStr;
    print(fStr, "\nDecoded string: ");
    return 0;
}