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
