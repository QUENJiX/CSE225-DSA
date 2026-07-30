#include "stacktype.h"

#include <iostream>
#include <new>

using namespace std;

template <class T>
StackType<T>::StackType() {
    head = NULL;
}

template <class T>
StackType<T>::~StackType() {
    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <class T>
bool StackType<T>::IsEmpty() {
    return head == NULL;
}

template <class T>
bool StackType<T>::IsFull() {
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
void StackType<T>::Push(T value) {
    if (IsFull()) {
        throw FullStack();
    }

    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
}

template <class T>
void StackType<T>::Pop() {
    if (IsEmpty()) {
        throw EmptyStack();
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

template <class T>
T StackType<T>::Top() {
    if (IsEmpty()) {
        throw EmptyStack();
    }

    return head->data;
}

template <class T>
void StackType<T>::Diagnose() {
    Node* current = head;

    while (current != NULL) {
        cout << "self: " << current
             << ", data: " << current->data
             << ", next: " << current->next
             << endl;
        current = current->next;
    }
}
