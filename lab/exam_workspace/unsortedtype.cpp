#include "unsortedtype.h"
#include <iostream>
using namespace std;

template <class T>
UnsortedType<T>::UnsortedType() {
    data = new T[UNSORTED_CAPACITY];
    currentSize = 0;
    pointTo = -1;
}

template <class T>
UnsortedType<T>::~UnsortedType() {
    delete[] data;
}

template <class T>
int UnsortedType<T>::Length() {
    return currentSize;
}

template <class T>
bool UnsortedType<T>::IsFull() {
    return currentSize == UNSORTED_CAPACITY;
}

template <class T>
bool UnsortedType<T>::IsEmpty() {
    return currentSize == 0;
}

template <class T>
void UnsortedType<T>::MakeEmpty() {
    currentSize = 0;
    pointTo = -1;
}

template <class T>
void UnsortedType<T>::Insert(const T& value) {
    if (IsFull()) {
        cout << "Error: List is full" << endl;
        return;
    }

    data[currentSize] = value;
    currentSize++;
}

template <class T>
void UnsortedType<T>::Search(const T& value, bool& found) const {
    found = false;

    for (int i = 0; i < currentSize; i++) {
        if (data[i] == value) {
            found = true;
            return;
        }
    }
}

template <class T>
void UnsortedType<T>::Delete(const T& value) {
    if (IsEmpty()) {
        cout << "Error: List is empty" << endl;
        return;
    }

    int location = 0;
    while (location < currentSize && !(data[location] == value)) {
        location++;
    }

    if (location == currentSize) {
        cout << "Error: Item could not be found in the list" << endl;
        return;
    }

    data[location] = data[currentSize - 1];
    currentSize--;

    if (pointTo >= currentSize) {
        pointTo = -1;
    }
}

template <class T>
void UnsortedType<T>::GetNext(T& value) {
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
void UnsortedType<T>::Reset() {
    pointTo = -1;
}
