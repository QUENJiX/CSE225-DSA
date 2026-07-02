#include <iostream>
#include "box.h"
using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void printPrimes(int start, int finish) {
    for (int n = start; n <= finish; n++) {
        if (isPrime(n)) {
            cout << n << " ";
        }
    }
    cout << endl;
}

double calculate(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/' && b != 0) return a / b;
    return 0;
}

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Sum: " << a + b << endl;

    int n;
    cout << "Enter n for factorial: ";
    cin >> n;
    cout << "Factorial: " << factorial(n) << endl;

    double x, y;
    char op;
    cout << "Enter expression (a op b): ";
    cin >> x >> op >> y;
    cout << "Result: " << calculate(x, y, op) << endl;

    cout << "Primes from 300 to 500:" << endl;
    printPrimes(300, 500);

    Box box1;
    Box box2(3, 4, 5);

    box1.setInfo(2, 3, 4);

    cout << "Box 1 volume: " << box1.volume() << endl;
    cout << "Box 2 volume: " << box2.volume() << endl;

    return 0;
}
