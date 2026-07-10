#include "dynarr.h"
#include <iostream>
using namespace std;

dynArr::dynArr() {
    data = nullptr;
    size = 0;
}

dynArr::dynArr(int s) {
    data = new int[s];
    size = s;
}

dynArr::~dynArr() {
    delete[] data;
}

void dynArr::allocate(int s) {
    if (s <= 0) {
        delete[] data;
        data = nullptr;
        size = 0;
        return;
    }

    int* newData = new int[s];
    int limit = (s < size) ? s : size;

    for (int i = 0; i < limit; i++) {
        newData[i] = data[i];
    }

    for (int i = limit; i < s; i++) {
        newData[i] = 0;
    }

    delete[] data;
    data = newData;
    size = s;
}

int dynArr::getValue(int index) {
    return data[index];
}

void dynArr::setValue(int index, int value) {
    data[index] = value;
}

int dynArr::getSize() {
    return size;
}
