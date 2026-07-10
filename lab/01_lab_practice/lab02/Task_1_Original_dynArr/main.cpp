#include <iostream>
#include "dynarr.h"
using namespace std;

int main() {
    dynArr emptyArray;
    dynArr numbers(5);

    int value;

    cout << "Enter 5 values: ";
    for (int i = 0; i < 5; i++) {
        cin >> value;
        numbers.setValue(i, value);
    }

    cout << "Stored values: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers.getValue(i) << " ";
    }

    cout << endl;

    return 0;
}
