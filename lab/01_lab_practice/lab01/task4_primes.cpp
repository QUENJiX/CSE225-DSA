#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int divisor = 2; divisor * divisor <= n; divisor++) {
        if (n % divisor == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Prime numbers between 300 and 500:" << endl;
    for (int n = 300; n <= 500; n++) {
        if (isPrime(n)) {
            cout << n << " ";
        }
    }
    cout << endl;
    return 0;
}
