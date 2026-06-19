/*
Algorithm: Single Dynamic Integer
Source idea: Lab 2 given example for allocating one integer on the heap.

Input:
    No user input.
Output:
    The value stored in the heap integer.

Algorithm:
    1. Declare an integer pointer named ptr.
    2. Allocate one integer on the heap using new int.
    3. Store 10 in the heap location using *ptr.
    4. Print the value using *ptr.
    5. Release the heap memory using delete ptr.
    6. Set ptr to nullptr so it no longer holds a freed address.

Pseudocode:
    ptr <- new integer
    *ptr <- 10
    PRINT *ptr
    delete ptr
    ptr <- nullptr
*/

#include <iostream>
using namespace std;

int main()
{
    int* ptr = new int;

    *ptr = 10;

    cout << "Value at ptr: " << *ptr << endl;

    delete ptr;
    ptr = nullptr;

    return 0;
}
