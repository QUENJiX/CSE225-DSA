/*
    CSE225L Lab 3 - Task 2: dynArr Header with allocate(int s)

    Algorithm:
    1. Declare a 1D dynamic array class.
    2. Store pointer and size privately.
    3. Add allocate(int s) so the array can be resized.
    4. Keep setValue/getValue for indexed access.
    5. Add getSize so the driver can loop over the current size.

    Pseudocode:
    CLASS dynArr
        PRIVATE:
            data: pointer to integer
            size: integer
        PUBLIC:
            dynArr()
            dynArr(s)
            ~dynArr()
            allocate(s)
            setValue(index, value)
            getValue(index)
            getSize()
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
    void allocate(int s);
    void setValue(int index, int value);
    int getValue(int index);
    int getSize();
};

#endif // DYNARR_H
