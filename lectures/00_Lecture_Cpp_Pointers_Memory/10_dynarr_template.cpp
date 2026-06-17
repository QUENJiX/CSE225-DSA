// Slides 30-31: template dynamic array definition file.

#include "10_dynarr_template.h"

#include <algorithm>
#include <stdexcept>

using namespace std;

template <class T>
dynArr<T>::dynArr() : data(nullptr), size(0) {}

template <class T>
dynArr<T>::dynArr(int requestedSize) : data(nullptr), size(0) {
    allocate(requestedSize);
}

template <class T>
dynArr<T>::dynArr(const dynArr& other) : data(new T[other.size]{}), size(other.size) {
    copy(other.data, other.data + other.size, data);
}

template <class T>
dynArr<T>& dynArr<T>::operator=(const dynArr& other) {
    if (this == &other) {
        return *this;
    }

    T* newData = new T[other.size]{};
    copy(other.data, other.data + other.size, newData);
    delete[] data;
    data = newData;
    size = other.size;
    return *this;
}

template <class T>
dynArr<T>::~dynArr() {
    delete[] data;
}

template <class T>
void dynArr<T>::checkSize(int requestedSize) const {
    if (requestedSize < 0) {
        throw invalid_argument("size cannot be negative");
    }
}

template <class T>
void dynArr<T>::checkIndex(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("index out of range");
    }
}

template <class T>
void dynArr<T>::allocate(int requestedSize) {
    checkSize(requestedSize);

    T* newData = new T[requestedSize]{};
    delete[] data;
    data = newData;
    size = requestedSize;
}

template <class T>
void dynArr<T>::setValue(int index, T value) {
    checkIndex(index);
    data[index] = value;
}

template <class T>
T dynArr<T>::getValue(int index) const {
    checkIndex(index);
    return data[index];
}

template <class T>
int dynArr<T>::getSize() const {
    return size;
}
