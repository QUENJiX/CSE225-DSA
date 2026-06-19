/*
Algorithm: Sum Two Integers
Source: CSE225L Lab 1, Task 1

Input:
    firstNumber, secondNumber
Output:
    Sum of firstNumber and secondNumber

Pseudocode:
    1. Create integer variable firstNumber.
    2. Create integer variable secondNumber.
    3. Ask the user for the first number and read it.
    4. Ask the user for the second number and read it.
    5. Compute firstNumber + secondNumber.
    6. Print the sum.

Complexity:
    Time: O(1)
    Space: O(1)
*/

#include <iostream>
using namespace std;

int main() {
    int firstNumber, secondNumber;

    cout << "Enter first integer: ";
    cin >> firstNumber;

    cout << "Enter second integer: ";
    cin >> secondNumber;

    cout << "Sum = " << firstNumber + secondNumber << endl;

    return 0;
}
