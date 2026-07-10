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
