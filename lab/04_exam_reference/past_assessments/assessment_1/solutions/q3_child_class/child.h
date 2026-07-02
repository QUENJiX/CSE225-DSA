/*
    EXAM PATTERN 3 - a class is GIVEN in .h/.cpp; you use it and EXTEND it.
    Maps to: Assessment 1, Question 3 (Child class).

    Part A: in main.cpp, make an object, use default ctor + setInfo(), print.
    Part B: ADD a new member function to .h AND .cpp, then call it in main.

    This file = the "given" header. In an exam this part is provided; your job
    is usually to ADD the Part B declaration (see favoriteSubject below).
*/

#ifndef CHILD_H
#define CHILD_H

#include <string>
using namespace std;

class Child {
   private:
    string name;
    int age;
    string favoriteColor;
    string favoriteFood;
    string favSubject;   // <-- Part B: backing field for the new function

   public:
    Child();
    Child(string n, int a, string c, string f);

    void setInfo(string n, int a, string c, string f);
    void printInfo();

    // Part B: added member function.
    // Stores the child's favorite subject and returns it.
    string favoriteSubject(string s);
};

#endif  // CHILD_H
