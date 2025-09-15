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

char *resizeString(char *&str, int newCapacity) {
    auto *new_str = new char[newCapacity];
    int i = 0;

    if (str) {
        while (str[i] != '\0' && i < newCapacity - 1) {
            new_str[i] = str[i];
            i++;
        }
        delete[] str;
    }

    new_str[i] = '\0';
    str = nullptr;

    return new_str;
}

char *getString(const char *msg) {
    cout << msg;

    int capacity = 1;
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