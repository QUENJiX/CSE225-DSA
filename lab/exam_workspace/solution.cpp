#include "solution.h"

template <class T>
dynArr<T>::dynArr() {
    data = nullptr;
    size = 0;
}

template <class T>
dynArr<T>::dynArr(int s) {
    data = nullptr;
    size = 0;
    allocate(s);
}

template <class T>
dynArr<T>::dynArr(const dynArr<T>& other) {
    data = nullptr;
    size = 0;
    copyFrom(other);
}

template <class T>
dynArr<T>::~dynArr() {
    clear();
}

template <class T>
dynArr<T>& dynArr<T>::operator=(const dynArr<T>& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

template <class T>
bool dynArr<T>::isValidIndex(int index) {
    return (index >= 0 && index < size);
}

template <class T>
void dynArr<T>::copyFrom(const dynArr<T>& other) {
    if (other.size <= 0) {
        data = nullptr;
        size = 0;
        return;
    }

    data = new T[other.size]();
    size = other.size;

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <class T>
void dynArr<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}

template <class T>
void dynArr<T>::allocate(int s) {
    clear();

    if (s <= 0) {
        return;
    }

    data = new T[s]();
    size = s;
}

template <class T>
void dynArr<T>::setValue(int index, T value) {
    if (isValidIndex(index)) {
        data[index] = value;
    }
}

template <class T>
T dynArr<T>::getValue(int index) {
    if (isValidIndex(index)) {
        return data[index];
    }
    return T();
}

template <class T>
int dynArr<T>::getSize() {
    return size;
}

template <class T>
bool dynArr<T>::isEmpty() {
    return size == 0;
}
