#include "sortedtype.h"
#include <iostream>
using namespace std;

template <class T>
SortedType<T>::SortedType() {
    data = new T[SORTED_CAPACITY];
    currentSize = 0;
    pointTo = -1;
}

template <class T>
SortedType<T>::~SortedType() {
    delete[] data;
}

template <class T>
int SortedType<T>::Length() const {
    return currentSize;
}

template <class T>
bool SortedType<T>::IsFull() const {
    return currentSize == SORTED_CAPACITY;
}

template <class T>
bool SortedType<T>::IsEmpty() const {
    return currentSize == 0;
}

template <class T>
void SortedType<T>::MakeEmpty() {
    currentSize = 0;
    pointTo = -1;
}

template <class T>
void SortedType<T>::Insert(const T& value) {
    if (IsFull()) {
        cout << "Error: List is full" << endl;
        return;
    }

    int location = 0;
    while (location < currentSize && data[location] < value) {
        location++;
    }

    for (int i = currentSize; i > location; i--) {
        data[i] = data[i - 1];
    }

    data[location] = value;
    currentSize++;
}

template <class T>
void SortedType<T>::Search(const T& value, bool& found) const {
    int first = 0;
    int last = currentSize - 1;
    found = false;

    while (first <= last) {
        int middle = (first + last) / 2;

        if (value < data[middle]) {
            last = middle - 1;
        } else if (value > data[middle]) {
            first = middle + 1;
        } else {
            found = true;
            return;
        }
    }
}

template <class T>
void SortedType<T>::Delete(const T& value) {
    int location = 0;
    while (location < currentSize && !(data[location] == value)) {
        location++;
    }

    if (location == currentSize) {
        cout << "Error: Item could not be found in the list" << endl;
        return;
    }

    for (int i = location; i < currentSize - 1; i++) {
        data[i] = data[i + 1];
    }

    currentSize--;
    pointTo = -1;
}

template <class T>
void SortedType<T>::GetNext(T& value) {
    if (IsEmpty()) {
        cout << "Error: List is empty" << endl;
        return;
    }

    if (pointTo + 1 >= currentSize) {
        pointTo = -1;
    }

    pointTo++;
    value = data[pointTo];
}

template <class T>
void SortedType<T>::Reset() {
    pointTo = -1;
}
