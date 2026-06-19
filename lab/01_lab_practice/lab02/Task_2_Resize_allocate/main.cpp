/*
    CSE225L Lab 3 - Task 2: Driver Program for allocate(int s)

    Algorithm:
    1. Create a dynArr object of size 5.
    2. Read five values and store them.
    3. Resize the array to size 8 using allocate(8).
    4. Read three more values and store them in indexes 5, 6, and 7.
    5. Print all values using the current size from getSize().

    Pseudocode:
    Create numbers with size 5.
    For i from 0 to 4:
        Read value.
        numbers.setValue(i, value).

    numbers.allocate(8).

    For i from 5 to 7:
        Read value.
        numbers.setValue(i, value).

    For i from 0 to numbers.getSize() - 1:
        Print numbers.getValue(i).
*/

#include <iostream>
#include "dynarr.h"
using namespace std;

int main()
{
    dynArr numbers(5);

    cout << "Enter 5 values: ";
    for (int i = 0; i < 5; i++)
    {
        int value;
        cin >> value;
        numbers.setValue(i, value);
    }

    numbers.allocate(8);

    cout << "After resizing to 8, enter 3 more values: ";
    for (int i = 5; i < 8; i++)
    {
        int value;
        cin >> value;
        numbers.setValue(i, value);
    }

    cout << "Array values: ";
    for (int i = 0; i < numbers.getSize(); i++)
    {
        cout << numbers.getValue(i) << " ";
    }

    cout << endl;

    return 0;
}
