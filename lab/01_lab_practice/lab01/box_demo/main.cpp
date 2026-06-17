#include <iostream>
#include "Box.h"
using namespace std;

int main() {
    Box smallBox(2, 3, 4);
    Box tallBox(5, 2, 6);
    Box cube(3, 3, 3);

    cout << "Small box: ";
    smallBox.volume();

    cout << "Tall box: ";
    tallBox.volume();

    cout << "Cube: ";
    cube.volume();

    return 0;
}

// To run: g++ main.cpp Box.cpp -o box_demo
// ./box_demo
