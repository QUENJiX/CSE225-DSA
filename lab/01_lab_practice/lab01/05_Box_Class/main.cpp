#include <iostream>
#include "Box.h"
using namespace std;

int main() {
    Box smallBox(2, 3, 4);
    Box tallBox(5, 2, 3);
    Box wideBox(1.5, 4, 2);

    cout << "Small box: ";
    smallBox.volume();

    cout << "Tall box: ";
    tallBox.volume();

    cout << "Wide box: ";
    wideBox.volume();

    return 0;
}
