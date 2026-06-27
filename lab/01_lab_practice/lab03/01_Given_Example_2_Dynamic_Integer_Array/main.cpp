/*
Algorithm: Dynamic Integer Array Example
Source idea: Lab 2 given example for allocating a fixed-size dynamic integer array.

Input:
    No user input. The size is fixed as 5 inside the program.
Output:
    The generated array elements.

Algorithm:
    1. Set size to 5.
    2. Allocate an integer array of length size using new int[size].
    3. For each index i from 0 to size - 1, store i * 2 in arr[i].
    4. Print every element from index 0 to size - 1.
    5. Release the heap array using delete[] arr.
    6. Set arr to nullptr.

Pseudocode:
    size <- 5
    arr <- new integer array of length size
    FOR i <- 0 to size - 1
        arr[i] <- i * 2
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
    int size = 5;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}
