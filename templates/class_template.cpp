#include <bits/stdc++.h>
using namespace std;

class ClassName {
private:
    int value;

public:
    explicit ClassName(int initialValue) : value(initialValue) {}

    int getValue() const {
        return value;
    }

    void setValue(int newValue) {
        value = newValue;
    }
};

int main() {
    ClassName item(42);
    cout << item.getValue() << '\n';
    return 0;
}
