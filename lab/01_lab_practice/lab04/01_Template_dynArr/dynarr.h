#ifndef DYNARR_H
#define DYNARR_H

#include <iostream>
using namespace std;

template <class T>
class dynArr {
   private:
    T* data;
    int size;

   public:
    dynArr();
    dynArr(int s);
    ~dynArr();

    void setValue(int index, T value);
    T getValue(int index) const;
    int getSize() const;
};

template <class T>
dynArr<T>::dynArr() {
    data = nullptr;
    size = 0;
}

template <class T>
dynArr<T>::dynArr(int s) {
    if (s <= 0) {
        data = nullptr;
        size = 0;
    } else {
        data = new T[s];
        size = s;
    }
}

#endif  // DYNARR_H
