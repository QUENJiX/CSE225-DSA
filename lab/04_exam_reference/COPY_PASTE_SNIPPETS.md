# Copy-Paste Snippets - Labs 1-5

Short code blocks for exam use. Pick the block, paste it, rename variables to
match the question.

## Program Skeleton

```cpp
#include <iostream>
using namespace std;

int main() {
    return 0;
}
```

## Read After `cin >>`

```cpp
string text;
getline(cin >> ws, text);
```

## Branch Priority

```cpp
if (n % 4 == 0) {
    for (int i = 1; i <= n; i++) cout << i * i << " ";
} else if (n % 6 == 0) {
    for (int i = 1; i <= n; i++) if (i % 2 != 0) cout << i << " ";
} else if (n % 9 == 0) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += i;
    cout << sum;
} else {
    cout << "Invalid Category";
}
```

## Factorial

```cpp
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}
```

## Prime Check

```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
```

## Class Header

```cpp
#ifndef THING_H
#define THING_H

class Thing {
   private:
    int value;

   public:
    Thing();
    Thing(int v);
    void setValue(int v);
    int getValue();
};

#endif
```

## Class Source

```cpp
#include "thing.h"

Thing::Thing() {
    value = 0;
}

Thing::Thing(int v) {
    value = v;
}

void Thing::setValue(int v) {
    value = v;
}

int Thing::getValue() {
    return value;
}
```

## Single Dynamic Value

```cpp
int* p = new int;
*p = 10;
cout << *p << endl;
delete p;
p = nullptr;
```

## Dynamic 1D Array

```cpp
int* arr = new int[size];

for (int i = 0; i < size; i++) {
    cin >> arr[i];
}

for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
}

delete[] arr;
arr = nullptr;
```

## Dynamic 2D Equal Rows

```cpp
int** data = new int*[rows];
for (int i = 0; i < rows; i++) {
    data[i] = new int[cols];
}

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        cin >> data[i][j];
    }
}

for (int i = 0; i < rows; i++) {
    delete[] data[i];
}
delete[] data;
data = nullptr;
```

## Print Matrix Rows In Reverse

```cpp
for (int i = rows - 1; i >= 0; i--) {
    for (int j = 0; j < cols; j++) {
        cout << data[i][j] << " ";
    }
    cout << endl;
}
```

## Jagged 2D Int Array

```cpp
int* cols = new int[rows];
int** data = new int*[rows];

for (int i = 0; i < rows; i++) {
    cin >> cols[i];
    data[i] = new int[cols[i]];
}

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols[i]; j++) {
        cin >> data[i][j];
    }
}

for (int i = 0; i < rows; i++) {
    delete[] data[i];
}
delete[] data;
delete[] cols;
data = nullptr;
cols = nullptr;
```

## 2D Char Array

```cpp
char** words = new char*[rows];
for (int i = 0; i < rows; i++) {
    words[i] = new char[cols + 1];
}

for (int i = 0; i < rows; i++) {
    cin >> words[i];
}

for (int i = 0; i < rows; i++) {
    delete[] words[i];
}
delete[] words;
words = nullptr;
```

## dynArr Header

```cpp
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
    void allocate(int s);
    void setValue(int index, int value);
    int getValue(int index);
    int getSize();
};

#endif
```

## dynArr Source

```cpp
#include "dynarr.h"

dynArr::dynArr() {
    data = nullptr;
    size = 0;
}

dynArr::dynArr(int s) {
    data = nullptr;
    size = 0;
    allocate(s);
}

dynArr::~dynArr() {
    delete[] data;
}

void dynArr::allocate(int s) {
    delete[] data;
    data = new int[s];
    size = s;
}

void dynArr::setValue(int index, int value) {
    data[index] = value;
}

int dynArr::getValue(int index) {
    return data[index];
}

int dynArr::getSize() {
    return size;
}
```

## Template dynArr Header

```cpp
#ifndef DYNARR_H
#define DYNARR_H

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
```

## Template dynArr Source

```cpp
#include "dynarr.h"

template <class T>
dynArr<T>::dynArr() {
    data = nullptr;
    size = 0;
}

template <class T>
dynArr<T>::dynArr(int s) {
    data = nullptr;
    size = 0;
    allocate(s);
}

template <class T>
dynArr<T>::~dynArr() {
    delete[] data;
}

template <class T>
void dynArr<T>::allocate(int s) {
    delete[] data;
    data = new T[s];
    size = s;
}

template <class T>
void dynArr<T>::setValue(int index, T value) {
    data[index] = value;
}

template <class T>
T dynArr<T>::getValue(int index) {
    return data[index];
}

template <class T>
int dynArr<T>::getSize() {
    return size;
}
```

## Template Main Include

```cpp
#include "dynarr.h"
#include "dynarr.cpp"
```

## UnsortedType Header

```cpp
const int SIZE = 5;

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
    void MakeEmpty();
    void Insert(T value);
    void Search(T value, bool& found);
    void Delete(T value);
    void GetNext(T& value);
    void Reset();
};
```

## Unsorted Insert/Search/Delete

```cpp
template <class T>
void UnsortedType<T>::Insert(T value) {
    if (!IsFull()) {
        data[currentSize] = value;
        currentSize++;
    }
}

template <class T>
void UnsortedType<T>::Search(T value, bool& found) {
    found = false;
    for (int i = 0; i < currentSize; i++) {
        if (data[i] == value) {
            found = true;
            break;
        }
    }
}

template <class T>
void UnsortedType<T>::Delete(T value) {
    int location = 0;
    while (location < currentSize && !(data[location] == value)) {
        location++;
    }
    if (location < currentSize) {
        data[location] = data[currentSize - 1];
        currentSize--;
    }
}
```

## Unsorted Traversal

```cpp
T item;
list.Reset();
for (int i = 0; i < list.Length(); i++) {
    list.GetNext(item);
    cout << item << " ";
}
```

## SortedType Insert

```cpp
template <class T>
void SortedType<T>::Insert(T value) {
    int location = 0;

    while (location < currentSize && data[location] < value) {
        location++;
    }

    for (int i = currentSize; i > location; i--) {
        data[i] = data[i - 1];
    }

    data[location] = value;
    currentSize++;
}
```

## SortedType Search

```cpp
template <class T>
void SortedType<T>::Search(T value, bool& found) {
    found = false;
    int location = 0;

    while (location < currentSize && data[location] < value) {
        location++;
    }

    if (location < currentSize && data[location] == value) {
        found = true;
    }
}
```

## Student For ADT

```cpp
class Student {
   private:
    int id;
    string name;
    double cgpa;

   public:
    Student() {
        id = 0;
        name = "";
        cgpa = 0.0;
    }

    Student(int i, string n, double c) {
        id = i;
        name = n;
        cgpa = c;
    }

    bool operator==(Student other) {
        return id == other.id;
    }

    bool operator<(Student other) {
        return id < other.id;
    }

    void Print() {
        cout << id << ", " << name << ", " << cgpa << endl;
    }
};
```
