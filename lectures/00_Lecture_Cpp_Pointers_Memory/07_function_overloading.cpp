// Slides 19-22: function overloading and static binding.

#include <iostream>
#include <string>

using namespace std;

void show() {
    cout << "show(): no argument\n";
}

void show(const string& text) {
    cout << "show(string): " << text << '\n';
}

void show(int value) {
    cout << "show(int): " << value << '\n';
}

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

void changeByValue(int value) {
    value = 100;
    cout << "Inside changeByValue: " << value << '\n';
}

void changeByReference(int& value) {
    value = 100;
    cout << "Inside changeByReference: " << value << '\n';
}

int main() {
    show();
    show("hello");
    show(225);

    cout << "add(int, int): " << add(10, 20) << '\n';
    cout << "add(double, double): " << add(10.5, 20.25) << '\n';

    int number = 5;
    changeByValue(number);
    cout << "After changeByValue: " << number << '\n';

    changeByReference(number);
    cout << "After changeByReference: " << number << '\n';

    return 0;
}
