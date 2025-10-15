#pragma once
#include <iostream>

template <typename T> class MyArray {
    T *data = nullptr;
    int size = 0;

  public:
    MyArray() = default;
    ~MyArray();
    T &operator[](int ind);
    MyArray(const MyArray &other);
    MyArray &operator=(const MyArray &other);
    void printArray();
    void pushElement(const T &element);
    friend std::ostream &operator<<(std::ostream &os, const MyArray &array) {
        for (int i = 0; i < array.size; i++) {
            os << array.data[i] << "\t";
        }

        os << std::endl;

        return os;
    }
    friend std::istream &operator>>(std::istream &in, MyArray &array) {
        for (int i = 0; i < array.size; i++) {
            in >> array.data[i];
        }

        return in;
    }
};

template <typename T> MyArray<T>::~MyArray() {
    delete[] data;
}

template <typename T> T &MyArray<T>::operator[](int ind) {
    return data[ind];
}

template <typename T> MyArray<T>::MyArray(const MyArray &other) : data(new T[other.size]), size(other.size) {
    for (int i = 0; i < other.size; i++) {
        data[i] = other.data[i];
    }
}

template <typename T> MyArray<T> &MyArray<T>::operator=(const MyArray &other) {
    if (&other != this) {
        delete[] data;
        size = other.size;
        data = new T[size];

        for (int i = 0; i < other.size; i++) {
            data[i] = other.data[i];
        }
    }

    return *this;
}

template <typename T> void MyArray<T>::printArray() {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << "\t";
        std::cout << std::endl;
    }
}

template <typename T> void MyArray<T>::pushElement(const T &element) {
    auto *newData = new T[size + 1];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    newData[size] = element;
    delete[] data;
    data = newData;
    size++;
}
