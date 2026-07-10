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
}

template <class T>
void SortedType<T>::Insert(T value) {
    if (IsFull()) {
        cout << "Error: List is full" << endl;
    }
    else {
        int i = 0;

        // Find the position where value belongs.
        while (i < currentSize) {
            if (value > data[i]) {
                i++;
            }
            else {
                // Shift items right to create an empty position.
                for (int j = currentSize; j > i; j--) {
                    data[j] = data[j - 1];
                }

                break;
            }
        }

        data[i] = value;
        currentSize++;
    }
}

template <class T>
void SortedType<T>::Search(T value, bool& found) {
    int midPoint;
    int first = 0;
    int last = currentSize - 1;

    found = false;

    while (first <= last) {
        midPoint = (first + last) / 2;

        if (value < data[midPoint]) {
            last = midPoint - 1;
        }
        else if (value > data[midPoint]) {
            first = midPoint + 1;
        }
        else {
            found = true;
            value = data[midPoint];
            break;
        }
    }
}

template <class T>
void SortedType<T>::Delete(T value) {
    bool found = false;
    int i = 0;

    // Find the item.
    while (i < currentSize) {
        if (data[i] == value) {
            found = true;
            break;
        }

        i++;
    }

    if (found) {
        // Shift later items one position left.
        while (i < currentSize - 1) {
            data[i] = data[i + 1];
            i++;
        }

        currentSize--;
    }
    else {
        cout << "Error: Item could not be found in the list"
            << endl;
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
