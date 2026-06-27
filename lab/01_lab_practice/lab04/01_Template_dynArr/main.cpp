/*
===============================================================================
CSE225L Lab 4 - Task 1: Test Template dynArr<T>
File: main.cpp
===============================================================================

ALGORITHM: Store and print values using a template dynamic array
Input:  Five integer values from the user
Output: Printed integer array and printed double array

1. Create dynArr<int> numbers(5).
2. Loop from 0 to numbers.getSize() - 1:
   a. Read an integer value.
   b. Store it using numbers.setValue(i, value).
3. Loop again and print numbers.getValue(i).
4. Create dynArr<double> marks(3).
5. Store three double values using setValue().
6. Loop and print marks.getValue(i).
7. When main ends, destructors run automatically and release heap memory.

PSEUDOCODE:
CREATE numbers as dynArr<int> of size 5
PRINT prompt
FOR i <- 0 to numbers.getSize() - 1
    READ value
    numbers.setValue(i, value)
END FOR

PRINT "Integer array"
FOR i <- 0 to numbers.getSize() - 1
    PRINT numbers.getValue(i)
END FOR

CREATE marks as dynArr<double> of size 3
marks[0] <- 87.5
marks[1] <- 91.25
marks[2] <- 78.0

PRINT "Double array"
FOR i <- 0 to marks.getSize() - 1
    PRINT marks.getValue(i)
END FOR
===============================================================================
*/

#include <iostream>
#include "dynarr.h"
using namespace std;

int main() {
    dynArr<int> numbers(5);

    cout << "Enter 5 integer values: ";
    for (int i = 0; i < numbers.getSize(); i++) {
        int value;
        cin >> value;
        numbers.setValue(i, value);
    }

    cout << "Integer array: ";
    for (int i = 0; i < numbers.getSize(); i++) {
        cout << numbers.getValue(i) << " ";
    }
    cout << endl;

    dynArr<double> marks(3);
    marks.setValue(0, 87.5);
    marks.setValue(1, 91.25);
    marks.setValue(2, 78.0);

    cout << "Double array: ";
    for (int i = 0; i < marks.getSize(); i++) {
        cout << marks.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
