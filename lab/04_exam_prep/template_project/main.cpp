/*
    CSE225L Exam Template - driver for the dynArr class

    Shows the typical things a driver does:
      - construct, fill, resize, read back
      - exercise the copy constructor / assignment (proves deep copy works)

    Build & run:
        g++ -std=c++17 -Wall main.cpp dynarr.cpp -o app
        ./app
*/

#include <iostream>
#include "dynarr.h"
using namespace std;

int main() {
    dynArr a(5);
    for (int i = 0; i < a.getSize(); i++) {
        a.setValue(i, (i + 1) * 10);   // 10 20 30 40 50
    }

    a.allocate(8);                     // grow; old values survive, rest are 0
    for (int i = 5; i < 8; i++) {
        a.setValue(i, (i + 1) * 10);   // 60 70 80
    }

    cout << "a: ";
    for (int i = 0; i < a.getSize(); i++) {
        cout << a.getValue(i) << " ";
    }
    cout << endl;

    // Copy constructor: b is an independent deep copy of a.
    dynArr b = a;
    b.setValue(0, -1);                 // changing b must NOT affect a

    cout << "b (copy, b[0] changed): ";
    for (int i = 0; i < b.getSize(); i++) {
        cout << b.getValue(i) << " ";
    }
    cout << endl;

    cout << "a (unchanged): ";
    for (int i = 0; i < a.getSize(); i++) {
        cout << a.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
