#include <iostream>
#include "dynarr.h"
using namespace std;

int main() {
    dynArr numbers(5);

    cout << "Enter 5 values: ";
    for (int i = 0; i < 5; i++) {
        int value;
        cin >> value;
        numbers.setValue(i, value);
    }

    numbers.allocate(8);

    cout << "After resizing to 8, enter 3 more values: ";
    for (int i = 5; i < 8; i++) {
        int value;
        cin >> value;
        numbers.setValue(i, value);
    }

    cout << "Array values: ";
    for (int i = 0; i < numbers.getSize(); i++) {
        cout << numbers.getValue(i) << " ";
    }

    cout << endl;

    return 0;
}
