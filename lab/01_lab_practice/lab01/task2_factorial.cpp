#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 0;
    }

    long long factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    cout << "Factorial of " << n << " = " << factorial << endl;
    return 0;
}
