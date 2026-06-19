/*
Algorithm: Factorial of an Integer
Source: CSE225L Lab 1, Task 2

Input:
    Integer n
Output:
    n! if n is non-negative, otherwise an error message

Pseudocode:
    1. Read n.
    2. If n < 0:
        a. Print that factorial is not defined for negative numbers.
        b. Stop normal factorial calculation.
    3. Set factorial = 1.
    4. For i from 2 to n:
        a. factorial = factorial * i.
    5. Print factorial.

Complexity:
    Time: O(n)
    Space: O(1)
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    unsigned long long factorial = 1;

    cout << "Enter an integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        for (int i = 2; i <= n; i++) {
            factorial = factorial * i;
        }

        cout << "Factorial of " << n << " = " << factorial << endl;
    }

    return 0;
}
