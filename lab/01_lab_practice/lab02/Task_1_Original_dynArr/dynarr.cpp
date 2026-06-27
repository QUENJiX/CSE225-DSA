/*
    CSE225L Lab 3 - Task 1: Original dynArr Source

    Algorithm:
    1. Default constructor sets data to NULL and size to 0.
    2. Parameterized constructor creates a dynamic integer array of size s.
    3. Destructor frees the dynamic array using delete[].
    4. setValue writes a value at the given index.
    5. getValue returns the value stored at the given index.

    Pseudocode:
    dynArr():
        data = NULL
        size = 0

    dynArr(s):
        data = new int[s]
        size = s

    destructor:
        delete[] data

    setValue(index, value):
        data[index] = value

    getValue(index):
        return data[index]
*/

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

int dynArr::getValue(int index) {
    return data[index];
}

void dynArr::setValue(int index, int value) {
    data[index] = value;
}
