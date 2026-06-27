/*
    CSE225L Exam Template - dynArr class declaration

    This is the *shape* to reproduce when asked to "write the full code".
    A resizable 1D integer array. Includes the Rule of Three (copy
    constructor + copy assignment) so the object is safe to copy.

    Reproduce this file structure from memory:
        1. header guard
        2. class name
        3. private members (the data + bookkeeping)
        4. public interface (ctors, dtor, operations, accessors)
        5. end header guard
*/

#ifndef DYNARR_H
#define DYNARR_H

class dynArr {
   private:
    int* data;
    int size;

   public:
    dynArr();                                 // default constructor
    dynArr(int s);                            // parameterized constructor
    dynArr(const dynArr& other);              // copy constructor   (Rule of Three)
    dynArr& operator=(const dynArr& other);   // copy assignment    (Rule of Three)
    ~dynArr();                                // destructor

    void allocate(int s);                     // resize, keep existing values
    void setValue(int index, int value);
    int getValue(int index);
    int getSize();
};

#endif  // DYNARR_H
