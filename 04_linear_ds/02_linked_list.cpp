#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void printList(Node* head) {
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->value;
        if (current->next != nullptr) {
            cout << " -> ";
        }
    }
    cout << '\n';
}

Node* reverseList(Node* head) {
    Node* previous = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    return previous;
}

int main() {
    Node first{10, nullptr};
    Node second{20, nullptr};
    Node third{30, nullptr};
    Node fourth{40, nullptr};

    first.next = &second;
    second.next = &third;
    third.next = &fourth;

    Node* head = &first;
    cout << "Original: ";
    printList(head);

    head = reverseList(head);
    cout << "Reversed: ";
    printList(head);

    return 0;
}

