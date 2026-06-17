#ifndef LECTURE0_DYNARR_TEMPLATE_H_INCLUDED
#define LECTURE0_DYNARR_TEMPLATE_H_INCLUDED

template <class T>
class dynArr {
private:
    T* data;
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
    void setValue(int index, T value);
    T getValue(int index) const;
    int getSize() const;
};

#endif  // LECTURE0_DYNARR_TEMPLATE_H_INCLUDED
