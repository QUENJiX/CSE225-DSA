#include <iostream>
#include "dynarr.h"
using namespace std;

template <class T>
dynArr<T>::~dynArr() {
    delete[] data;
}

template <class T>
void dynArr<T>::setValue(int index, T value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}

template <class T>
T dynArr<T>::getValue(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return T();
}

template <class T>
int dynArr<T>::getSize() const {
    return size;
}
