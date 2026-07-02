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
dynArr<T>::~dynArr() {
    delete[] data;
}

template <class T>
void dynArr<T>::allocate(int s) {
    delete[] data;

    if (s <= 0) {
        data = nullptr;
        size = 0;
        return;
    }

    data = new T[s];
    size = s;
}

template <class T>
void dynArr<T>::setValue(int index, T value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}

template <class T>
T dynArr<T>::getValue(int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return T();
}

template <class T>
int dynArr<T>::getSize() {
    return size;
}
