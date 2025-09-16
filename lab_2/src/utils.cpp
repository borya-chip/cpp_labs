#include "utils.h"
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