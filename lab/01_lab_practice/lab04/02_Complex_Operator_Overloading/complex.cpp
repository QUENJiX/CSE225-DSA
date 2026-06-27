/*
===============================================================================
CSE225L Lab 4 - Task 2: Complex Operator Definitions
File: complex.cpp
===============================================================================

ALGORITHM: Implement Complex operator* and operator!=
Input:  Left object = this, right object = parameter a
Output: Product object for *, true/false result for !=

Complex multiplication formula:
    (a + bi)(c + di) = (ac - bd) + (ad + bc)i

1. operator+:
   a. Create temporary Complex t.
   b. Add real parts.
   c. Add imaginary parts.
   d. Return t.
2. operator*:
   a. Create temporary Complex t.
   b. t.real = real * a.real - imaginary * a.imaginary.
   c. t.imaginary = real * a.imaginary + imaginary * a.real.
   d. Return t.
3. operator!=:
   a. Return true if real parts differ OR imaginary parts differ.
   b. Otherwise return false.
4. Print():
   a. Display real and imaginary fields.

PSEUDOCODE:
operator*(a)
    CREATE t
    t.real <- real * a.real - imaginary * a.imaginary
    t.imaginary <- real * a.imaginary + imaginary * a.real
    RETURN t

operator!=(a)
    IF real != a.real OR imaginary != a.imaginary THEN
        RETURN true
    ELSE
        RETURN false
    END IF
===============================================================================
*/

#include "complex.h"
#include <iostream>
using namespace std;

Complex::Complex() {
    real = 0;
    imaginary = 0;
}

Complex::Complex(double r, double i) {
    real = r;
    imaginary = i;
}

Complex Complex::operator+(Complex a) {
    Complex t;
    t.real = real + a.real;
    t.imaginary = imaginary + a.imaginary;
    return t;
}

Complex Complex::operator*(Complex a) {
    Complex t;
    t.real = (real * a.real) - (imaginary * a.imaginary);
    t.imaginary = (real * a.imaginary) + (imaginary * a.real);
    return t;
}

bool Complex::operator!=(Complex a) {
    return real != a.real || imaginary != a.imaginary;
}

void Complex::Print() {
    cout << "Real: " << real << ", Imaginary: " << imaginary << endl;
}
