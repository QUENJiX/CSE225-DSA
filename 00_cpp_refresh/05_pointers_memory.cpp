#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    explicit Node(int nodeValue) : value(nodeValue) {}
};

int main() {
    int number = 42;
    int& reference = number;
    int* pointer = &number;

    cout << "number: " << number << '\n';
    cout << "reference: " << reference << '\n';
    cout << "pointer points to: " << *pointer << '\n';

    reference = 50;
    cout << "after reference update: " << number << '\n';

    auto smartNode = make_unique<Node>(99);
    cout << "unique_ptr node value: " << smartNode->value << '\n';

    vector<int> dynamicArray(5, 10);
    dynamicArray.push_back(20);

    cout << "vector manages dynamic memory for you: ";
    for (int value : dynamicArray) {
        cout << value << ' ';
    }
    cout << '\n';

    Node* rawNode = new Node(123);
    cout << "raw pointer node value: " << rawNode->value << '\n';
    delete rawNode;

    return 0;
}
