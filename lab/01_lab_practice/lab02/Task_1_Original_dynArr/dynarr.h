#ifndef DYNARR_H
#define DYNARR_H

class dynArr {
private:
    int* data;
    int size;

public:
    dynArr();
    dynArr(int s);
    ~dynArr();
    void setValue(int index, int value);
    int getValue(int index);
};

#endif  // DYNARR_H
