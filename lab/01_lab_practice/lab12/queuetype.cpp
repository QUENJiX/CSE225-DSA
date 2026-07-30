#include "queuetype.h"

#include <new>

using namespace std;

template <class T>
QueueType<T>::QueueType() {
    front = NULL;
    rear = NULL;
}

template <class T>
QueueType<T>::~QueueType() {
    MakeEmpty();
}

template <class T>
bool QueueType<T>::IsEmpty() {
    return front == NULL;
}

template <class T>
bool QueueType<T>::IsFull() {
    try {
        Node* temp = new Node;
        delete temp;
        return false;
    }
    catch (const bad_alloc&) {
        return true;
    }
}

template <class T>
void QueueType<T>::Enqueue(T value) {
    if (IsFull()) {
        throw FullQueue();
    }

    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (rear == NULL) {
        front = temp;
    }
    else {
        rear->next = temp;
    }

    rear = temp;
}

template <class T>
void QueueType<T>::Dequeue(T& value) {
    if (IsEmpty()) {
        throw EmptyQueue();
    }

    Node* temp = front;
    value = front->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

template <class T>
void QueueType<T>::MakeEmpty() {
    while (front != NULL) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    rear = NULL;
}
