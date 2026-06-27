/*
    CSE225L Lab 3 - Task 3: Driver Program for 2D dynArr

    Algorithm:
    1. Read number of rows and columns from the user.
    2. Create a dynArr matrix using those dimensions.
    3. Use nested loops to read every matrix value.
    4. Store each value using setValue(row, col, value).
    5. Use nested loops again to print every value using getValue(row, col).
    6. When main ends, the matrix destructor releases all dynamic memory.

    Pseudocode:
    Read rows and cols.
    Create matrix(rows, cols).

    For i from 0 to rows - 1:
        For j from 0 to cols - 1:
            Read value.
            matrix.setValue(i, j, value).

    For i from 0 to matrix.getRows() - 1:
        For j from 0 to matrix.getCols() - 1:
            Print matrix.getValue(i, j).
        Print newline.
*/

#include <iostream>
#include "dynarr.h"
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    dynArr matrix(rows, cols);

    cout << "Enter " << rows * cols << " values:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            cin >> value;
            matrix.setValue(i, j, value);
        }
    }

    cout << "Matrix values:" << endl;
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            cout << matrix.getValue(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
