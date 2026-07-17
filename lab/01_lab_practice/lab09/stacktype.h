#ifndef STACKTYPE_H
#define STACKTYPE_H

const int SIZE = 5;

class FullStack {};
class EmptyStack {};

template <class T>
class StackType {
private:
    T* data;
    int top;

public:
    StackType();
    ~StackType();

    bool IsFull();
    bool IsEmpty();
    void Push(T value);
    void Pop();
    T Top();
};

#endif
