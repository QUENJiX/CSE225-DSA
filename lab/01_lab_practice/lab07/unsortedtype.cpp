#include "unsortedtype.h"
#include <iostream>

using namespace std;

template <class T>
UnsortedType<T>::UnsortedType() {
    head = NULL;
    pointTo = NULL;
    size = 0;
}

template <class T>
UnsortedType<T>::~UnsortedType() {
    MakeEmpty();
}

template <class T>
int UnsortedType<T>::Length() {
    return size;
}

template <class T>
void UnsortedType<T>::Insert(T value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
    size++;
}

template <class T>
void UnsortedType<T>::Search(T value, bool& found) {
    found = false;
    Node* current = head;

    while (current != NULL) {
        if (value == current->data) {
            found = true;
            break;
        }

        current = current->next;
    }
}

template <class T>
void UnsortedType<T>::Delete(T value) {
    bool found = false;
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        if (value == current->data) {
            found = true;
            break;
        }

        previous = current;
        current = current->next;
    }

    if (found) {
        if (previous == NULL) {
            head = current->next;
        }
        else {
            previous->next = current->next;
        }

        delete current;
        size--;
    }
    else {
        cout << "Error: Item could not be found in the list" << endl;
    }
}

template <class T>
void UnsortedType<T>::MakeEmpty() {
    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = NULL;
    pointTo = NULL;
    size = 0;
}

template <class T>
void UnsortedType<T>::GetNext(T& value) {
    if (pointTo == NULL) {
        pointTo = head;
    }

    value = pointTo->data;
    pointTo = pointTo->next;
}

template <class T>
void UnsortedType<T>::Reset() {
    pointTo = NULL;
}
