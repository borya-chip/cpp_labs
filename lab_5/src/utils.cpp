#include <utils.h>
#include <iostream>
#include<program.h>

using namespace std;
template<typename T>
T getValue() {
    T value;

    while (true) {
        if (cin >> value && cin.get() == '\n') {
                return value;
        }

        cin.clear();
        while (cin.get() != '\n');
        cout << "Error, enter a valid number: ";
    }
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
    }
}

void runProgram() {
    std::cout << "Choose array type:\n1. Array of Int elements\n2. Array of double elements\nChoice: ";
    int typeChoice = getDigit();
    
    switch (typeChoice) {
        case 1: {
            system("cls");
            Program<int> program;
            program.run();
            break;
        }
        case 2: {
            system("cls");
            Program<double> program;
            program.run();
            break;
        }
        default:
            std::cout << "Incorrect type choice!";
            break;
    }
}