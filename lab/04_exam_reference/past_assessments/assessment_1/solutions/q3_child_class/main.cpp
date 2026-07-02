/*
    Driver for the Child class (the file you WRITE in the exam).

    Part A: default constructor + setInfo() from user input, then printInfo().
    Part B: read a subject, call favoriteSubject(), print what it returns.

    Reading a full line (name/food can contain spaces) -> getline.
    Mixing cin >> and getline needs `>> ws` to eat the leftover newline.
*/

#include <iostream>
#include <string>
#include "child.h"
using namespace std;

int main() {
    Child child;   // default constructor

    string name, color, food, subject;
    int age;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter favorite color: ";
    cin >> color;
    cout << "Enter favorite food: ";
    cin >> food;

    child.setInfo(name, age, color, food);

    cout << "\n--- Child Info ---" << endl;
    child.printInfo();

    // Part B
    cout << "\nEnter favorite subject: ";
    getline(cin >> ws, subject);
    cout << "Favorite Subject: " << child.favoriteSubject(subject) << endl;

    return 0;
}
