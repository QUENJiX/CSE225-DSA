#include "stacktype.h"
#include <iostream>

using namespace std;

template <class T>
StackType<T>::StackType() {
    data = new T[SIZE];
    top = -1;
}

template <class T>
StackType<T>::~StackType() {
    delete[] data;
}

template <class T>
bool StackType<T>::IsEmpty() {
    return top == -1;
}

template <class T>
bool StackType<T>::IsFull() {
    return top == SIZE - 1;
}

template <class T>
void StackType<T>::Push(T value) {
    try {
        if (IsFull()) {
            throw FullStack();
        }

        top++;
        data[top] = value;
    }
    catch (FullStack error) {
        cout << "Error: Stack is full" << endl;
    }
}

template <class T>
void StackType<T>::Pop() {
    try {
        if (IsEmpty()) {
            throw EmptyStack();
        }

        top--;
    }
    catch (EmptyStack error) {
        cout << "Error: Stack is empty" << endl;
    }
}

template <class T>
T StackType<T>::Top() {
    if (IsEmpty()) {
        throw EmptyStack();
    }

    return data[top];
}
