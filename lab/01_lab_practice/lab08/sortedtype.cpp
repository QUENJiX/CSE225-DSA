#include "sortedtype.h"
#include <iostream>

using namespace std;

template <class T>
SortedType<T>::SortedType() {
    head = NULL;
    pointTo = NULL;
    size = 0;
}

template <class T>
SortedType<T>::~SortedType() {
    MakeEmpty();
}

template <class T>
int SortedType<T>::Length() {
    return size;
}

template <class T>
void SortedType<T>::Insert(T value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    }
    else if (value < head->data) {
        temp->next = head;
        head = temp;
    }
    else {
        Node* current = head;
        Node* previous = NULL;

        while (current != NULL && value > current->data) {
            previous = current;
            current = current->next;
        }

        temp->next = current;
        previous->next = temp;
    }

    size++;
}

template <class T>
void SortedType<T>::Search(T value, bool& found) {
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
void SortedType<T>::Delete(T value) {
    Node* current = head;
    Node* previous = NULL;
    bool found = false;

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
void SortedType<T>::MakeEmpty() {
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
void SortedType<T>::GetNext(T& value) {
    if (pointTo == NULL) {
        pointTo = head;
    }

    value = pointTo->data;
    pointTo = pointTo->next;
}

template <class T>
void SortedType<T>::Reset() {
    pointTo = NULL;
}
