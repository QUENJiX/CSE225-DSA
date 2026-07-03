#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

const int SIZE = 5;

template <class T>
class SortedType {
   private:
    T* data;
    int currentSize;
    int pointTo;

   public:
    SortedType();
    ~SortedType();
    int Length();
    bool IsFull();
    bool IsEmpty();
    void MakeEmpty();
    void Insert(T value);
    void Search(T value, bool& found);
    void Delete(T value);
    void GetNext(T& value);
    void Reset();
};

#endif
