#include "program.h"
#include "menus.h"
#include "string.h"
#include "utils.h"
#include <iostream>

using namespace std;

void Program::inputString() {
    if (str.isEmpty()) {
        input(str, "\nPlease enter the string: ");
        cout << "String successfully entered using String method(input)!" << endl;
        return;
    }

    cout << "The string has already been entered!" << endl;
}

void Program::showString() const {
    if (str.isEmpty()) {
        cout << "\nError, string has not been entered. Please use the first option and try again!" << endl;
        return;
    }

    print(str, "\nString: ");

    cout << "\nThe string was successfully displayed on the screen using the String method(show)!" << endl;
}

void Program::encode() {
    if (str.isEmpty()) {
        cout << "\nError, string has not been entered. Please use the first option and try again!" << endl;
        return;
    }
    String codedStr = ++str;
    if (codedStr.isEmpty()) {
        cout << "Empty string" << endl;
    } else {
        print(codedStr, "Encoding result: ");
        cout << "\nStrings were successfully encoded!" << endl;
    }
}

void Program::decode() {
    if (str.isEmpty()) {
        cout << "\nError, string has not been entered. Please use the first option and try again!" << endl;
        return;
    }
    String decodeStr = --str;
    if (decodeStr.isEmpty()) {
        cout << "Empty string" << endl;
    } else {
        print(decodeStr, "Decoding result: ");
        cout << "\nStrings were successfully coded!" << endl;
    }
}

void Program::run() {
    int opt = 0;

    showTaskMenu();

    while (true) {
        cout << "\nPlease select a task menu option: ";

        opt = getDigit();

        switch (opt) {
        case 1:
            inputString();
            break;
        case 2:
            showString();
            break;
        case 3:
            encode();
            break;
        case 4:
            decode();
            break;
        case 5:
            cout << "\nYou have successfully exited the program." << endl;
            return;
        default:
            cout << "\nError, you picked is an incorrect menu option. Please try again." << endl;
        }
    }
}