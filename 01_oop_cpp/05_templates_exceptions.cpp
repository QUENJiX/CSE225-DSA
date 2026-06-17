#include <bits/stdc++.h>
using namespace std;

template <typename T>
T largerOf(T a, T b) {
    return (a < b) ? b : a;
}

template <typename T>
class SimpleStack {
private:
    vector<T> values;

public:
    void push(const T& value) {
        values.push_back(value);
    }

    T pop() {
        if (values.empty()) {
            throw out_of_range("cannot pop from an empty stack");
        }

        T value = values.back();
        values.pop_back();
        return value;
    }

    bool empty() const {
        return values.empty();
    }
};

int main() {
    cout << "largerOf ints: " << largerOf(10, 25) << '\n';
    cout << "largerOf strings: " << largerOf(string("heap"), string("graph")) << '\n';

    SimpleStack<string> stack;
    stack.push("first");
    stack.push("second");

    while (!stack.empty()) {
        cout << stack.pop() << '\n';
    }

    try {
        stack.pop();
    } catch (const out_of_range& error) {
        cout << "Caught exception: " << error.what() << '\n';
    }

    return 0;
}

