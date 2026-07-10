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
