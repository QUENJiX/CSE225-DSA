#include <bits/stdc++.h>
using namespace std;

int squareByValue(int x) {
    x *= x;
    return x;
}

void addBonusByReference(int& marks, int bonus) {
    marks += bonus;
}

void printVector(const vector<int>& values) {
    for (int value : values) {
        cout << value << ' ';
    }
    cout << '\n';
}

int sum(initializer_list<int> values) {
    int total = 0;
    for (int value : values) {
        total += value;
    }
    return total;
}

int main() {
    int n = 7;
    cout << "squareByValue(7): " << squareByValue(n) << '\n';
    cout << "n is still: " << n << '\n';

    int marks = 83;
    addBonusByReference(marks, 5);
    cout << "Marks after reference update: " << marks << '\n';

    vector<int> data = {3, 1, 4, 1, 5};
    cout << "Vector: ";
    printVector(data);

    auto isEven = [](int x) { return x % 2 == 0; };
    cout << "10 is even? " << boolalpha << isEven(10) << '\n';
    cout << "Sum: " << sum({1, 2, 3, 4, 5}) << '\n';

    return 0;
}
