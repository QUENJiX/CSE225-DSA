/*
    CSE225L Exam Template - dynArr class definitions

    Every method is scoped with dynArr:: and defined here.
    Compile this file together with main.cpp (NOT dynarr.h):
        g++ -std=c++17 -Wall main.cpp dynarr.cpp -o app
*/

#include "dynarr.h"
using namespace std;

dynArr::dynArr() {
    data = nullptr;
    size = 0;
}

dynArr::dynArr(int s) {
    data = new int[s];
    size = s;
}

dynArr::dynArr(const dynArr& other) {
    size = other.size;
    data = (size > 0) ? new int[size] : nullptr;
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];   // deep copy: each object owns its own block
    }
}

dynArr& dynArr::operator=(const dynArr& other) {
    if (this == &other) {
        return *this;              // guard against self-assignment (a = a)
    }
    delete[] data;                 // free what we currently hold
    size = other.size;
    data = (size > 0) ? new int[size] : nullptr;
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

dynArr::~dynArr() {
    delete[] data;
}

void dynArr::allocate(int s) {
    if (s <= 0) {                  // invalid size empties the object
        delete[] data;
        data = nullptr;
        size = 0;
        return;
    }

    int* newData = new int[s];
    int limit = (s < size) ? s : size;   // copy the smaller of old/new

    for (int i = 0; i < limit; i++) {
        newData[i] = data[i];      // keep old values
    }
    for (int i = limit; i < s; i++) {
        newData[i] = 0;            // pad new cells with 0
    }

    delete[] data;                 // free old block
    data = newData;                // adopt new block
    size = s;
}

void dynArr::setValue(int index, int value) {
    data[index] = value;
}

int dynArr::getValue(int index) {
    return data[index];
}

int dynArr::getSize() {
    return size;
}
