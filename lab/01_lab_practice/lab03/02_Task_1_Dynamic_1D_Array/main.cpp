/*
Algorithm: Task 1 - Dynamic Array Allocation (1D)
Task: Use new to allocate an integer array of user-specified size. Input each element,
      print the values, and deallocate the array using delete[].

Input:
    size: number of integers in the array
    size integer values
Output:
    The stored array values

Algorithm:
    1. Read size from the user.
    2. If size <= 0, print an error message and stop.
    3. Allocate arr = new int[size].
    4. For i from 0 to size - 1, read arr[i].
    5. For i from 0 to size - 1, print arr[i].
    6. Release memory using delete[] arr.
    7. Set arr to nullptr.

Pseudocode:
    READ size
    IF size <= 0 THEN
        PRINT "Size must be positive."
        STOP
    END IF

    arr <- new integer array of length size

    FOR i <- 0 to size - 1
        READ arr[i]
    END FOR

    FOR i <- 0 to size - 1
        PRINT arr[i]
    END FOR

    delete[] arr
    arr <- nullptr
*/

#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter array size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Size must be positive." << endl;
        return 0;
    }

    int* arr = new int[size];

    cout << "Enter " << size << " integer values: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Array values: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}
