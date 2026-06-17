// Slides 15-17: inheritance syntax and access changes.

#include <iostream>
using namespace std;

class Base {
public:
    int publicValue = 10;

protected:
    int protectedValue = 20;

private:
    int privateValue = 30;

public:
    int getPrivateValue() const {
        return privateValue;
    }
};

class PublicDerived : public Base {
public:
    void showAccessibleMembers() const {
        cout << "publicValue from derived class: " << publicValue << '\n';
        cout << "protectedValue from derived class: " << protectedValue << '\n';
    }
};

class PrivateDerived : private Base {
public:
    void showAccessibleMembers() const {
        cout << "publicValue became private inside PrivateDerived: " << publicValue << '\n';
        cout << "protectedValue became private inside PrivateDerived: " << protectedValue << '\n';
    }
};

int main() {
    PublicDerived publicChild;
    publicChild.showAccessibleMembers();
    cout << "publicValue from main: " << publicChild.publicValue << '\n';
    cout << "privateValue through public getter: " << publicChild.getPrivateValue() << '\n';

    PrivateDerived privateChild;
    privateChild.showAccessibleMembers();

    return 0;
}
