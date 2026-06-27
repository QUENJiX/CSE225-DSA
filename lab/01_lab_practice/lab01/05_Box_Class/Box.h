/*
Algorithm: Box Class Declaration
Source: CSE225L Lab 1, OOP Task

Purpose:
    Declare a Box class with height, width, depth, a constructor, and volume().

Pseudocode:
    1. Start header guard.
    2. Declare class Box.
    3. Keep height, width, and depth private.
    4. Declare constructor Box(h, w, d).
    5. Declare volume() as a const member function.
    6. End header guard.
*/

#ifndef BOX_H
#define BOX_H

class Box {
   private:
    double height;
    double width;
    double depth;

   public:
    Box(double h, double w, double d);
    void volume() const;
};

#endif  // BOX_H
