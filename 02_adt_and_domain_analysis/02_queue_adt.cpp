#include <bits/stdc++.h>
using namespace std;

template <typename T>
class QueueADT {
public:
    virtual ~QueueADT() = default;
    virtual void enqueue(const T& item) = 0;
    virtual T dequeue() = 0;
    virtual const T& front() const = 0;
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
};

template <typename T>
class DequeQueue : public QueueADT<T> {
private:
    deque<T> items;

public:
    void enqueue(const T& item) override {
        items.push_back(item);
    }

    T dequeue() override {
        if (items.empty()) {
            throw out_of_range("dequeue from empty queue");
        }

        T removed = items.front();
        items.pop_front();
        return removed;
    }

    const T& front() const override {
        if (items.empty()) {
            throw out_of_range("front from empty queue");
        }
        return items.front();
    }

    bool empty() const override {
        return items.empty();
    }

    size_t size() const override {
        return items.size();
    }
};

template <typename T>
class CircularArrayQueue : public QueueADT<T> {
private:
    vector<T> items;
    size_t firstIndex = 0;
    size_t length = 0;

    size_t physicalIndex(size_t logicalIndex) const {
        return (firstIndex + logicalIndex) % items.size();
    }

    void grow() {
        size_t newCapacity = max<size_t>(2, items.size() * 2);
        vector<T> resized(newCapacity);

        for (size_t index = 0; index < length; ++index) {
            resized[index] = items[physicalIndex(index)];
        }

        items = move(resized);
        firstIndex = 0;
    }

public:
    explicit CircularArrayQueue(size_t initialCapacity = 4) : items(initialCapacity) {}

    void enqueue(const T& item) override {
        if (length == items.size()) {
            grow();
        }

        items[physicalIndex(length)] = item;
        ++length;
    }

    T dequeue() override {
        if (empty()) {
            throw out_of_range("dequeue from empty queue");
        }

        T removed = items[firstIndex];
        firstIndex = (firstIndex + 1) % items.size();
        --length;
        return removed;
    }

    const T& front() const override {
        if (empty()) {
            throw out_of_range("front from empty queue");
        }
        return items[firstIndex];
    }

    bool empty() const override {
        return length == 0;
    }

    size_t size() const override {
        return length;
    }
};

void serveStudents(const string& label, QueueADT<string>& queue) {
    cout << label << '\n';
    queue.enqueue("Ari");
    queue.enqueue("Mira");
    queue.enqueue("Tuhin");

    while (!queue.empty()) {
        cout << "  serving " << queue.dequeue() << '\n';
    }
}

int main() {
    DequeQueue<string> dequeQueue;
    CircularArrayQueue<string> circularQueue;

    serveStudents("Deque-backed Queue ADT:", dequeQueue);
    serveStudents("Circular-array-backed Queue ADT:", circularQueue);

    cout << "\nSame Queue behavior: first in, first out.\n";
    return 0;
}
