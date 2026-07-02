/*
    Exam starter for Lab 3/4 style questions.

    Common swaps:
    - int -> double / char / string if the question changes the data type
    - dynArr<int> arr; arr.allocate(n); for default-constructor questions
    - dynArr<int> arr(n); for parameterized-constructor questions
    - Keep solution.cpp included because this is a template class.
*/

#include <iostream>
#include "solution.h"
#include "solution.cpp"
using namespace std;

template <class T>
void readValues(dynArr<T>& arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        T value;
        cin >> value;
        arr.setValue(i, value);
    }
}

template <class T>
void printValues(dynArr<T>& arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr.getValue(i) << " ";
    }
    cout << endl;
}

template <class T>
int countValue(dynArr<T>& arr, T target) {
    int count = 0;
    for (int i = 0; i < arr.getSize(); i++) {
        if (arr.getValue(i) == target) {
            count++;
        }
    }
    return count;
}

template <class T>
int findFirstIndex(dynArr<T>& arr, T target) {
    for (int i = 0; i < arr.getSize(); i++) {
        if (arr.getValue(i) == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    dynArr<int> values;
    values.allocate(n);

    if (values.isEmpty()) {
        cout << "No values" << endl;
        return 0;
    }

    readValues(values);

    int target;
    cin >> target;

    cout << "Values: ";
    printValues(values);
    cout << "Count: " << countValue(values, target) << endl;
    cout << "First index: " << findFirstIndex(values, target) << endl;

    dynArr<int> backup = values;
    values.clear();
    cout << "Backup size: " << backup.getSize() << endl;

    return 0;
}
