#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

const int UNSORTED_CAPACITY = 5;

template <class T>
class UnsortedType {
private:
    T* data;
    int currentSize;
    int pointTo;

public:
    UnsortedType();
    ~UnsortedType();
    int Length();
    bool IsFull();
    bool IsEmpty();
    void MakeEmpty();
    void Insert(const T& value);
    void Search(const T& value, bool& found) const;
    void Delete(const T& value);
    void GetNext(T& value);
    void Reset();
};

#endif
