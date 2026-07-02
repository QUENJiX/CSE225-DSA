#include "box.h"

Box::Box() {
    height = 0;
    width = 0;
    depth = 0;
}

Box::Box(double h, double w, double d) {
    height = h;
    width = w;
    depth = d;
}

void Box::setInfo(double h, double w, double d) {
    height = h;
    width = w;
    depth = d;
}

double Box::volume() {
    return height * width * depth;
}
