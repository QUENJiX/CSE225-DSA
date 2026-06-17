// Slides 5, 9-10: class declaration, object creation, and member functions.

#include <iostream>

using namespace std;

class Box {
private:
    double length;
    double width;
    double height;

public:
    Box(double boxLength, double boxWidth, double boxHeight)
        : length(boxLength), width(boxWidth), height(boxHeight) {}

    double volume() const {
        return length * width * height;
    }

    void resize(double boxLength, double boxWidth, double boxHeight) {
        length = boxLength;
        width = boxWidth;
        height = boxHeight;
    }
};

int main() {
    Box smallBox(2.0, 3.0, 4.0);
    cout << "Small box volume: " << smallBox.volume() << '\n';

    Box anotherBox(5.5, 2.0, 3.0);
    cout << "Another box volume: " << anotherBox.volume() << '\n';

    anotherBox.resize(10.0, 4.0, 2.0);
    cout << "After resize: " << anotherBox.volume() << '\n';

    return 0;
}
