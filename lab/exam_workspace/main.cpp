/*
    Exam starter for Lab 3/4 style questions.

    Common swaps:
    - int -> double / char / string if the question changes the data type
    - dynArr<int> arr; arr.allocate(n); for default-constructor questions
    - dynArr<int> arr(n); for parameterized-constructor questions
*/

#include <iostream>
#include "solution.h"
#include "solution.cpp"
using namespace std;

int main() {
    int n;
    cin >> n;

    dynArr<int> arr;
    arr.allocate(n);

    for (int i = 0; i < arr.getSize(); i++) {
        int value;
        cin >> value;
        arr.setValue(i, value);
    }

    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
