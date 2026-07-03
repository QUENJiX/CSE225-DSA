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
    return SIZE == currentSize;
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
    while (location < currentSize && value > data[location]) {
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
    int first = 0;
    int last = currentSize - 1;
    found = false;

    while (first <= last) {
        int midPoint = (first + last) / 2;

        if (value < data[midPoint]) {
            last = midPoint - 1;
        } else if (value > data[midPoint]) {
            first = midPoint + 1;
        } else {
            found = true;
            break;
        }
    }
}

template <class T>
void SortedType<T>::Delete(T value) {
    bool found = false;
    int location = 0;

    while (location < currentSize) {
        if (data[location] == value) {
            found = true;
            break;
        }
        location++;
    }

    if (!found) {
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
    pointTo++;
    value = data[pointTo];
}

template <class T>
void SortedType<T>::Reset() {
    pointTo = -1;
}
