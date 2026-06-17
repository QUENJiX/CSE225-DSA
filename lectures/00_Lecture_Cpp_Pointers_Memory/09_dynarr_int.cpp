// Slides 34-35: integer dynamic array definition file.

#include "09_dynarr_int.h"

#include <algorithm>
#include <stdexcept>

using namespace std;

dynArr::dynArr() : data(nullptr), size(0) {}

dynArr::dynArr(int requestedSize) : data(nullptr), size(0) {
    allocate(requestedSize);
}

dynArr::dynArr(const dynArr& other) : data(new int[other.size]{}), size(other.size) {
    copy(other.data, other.data + other.size, data);
}

dynArr& dynArr::operator=(const dynArr& other) {
    if (this == &other) {
        return *this;
    }

    int* newData = new int[other.size]{};
    copy(other.data, other.data + other.size, newData);
    delete[] data;
    data = newData;
    size = other.size;
    return *this;
}

dynArr::~dynArr() {
    delete[] data;
}

void dynArr::checkSize(int requestedSize) const {
    if (requestedSize < 0) {
        throw invalid_argument("size cannot be negative");
    }
}

void dynArr::checkIndex(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("index out of range");
    }
}

void dynArr::allocate(int requestedSize) {
    checkSize(requestedSize);

    int* newData = new int[requestedSize]{};
    delete[] data;
    data = newData;
    size = requestedSize;
}

void dynArr::setValue(int index, int value) {
    checkIndex(index);
    data[index] = value;
}

int dynArr::getValue(int index) const {
    checkIndex(index);
    return data[index];
}

int dynArr::getSize() const {
    return size;
}
