#include "utils.h"
#include <iostream>
using namespace std;

int myStrlen(const char *str) {
    if (!str)
        return 0;

    int length = 0;

    while (str[length] != '\0') {
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

    int capacity = 16;
    auto *str = new char[capacity];
    int length = 0;

    while (true) {
        int ch = cin.get();
        if (ch == '\n' || ch == EOF)
            break;

        if (length + 1 >= capacity) {
            capacity *= 2;
            str = resizeString(str, capacity);
        }

        str[length++] = char(ch);
        str[length] = '\0';
    }

    return str;
}

int getDigit() {
    int check = 0;

    while (true) {
        check = cin.get();

        if (check != '\n' && check != EOF) {
            if (isdigit(check) == 1 && cin.get() == '\n') {
                return check - '0';
            }

            while (cin.get() != '\n' && !cin.eof())
                ;
        }

        cout << "\nError, invalid input. Please try again: ";
    }
}