/*
Algorithm: Task 2 - Dynamic 2D Character Array With Equal Rows
Task: Allocate a two-dimensional character array where the number of rows and columns
      is provided by the user. Input one string for each row, print all strings, and
      deallocate the memory.

Input:
    rows: number of string rows
    columns: maximum characters per string row
    one word/string for each row
Output:
    All stored strings

Algorithm:
    1. Read rows and columns.
    2. If rows <= 0 or columns <= 0, print an error message and stop.
    3. Allocate words = new char*[rows].
    4. For each row i, allocate words[i] = new char[columns + 1].
       The +1 is needed for the C-style string null terminator '\0'.
    5. For each row i, read one string with width protection so input cannot overflow.
    6. Print every stored string.
    7. Delete every row using delete[] words[i].
    8. Delete the outer pointer array using delete[] words.
    9. Set words to nullptr.

Pseudocode:
    READ rows, columns
    IF rows <= 0 OR columns <= 0 THEN
        PRINT error message
        STOP
    END IF

    words <- new char pointer array of length rows

    FOR i <- 0 to rows - 1
        words[i] <- new char array of length columns + 1
    END FOR

    FOR i <- 0 to rows - 1
        READ words[i] with maximum columns characters
    END FOR

    FOR i <- 0 to rows - 1
        PRINT words[i]
    END FOR

    FOR i <- 0 to rows - 1
        delete[] words[i]
    END FOR

    delete[] words
    words <- nullptr
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int rows, columns;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter maximum characters per row: ";
    cin >> columns;

    if (rows <= 0 || columns <= 0) {
        cout << "Rows and columns must be positive." << endl;
        return 0;
    }

    char** words = new char*[rows];

    for (int i = 0; i < rows; i++) {
        words[i] = new char[columns + 1];
    }

    cout << "Enter one string for each row." << endl;
    cout << "Each string can contain at most " << columns << " characters." << endl;

    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << ": ";
        cin >> setw(columns + 1) >> words[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Stored strings:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << words[i] << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] words[i];
    }
    delete[] words;
    words = nullptr;

    return 0;
}
