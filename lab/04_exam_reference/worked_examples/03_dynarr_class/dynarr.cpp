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

dynArr::dynArr(const dynArr& other) {
    data = nullptr;
    rows = 0;
    cols = 0;
    copyFrom(other);
}

dynArr::~dynArr() {
    clear();
}

dynArr& dynArr::operator=(const dynArr& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

bool dynArr::isValidIndex(int row, int col) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

void dynArr::copyFrom(const dynArr& other) {
    if (other.rows <= 0 || other.cols <= 0) {
        data = nullptr;
        rows = 0;
        cols = 0;
        return;
    }

    rows = other.rows;
    cols = other.cols;
    data = new int*[rows];

    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols]();
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

void dynArr::clear() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
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
        data[i] = new int[cols]();
    }
}

void dynArr::setValue(int row, int col, int value) {
    if (isValidIndex(row, col)) {
        data[row][col] = value;
    }
}

int dynArr::getValue(int row, int col) {
    if (isValidIndex(row, col)) {
        return data[row][col];
    }
    return 0;
}

int dynArr::getRows() {
    return rows;
}

int dynArr::getCols() {
    return cols;
}

bool dynArr::isEmpty() {
    return rows == 0 || cols == 0;
}
