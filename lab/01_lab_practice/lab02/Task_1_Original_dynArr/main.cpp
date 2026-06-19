/*
    CSE225L Lab 3 - Task 1: Driver Program

    Algorithm:
    1. Create one dynArr object using the default constructor.
    2. Create one dynArr object with size 5.
    3. Read five integer values from the user.
    4. Store each value in the second object using setValue.
    5. Print each stored value using getValue.

    Pseudocode:
    Create emptyArray using default constructor.
    Create numbers using constructor argument 5.
    For i from 0 to 4:
        Read value.
        numbers.setValue(i, value).
    Print "Stored values:".
    For i from 0 to 4:
        Print numbers.getValue(i).
*/

#include <iostream>
#include "dynarr.h"
using namespace std;

int main()
{
    dynArr emptyArray;
    dynArr numbers(5);

    int value;

    cout << "Enter 5 values: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        numbers.setValue(i, value);
    }

    cout << "Stored values: ";
    for (int i = 0; i < 5; i++)
    {
        cout << numbers.getValue(i) << " ";
    }

    cout << endl;

    return 0;
}
