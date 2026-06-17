#include <bits/stdc++.h>
using namespace std;

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdRecursive(b, a % b);
}

long long powerFast(long long base, long long exponent) {
    if (exponent == 0) {
        return 1;
    }

    long long half = powerFast(base, exponent / 2);
    if (exponent % 2 == 0) {
        return half * half;
    }
    return half * half * base;
}

int sumVector(const vector<int>& values, int index) {
    if (index == static_cast<int>(values.size())) {
        return 0;
    }
    return values[index] + sumVector(values, index + 1);
}

int main() {
    vector<int> values = {2, 4, 6, 8};

    cout << "5! = " << factorial(5) << '\n';
    cout << "gcd(48, 18) = " << gcdRecursive(48, 18) << '\n';
    cout << "2^10 = " << powerFast(2, 10) << '\n';
    cout << "Recursive vector sum = " << sumVector(values, 0) << '\n';

    return 0;
}

