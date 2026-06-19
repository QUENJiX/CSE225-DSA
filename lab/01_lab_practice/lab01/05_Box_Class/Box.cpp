/*
Algorithm: Box Constructor and volume()
Source: CSE225L Lab 1, OOP Task

Input:
    Constructor receives h, w, d.
Output:
    volume() prints height * width * depth.

Pseudocode:
    Constructor Box(h, w, d):
        1. Store h in height.
        2. Store w in width.
        3. Store d in depth.

    volume():
        1. Calculate result = height * width * depth.
        2. Print result.

Complexity:
    Time: O(1) per object
    Space: O(1) per object
*/

#include <iostream>
#include "Box.h"
using namespace std;

Box::Box(double h, double w, double d) {
    height = h;
    width = w;
    depth = d;
}

void Box::volume() const {
    double result = height * width * depth;
    cout << "Volume = " << result << endl;
}
