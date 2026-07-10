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
