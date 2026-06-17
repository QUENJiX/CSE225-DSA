// Slides 13-14: copy constructors and deep copy for dynamically allocated memory.

#include <algorithm>
#include <iostream>
#include <stdexcept>

using namespace std;

class IntArray {
private:
    int* data;
    int size;

    void checkIndex(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("index out of range");
        }
    }

public:
    explicit IntArray(int arraySize) : data(new int[arraySize]{}), size(arraySize) {}

    ~IntArray() {
        delete[] data;
    }

    IntArray(const IntArray& other) : data(new int[other.size]), size(other.size) {
        copy(other.data, other.data + other.size, data);
    }

    IntArray& operator=(const IntArray& other) {
        if (this == &other) {
            return *this;
        }

        int* newData = new int[other.size];
        copy(other.data, other.data + other.size, newData);
        delete[] data;
        data = newData;
        size = other.size;
        return *this;
    }

    void setValue(int index, int value) {
        checkIndex(index);
        data[index] = value;
    }

    int getValue(int index) const {
        checkIndex(index);
        return data[index];
    }
};

int main() {
    IntArray original(3);
    original.setValue(0, 10);
    original.setValue(1, 20);
    original.setValue(2, 30);

    IntArray copied = original;
    copied.setValue(0, 999);

    cout << "Original first value: " << original.getValue(0) << '\n';
    cout << "Copied first value: " << copied.getValue(0) << '\n';

    return 0;
}
