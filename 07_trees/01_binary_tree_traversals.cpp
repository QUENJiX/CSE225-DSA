#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    unique_ptr<Node> left;
    unique_ptr<Node> right;

    explicit Node(int nodeValue) : value(nodeValue) {}
};

void preorder(const Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->value << ' ';
    preorder(node->left.get());
    preorder(node->right.get());
}

void inorder(const Node* node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left.get());
    cout << node->value << ' ';
    inorder(node->right.get());
}

void postorder(const Node* node) {
    if (node == nullptr) {
        return;
    }
    postorder(node->left.get());
    postorder(node->right.get());
    cout << node->value << ' ';
}

vector<vector<int>> levelOrder(const Node* root) {
    vector<vector<int>> levels;
    if (root == nullptr) {
        return levels;
    }

    queue<const Node*> pending;
    pending.push(root);

    while (!pending.empty()) {
        int levelSize = static_cast<int>(pending.size());
        vector<int> level;

        for (int i = 0; i < levelSize; ++i) {
            const Node* current = pending.front();
            pending.pop();
            level.push_back(current->value);

            if (current->left != nullptr) {
                pending.push(current->left.get());
            }
            if (current->right != nullptr) {
                pending.push(current->right.get());
            }
        }

        levels.push_back(level);
    }

    return levels;
}

int main() {
    auto root = make_unique<Node>(1);
    root->left = make_unique<Node>(2);
    root->right = make_unique<Node>(3);
    root->left->left = make_unique<Node>(4);
    root->left->right = make_unique<Node>(5);

    cout << "Preorder: ";
    preorder(root.get());
    cout << "\nInorder: ";
    inorder(root.get());
    cout << "\nPostorder: ";
    postorder(root.get());

    cout << "\nLevel order:\n";
    for (const auto& level : levelOrder(root.get())) {
        for (int value : level) {
            cout << value << ' ';
        }
        cout << '\n';
    }

    return 0;
}
