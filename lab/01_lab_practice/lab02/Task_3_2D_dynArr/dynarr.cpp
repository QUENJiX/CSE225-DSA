/*
    CSE225L Lab 3 - Task 3: 2D dynArr Source

    Algorithm:
    1. Default constructor starts with no matrix: data = NULL, rows = 0, cols = 0.
    2. Parameterized constructor starts empty, then calls allocate(r, c).
    3. clear() deletes the old matrix safely:
       a. Delete each row with delete[].
       b. Delete the outer row-pointer array with delete[].
       c. Reset data, rows, and cols.
    4. allocate(r, c) clears old memory first.
    5. If dimensions are valid, allocate row pointers, then allocate every row.
    6. Initialize all matrix cells with 0.
    7. setValue and getValue access a cell using row and column indexes.

    Pseudocode:
    clear():
        IF data is not NULL THEN
            For i from 0 to rows - 1:
                delete[] data[i]
            delete[] data
        END IF
        data = NULL
        rows = 0
        cols = 0

    allocate(r, c):
        clear()
        IF r <= 0 OR c <= 0 THEN stop
        rows = r
        cols = c
        data = new int*[rows]
        For i from 0 to rows - 1:
            data[i] = new int[cols]
            For j from 0 to cols - 1:
                data[i][j] = 0
*/

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
