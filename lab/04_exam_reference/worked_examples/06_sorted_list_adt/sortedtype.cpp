#include "sortedtype.h"
#include <iostream>
using namespace std;

template <class T>
SortedType<T>::SortedType() {
    data = new T[SIZE];
    currentSize = 0;
    pointTo = -1;
}

template <class T>
SortedType<T>::~SortedType() {
    delete[] data;
}

template <class T>
int SortedType<T>::Length() {
    return currentSize;
}

template <class T>
bool SortedType<T>::IsFull() {
    return currentSize == SIZE;
}

template <class T>
bool SortedType<T>::IsEmpty() {
    return currentSize == 0;
}

template <class T>
void SortedType<T>::MakeEmpty() {
    currentSize = 0;
    pointTo = -1;
}

template <class T>
void SortedType<T>::Insert(T value) {
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
void SortedType<T>::Search(T value, bool& found) {
    found = false;

    int first = 0;
    int last = currentSize - 1;

    while (first <= last) {
        int midPoint = (first + last) / 2;

        if (data[midPoint] == value) {
            found = true;
            return;
        }

        if (value < data[midPoint]) {
            last = midPoint - 1;
        } else {
            first = midPoint + 1;
        }
    }
}

template <class T>
void SortedType<T>::Delete(T value) {
    if (IsEmpty()) {
        cout << "Error: List is empty" << endl;
        return;
    }

    int location = 0;
    while (location < currentSize && data[location] < value) {
        location++;
    }

    if (location == currentSize || !(data[location] == value)) {
        cout << "Error: Item could not be found in the list" << endl;
        return;
    }

    for (int i = location; i < currentSize - 1; i++) {
        data[i] = data[i + 1];
    }

    currentSize--;
    if (pointTo >= currentSize) {
        pointTo = -1;
    }
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
