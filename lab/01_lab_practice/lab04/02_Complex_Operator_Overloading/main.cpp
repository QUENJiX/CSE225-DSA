/*
===============================================================================
CSE225L Lab 4 - Task 2: Test Complex Operators
File: main.cpp
===============================================================================

ALGORITHM: Demonstrate overloaded * and != operators
Input:  Two hardcoded Complex objects
Output: Printed complex numbers, product, and equality result

1. Create Complex c1(2, 3).
2. Create Complex c2(4, -1).
3. Print both objects using Print().
4. Compute Complex product = c1 * c2.
5. Print product.
6. Test c1 != c2.
7. If true, print that the two complex numbers are not equal.
8. Otherwise, print that they are equal.

PSEUDOCODE:
CREATE c1 as Complex(2, 3)
CREATE c2 as Complex(4, -1)
PRINT c1
PRINT c2

product <- c1 * c2
PRINT product

IF c1 != c2 THEN
    PRINT "not equal"
ELSE
    PRINT "equal"
END IF

Expected product:
(2 + 3i)(4 - 1i) = 11 + 10i
===============================================================================
*/

#include <iostream>
#include "complex.h"
using namespace std;

int main() {
    Complex c1(2, 3);
    Complex c2(4, -1);

    cout << "First complex number: ";
    c1.Print();

    cout << "Second complex number: ";
    c2.Print();

    Complex product = c1 * c2;
    cout << "Product: ";
    product.Print();

    if (c1 != c2) {
        cout << "The two complex numbers are not equal." << endl;
    } else {
        cout << "The two complex numbers are equal." << endl;
    }

    return 0;
}
