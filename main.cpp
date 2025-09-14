#include <cstring>
#include <iostream>

using namespace std;

int myStrlen(const char *str) {
    if (!str) return 0;

    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

char *resizeString(char *&str, int newCapacity) {
    char *new_str = new char[newCapacity];
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

    int capacity = 2; // начальная ёмкость
    char *str = new char[capacity];
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

class String {
    char *stringData;
    int length;
    int capacity;

  public:
    String() : stringData(nullptr), length(0), capacity(0) {
    }

    String(const char *str) : length(myStrlen(str)), capacity(length + 1) {
        stringData = new char[capacity];

        for (int i = 0; i < length; i++) {
            stringData[i] = str[i];
        }
        stringData[length] = '\0';

        cout << this <<"\nconst char constructor\n";
    }

    String(const String &other) : length(other.length), capacity(length + 1) {
        stringData = new char[other.capacity];

        for (int i = 0; i < other.length; i++) {
            stringData[i] = other.stringData[i];
        }

        stringData[length] = '\0';
        cout << this <<"\nConstructor copy";
    }

    bool isEmpty() const {
        return (stringData == nullptr || length == 0);
    }

    void inputString() {
        delete[] stringData;
        stringData = getString("Enter string: ");
        length = myStrlen(stringData);
        capacity = length + 1;
    }

    void PrintString(const char *msg = "") const {
        cout << msg;
        if (stringData)
            cout << stringData;
        else
            cout << "Empty string";
    }

    String intersection(const String &other) const {
        if (!stringData || !other.stringData) {
            return String();
        }

        char *buffer = new char[length + 1];
        int resultIndex = 0;

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < other.length; j++) {
                if (stringData[i] == other.stringData[j]) {
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

    ~String() {
        delete[] stringData;
    }
};

int main() {
    String myString1;
    String myString2;

    myString1.inputString();
    myString2.inputString();

    myString1.PrintString("\nEntered string 1: ");
    myString2.PrintString("\nEntered string 2: ");

    String result = myString1.intersection(myString2);
    result.PrintString("\nResult of intersection: ");

    return 0;
}
