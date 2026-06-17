#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    unique_ptr<Node> left;
    unique_ptr<Node> right;

    explicit Node(int nodeValue) : value(nodeValue) {}
};

void insert(unique_ptr<Node>& node, int value) {
    if (node == nullptr) {
        node = make_unique<Node>(value);
        return;
    }

    if (value < node->value) {
        insert(node->left, value);
    } else if (value > node->value) {
        insert(node->right, value);
    }
}

bool search(const Node* node, int value) {
    if (node == nullptr) {
        return false;
    }

    if (node->value == value) {
        return true;
    }

    if (value < node->value) {
        return search(node->left.get(), value);
    }
    return search(node->right.get(), value);
}

void inorder(const Node* node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left.get());
    cout << node->value << ' ';
    inorder(node->right.get());
}

int minimumValue(const Node* node) {
    const Node* current = node;
    while (current != nullptr && current->left != nullptr) {
        current = current->left.get();
    }
    return current->value;
}

int main() {
    unique_ptr<Node> root;
    for (int value : {50, 30, 70, 20, 40, 60, 80}) {
        insert(root, value);
    }

    cout << "BST inorder is sorted: ";
    inorder(root.get());
    cout << '\n';

    cout << boolalpha;
    cout << "Search 60: " << search(root.get(), 60) << '\n';
    cout << "Search 99: " << search(root.get(), 99) << '\n';
    cout << "Minimum value: " << minimumValue(root.get()) << '\n';

    return 0;
}
