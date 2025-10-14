#pragma once
#include <utils.h>
#include<iostream>

#include "myarray.h"

template <typename T>
class Program {
    MyArray<T> array;
    void addElementInArray();
    void printArray();

   public:
   void run();
};

template <typename T>
void Program<T>::addElementInArray() {
    std::cout << "Enter array element: ";
    T value = getValue<T>();
    array.pushElement(value);
}

template <typename T>
void Program<T>::printArray(){
   std::cout <<"\nResult array: "<< array;
}

template <typename T>
void Program<T>::run() {
    int choice;
    while (true) {
        std::cout << "\n1. Add element\n2. Print array\n3. Exit\nChoice: ";
        choice = getDigit();
        switch (choice) {
            case 1: system("cls"); addElementInArray(); break;
            case 2: system("cls"); printArray(); break;
            case 3:  std::cout << "\nYou have successfully exited the program.\n" << std::endl;return;
            default: std::cout << "Incorrect choice!"; break;
        }
    }
}