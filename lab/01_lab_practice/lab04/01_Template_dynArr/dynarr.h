/*
===============================================================================
CSE225L Lab 4 - Task 1: Template dynArr<T>
File: dynarr.h
===============================================================================

ALGORITHM: Convert int-only dynArr into a generic template class
Input:  size s and values of any type T
Output: A dynamic array object that can store values of type T

1. Declare a template class using template <class T>.
2. Keep a private pointer T* data to hold the heap array.
3. Keep an int size because size counts elements, not element type.
4. Default constructor:
   a. Set data to NULL.
   b. Set size to 0.
5. Parameterized constructor:
   a. If s <= 0, create an empty object.
   b. Otherwise allocate data = new T[s].
   c. Store size = s.
6. setValue(index, value):
   a. If index is valid, store value in data[index].
7. getValue(index):
   a. If index is valid, return data[index].
   b. Otherwise return T(), the default value for type T.
8. getSize():
   a. Return size.
9. Destructor:
   a. Release heap memory using delete[] data.

PSEUDOCODE:
Class dynArr<T>
    Private:
        T* data
        int size

    Constructor dynArr()
        data <- NULL
        size <- 0

    Constructor dynArr(s)
        IF s <= 0 THEN
            data <- NULL
            size <- 0
        ELSE
            data <- new T array of length s
            size <- s
        END IF

    setValue(index, value)
        IF index >= 0 AND index < size THEN
            data[index] <- value
        END IF

    getValue(index)
        IF index >= 0 AND index < size THEN
            RETURN data[index]
        END IF
        RETURN T()

    getSize()
        RETURN size

    Destructor
        delete[] data

NOTE:
Template definitions are kept in this header file because the compiler must see
method bodies when it creates dynArr<int>, dynArr<double>, etc.
===============================================================================
*/

#ifndef DYNARR_H
#define DYNARR_H

#include <iostream>
using namespace std;

template <class T>
class dynArr {
   private:
    T* data;
    int size;

   public:
    dynArr();
    dynArr(int s);
    ~dynArr();

    void setValue(int index, T value);
    T getValue(int index) const;
    int getSize() const;
};

template <class T>
dynArr<T>::dynArr() {
    data = nullptr;
    size = 0;
}

template <class T>
dynArr<T>::dynArr(int s) {
    if (s <= 0) {
        data = nullptr;
        size = 0;
    } else {
        data = new T[s];
        size = s;
    }
}

template <class T>
dynArr<T>::~dynArr() {
    delete[] data;
}

template <class T>
void dynArr<T>::setValue(int index, T value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}

template <class T>
T dynArr<T>::getValue(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return T();
}

template <class T>
int dynArr<T>::getSize() const {
    return size;
}

#endif  // DYNARR_H
