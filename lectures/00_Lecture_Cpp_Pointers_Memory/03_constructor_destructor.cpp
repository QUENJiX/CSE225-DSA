// Slide 12: constructors run when an object is created, destructors run when it is destroyed.

#include <iostream>

using namespace std;

class TrackedBox {
private:
    int id;
    static int nextId;

public:
    TrackedBox() : id(nextId++) {
        cout << "Constructor: box " << id << " created\n";
    }

    explicit TrackedBox(int customId) : id(customId) {
        cout << "Constructor: box " << id << " created with custom id\n";
    }

    ~TrackedBox() {
        cout << "Destructor: box " << id << " destroyed\n";
    }

    void show() const {
        cout << "Using box " << id << '\n';
    }
};

int TrackedBox::nextId = 1;

int main() {
    TrackedBox first;
    first.show();

    {
        TrackedBox temporary(100);
        temporary.show();
    }

    cout << "Temporary object is already destroyed here.\n";

    return 0;
}
