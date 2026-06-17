#include <bits/stdc++.h>
using namespace std;

template <typename T>
class StackADT {
public:
    virtual ~StackADT() = default;
    virtual void push(const T& item) = 0;
    virtual T pop() = 0;
    virtual const T& top() const = 0;
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
};

template <typename T>
class VectorStack : public StackADT<T> {
private:
    vector<T> items;

public:
    void push(const T& item) override {
        items.push_back(item);
    }

    T pop() override {
        if (items.empty()) {
            throw out_of_range("pop from empty stack");
        }

        T removed = items.back();
        items.pop_back();
        return removed;
    }

    const T& top() const override {
        if (items.empty()) {
            throw out_of_range("top from empty stack");
        }
        return items.back();
    }

    bool empty() const override {
        return items.empty();
    }

    size_t size() const override {
        return items.size();
    }
};

template <typename T>
class LinkedStack : public StackADT<T> {
private:
    struct Node {
        T data;
        unique_ptr<Node> next;

        Node(const T& nodeData, unique_ptr<Node> nextNode)
            : data(nodeData), next(move(nextNode)) {}
    };

    unique_ptr<Node> head;
    size_t length = 0;

public:
    void push(const T& item) override {
        head = make_unique<Node>(item, move(head));
        ++length;
    }

    T pop() override {
        if (head == nullptr) {
            throw out_of_range("pop from empty stack");
        }

        T removed = head->data;
        head = move(head->next);
        --length;
        return removed;
    }

    const T& top() const override {
        if (head == nullptr) {
            throw out_of_range("top from empty stack");
        }
        return head->data;
    }

    bool empty() const override {
        return length == 0;
    }

    size_t size() const override {
        return length;
    }
};

void demonstrateStack(const string& label, StackADT<string>& stack) {
    cout << label << '\n';
    stack.push("read problem");
    stack.push("write solution");
    stack.push("debug");

    while (!stack.empty()) {
        cout << "  " << stack.pop() << '\n';
    }
}

int main() {
    VectorStack<string> vectorStack;
    LinkedStack<string> linkedStack;

    demonstrateStack("Vector-backed Stack ADT:", vectorStack);
    demonstrateStack("Linked-list-backed Stack ADT:", linkedStack);

    cout << "\nSame Stack ADT, different internal representation.\n";
    return 0;
}
