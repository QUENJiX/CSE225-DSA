/*
    EXAM PATTERN 2 - dynamic 2D array (int**), read, transform, print, free
    Maps to: Assessment 1, Question 2 (print rows in reverse order).

    Steps that almost every 2D-dynamic question needs:
      1. read rows, cols
      2. allocate int** (array of row pointers, then each row)
      3. read all elements
      4. print with the required transform
      5. FREE: delete each row, then the outer array   <-- marks live here

    HOW TO ADAPT the print/transform step (only that loop changes):
      - reverse row order : for (i = rows-1; i >= 0; i--)         (shown below)
      - reverse each row  : for (j = cols-1; j >= 0; j--)
      - transpose         : print matrix[j][i] with swapped bounds
      - row/col sums      : accumulate along one index
*/

#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Rows and columns must be positive." << endl;
        return 0;
    }

    // allocate
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // input
    cout << "Enter " << rows * cols << " values:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // transform + print: rows in reverse order (last row first)
    cout << "Matrix in reverse row order:" << endl;
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // free: inner rows first, then outer array
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;

    return 0;
}
