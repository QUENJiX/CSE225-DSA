#ifndef LECTURE0_DYNARR_INT_H_INCLUDED
#define LECTURE0_DYNARR_INT_H_INCLUDED

class dynArr {
private:
    int* data;
    int size;

    void checkSize(int requestedSize) const;
    void checkIndex(int index) const;

public:
    dynArr();
    explicit dynArr(int size);
    dynArr(const dynArr& other);
    dynArr& operator=(const dynArr& other);
    ~dynArr();

    void allocate(int size);
    void setValue(int index, int value);
    int getValue(int index) const;
    int getSize() const;
};

#endif  // LECTURE0_DYNARR_INT_H_INCLUDED
