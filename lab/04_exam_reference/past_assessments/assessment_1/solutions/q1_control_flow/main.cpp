/*
    EXAM PATTERN 1 - one input, branch, print a sequence
    Maps to: Assessment 1, Question 1.

    Read N, then EXACTLY ONE branch runs (if / else-if chain, top wins):
      - N divisible by 4 -> print squares of 1..N
      - else if divisible by 6 -> print odd numbers 1..N
      - else if divisible by 9 -> print sum of 1..N
      - else -> "Invalid Category"

    HOW TO ADAPT: swap the conditions (% test, >, <, ranges) and swap the
    body of each branch (squares / odds / evens / sum / product / count...).

    TRAP: order matters. 12 is divisible by BOTH 4 and 6 -> the 4 branch wins
    because it is checked first. Put the intended-priority test on top.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    if (n % 4 == 0) {
        // squares of 1..N
        for (int i = 1; i <= n; i++) {
            cout << i * i << " ";
        }
        cout << endl;
    } else if (n % 6 == 0) {
        // odd numbers 1..N
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    } else if (n % 9 == 0) {
        // sum of 1..N
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        cout << sum << endl;
    } else {
        cout << "Invalid Category" << endl;
    }

    return 0;
}
