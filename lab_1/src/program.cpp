#include "program.h"
#include "menus.h"
#include "my_string.h"
#include "utils.h"
#include <iostream>

using namespace std;

void Program::inputString() {
    if (str.isEmpty()) {
        str.input("\nPlease enter the string: ");
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

    str.print("\nString: ");

    cout << "\nThe string was successfully displayed on the screen using the String method(show)!" << endl;
}

void Program::intersectionStrings() {
    if (str.isEmpty()) {
        cout << "\nError, string has not been entered. Please use the first option and try again!" << endl;
        return;
    }
    String src;
    src.input("Please enter a string to intersect with the original string: ");
    String result = str.intersection(src);
    result.print("Intersection result: ");
    cout << "\nStrings were successfully intersected!" << endl;
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
            intersectionStrings();
            break;
        case 4:
            cout << "\nYou have successfully exited the program." << endl;
            return;
        default:
            cout << "\nError, you picked is an incorrect menu option. Please try again." << endl;
        }
    }
}