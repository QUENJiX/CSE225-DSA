#include <iostream>
#include "dynarr.h"
using namespace std;

template <class T>
dynArr<T>::dynArr(){
    data = NULL;
    size = 0;
}
template <class T>
dynArr<T>::dynArr(int s){
    size = s;
    data = new T[size];
}
template <class T>
dynArr<T>::~dynArr() {
    delete[] data;
}

template <class T>
void dynArr<T>::setValue(int index, T value) {
        data[index] = value;
}
template <class T>
T dynArr<T>::getValue(int index) const {
        return data[index];
}
template <class T>
int dynArr<T>::getSize() const {
    return size;
}
