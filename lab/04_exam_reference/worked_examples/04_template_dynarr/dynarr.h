#ifndef DYNARR_H
#define DYNARR_H

template <class T>
class dynArr {
   private:
    T* data;
    int size;
    bool isValidIndex(int index);
    void copyFrom(const dynArr<T>& other);

   public:
    dynArr();
    dynArr(int s);
    dynArr(const dynArr<T>& other);
    ~dynArr();

    dynArr<T>& operator=(const dynArr<T>& other);
    void clear();
    void allocate(int s);
    void setValue(int index, T value);
    T getValue(int index);
    int getSize();
    bool isEmpty();
};

#endif
