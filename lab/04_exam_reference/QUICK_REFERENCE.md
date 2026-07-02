# CSE225L Quick Reference - Labs 1-5

Use this as the map. Use `COPY_PASTE_SNIPPETS.md` when you need the actual
code block.

## Fast Index

| Need | Jump |
|---|---|
| Exam workspace | `../exam_workspace/` |
| 3-file class shape | [Class files](#class-files) |
| Template class shape | [Template files](#template-files) |
| `allocate(int s)` | [Allocate](#allocate) |
| Raw `new` / `delete` | [Memory rules](#memory-rules) |
| 1D / 2D / jagged arrays | [Array patterns](#array-patterns) |
| `dynArr` class | [dynArr class](#dynarr-class) |
| `dynArr<T>` template | [Template dynArr](#template-dynarr) |
| Unsorted List ADT | [Unsorted list](#unsorted-list) |
| Sorted List ADT | [Sorted list](#sorted-list) |
| Student/custom object | [Custom object](#custom-object) |
| Assessment 1 style | [Assessment 1 patterns](#assessment-1-patterns) |

## Class Files

Normal class questions usually mean:

```text
main.cpp      driver / input / calls
thing.h       class declaration
thing.cpp     member definitions
```

Header contains fields and function prototypes. Source contains `ClassName::`
definitions. `main.cpp` creates objects and calls functions.

Compile:

```bash
g++ -std=c++17 -Wall main.cpp thing.cpp -o app
```

Do not compile the header.

## Template Files

Template questions can still use the lab split:

```text
main.cpp      includes header and template source
dynarr.h      template class declaration
dynarr.cpp    template method definitions
```

In `main.cpp`:

```cpp
#include "dynarr.h"
#include "dynarr.cpp"
```

Compile `main.cpp` only:

```bash
g++ -std=c++17 -Wall main.cpp -o app
```

## Allocate

Use `allocate(int s)` when the question says resize, create after default
constructor, or allocate using a user-provided size.

Core steps:

1. Free old memory.
2. If size is invalid, set pointer to `nullptr` and size to `0`.
3. Allocate new array.
4. Save new size.

For a simple lab answer, not preserving old values is usually enough unless the
question explicitly says "keep previous values".

## Memory Rules

| You write | You must free with |
|---|---|
| `new int` | `delete p;` |
| `new int[n]` | `delete[] arr;` |
| `new int*[rows]` plus row arrays | delete each row, then `delete[] outer;` |

Good habit after delete:

```cpp
p = nullptr;
```

## Array Patterns

1D dynamic array:

```cpp
int* arr = new int[n];
```

2D equal row array:

```cpp
int** data = new int*[rows];
for (int i = 0; i < rows; i++) {
    data[i] = new int[cols];
}
```

Jagged array:

```cpp
int* cols = new int[rows];
int** data = new int*[rows];
```

Character strings:

```cpp
char** words = new char*[rows];
words[i] = new char[cols + 1];
```

`cols + 1` is for the null character.

## dynArr Class

Use this for Lab 3 style questions. It is a class that owns dynamic memory.

Common fields:

```cpp
int* data;
int size;
```

Common functions:

- default constructor
- parameterized constructor
- destructor
- `allocate(int s)`
- `setValue`
- `getValue`
- `getSize`

If the lab asks for 2D, fields usually become:

```cpp
int** data;
int rows;
int cols;
```

## Template dynArr

Use this for Lab 4 style questions. Convert the type from `int` to `T`.

Change:

```cpp
int* data;
void setValue(int index, int value);
int getValue(int index);
```

To:

```cpp
T* data;
void setValue(int index, T value);
T getValue(int index);
```

Every source definition starts with:

```cpp
template <class T>
```

And uses:

```cpp
dynArr<T>::
```

## Unsorted List

Unsorted list operations:

- `Insert`: append at `currentSize`
- `Search`: linear scan
- `Delete`: find item, replace it with last item, reduce size
- `Reset`: set cursor to `-1`
- `GetNext`: advance cursor and return item

Important: delete does not preserve order.

## Sorted List

Sorted list operations are similar, but `Insert` keeps order.

Typical sorted insert:

1. Find the first position where `data[pos] > item`.
2. Shift elements right.
3. Put item in the hole.
4. Increase size.

Typical sorted search can stop early when `data[i] > item`.

This may appear as a later list variant. Keep the pattern handy.

## Custom Object

For a custom object inside an ADT, usually write:

- default constructor
- parameterized constructor
- `operator==` for search/delete
- `operator>` or `operator<` for sorted insert/search
- `Print()`

For `Student`, compare by ID unless the question says otherwise.

## Assessment 1 Patterns

Q1: one input, one branch, first true condition wins.

Q2: raw `int**`, print rows in reverse:

```cpp
for (int i = rows - 1; i >= 0; i--) {
    for (int j = 0; j < cols; j++) {
        cout << data[i][j] << " ";
    }
    cout << endl;
}
```

Q3: given header/source, add one member:

1. Add prototype in `.h`.
2. Add `ClassName::functionName` body in `.cpp`.
3. Call from `main.cpp`.

If the question says the function returns something, use that return type even
if the prompt accidentally writes `void`.
