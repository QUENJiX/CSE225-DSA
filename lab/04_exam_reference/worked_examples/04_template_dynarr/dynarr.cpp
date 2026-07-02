#include "dynarr.h"

template <class T>
dynArr<T>::dynArr() {
    data = nullptr;
    size = 0;
}

template <class T>
dynArr<T>::dynArr(int s) {
    if (s <= 0) {
        data = nullptr;
        size = 0;
    } else {
        data = new T[s];
        size = s;
    }
}

template <class T>
dynArr<T>::~dynArr() {
    delete[] data;
}

template <class T>
void dynArr<T>::setValue(int index, T value) {
    data[index] = value;
}

template <class T>
T dynArr<T>::getValue(int index) {
    return data[index];
}

template <class T>
int dynArr<T>::getSize() {
    return size;
}
