#ifndef SOLUTION_H
#define SOLUTION_H

template <class T>
class dynArr {
   private:
    T* data;
    int size;

   public:
    dynArr();
    dynArr(int s);
    ~dynArr();

    void allocate(int s);
    void setValue(int index, T value);
    T getValue(int index);
    int getSize();
};

#endif
