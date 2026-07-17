#include "queuetype.h"
#include <iostream>

using namespace std;

template <class T>
QueueType<T>::QueueType() {
    data = new T[SIZE];
    front = 0;
    rear = 0;
    size = SIZE;
}

template <class T>
QueueType<T>::QueueType(int requestedSize) {
    size = requestedSize + 1;
    data = new T[size];
    front = 0;
    rear = 0;
}

template <class T>
QueueType<T>::~QueueType() {
    delete[] data;
}

template <class T>
void QueueType<T>::MakeEmpty() {
    front = 0;
    rear = 0;
}

template <class T>
bool QueueType<T>::IsEmpty() {
    return front == rear;
}

template <class T>
bool QueueType<T>::IsFull() {
    return (rear + 1) % size == front;
}

template <class T>
void QueueType<T>::Enqueue(T value) {
    try {
        if (IsFull()) {
            throw FullQueue();
        }

        rear = (rear + 1) % size;
        data[rear] = value;
    }
    catch (FullQueue error) {
        cout << "Queue Overflow" << endl;
    }
}

template <class T>
void QueueType<T>::Dequeue(T& value) {
    try {
        if (IsEmpty()) {
            throw EmptyQueue();
        }

        front = (front + 1) % size;
        value = data[front];
    }
    catch (EmptyQueue error) {
        cout << "Queue Underflow" << endl;
    }
}
