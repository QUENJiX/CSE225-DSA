/*
    CSE225L Lab 3 - Task 1: Original dynArr Header

    Algorithm:
    1. Declare a class named dynArr.
    2. Keep the dynamic array pointer private.
    3. Keep the array size private.
    4. Provide constructors to initialize the object.
    5. Provide a destructor to release heap memory.
    6. Provide setValue and getValue methods for controlled access.

    Pseudocode:
    CLASS dynArr
        PRIVATE:
            data: pointer to integer
            size: integer
        PUBLIC:
            dynArr()
            dynArr(s)
            ~dynArr()
            setValue(index, value)
            getValue(index)
    END CLASS
*/

#ifndef DYNARR_H
#define DYNARR_H

class dynArr
{
private:
    int *data;
    int size;

public:
    dynArr();
    dynArr(int s);
    ~dynArr();
    void setValue(int index, int value);
    int getValue(int index);
};

#endif // DYNARR_H
