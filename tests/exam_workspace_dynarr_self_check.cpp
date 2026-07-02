#include <cassert>
#include <string>
#include "solution.h"
#include "solution.cpp"
using namespace std;

int main() {
    dynArr<int> empty;
    assert(empty.getSize() == 0);
    assert(empty.isEmpty());

    empty.allocate(-4);
    assert(empty.getSize() == 0);
    assert(empty.getValue(0) == 0);

    dynArr<int> numbers;
    numbers.allocate(3);
    numbers.setValue(0, 10);
    numbers.setValue(1, 20);
    numbers.setValue(2, 30);
    numbers.setValue(-1, 99);
    numbers.setValue(3, 99);
    assert(numbers.getValue(0) == 10);
    assert(numbers.getValue(1) == 20);
    assert(numbers.getValue(2) == 30);

    dynArr<int> copied(numbers);
    copied.setValue(0, 111);
    assert(numbers.getValue(0) == 10);
    assert(copied.getValue(0) == 111);

    dynArr<int> assigned;
    assigned = numbers;
    assigned.setValue(1, 222);
    assert(numbers.getValue(1) == 20);
    assert(assigned.getValue(1) == 222);

    numbers.clear();
    assert(numbers.isEmpty());
    assert(numbers.getSize() == 0);

    dynArr<string> names(2);
    names.setValue(0, "A");
    assert(names.getValue(0) == "A");
    assert(names.getValue(9) == "");

    return 0;
}
