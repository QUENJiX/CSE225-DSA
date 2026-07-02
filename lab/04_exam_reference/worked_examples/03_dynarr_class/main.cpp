#include <iostream>
#include "dynarr.h"
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    dynArr matrix(rows, cols);
    if (matrix.isEmpty()) {
        cout << "Invalid matrix size" << endl;
        return 0;
    }

    cout << "Enter matrix values:" << endl;
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            int value;
            cin >> value;
            matrix.setValue(i, j, value);
        }
    }

    cout << "Matrix:" << endl;
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            cout << matrix.getValue(i, j) << " ";
        }
        cout << endl;
    }

    matrix.setValue(-1, 0, 999);
    cout << "Invalid read gives: " << matrix.getValue(-1, 0) << endl;

    dynArr backup = matrix;
    matrix.clear();
    cout << "Backup still has " << backup.getRows() << " rows" << endl;

    return 0;
}
