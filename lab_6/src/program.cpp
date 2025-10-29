#include "program.h"
#include "menu.h"
#include "utils.h"
#include "myexception.h"
#include <iostream>
#include<limits>

using namespace std;

void Program::testConstructors() const {
    try {
        cout << "Default constructor:";
        Date defaultDate;
        cout << defaultDate << endl;
    } catch (const DateException &ex) {
        cout << "Error:" << ex.what() << endl;
    }

    try {
        cout << "Valid date (23/03/15):";
        Date firstDate("23/03/15");
        cout << firstDate << endl;
    } catch (const DateException &ex) {
        cout << "Error:" << ex.what() << endl;
    }

    try {
        cout << "Invalid month (13/13/23):";
        Date secondDate("13/13/23");
        cout << secondDate << endl;
    } catch (const DateException &ex) {
        cout << ex.what() << endl;
    }

    try {
        cout << "Invalid day (23/02/30):";
        Date thirdDate("23/02/30");
        cout << thirdDate << endl;
    } catch (const DateException &ex) {
        cout << ex.what() << endl;
    }

    try {
        cout << "Invalid format (230315):";
        Date fourthDate("230315");
        cout << fourthDate << endl;
    } catch (const DateException &ex) {
        cout << ex.what() << endl;
    }

    try {
        cout << "Leap year (24/02/29):";
        Date fifthDate("24/02/29");
        cout << fifthDate << endl;
    } catch (const DateException &ex) {
        cout << ex.what() << endl;
    }
}

void Program::testInputDate() {
    try {
        cout << "Enter the date (YY/MM/DD):";
        cin >> date;
        cout << "The value " << date << " of date was set succesfully" << endl;
    } catch (const DateException &ex) {
        cout << "Input error:" << ex.what() << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Program::showCurrentDate() const {
    cout << date << endl;
}

void Program::run() {
    while (true) {
        showMenu();
        int choice = 0;
        choice = getDigit();
        switch (choice) {
        case 1:
            system("cls");
            testConstructors();
            break;
        case 2:
            system("cls");
            testInputDate();
            break;
        case 3:
            system("cls");
            showCurrentDate();
            break;
        case 0:
            cout << "\nYou have successfully exited the program." << endl;
            return;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}