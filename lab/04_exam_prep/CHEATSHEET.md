# CSE225L Exam Cheat Sheet — Labs 1–3

Everything you need to **complete a function** or **write full code** under time pressure.
Style matches your labs: `using namespace std;`, `nullptr`, 4-space indent, attached braces.

## Contents
1. [Program skeleton + compile](#1-program-skeleton--compile)
2. [Lab 1 — I/O, loops, basics](#2-lab-1--io-loops-basics)
3. [Lab 1 — a class in `.h` / `.cpp` / `main.cpp`](#3-lab-1--a-class-in-h--cpp--maincpp)
4. [Lab 2 — `dynArr` class (1D, resizable, 2D)](#4-lab-2--dynarr-class)
5. [Lab 3 — raw dynamic memory in `main()`](#5-lab-3--raw-dynamic-memory-in-main)
6. [Deallocation rules (most marks lost here)](#6-deallocation-rules)
7. ["Complete the function" recall table](#7-complete-the-function-recall-table)
8. [Common traps & Rule of Three](#8-common-traps--rule-of-three)

---

## 1. Program skeleton + compile

```cpp
#include <iostream>
using namespace std;

int main() {
    // code
    return 0;
}
```

```bash
g++ -std=c++17 -Wall main.cpp -o app      # single file
g++ -std=c++17 -Wall main.cpp dynarr.cpp -o app   # multi-file (do NOT compile the .h)
```

**Read input:** `cin >> x;` &nbsp; **Print:** `cout << x << endl;`

---

## 2. Lab 1 — I/O, loops, basics

**Sum / arithmetic**
```cpp
int a, b;
cin >> a >> b;
cout << "Sum = " << a + b << endl;
```

**Factorial (loop)**
```cpp
long long fact = 1;
for (int i = 2; i <= n; i++) {
    fact *= i;
}
```

**Switch calculator**
```cpp
char op;
double x, y;
cin >> x >> op >> y;
switch (op) {
    case '+': cout << x + y; break;
    case '-': cout << x - y; break;
    case '*': cout << x * y; break;
    case '/':
        if (y != 0) cout << x / y;
        else cout << "Division by zero";
        break;
    default: cout << "Invalid operator";
}
```

**Primes in a range (e.g. 300–500)**
```cpp
for (int n = 300; n <= 500; n++) {
    bool isPrime = (n > 1);
    for (int d = 2; d * d <= n; d++) {   // check up to sqrt(n)
        if (n % d == 0) { isPrime = false; break; }
    }
    if (isPrime) cout << n << " ";
}
```

---

## 3. Lab 1 — a class in `.h` / `.cpp` / `main.cpp`

The 3-file split your exam expects. Example: `Box`.

**Box.h** — declaration only
```cpp
#ifndef BOX_H
#define BOX_H

class Box {
   private:
    double height, width, depth;

   public:
    Box(double h, double w, double d);   // constructor
    void volume() const;                 // const = does not modify members
};

#endif  // BOX_H
```

**Box.cpp** — definitions, scope with `Box::`
```cpp
#include <iostream>
#include "Box.h"
using namespace std;

Box::Box(double h, double w, double d) {
    height = h;
    width = w;
    depth = d;
}

void Box::volume() const {
    cout << "Volume = " << height * width * depth << endl;
}
```

**main.cpp** — driver
```cpp
#include "Box.h"

int main() {
    Box b(2, 3, 4);
    b.volume();
    return 0;
}
```

> **Pattern to memorize:** `.h` = guards + class with declarations; `.cpp` = `#include "x.h"` + `ClassName::method` bodies; `main.cpp` = `#include "x.h"` + use it.

---

## 4. Lab 2 — `dynArr` class

### 4a. 1D resizable `dynArr` (the richest single example — know this cold)

**dynarr.h**
```cpp
#ifndef DYNARR_H
#define DYNARR_H

class dynArr {
   private:
    int* data;
    int size;

   public:
    dynArr();                              // default
    dynArr(int s);                         // parameterized
    ~dynArr();                             // destructor
    void allocate(int s);                  // resize, keeps old values
    void setValue(int index, int value);
    int getValue(int index);
    int getSize();
};

#endif  // DYNARR_H
```

**dynarr.cpp**
```cpp
#include "dynarr.h"
using namespace std;

dynArr::dynArr() {
    data = nullptr;
    size = 0;
}

dynArr::dynArr(int s) {
    data = new int[s];
    size = s;
}

dynArr::~dynArr() {
    delete[] data;
}

void dynArr::allocate(int s) {
    if (s <= 0) {                 // invalid → empty the object
        delete[] data;
        data = nullptr;
        size = 0;
        return;
    }

    int* newData = new int[s];
    int limit = (s < size) ? s : size;   // copy the smaller count

    for (int i = 0; i < limit; i++) newData[i] = data[i];   // keep old
    for (int i = limit; i < s; i++) newData[i] = 0;         // pad with 0

    delete[] data;                // free old block
    data = newData;               // point to new block
    size = s;
}

void dynArr::setValue(int index, int value) { data[index] = value; }
int  dynArr::getValue(int index)            { return data[index]; }
int  dynArr::getSize()                       { return size; }
```

**main.cpp**
```cpp
#include <iostream>
#include "dynarr.h"
using namespace std;

int main() {
    dynArr a(5);
    for (int i = 0; i < 5; i++) a.setValue(i, i * 10);

    a.allocate(8);                          // grow, old values survive
    for (int i = 5; i < 8; i++) a.setValue(i, i * 10);

    for (int i = 0; i < a.getSize(); i++) cout << a.getValue(i) << " ";
    cout << endl;
    return 0;
}
```

### 4b. 2D `dynArr` (`int**`) with `clear()` helper

**dynarr.h** (key parts)
```cpp
class dynArr {
   private:
    int** data;
    int rows, cols;
    void clear();                 // private helper to free safely

   public:
    dynArr();
    dynArr(int r, int c);
    ~dynArr();
    void allocate(int r, int c);
    void setValue(int row, int col, int value);
    int getValue(int row, int col);
    int getRows();
    int getCols();
};
```

**dynarr.cpp** (the memory-critical parts)
```cpp
dynArr::dynArr() { data = nullptr; rows = 0; cols = 0; }

dynArr::dynArr(int r, int c) {
    data = nullptr; rows = 0; cols = 0;
    allocate(r, c);
}

dynArr::~dynArr() { clear(); }

void dynArr::clear() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) delete[] data[i];  // each row
        delete[] data;                                    // outer array
    }
    data = nullptr; rows = 0; cols = 0;
}

void dynArr::allocate(int r, int c) {
    clear();                            // free anything old first
    if (r <= 0 || c <= 0) return;
    rows = r; cols = c;
    data = new int*[rows];             // array of row pointers
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];       // each row
        for (int j = 0; j < cols; j++) data[i][j] = 0;
    }
}

void dynArr::setValue(int r, int c, int v) { data[r][c] = v; }
int  dynArr::getValue(int r, int c)        { return data[r][c]; }
int  dynArr::getRows()                      { return rows; }
int  dynArr::getCols()                      { return cols; }
```

---

## 5. Lab 3 — raw dynamic memory in `main()`

No class — pure `new` / `delete`. Four canonical shapes.

### 5a. Single dynamic value
```cpp
int* ptr = new int;     // allocate
*ptr = 42;              // use
cout << *ptr;
delete ptr;             // free (no [])
ptr = nullptr;          // avoid dangling pointer
```

### 5b. Dynamic 1D array
```cpp
int n;  cin >> n;
int* arr = new int[n];          // allocate
for (int i = 0; i < n; i++) cin >> arr[i];
// ... use arr ...
delete[] arr;                   // free with []
arr = nullptr;
```

### 5c. Dynamic 2D — equal rows (`char**`, strings)
```cpp
int rows, columns;
cin >> rows >> columns;
char** words = new char*[rows];                 // row pointers
for (int i = 0; i < rows; i++)
    words[i] = new char[columns + 1];           // +1 for '\0'

for (int i = 0; i < rows; i++)
    cin >> setw(columns + 1) >> words[i];       // setw guards overflow
                                                // (needs <iomanip>)
for (int i = 0; i < rows; i++) cout << words[i] << endl;

for (int i = 0; i < rows; i++) delete[] words[i];  // each row
delete[] words;                                    // outer array
words = nullptr;
```

### 5d. Dynamic 2D — jagged rows (each row a different length)
```cpp
int rows;  cin >> rows;
int* columns = new int[rows];        // length of each row
int** data   = new int*[rows];       // the rows

for (int i = 0; i < rows; i++) {
    cin >> columns[i];
    data[i] = new int[columns[i]];   // row i has columns[i] cells
}
for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns[i]; j++) cin >> data[i][j];

for (int i = 0; i < rows; i++) {     // print
    for (int j = 0; j < columns[i]; j++) cout << data[i][j] << " ";
    cout << endl;
}

for (int i = 0; i < rows; i++) delete[] data[i];  // each row
delete[] data;                                    // outer
delete[] columns;                                 // the lengths array
data = nullptr; columns = nullptr;
```

---

## 6. Deallocation rules

| You allocated with | Free with |
|---|---|
| `new int` | `delete ptr;` |
| `new int[n]` | `delete[] arr;` |
| `new int*[rows]` + `new int[cols]` per row | loop `delete[] data[i]` **then** `delete[] data` |

**Golden order for 2D:** inner rows first, outer array last. Reversing it leaks/crashes.
After freeing, set the pointer to `nullptr`.

---

## 7. "Complete the function" recall table

If the header is given and you must fill the body:

| Signature | Body |
|---|---|
| `dynArr::dynArr()` | `data = nullptr; size = 0;` |
| `dynArr::dynArr(int s)` | `data = new int[s]; size = s;` |
| `dynArr::~dynArr()` | `delete[] data;` |
| `int dynArr::getValue(int i)` | `return data[i];` |
| `void dynArr::setValue(int i, int v)` | `data[i] = v;` |
| `int dynArr::getSize()` | `return size;` |
| 2D `~dynArr()` | `clear();` (loop-delete rows, then outer) |

---

## 8. Common traps & Rule of Three

- **Forgot `[]` in `delete[]`** for arrays → undefined behavior. Match `new[]` ↔ `delete[]`.
- **Missing header guard** → "redefinition" errors when `.h` is included twice.
- **Compiling the `.h`** → don't. Compile `.cpp` files only; the `.h` is `#include`d.
- **`char` row size** → `new char[columns + 1]`, the `+1` holds `'\0'`.
- **Returning from a constructor before allocating**, then calling a method → null deref.

### Rule of Three (if the class is *copied* or *passed by value*)
The lab `dynArr` has **no copy constructor / assignment** — copying it makes two objects
share one pointer, so the destructor runs `delete[]` twice → **double free crash**.
If the exam asks for a "safe to copy" class, add these:

```cpp
// in dynarr.h, public:
dynArr(const dynArr& other);             // copy constructor
dynArr& operator=(const dynArr& other);  // copy assignment

// in dynarr.cpp:
dynArr::dynArr(const dynArr& other) {
    size = other.size;
    data = (size > 0) ? new int[size] : nullptr;
    for (int i = 0; i < size; i++) data[i] = other.data[i];   // deep copy
}

dynArr& dynArr::operator=(const dynArr& other) {
    if (this == &other) return *this;     // self-assignment guard
    delete[] data;                        // free old
    size = other.size;
    data = (size > 0) ? new int[size] : nullptr;
    for (int i = 0; i < size; i++) data[i] = other.data[i];
    return *this;
}
```

> **Rule of Three:** if you write any one of { destructor, copy constructor, copy
> assignment }, you usually need all three.
