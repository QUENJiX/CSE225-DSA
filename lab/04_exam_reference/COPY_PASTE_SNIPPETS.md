# Copy-Paste Snippets - Labs 1-6

Use this as the code bank. Copy only the block you need, then rename class,
file, and variable names to match the question.

## Program Skeleton

```cpp
#include <iostream>
using namespace std;

int main() {
    return 0;
}
```

## Read Line After `cin >>`

```cpp
string text;
getline(cin >> ws, text);
```

## Branch Priority Pattern

```cpp
if (n % 4 == 0) {
    for (int i = 1; i <= n; i++) {
        cout << i * i << " ";
    }
} else if (n % 6 == 0) {
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
} else if (n % 9 == 0) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
} else {
    cout << "Invalid Category";
}
```

## Common Small Functions

```cpp
int countValue(int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int firstIndex(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int maxValue(int arr[], int size) {
    int mx = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
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

## 1D Allocate/Delete Helpers

```cpp
int* allocateIntArray(int size) {
    if (size <= 0) {
        return nullptr;
    }
    return new int[size];
}

void deleteIntArray(int*& arr) {
    delete[] arr;
    arr = nullptr;
}
```

## 1D Read/Print Pattern

```cpp
int* arr = allocateIntArray(size);

if (arr == nullptr) {
    cout << "Invalid size" << endl;
} else {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    deleteIntArray(arr);
}
```

## 2D Equal Rows Allocate/Delete Helpers

```cpp
int** allocateMatrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        return nullptr;
    }

    int** data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
    }
    return data;
}

void deleteMatrix(int**& data, int rows) {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
    }

    delete[] data;
    data = nullptr;
}
```

## 2D Read/Print Pattern

```cpp
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        cin >> data[i][j];
    }
}

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        cout << data[i][j] << " ";
    }
    cout << endl;
}
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

## Jagged Array Allocate/Delete Helpers

```cpp
int** allocateJaggedIntArray(int rows, int*& cols) {
    if (rows <= 0) {
        cols = nullptr;
        return nullptr;
    }

    cols = new int[rows];
    int** data = new int*[rows];

    for (int i = 0; i < rows; i++) {
        cin >> cols[i];
        if (cols[i] <= 0) {
            cols[i] = 0;
            data[i] = nullptr;
        } else {
            data[i] = new int[cols[i]];
        }
    }

    return data;
}

void deleteJaggedIntArray(int**& data, int*& cols, int rows) {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
    }

    delete[] data;
    delete[] cols;
    data = nullptr;
    cols = nullptr;
}
```

## Jagged Read/Print Pattern

```cpp
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols[i]; j++) {
        cin >> data[i][j];
    }
}

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols[i]; j++) {
        cout << data[i][j] << " ";
    }
    cout << endl;
}
```

## 2D Char Array Helpers

```cpp
#include <iomanip>

char** allocateWords(int rows, int maxLength) {
    if (rows <= 0 || maxLength <= 0) {
        return nullptr;
    }

    char** words = new char*[rows];
    for (int i = 0; i < rows; i++) {
        words[i] = new char[maxLength + 1];
    }
    return words;
}

void deleteWords(char**& words, int rows) {
    if (words != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] words[i];
        }
    }

    delete[] words;
    words = nullptr;
}
```

## 2D Char Read/Print Pattern

```cpp
for (int i = 0; i < rows; i++) {
    cin >> setw(maxLength + 1) >> words[i];
}

for (int i = 0; i < rows; i++) {
    cout << words[i] << endl;
}
```

## 3-File Class Header

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

## 3-File Class Source

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

## 1D dynArr Header

```cpp
#ifndef DYNARR_H
#define DYNARR_H

class dynArr {
   private:
    int* data;
    int size;
    bool isValidIndex(int index);
    void copyFrom(const dynArr& other);

   public:
    dynArr();
    dynArr(int s);
    dynArr(const dynArr& other);
    ~dynArr();

    dynArr& operator=(const dynArr& other);
    void clear();
    void allocate(int s);
    void setValue(int index, int value);
    int getValue(int index);
    int getSize();
    bool isEmpty();
};

#endif
```

## 1D dynArr Source

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

dynArr::dynArr(const dynArr& other) {
    data = nullptr;
    size = 0;
    copyFrom(other);
}

dynArr::~dynArr() {
    clear();
}

dynArr& dynArr::operator=(const dynArr& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

bool dynArr::isValidIndex(int index) {
    return index >= 0 && index < size;
}

void dynArr::copyFrom(const dynArr& other) {
    if (other.size <= 0) {
        data = nullptr;
        size = 0;
        return;
    }

    data = new int[other.size]();
    size = other.size;

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

void dynArr::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}

void dynArr::allocate(int s) {
    clear();

    if (s <= 0) {
        return;
    }

    data = new int[s]();
    size = s;
}

void dynArr::setValue(int index, int value) {
    if (isValidIndex(index)) {
        data[index] = value;
    }
}

int dynArr::getValue(int index) {
    if (isValidIndex(index)) {
        return data[index];
    }
    return 0;
}

int dynArr::getSize() {
    return size;
}

bool dynArr::isEmpty() {
    return size == 0;
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
dynArr<T>::dynArr(const dynArr<T>& other) {
    data = nullptr;
    size = 0;
    copyFrom(other);
}

template <class T>
dynArr<T>::~dynArr() {
    clear();
}

template <class T>
dynArr<T>& dynArr<T>::operator=(const dynArr<T>& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

template <class T>
bool dynArr<T>::isValidIndex(int index) {
    return index >= 0 && index < size;
}

template <class T>
void dynArr<T>::copyFrom(const dynArr<T>& other) {
    if (other.size <= 0) {
        data = nullptr;
        size = 0;
        return;
    }

    data = new T[other.size]();
    size = other.size;

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <class T>
void dynArr<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}

template <class T>
void dynArr<T>::allocate(int s) {
    clear();

    if (s <= 0) {
        return;
    }

    data = new T[s]();
    size = s;
}

template <class T>
void dynArr<T>::setValue(int index, T value) {
    if (isValidIndex(index)) {
        data[index] = value;
    }
}

template <class T>
T dynArr<T>::getValue(int index) {
    if (isValidIndex(index)) {
        return data[index];
    }
    return T();
}

template <class T>
int dynArr<T>::getSize() {
    return size;
}

template <class T>
bool dynArr<T>::isEmpty() {
    return size == 0;
}
```

## Template Main Include

```cpp
#include "dynarr.h"
#include "dynarr.cpp"
```

## UnsortedType Header

```cpp
#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

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
    bool IsEmpty();
    void MakeEmpty();
    void Insert(T value);
    void Search(T value, bool& found);
    void Delete(T value);
    void GetNext(T& value);
    void Reset();
};

#endif
```

## UnsortedType Source

```cpp
#include "unsortedtype.h"
#include <iostream>
using namespace std;

template <class T>
UnsortedType<T>::UnsortedType() {
    data = new T[SIZE];
    currentSize = 0;
    pointTo = -1;
}

template <class T>
UnsortedType<T>::~UnsortedType() {
    delete[] data;
}

template <class T>
int UnsortedType<T>::Length() {
    return currentSize;
}

template <class T>
bool UnsortedType<T>::IsFull() {
    return currentSize == SIZE;
}

template <class T>
bool UnsortedType<T>::IsEmpty() {
    return currentSize == 0;
}

template <class T>
void UnsortedType<T>::MakeEmpty() {
    currentSize = 0;
    pointTo = -1;
}

template <class T>
void UnsortedType<T>::Insert(T value) {
    if (IsFull()) {
        cout << "Error: List is full" << endl;
        return;
    }

    data[currentSize] = value;
    currentSize++;
}

template <class T>
void UnsortedType<T>::Search(T value, bool& found) {
    found = false;
    for (int i = 0; i < currentSize; i++) {
        if (data[i] == value) {
            found = true;
            return;
        }
    }
}

template <class T>
void UnsortedType<T>::Delete(T value) {
    if (IsEmpty()) {
        cout << "Error: List is empty" << endl;
        return;
    }

    int location = 0;
    while (location < currentSize && !(data[location] == value)) {
        location++;
    }

    if (location == currentSize) {
        cout << "Error: Item could not be found in the list" << endl;
        return;
    }

    data[location] = data[currentSize - 1];
    currentSize--;

    if (pointTo >= currentSize) {
        pointTo = -1;
    }
}

template <class T>
void UnsortedType<T>::Reset() {
    pointTo = -1;
}

template <class T>
void UnsortedType<T>::GetNext(T& value) {
    if (IsEmpty()) {
        cout << "Error: List is empty" << endl;
        return;
    }

    if (pointTo + 1 >= currentSize) {
        pointTo = -1;
    }

    pointTo++;
    value = data[pointTo];
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

## SortedType Header

```cpp
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
```

## SortedType Source

```cpp
#include "sortedtype.h"
#include <iostream>
using namespace std;

template <class T>
SortedType<T>::SortedType() {
    data = new T[SIZE];
    currentSize = 0;
    pointTo = -1;
}

template <class T>
SortedType<T>::~SortedType() {
    delete[] data;
}

template <class T>
int SortedType<T>::Length() {
    return currentSize;
}

template <class T>
bool SortedType<T>::IsFull() {
    return currentSize == SIZE;
}

template <class T>
bool SortedType<T>::IsEmpty() {
    return currentSize == 0;
}

template <class T>
void SortedType<T>::MakeEmpty() {
    currentSize = 0;
    pointTo = -1;
}

template <class T>
void SortedType<T>::Insert(T value) {
    if (IsFull()) {
        cout << "Error: List is full" << endl;
        return;
    }

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

template <class T>
void SortedType<T>::Delete(T value) {
    if (IsEmpty()) {
        cout << "Error: List is empty" << endl;
        return;
    }

    int location = 0;
    while (location < currentSize && data[location] < value) {
        location++;
    }

    if (location == currentSize || !(data[location] == value)) {
        cout << "Error: Item could not be found in the list" << endl;
        return;
    }

    for (int i = location; i < currentSize - 1; i++) {
        data[i] = data[i + 1];
    }

    currentSize--;
    if (pointTo >= currentSize) {
        pointTo = -1;
    }
}

template <class T>
void SortedType<T>::Reset() {
    pointTo = -1;
}

template <class T>
void SortedType<T>::GetNext(T& value) {
    if (IsEmpty()) {
        cout << "Error: List is empty" << endl;
        return;
    }

    if (pointTo + 1 >= currentSize) {
        pointTo = -1;
    }

    pointTo++;
    value = data[pointTo];
}
```

## Student For ADT

```cpp
#include <iostream>
#include <string>
using namespace std;

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

    bool operator>(Student other) {
        return id > other.id;
    }

    void Print() {
        cout << id << ", " << name << ", " << cgpa << endl;
    }
};
```

## timeStamp For SortedType

```cpp
#include <iomanip>
#include <iostream>
using namespace std;

class timeStamp {
   private:
    int seconds;
    int minutes;
    int hours;

    int totalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

   public:
    timeStamp() {
        seconds = 0;
        minutes = 0;
        hours = 0;
    }

    timeStamp(int s, int m, int h) {
        seconds = s;
        minutes = m;
        hours = h;
    }

    bool operator==(const timeStamp& other) const {
        return totalSeconds() == other.totalSeconds();
    }

    bool operator<(const timeStamp& other) const {
        return totalSeconds() < other.totalSeconds();
    }

    bool operator>(const timeStamp& other) const {
        return totalSeconds() > other.totalSeconds();
    }

    void Print() const {
        cout << setw(2) << setfill('0') << seconds << ": "
             << setw(2) << minutes << ": "
             << setw(2) << hours << setfill(' ') << endl;
    }
};
```

## SortedType Driver Pattern

```cpp
SortedType<int> numbers;

numbers.Insert(5);
numbers.Insert(4);
numbers.Insert(2);
numbers.Insert(1);
numbers.Insert(7);

bool found;
numbers.Search(5, found);
cout << (found ? "Item is found" : "Item is not found") << endl;

numbers.Delete(4);

int item;
numbers.Reset();
for (int i = 0; i < numbers.Length(); i++) {
    numbers.GetNext(item);
    cout << item << " ";
}
cout << endl;
```

## Template Driver Example

```cpp
#include <iostream>
#include "dynarr.h"
#include "dynarr.cpp"
using namespace std;

int main() {
    int n;
    cin >> n;

    dynArr<int> arr;
    arr.allocate(n);

    for (int i = 0; i < arr.getSize(); i++) {
        int value;
        cin >> value;
        arr.setValue(i, value);
    }

    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
```
