#include <iomanip>
#include <iostream>

#include "recursion.h"

using namespace std;

int main() {
    cout << "RECURSION TASKS" << endl;
    cout << "---------------" << endl;

    cout << "fib(10) = " << fib(10) << endl;
    cout << "factorial(5) = " << factorial(5) << endl;
    cout << "sumOfDigits(12345) = " << sumOfDigits(12345) << endl;

    int values[] = {8, 3, 11, -2, 7};
    int size = sizeof(values) / sizeof(values[0]);
    cout << "findMin({8, 3, 11, -2, 7}) = "
         << findMin(values, size)
         << endl;

    cout << "DecToBin(13) = " << DecToBin(13) << endl;
    cout << "sumSeries(4) = "
         << fixed << setprecision(4)
         << sumSeries(4)
         << endl;

    return 0;
}
