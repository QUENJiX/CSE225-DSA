#include <iostream>
#include <string>

#include "queuetype.h"
#include "queuetype.cpp"

using namespace std;

template <class T>
void PrintQueue(QueueType<T>& queue, int capacity) {
    QueueType<T> temporary(capacity);
    T value;

    while (!queue.IsEmpty()) {
        queue.Dequeue(value);
        temporary.Enqueue(value);
    }

    bool first = true;
    while (!temporary.IsEmpty()) {
        temporary.Dequeue(value);

        if (!first) {
            cout << ", ";
        }

        cout << value;
        first = false;
        queue.Enqueue(value);
    }

    cout << endl;
}

void PrintEmptyStatus(QueueType<int>& queue) {
    cout << (queue.IsEmpty() ? "Queue is Empty" : "Queue is not Empty")
         << endl;
}

void PrintFullStatus(QueueType<int>& queue) {
    cout << (queue.IsFull() ? "Queue is Full" : "Queue is not full")
         << endl;
}

void PrintBinaryNumbers(int n) {
    QueueType<string> binaries(n + 1);
    binaries.Enqueue("1");

    for (int i = 0; i < n; i++) {
        string current;
        binaries.Dequeue(current);
        cout << current << endl;
        binaries.Enqueue(current + "0");
        binaries.Enqueue(current + "1");
    }
}

int main() {
    cout << "ARRAY-BASED CIRCULAR QUEUE" << endl;
    cout << "--------------------------" << endl;

    const int capacity = 5;
    QueueType<int> queue(capacity);
    PrintEmptyStatus(queue);

    queue.Enqueue(5);
    queue.Enqueue(7);
    queue.Enqueue(4);
    queue.Enqueue(2);
    PrintEmptyStatus(queue);
    PrintFullStatus(queue);

    queue.Enqueue(6);
    cout << "Queue values: ";
    PrintQueue(queue, capacity);
    PrintFullStatus(queue);

    queue.Enqueue(8);

    int value;
    queue.Dequeue(value);
    queue.Dequeue(value);
    cout << "After two dequeues: ";
    PrintQueue(queue, capacity);

    queue.Dequeue(value);
    queue.Dequeue(value);
    queue.Dequeue(value);
    PrintEmptyStatus(queue);
    queue.Dequeue(value);

    cout << endl;
    cout << "BINARY VALUES FROM 1 TO 10" << endl;
    cout << "--------------------------" << endl;
    PrintBinaryNumbers(10);

    return 0;
}
