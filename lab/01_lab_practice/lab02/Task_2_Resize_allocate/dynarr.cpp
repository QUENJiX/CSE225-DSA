/*
    CSE225L Lab 3 - Task 2: dynArr Source with Leak-Safe Resize

    Algorithm:
    1. Initialize objects with NULL pointer and size 0, or allocate size s.
    2. When allocate(s) is called:
       a. If s is invalid, delete old data and reset the object.
       b. Create a temporary newData array.
       c. Copy values from the old array up to the smaller of old size and new size.
       d. Fill new extra cells with 0.
       e. Delete the old array.
       f. Point data to newData.
       g. Update size.
    3. Use delete[] in the destructor.

    Pseudocode:
    allocate(s):
        IF s <= 0 THEN
            delete[] data
            data = NULL
            size = 0
            stop
        END IF

        newData = new int[s]
        limit = smaller(s, size)

        For i from 0 to limit - 1:
            newData[i] = data[i]

        For i from limit to s - 1:
            newData[i] = 0

        delete[] data
        data = newData
        size = s
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
