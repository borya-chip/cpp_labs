#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "myalgorithm.h"
#include "mycontainer.h"

void showMenu();

template <typename T>
void printMatrix(const MyContainer<T>& matrix) {
  matrix.print();
}

template <typename T>
void inputMatrix(MyContainer<T>& matrix) {
  T* arr = nullptr;

  try {
    std::cout << "Enter the rows number of matrix: ";
    int newRows;
    std::cin >> newRows;

    if (std::cin.fail() || newRows <= 0) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw MyException("Rows should be positive number");
    }

    std::cout << "Enter the cols number of matrix: ";
    int newCols;
    std::cin >> newCols;

    if (std::cin.fail() || newCols <= 0) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw MyException("Cols should be positive number");
    }

    int totalElements = newRows * newCols;
    arr = new T[totalElements];

    std::cout << "Enter " << totalElements
              << " elements of matrix:" << std::endl;

    for (int i = 0; i < totalElements; i++) {
      std::cout << "Element " << (i + 1) << ": ";
      std::cin >> arr[i];

      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw MyException("Invalid input for matrix element");
      }
    }

    matrix.resize(newRows, newCols);
    matrix.fillFromArray(arr, totalElements);

    delete[] arr;
    arr = nullptr;

    std::cout << "Matrix successfully created!" << std::endl;
  } catch (const MyException& ex) {
    if (arr != nullptr) {
      delete[] arr;
      arr = nullptr;
    }

    std::cout << "Input error: " << ex.what() << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

template <typename T>
void findElement(MyContainer<T>& matrix) {
  try {
    matrix.print();

    if (matrix.isEmpty()) {
      std::cout << "Matrix is empty" << std::endl;
      return;
    }

    std::cout << "Enter the value to find: ";
    T value;

    std::cin >> value;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw MyException("Invalid input");
    }

    if (auto it = MyAlgorithm<T>::find(matrix, value); it != matrix.end()) {
      std::cout << "Found: " << *it << "\n";
    } else {
      std::cout << "Value isn't found.\n";
    }
  } catch (const MyException& ex) {
    std::cout << "Input error:" << ex.what() << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

template <typename T>
void sortMatrix(MyContainer<T>& matrix) {
  try {
    if (matrix.isEmpty()) {
      std::cout << "Matrix is empty! Cannot sort." << std::endl;
      return;
    }

    std::cout << "Your matrix:" << std::endl;
    matrix.print();

    MyAlgorithm<T>::sortContainer(matrix);

    std::cout << "Sorted matrix:" << std::endl;
    matrix.print();
  } catch (const MyException& e) {
    std::cout << "Sorting error: " << e.what() << std::endl;
  }
}
#endif
