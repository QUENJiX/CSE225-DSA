// Slides 3-4: C++ console input/output compared with C-style I/O.

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int count = 42;
    double price = 100.99;

    cout << "Hello World!" << '\n';
    printf("Hello World!\n");

    cout << "cout prints int: " << count << '\n';
    printf("printf prints int: %d\n", count);

    cout << "cout prints double: " << price << '\n';
    printf("printf prints double: %.2f\n", price);

    string name;
    int inputCount;
    float value;

    cout << "\nEnter name, count, and value: ";
    if (cin >> name >> inputCount >> value) {
        cout << "cin captured: " << name << ", " << inputCount << ", " << value << '\n';
        printf("printf can print them too: %s, %d, %.2f\n", name.c_str(), inputCount, value);
    } else {
        cout << "No complete input received.\n";
    }

    return 0;
}
