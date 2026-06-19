/*
Algorithm: isPrime(int n) and Print Primes from 300 to 500
Source: CSE225L Lab 1, Task 4

Input:
    No user input. The program checks numbers from 300 to 500.
Output:
    Prime numbers between 300 and 500, inclusive

Pseudocode:
    Function isPrime(n):
        1. If n < 2, return false.
        2. For divisor from 2 while divisor * divisor <= n:
            a. If n % divisor == 0, return false.
        3. Return true.

    main:
        1. Print heading.
        2. For number from 300 to 500:
            a. If isPrime(number) returns true, print number.
        3. Print a final newline.

Complexity:
    Single isPrime(n): O(sqrt(n)) time, O(1) space
    Range printing: O(k sqrt(n)) generally, O(1) extra space
*/

#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int divisor = 2; divisor * divisor <= n; divisor++) {
        if (n % divisor == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << "Prime numbers between 300 and 500:" << endl;

    for (int number = 300; number <= 500; number++) {
        if (isPrime(number)) {
            cout << number << " ";
        }
    }

    cout << endl;
    return 0;
}
