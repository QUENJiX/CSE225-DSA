/*
Algorithm: Simple Calculator Using switch/case
Source: CSE225L Lab 1, Task 3

Input:
    firstNumber, secondNumber, operation
Output:
    Result of firstNumber operation secondNumber, or invalid-operation message

Pseudocode:
    1. Read firstNumber.
    2. Read secondNumber.
    3. Read operation.
    4. Switch on operation:
        a. If operation is '+', print firstNumber + secondNumber and break.
        b. If operation is '-', print firstNumber - secondNumber and break.
        c. If operation is '*', print firstNumber * secondNumber and break.
        d. Otherwise, print invalid operation.

Complexity:
    Time: O(1)
    Space: O(1)
*/

#include <iostream>
using namespace std;

int main() {
    int firstNumber, secondNumber;
    char operation;

    cout << "Enter first integer: ";
    cin >> firstNumber;

    cout << "Enter second integer: ";
    cin >> secondNumber;

    cout << "Enter operation (+, -, *): ";
    cin >> operation;

    switch (operation) {
        case '+':
            cout << "Result = " << firstNumber + secondNumber << endl;
            break;

        case '-':
            cout << "Result = " << firstNumber - secondNumber << endl;
            break;

        case '*':
            cout << "Result = " << firstNumber * secondNumber << endl;
            break;

        default:
            cout << "Invalid operation." << endl;
    }

    return 0;
}
