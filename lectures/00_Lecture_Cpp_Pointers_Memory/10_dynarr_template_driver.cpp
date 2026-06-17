// Slide 32: driver file for the template dynamic array.

#include "10_dynarr_template.cpp"

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    dynArr<int> di(10);
    dynArr<double> dd(10);

    for (int i = 0; i < 10; ++i) {
        di.setValue(i, 3 * i + 1);
        dd.setValue(i, 7.29 * i / 1.45);
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < 10; ++i) {
        cout << di.getValue(i) << " " << dd.getValue(i) << '\n';
    }

    dynArr<double> copied = dd;
    copied.setValue(0, 99.99);

    cout << "Original double first value after copy edit: " << dd.getValue(0) << '\n';
    cout << "Copied double first value: " << copied.getValue(0) << '\n';

    return 0;
}
