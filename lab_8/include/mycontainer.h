#ifndef MYCONTAINER_H
#define MYCONTAINER_H

#include "myexception.h"
#include "myiterator.h"

template <typename T>
class MyContainer {
 private:
  T** data;
  int rows;
  int cols;

 public:
  MyContainer();
  explicit MyContainer(int newRows, int newCols);

  MyContainer(const MyContainer& other);
  MyContainer(MyContainer&& other) noexcept;

  MyContainer& operator=(const MyContainer& other);
  MyContainer& operator=(MyContainer&& other) noexcept;

  T& operator()(int row, int col);
  const T& operator()(int row, int col) const;

  int getRows() const;
  int getCols() const;
  int getTotalSize() const;
  bool isEmpty() const;

  MyIterator<T> begin();
  MyIterator<T> end();

  void fill(const T& value);
  void fillFromArray(const T* array, int size);

  void print() const;

  void swap(MyContainer& other) noexcept;

  void resize(int newRows, int newCols);

  ~MyContainer();
};

template <typename T>
MyContainer<T>::MyContainer() : data(nullptr), rows(0), cols(0) {}

template <typename T>
MyContainer<T>::MyContainer(int newRows, int newCols)
    : rows(newRows), cols(newCols) {
  if (newRows < 0 || newCols < 0) {
    throw MyException("Error.Size shouldn't be negative");
  }
  if (newRows == 0 || newCols == 0) {
    data = nullptr;
    return;
  }
  data = new T*[rows];
  for (int i = 0; i < rows; i++) {
    data[i] = new T[cols];
    for (int j = 0; j < cols; j++) {
      data[i][j] = T();
    }
  }
}

template <typename T>
MyContainer<T>::MyContainer(const MyContainer& other)
    : rows(other.rows), cols(other.cols) {
  data = new T*[rows];
  for (int i = 0; i < rows; i++) {
    data[i] = new T[cols];
    for (int j = 0; j < cols; j++) {
      data[i][j] = other.data[i][j];
    }
  }
}

template <typename T>
MyContainer<T>::MyContainer(MyContainer&& other) noexcept
    : data(other.data), rows(other.rows), cols(other.cols) {
  other.data = nullptr;
  other.rows = 0;
  other.cols = 0;
}

template <typename T>
MyContainer<T>& MyContainer<T>::operator=(const MyContainer& other) {
  if (this != &other) {
    for (int i = 0; i < rows; i++) {
      delete[] data[i];
    }
    delete[] data;
    data = nullptr;

    rows = other.rows;
    cols = other.cols;

    data = new T*[rows];
    for (int i = 0; i < rows; i++) {
      data[i] = new T[cols];
      for (int j = 0; j < cols; j++) {
        data[i][j] = other.data[i][j];
      }
    }
  }
  return *this;
}

template <typename T>
MyContainer<T>& MyContainer<T>::operator=(MyContainer&& other) noexcept {
  if (this != &other) {
    data = other.data;
    rows = other.rows;
    cols = other.cols;
    other.data = nullptr;
    other.rows = 0;
    other.cols = 0;
  }
  return *this;
}

template <typename T>
T& MyContainer<T>::operator()(int row, int col) {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw MyException("Error: Position out of bounds");
  }
  if (data == nullptr || data[row] == nullptr) {
    throw MyException("Error: Invalid data structure");
  }
  return data[row][col];
}

template <typename T>
const T& MyContainer<T>::operator()(int row, int col) const {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw MyException("Error: Position out of bounds");
  }
  if (data == nullptr || data[row] == nullptr) {
    throw MyException("Error: Invalid data structure");
  }
  return data[row][col];
}

template <typename T>
int MyContainer<T>::getRows() const {
  return rows;
}

template <typename T>
int MyContainer<T>::getCols() const {
  return cols;
}

template <typename T>
int MyContainer<T>::getTotalSize() const {
  return rows * cols;
}

template <typename T>
bool MyContainer<T>::isEmpty() const {
  return rows == 0 || cols == 0;
}

template <typename T>
MyIterator<T> MyContainer<T>::begin() {
  return MyIterator<T>(data, rows, cols, 0, 0);
}

template <typename T>
MyIterator<T> MyContainer<T>::end() {
  return MyIterator<T>(data, rows, cols, rows, 0);
}

template <typename T>
void MyContainer<T>::fill(const T& value) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      data[i][j] = value;
    }
  }
}

template <typename T>
void MyContainer<T>::fillFromArray(const T* array, int size) {
  if (!array || size <= 0) {
    throw MyException("Invalid array or size");
  }

  int count = 0;
  int totalElements = rows * cols;
  int elementsToCopy = (size < totalElements) ? size : totalElements;

  for (int i = 0; i < rows && count < elementsToCopy; ++i) {
    for (int j = 0; j < cols && count < elementsToCopy; ++j) {
      if (count >= 0 && count < size) {
        data[i][j] = array[count];
      }
      count++;
    }
  }
}

template <typename T>
void MyContainer<T>::print() const {
  if (isEmpty()) {
    std::cout << "Array is empty" << std::endl;
    return;
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cout << data[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

template <typename T>
void MyContainer<T>::swap(MyContainer& other) noexcept {
  T** tempData = data;
  int tempRows = rows;
  int tempCols = cols;

  data = other.data;
  rows = other.rows;
  cols = other.cols;

  other.data = tempData;
  other.rows = tempRows;
  other.cols = tempCols;
}

template <typename T>
void MyContainer<T>::resize(int newRows, int newCols) {
  if (newRows <= 0 || newCols <= 0) {
    throw MyException("Error.Size shouldn't be negative or zero");
  }

  auto newData = new T*[newRows];
  try {
    for (int i = 0; i < newRows; i++) {
      newData[i] = new T[newCols]();

      for (int j = 0; j < newCols; ++j) {
        if (i < rows && j < cols) {
          newData[i][j] = data[i][j];
        }
      }
    }

    for (int i = 0; i < rows; i++) {
      delete[] data[i];
    }
    delete[] data;

    data = newData;
    rows = newRows;
    cols = newCols;
  } catch (...) {
    for (int i = 0; i < newRows; i++) {
      delete[] newData[i];
    }
    delete[] newData;
    throw;
  }
}

template <typename T>
MyContainer<T>::~MyContainer() {
  for (int i = 0; i < rows; i++) {
    delete[] data[i];
  }
  delete[] data;
  data = nullptr;
}

#endif
