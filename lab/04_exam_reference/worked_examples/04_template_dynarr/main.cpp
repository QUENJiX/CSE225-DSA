#include <iostream>
#include "dynarr.h"
#include "dynarr.cpp"
using namespace std;

int main() {
    dynArr<int> numbers;
    numbers.allocate(5);

    for (int i = 0; i < numbers.getSize(); i++) {
        numbers.setValue(i, (i + 1) * 10);
    }
    numbers.setValue(-1, 999);
    numbers.setValue(10, 999);

    cout << "Integer array: ";
    for (int i = 0; i < numbers.getSize(); i++) {
        cout << numbers.getValue(i) << " ";
    }
    cout << endl;
    cout << "Invalid int read: " << numbers.getValue(10) << endl;

    dynArr<double> marks(3);
    marks.setValue(0, 87.5);
    marks.setValue(1, 90.0);
    marks.setValue(2, 76.5);

    cout << "Double array: ";
    for (int i = 0; i < marks.getSize(); i++) {
        cout << marks.getValue(i) << " ";
    }
    cout << endl;

    dynArr<double> copyMarks = marks;
    copyMarks.setValue(0, 100.0);
    cout << "Original first mark: " << marks.getValue(0) << endl;
    cout << "Copied first mark: " << copyMarks.getValue(0) << endl;

    marks.clear();
    cout << "Marks empty: " << (marks.isEmpty() ? "yes" : "no") << endl;

    return 0;
}
