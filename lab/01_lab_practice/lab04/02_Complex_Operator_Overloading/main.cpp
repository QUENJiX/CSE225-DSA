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
