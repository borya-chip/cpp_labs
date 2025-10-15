#pragma once
#include<iostream>


template <typename T>
class MyArray {
    T* data;
    int size;

   public:
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const MyArray<U>& array);
    template <typename U>
    friend std::istream& operator>>(std::istream& in, MyArray<U>& array);
    MyArray() : data(nullptr), size(0) {}
    ~MyArray();
    T& operator[](int ind);
    MyArray(const MyArray& other);
    MyArray& operator=(const MyArray& other);
    void printArray();
    void pushElement(const T& element);
};

template <typename T>
MyArray<T>::~MyArray() {
    delete[] data;
}

template <typename T>
T& MyArray<T>::operator[](int ind) {
    return data[ind];
}

template <typename T>
MyArray<T>::MyArray(const MyArray& other) : size(other.size) {
    data = new T[other.size];

    for (int i = 0; i < other.size; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray& other) {
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

template <typename T>
void MyArray<T>::printArray() {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << "\t";
        std::cout << std::endl;
    }
}

template <typename T>
void MyArray<T>::pushElement(const T& element) {
    T* newData = new T[size + 1];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    newData[size] = element;
    delete[] data;
    data = newData;
    size++;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyArray<T>& array) {
    for (int i = 0; i < array.size; i++) {
        os << array.data[i] << "\t";
    }
    
    os << std::endl;

    return os;
}

template <typename T>
std::istream& operator>>(std::istream& in, MyArray<T>& array) {
    for (int i = 0; i < array.size; i++) {
        in >> array.data[i];
    }

    return in;
}
