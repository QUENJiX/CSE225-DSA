#include "dynarr.h"
#include <iostream>
using namespace std;

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
    clear();
}

void dynArr::clear() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    data = nullptr;
    rows = 0;
    cols = 0;
}

void dynArr::allocate(int r, int c) {
    clear();

    if (r <= 0 || c <= 0) {
        return;
    }

    rows = r;
    cols = c;

    data = new int*[rows];

    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];

        for (int j = 0; j < cols; j++) {
            data[i][j] = 0;
        }
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
