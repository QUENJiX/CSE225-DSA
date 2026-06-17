// Slides 24-27: generic functions and explicit overloads.

#include <iostream>

using namespace std;

template <class X>
void swapargs(X& a, X& b) {
    cout << "template version\n";
    X temp = a;
    a = b;
    b = temp;
}

void swapargs(int& a, int& b) {
    cout << "int overload version\n";
    int temp = a;
    a = b;
    b = temp;
}

template <class X1, class X2>
void printValues(const X1& x, const X2& y) {
    cout << x << ", " << y << '\n';
}

int main() {
    int i = 10;
    int j = 20;
    double x = 11.11;
    double y = 22.22;

    printValues(i, j);
    swapargs(i, j);
    printValues(i, j);

    printValues(x, y);
    swapargs(x, y);
    printValues(x, y);

    printValues(i, y);

    return 0;
}
