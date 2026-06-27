/*
Algorithm: Task 3 - Dynamic 2D Integer Array With Uneven Rows
Task: Allocate a two-dimensional integer array where each row has a different number of
      columns. Ask for the number of elements in each row, input values, print the entire
      2D array, and deallocate all memory.

Input:
    rows: number of rows
    columns[i]: number of integers in row i
    data[i][j]: values for every row and column
Output:
    The complete jagged 2D integer array

Algorithm:
    1. Read rows.
    2. If rows <= 0, print an error message and stop.
    3. Allocate columns = new int[rows] to store each row length.
    4. Allocate data = new int*[rows] to store row addresses.
    5. For each row i:
       a. Read columns[i].
       b. If columns[i] <= 0, delete all rows already allocated, delete data,
          delete columns, and stop.
       c. Allocate data[i] = new int[columns[i]].
    6. For each row i and column j from 0 to columns[i] - 1, read data[i][j].
    7. For each row i and column j from 0 to columns[i] - 1, print data[i][j].
    8. Delete every row using delete[] data[i].
    9. Delete data and columns using delete[].
    10. Set data and columns to nullptr.

Pseudocode:
    READ rows
    IF rows <= 0 THEN
        PRINT error message
        STOP
    END IF

    columns <- new integer array of length rows
    data <- new integer pointer array of length rows

    FOR i <- 0 to rows - 1
        READ columns[i]
        IF columns[i] <= 0 THEN
            FOR j <- 0 to i - 1
                delete[] data[j]
            END FOR
            delete[] data
            delete[] columns
            STOP
        END IF
        data[i] <- new integer array of length columns[i]
    END FOR

    FOR i <- 0 to rows - 1
        FOR j <- 0 to columns[i] - 1
            READ data[i][j]
        END FOR
    END FOR

    FOR i <- 0 to rows - 1
        FOR j <- 0 to columns[i] - 1
            PRINT data[i][j]
        END FOR
        PRINT newline
    END FOR

    FOR i <- 0 to rows - 1
        delete[] data[i]
    END FOR
    delete[] data
    delete[] columns
    data <- nullptr
    columns <- nullptr
*/

#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    if (rows <= 0) {
        cout << "Rows must be positive." << endl;
        return 0;
    }

    int* columns = new int[rows];
    int** data = new int*[rows];

    for (int i = 0; i < rows; i++) {
        cout << "Enter number of elements in row " << i << ": ";
        cin >> columns[i];

        if (columns[i] <= 0) {
            cout << "Column count must be positive." << endl;

            for (int j = 0; j < i; j++) {
                delete[] data[j];
            }

            delete[] data;
            delete[] columns;

            return 0;
        }

        data[i] = new int[columns[i]];
    }

    for (int i = 0; i < rows; i++) {
        cout << "Enter " << columns[i] << " values for row " << i << ": ";

        for (int j = 0; j < columns[i]; j++) {
            cin >> data[i][j];
        }
    }

    cout << "Jagged 2D array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns[i]; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
    delete[] columns;

    data = nullptr;
    columns = nullptr;

    return 0;
}
