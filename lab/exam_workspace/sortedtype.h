#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

const int SORTED_CAPACITY = 5;

template <class T>
class SortedType {
   private:
    T* data;
    int currentSize;
    int pointTo;

   public:
    SortedType();
    ~SortedType();

    int Length() const;
    bool IsFull() const;
    bool IsEmpty() const;
    void MakeEmpty();

    void Insert(const T& value);
    void Search(const T& value, bool& found) const;
    void Delete(const T& value);

    void GetNext(T& value);
    void Reset();
};

#endif
