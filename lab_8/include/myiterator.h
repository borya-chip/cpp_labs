#ifndef MYITERATOR_H
#define MYITERATOR_H

#include "myexception.h"

template <typename T>
class MyIterator {
 private:
  T** data;
  int currentRow;
  int currentCol;
  int totalRows;
  int totalCols;

 public:
  MyIterator(T** matrix, int rows, int cols, int startRow = 0,
             int startCol = 0);
  MyIterator(const MyIterator& other);

  MyIterator& operator=(const MyIterator& other);

  T& operator*();
  T* operator->();

  MyIterator& operator++();
  MyIterator operator++(int);

  MyIterator& operator--();
  MyIterator operator--(int);

  bool operator==(const MyIterator& other) const;

  void getPosition(int& r, int& c) const;

  bool isEnd() const;

  bool isValid() const;

  ~MyIterator();
};

template <typename T>
MyIterator<T>::~MyIterator() {
  data = nullptr;
}

template <typename T>
MyIterator<T>::MyIterator(T** matrix, int rows, int cols, int startRow,
                          int startCol)
    : data(matrix),
      currentRow(startRow),
      currentCol(startCol),
      totalRows(rows),
      totalCols(cols) {
  if (startRow < 0 || startCol < 0) {
    throw MyException("Error in the transfer of the position");
  }
}

template <typename T>
MyIterator<T>::MyIterator(const MyIterator& other)
    : data(other.data),
      currentRow(other.currentRow),
      currentCol(other.currentCol),
      totalRows(other.totalRows),
      totalCols(other.totalCols) {}

template <typename T>
MyIterator<T>& MyIterator<T>::operator=(const MyIterator& other) {
  if (this != &other) {
    data = other.data;
    currentRow = other.currentRow;
    currentCol = other.currentCol;
    totalRows = other.totalRows;
    totalCols = other.totalCols;
  }
  return *this;
}

template <typename T>
T& MyIterator<T>::operator*() {
  if (currentRow < 0 || currentRow >= totalRows || currentCol < 0 ||
      currentCol >= totalCols) {
    throw MyException("Error:Iterator out of range");
  }
  return data[currentRow][currentCol];
}

template <typename T>
T* MyIterator<T>::operator->() {
  if (currentRow < 0 || currentRow >= totalRows || currentCol < 0 ||
      currentCol >= totalCols) {
    throw MyException("Error:Iterator out of range");
  }
  return &data[currentRow][currentCol];
}

template <typename T>
MyIterator<T>& MyIterator<T>::operator++() {
  if (currentRow < totalRows) {
    currentCol++;
    if (currentCol >= totalCols) {
      currentRow++;
      currentCol = 0;
    }
  }
  return *this;
}

template <typename T>
MyIterator<T> MyIterator<T>::operator++(int) {
  MyIterator temp = *this;
  ++(*this);
  return temp;
}

template <typename T>
MyIterator<T>& MyIterator<T>::operator--() {
  if (currentCol == 0) {
    if (currentRow > 0) {
      currentRow--;
      currentCol = totalCols - 1;
    }
  } else {
    currentCol--;
  }
  return *this;
}

template <typename T>
MyIterator<T> MyIterator<T>::operator--(int) {
  MyIterator temp = *this;
  --(*this);
  return temp;
}

template <typename T>
bool MyIterator<T>::operator==(const MyIterator& other) const {
  return data == other.data && currentRow == other.currentRow &&
         currentCol == other.currentCol;
}

template <typename T>
void MyIterator<T>::getPosition(int& r, int& c) const {
  r = currentRow;
  c = currentCol;
}

template <typename T>
bool MyIterator<T>::isEnd() const {
  return currentRow >= totalRows;
}

template <typename T>
bool MyIterator<T>::isValid() const {
  return currentRow >= 0 && currentRow < totalRows && currentCol >= 0 &&
         currentCol < totalCols;
}

#endif
