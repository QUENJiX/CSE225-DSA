/*
Algorithm: Box Driver Program
Source: CSE225L Lab 1, OOP Task

Input:
    No user input. The program creates Box objects with fixed dimensions.
Output:
    Volumes of multiple Box objects

Pseudocode:
    1. Include iostream and Box.h.
    2. Create smallBox with dimensions 2, 3, 4.
    3. Create tallBox with dimensions 5, 2, 3.
    4. Create wideBox with dimensions 1.5, 4, 2.
    5. Print a label for each object.
    6. Call volume() for each object.

Complexity:
    Time: O(m) for m Box objects
    Space: O(m) for m Box objects
*/

#include <iostream>
#include "Box.h"
using namespace std;

int main() {
    Box smallBox(2, 3, 4);
    Box tallBox(5, 2, 3);
    Box wideBox(1.5, 4, 2);

    cout << "Small box: ";
    smallBox.volume();

    cout << "Tall box: ";
    tallBox.volume();

    cout << "Wide box: ";
    wideBox.volume();

    return 0;
}
