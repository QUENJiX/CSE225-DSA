#include <iostream>
using namespace std;

int main() {
    int a, b;
    char operation;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Choose operation (+, -, *): ";
    cin >> operation;

    switch (operation) {
        case '+':
            cout << "Result = " << a + b << endl;
            break;
        case '-':
            cout << "Result = " << a - b << endl;
            break;
        case '*':
            cout << "Result = " << a * b << endl;
            break;
        default:
            cout << "Invalid operation." << endl;
    }
    return 0;
}
