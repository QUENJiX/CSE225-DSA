#ifndef QUEUETYPE_H
#define QUEUETYPE_H

class FullQueue {};
class EmptyQueue {};

template <class T>
class QueueType {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    QueueType();
    ~QueueType();

    bool IsEmpty();
    bool IsFull();
    void MakeEmpty();
    void Enqueue(T value);
    void Dequeue(T& value);
};

#endif
