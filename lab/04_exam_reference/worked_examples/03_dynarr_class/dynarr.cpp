#include "dynarr.h"

dynArr::dynArr() {
    data = nullptr;
    rows = 0;
    cols = 0;
}

dynArr::dynArr(int r, int c) {
    data = nullptr;
    rows = 0;
    cols = 0;
    allocate(r, c);
}

dynArr::~dynArr() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

void dynArr::allocate(int r, int c) {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;

    rows = r;
    cols = c;
    data = new int*[rows];

    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
    }
}

void dynArr::setValue(int row, int col, int value) {
    data[row][col] = value;
}

int dynArr::getValue(int row, int col) {
    return data[row][col];
}

int dynArr::getRows() {
    return rows;
}

int dynArr::getCols() {
    return cols;
}
