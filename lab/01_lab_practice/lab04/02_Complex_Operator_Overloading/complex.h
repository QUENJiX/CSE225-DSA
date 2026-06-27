/*
===============================================================================
CSE225L Lab 4 - Task 2: Complex Operator Overloading
File: complex.h
===============================================================================

ALGORITHM: Declare a Complex class with overloaded operators
Input:  Real and imaginary values for complex number objects
Output: Objects that can use +, *, !=, and Print()

1. Store real and imaginary parts privately.
2. Provide a default constructor for 0 + 0i.
3. Provide a parameterized constructor for r + i*i.
4. Declare operator+ to add two complex numbers.
5. Declare operator* to multiply two complex numbers.
6. Declare operator!= to compare two complex numbers.
7. Declare Print() to display a complex number.

PSEUDOCODE:
Class Complex
    Private:
        double real
        double imaginary

    Public:
        Constructor Complex()
        Constructor Complex(r, i)
        operator+(Complex a) returns Complex
        operator*(Complex a) returns Complex
        operator!=(Complex a) returns bool
        Print()
===============================================================================
*/

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    double real, imaginary;

public:
    Complex();
    Complex(double r, double i);

    Complex operator+(Complex a);
    Complex operator*(Complex a);
    bool operator!=(Complex a);

    void Print();
};

#endif // COMPLEX_H
