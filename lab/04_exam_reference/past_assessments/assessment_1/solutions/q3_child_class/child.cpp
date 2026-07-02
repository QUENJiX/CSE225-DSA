/*
    Child class definitions (the "given" source in the exam).
    Every method is scoped with Child::

    Part B note: the exam wording ("void favoriteSubject(str)" but "return the
    name") is inconsistent. A clean, compiling reading: take the subject as
    input, store it, and RETURN it as a string. Adapt if your sheet differs.
*/

#include "child.h"
#include <iostream>
using namespace std;

Child::Child() {
    name = "";
    age = 0;
    favoriteColor = "";
    favoriteFood = "";
    favSubject = "";
}

Child::Child(string n, int a, string c, string f) {
    name = n;
    age = a;
    favoriteColor = c;
    favoriteFood = f;
    favSubject = "";
}

void Child::setInfo(string n, int a, string c, string f) {
    name = n;
    age = a;
    favoriteColor = c;
    favoriteFood = f;
}

void Child::printInfo() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Favorite Color: " << favoriteColor << endl;
    cout << "Favorite Food: " << favoriteFood << endl;
}

// Part B
string Child::favoriteSubject(string s) {
    favSubject = s;
    return favSubject;
}
