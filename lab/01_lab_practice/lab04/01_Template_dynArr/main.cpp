#include <iostream>
#include "dynarr.h"
using namespace std;

int main() {
    dynArr<int> numbers(5);

    cout << "Enter 5 integer values: ";
    for (int i = 0; i < numbers.getSize(); i++) {
        int value;
        cin >> value;
        numbers.setValue(i, value);
    }

    cout << "Integer array: ";
    for (int i = 0; i < numbers.getSize(); i++) {
        cout << numbers.getValue(i) << " ";
    }
    cout << endl;

    dynArr<double> marks(3);
    marks.setValue(0, 87.5);
    marks.setValue(1, 91.25);
    marks.setValue(2, 78.0);

    cout << "Double array: ";
    for (int i = 0; i < marks.getSize(); i++) {
        cout << marks.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
