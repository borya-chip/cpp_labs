#include <cstring>
#include <iostream>

using namespace std;

int myStrlen(const char *str) {
    if (str == nullptr) {
        return 0;
    }

    int length = 0;

    for (int index = 0; str[length] != '\0'; index++) {
        length++;
    }

    return length;
}

char *resizeString(char *&str, int length) {
    char *new_str = new char[length];

    for (int index = 0; index < length; index++) {
        new_str[index] = '\0';
    }

    for (int index = 0; str[index] != '\0'; index++) {
        new_str[index] = str[index];
    }

    delete[] str;
    str = nullptr;

    return new_str;
}

char *getString(const char *msg) {
    cout << msg;

    int capacity = 1;
    char *str = new char[capacity];
    int check = 0;
    int length = 0;

    while (true) {
        check = cin.get();

        if ((char)check == '\n') {
            break;
        }

        if (length + 1 == capacity) {
            capacity *= 2;
            str = resizeString(str, capacity);
        }

        str[length] = char(check);
        length++;

        if (str[0] == '\0') {
            cout << "Error, string can not be empty,please try again!" << endl;
            length = 0;
            capacity = 1;
        }

        str[length] = '\0';
    }
    return str;
}

class String {

    char *stringData;
    int length;
    int capacity;

  public:
    String() : stringData(nullptr), length(0), capacity(0) {
    }

    bool isEmpty() {
        return (stringData == nullptr && capacity == 0 && length == 0);
    }

    void inputString() {
        if (stringData != nullptr) {
            delete[] stringData;
            stringData = nullptr;
        }

        stringData = getString("Enter string:");
        length = myStrlen(stringData);
        capacity = length + 1;
    }

    void PrintString(const char *msg) {
        cout << msg;
        cout << stringData;
    }

    String intersection(const String &other) {
        if (stringData == 0 || other.stringData == 0) {
            return String();
        }

        char *buffer = new char[length + 1];
        int resultIndex = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < other.length; j++) {
                if (stringData[length] == other.stringData[other.length]) {
                    buffer[resultIndex] = stringData[length];
                    break;
                }
            }
        }
        buffer[resultIndex] = '\0';
        String(buffer);
        delete [] buffer;
    }

    ~String() {
        delete[] stringData;
        stringData = nullptr;
        length = 0;
        capacity = 0;
    }
};

int main() {
    String myString;
    myString.inputString();
    myString.PrintString("\nEntered string: ");
    return 0;
}