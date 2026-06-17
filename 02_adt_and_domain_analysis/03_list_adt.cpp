#include <bits/stdc++.h>
using namespace std;

class ListADT {
public:
    virtual ~ListADT() = default;
    virtual void insertAt(size_t index, int value) = 0;
    virtual void eraseAt(size_t index) = 0;
    virtual int get(size_t index) const = 0;
    virtual size_t size() const = 0;
};

class ArrayList : public ListADT {
private:
    vector<int> items;

public:
    void insertAt(size_t index, int value) override {
        if (index > items.size()) {
            throw out_of_range("insert index out of range");
        }
        items.insert(items.begin() + static_cast<ptrdiff_t>(index), value);
    }

    void eraseAt(size_t index) override {
        if (index >= items.size()) {
            throw out_of_range("erase index out of range");
        }
        items.erase(items.begin() + static_cast<ptrdiff_t>(index));
    }

    int get(size_t index) const override {
        if (index >= items.size()) {
            throw out_of_range("get index out of range");
        }
        return items[index];
    }

    size_t size() const override {
        return items.size();
    }
};

class LinkedList : public ListADT {
private:
    struct Node {
        int value;
        unique_ptr<Node> next;

        explicit Node(int nodeValue) : value(nodeValue) {}
    };

    unique_ptr<Node> head;
    size_t length = 0;

    Node* nodeBefore(size_t index) const {
        Node* current = head.get();
        for (size_t step = 0; step + 1 < index; ++step) {
            current = current->next.get();
        }
        return current;
    }

public:
    void insertAt(size_t index, int value) override {
        if (index > length) {
            throw out_of_range("insert index out of range");
        }

        if (index == 0) {
            auto inserted = make_unique<Node>(value);
            inserted->next = move(head);
            head = move(inserted);
        } else {
            Node* previous = nodeBefore(index);
            auto inserted = make_unique<Node>(value);
            inserted->next = move(previous->next);
            previous->next = move(inserted);
        }

        ++length;
    }

    void eraseAt(size_t index) override {
        if (index >= length) {
            throw out_of_range("erase index out of range");
        }

        if (index == 0) {
            head = move(head->next);
        } else {
            Node* previous = nodeBefore(index);
            previous->next = move(previous->next->next);
        }

        --length;
    }

    int get(size_t index) const override {
        if (index >= length) {
            throw out_of_range("get index out of range");
        }

        Node* current = head.get();
        for (size_t step = 0; step < index; ++step) {
            current = current->next.get();
        }
        return current->value;
    }

    size_t size() const override {
        return length;
    }
};

void printList(const string& label, const ListADT& list) {
    cout << label;
    for (size_t index = 0; index < list.size(); ++index) {
        cout << list.get(index) << ' ';
    }
    cout << '\n';
}

void demonstrateList(const string& label, ListADT& list) {
    list.insertAt(0, 10);
    list.insertAt(1, 30);
    list.insertAt(1, 20);
    list.eraseAt(0);
    printList(label, list);
}

int main() {
    ArrayList arrayList;
    LinkedList linkedList;

    demonstrateList("ArrayList: ", arrayList);
    demonstrateList("LinkedList: ", linkedList);

    cout << "\nSame List ADT operations, different performance tradeoffs.\n";
    return 0;
}
