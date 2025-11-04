#include "program.h"
#include "menu.h"
#include "utils.h"
#include "myexception.h"
#include "date_format_exception.h"
#include "date_digit_exception.h"
#include "date_range_exception.h"
#include <iostream>
#include <limits>

using namespace std;

void Program::testConstructors() const {
    try {
        cout << "Default constructor: ";
        Date defaultDate;
        cout << defaultDate << endl;
    } catch (const DateException &ex) {
        cout << "Error: " << ex.what() << endl;
    }

    try {
        cout << "Valid date (23/03/15): ";
        Date firstDate("23/03/15");
        cout << firstDate << endl;
    } catch (const DateLengthException& ex) {
        cout << "Length error: " << ex.what() << endl;
    } catch (const DateSeparatorException& ex) {
        cout << "Separator error: " << ex.what() << endl;
    } catch (const YearDigitException& ex) {
        cout << "Year digit error: " << ex.what() << endl;
    } catch (const MonthRangeException& ex) {
        cout << "Month range error: " << ex.what() << endl;
    } catch (const DateException& ex) {
        cout << "General error: " << ex.what() << endl;
    }

    try {
        cout << "Invalid month (13/13/23): ";
        Date secondDate("13/13/23");
        cout << secondDate << endl;
    } catch (const MonthRangeException& ex) {
        cout << "Month error: " << ex.what() << endl;
    } catch (const DateException& ex) {
        cout << "Error: " << ex.what() << endl;
    }

    try {
        cout << "Invalid day (23/02/30): ";
        Date thirdDate("23/02/30");
        cout << thirdDate << endl;
    } catch (const DayRangeException& ex) {
        cout << "Day error: " << ex.what() << endl;
    } catch (const DateException& ex) {
        cout << "Error: " << ex.what() << endl;
    }

    try {
        cout << "Invalid format (230315): ";
        Date fourthDate("230315");
        cout << fourthDate << endl;
    } catch (const DateLengthException& ex) {
        cout << "Format error: " << ex.what() << endl;
    } catch (const DateException& ex) {
        cout << "Error: " << ex.what() << endl;
    }

    try {
        cout << "Leap year (24/02/29): ";
        Date fifthDate("24/02/29");
        cout << fifthDate << endl;
    } catch (const DateException& ex) {
        cout << "Error: " << ex.what() << endl;
    }
}

void Program::testInputDate() {
    try {
        cout << "Enter the date (YY/MM/DD): ";
        cin >> date;
        cout << "The value " << date << " of date was set successfully" << endl;
    } catch (const DateLengthException& ex) {
        cout << "Length error: " << ex.what() << endl;
    } catch (const DateSeparatorException& ex) {
        cout << "Separator error: " << ex.what() << endl;
    } catch (const YearDigitException& ex) {
        cout << "Year digit error: " << ex.what() << endl;
    } catch (const MonthRangeException& ex) {
        cout << "Month range error: " << ex.what() << endl;
    } catch (const DayRangeException& ex) {
        cout << "Day range error: " << ex.what() << endl;
    } catch (const DateException& ex) {
        cout << "General date error: " << ex.what() << endl;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Program::showCurrentDate() const {
    cout << "Current date: " << date << endl;
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