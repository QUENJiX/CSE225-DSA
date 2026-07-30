#include "recursion.h"

#include <stdexcept>

int fib(int n) {
    if (n < 0) {
        throw std::invalid_argument("Fibonacci index cannot be negative");
    }

    if (n <= 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial input cannot be negative");
    }

    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

int sumOfDigits(int x) {
    if (x < 0) {
        return sumOfDigits(-x);
    }

    if (x < 10) {
        return x;
    }

    return x % 10 + sumOfDigits(x / 10);
}

int findMin(int a[], int size) {
    if (size <= 0) {
        throw std::invalid_argument("Array size must be positive");
    }

    if (size == 1) {
        return a[0];
    }

    int minimumOfRest = findMin(a + 1, size - 1);
    return a[0] < minimumOfRest ? a[0] : minimumOfRest;
}

int DecToBin(int dec) {
    if (dec < 0) {
        throw std::invalid_argument("Decimal input cannot be negative");
    }

    if (dec < 2) {
        return dec;
    }

    return DecToBin(dec / 2) * 10 + dec % 2;
}

double sumSeries(int n) {
    if (n < 0) {
        throw std::invalid_argument("Series index cannot be negative");
    }

    if (n == 0) {
        return 1.0;
    }

    return 1.0 + sumSeries(n - 1) / 2.0;
}
