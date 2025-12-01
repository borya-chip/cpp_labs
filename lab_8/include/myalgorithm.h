#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <numeric>

#include "mycontainer.h"
#include "myiterator.h"

template <typename T>
class MyAlgorithm {
 private:
  static void quickSort(T* array, int left, int right);
  static void swap(T& a, T& b);
  static bool validateIndex(const T* array, int index, int size);

 public:
  static MyIterator<T> find(MyContainer<T>& data, const T& value);
  static void sortContainer(MyContainer<T>& data);
};

template <typename T>
bool MyAlgorithm<T>::validateIndex(const T* array, int index, int size) {
  return array != nullptr && index >= 0 && index < size;
}

template <typename T>
MyIterator<T> MyAlgorithm<T>::find(MyContainer<T>& data, const T& value) {
  for (auto it = data.begin(); it != data.end(); ++it) {
    if (*it == value) {
      return it;
    }
  }
  return data.end();
}

template <typename T>
void MyAlgorithm<T>::swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
void MyAlgorithm<T>::quickSort(T* array, int left, int right) {
  if (array == nullptr || left < 0 || right < 0 || left >= right) return;

  int pivotIndex = std::midpoint(left, right);
  if (pivotIndex < left) pivotIndex = left;
  if (pivotIndex > right) pivotIndex = right;

  if (!validateIndex(array, pivotIndex, right + 1)) return;

  T pivot = array[pivotIndex];
  int i = left;
  int j = right;

  while (i <= j) {
    while (i <= right && validateIndex(array, i, right + 1) && array[i] < pivot)
      i++;
    while (j >= left && validateIndex(array, j, right + 1) && array[j] > pivot)
      j--;

    if (bool canSwap = (i <= j) && validateIndex(array, i, right + 1) &&
                       validateIndex(array, j, right + 1);
        canSwap) {
      swap(array[i], array[j]);
      i++;
      j--;
    } else {
      break;
    }

    if (i < left) i = left;
    if (j > right) j = right;
  }

  if (left < j) quickSort(array, left, j);
  if (i < right) quickSort(array, i, right);
}

template <typename T>
void MyAlgorithm<T>::sortContainer(MyContainer<T>& data) {
  int totalSize = data.getTotalSize();

  if (totalSize <= 0) return;

  T* temp = nullptr;
  try {
    temp = new T[totalSize];

    int index = 0;
    MyIterator<T> it = data.begin();
    const MyIterator<T> end = data.end();

    while (it != end) {
      if (index >= totalSize) {
        break;
      }

      if (it.isValid()) {
        temp[index] = *it;
      } else {
        temp[index] = T();
      }

      ++index;
      ++it;
    }

    if (index != totalSize) {
      throw MyException("Data copy incomplete during sorting");
    }

    if (totalSize > 1 && temp != nullptr) {
      quickSort(temp, 0, totalSize - 1);
    }

    index = 0;
    it = data.begin();

    while (it != end && index < totalSize) {
      if (it.isValid()) {
        *it = temp[index];
      }
      ++index;
      ++it;
    }

    delete[] temp;
    temp = nullptr;
  } catch (...) {
    if (temp != nullptr) {
      delete[] temp;
      temp = nullptr;
    }
    throw;
  }
}

#endif
