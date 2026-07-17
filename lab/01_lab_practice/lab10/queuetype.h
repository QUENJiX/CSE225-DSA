#ifndef QUEUETYPE_H
#define QUEUETYPE_H

const int SIZE = 6;

class FullQueue {};
class EmptyQueue {};

template <class T>
class QueueType {
private:
    T* data;
    int front;
    int rear;
    int size;

public:
    QueueType();
    QueueType(int size);
    ~QueueType();

    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(T value);
    void Dequeue(T& value);
};

#endif
