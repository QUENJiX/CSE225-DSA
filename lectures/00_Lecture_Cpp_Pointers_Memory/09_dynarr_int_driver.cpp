// Slide 36: driver file for the integer dynamic array.

#include "09_dynarr_int.h"

#include <iostream>

using namespace std;

int main() {
    dynArr d(10);

    for (int i = 0; i < d.getSize(); ++i) {
        d.setValue(i, 3 * i + 1);
    }

    for (int i = 0; i < d.getSize(); ++i) {
        cout << d.getValue(i) << '\n';
    }

    dynArr copied = d;
    copied.setValue(0, 999);

    cout << "Original first value after copy edit: " << d.getValue(0) << '\n';
    cout << "Copied first value: " << copied.getValue(0) << '\n';

    return 0;
}
