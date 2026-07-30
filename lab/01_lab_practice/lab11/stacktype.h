#ifndef STACKTYPE_H
#define STACKTYPE_H

class FullStack {};
class EmptyStack {};

template <class T>
class StackType {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;

public:
    StackType();
    ~StackType();

    bool IsEmpty();
    bool IsFull();
    void Push(T value);
    void Pop();
    void Diagnose();
    T Top();
};

#endif
