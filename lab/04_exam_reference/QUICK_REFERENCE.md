# CSE225L Quick Reference - Labs 1-6

## What This File Is Doing

Use this file as the decision map during exam pressure. It tells you which
pattern to use. Use `COPY_PASTE_SNIPPETS.md` when you need the actual code.

Think of the files like this:

| File/folder | Use it for |
|---|---|
| `../exam_workspace/` | Current exam-day starter project |
| `QUICK_REFERENCE.md` | Decide the pattern quickly |
| `COPY_PASTE_SNIPPETS.md` | Paste code blocks |
| `worked_examples/` | Full solved lab-style master problems |
| `past_assessments/` | Previous exam style and solutions |

## Fast Exam Decisions

| Prompt says | Use this pattern |
|---|---|
| "main, source, header" | 3-file class answer |
| "create object and member function" | Normal class |
| "dynamic memory" | Raw `new`/`delete` helpers |
| "default constructor then size from user" | `allocate(size)` |
| "resize" | `clear()` then `allocate(newSize)` |
| "2D same columns" | `int**` with one row allocation loop |
| "different columns per row" | jagged `int**` plus `cols[]` |
| "template class" | `template <class T>` `dynArr<T>` |
| "template source file" | Put definitions in `.cpp`, include `.cpp` from `main.cpp` |
| "unsorted delete" | Replace deleted item with last item |
| "sorted insert/delete" | Shift elements to keep order |
| "timeStamp list" | `SortedType<timeStamp>` with `<`, `>`, and `==` |
| "custom object in list" | Write `operator==`; add `<` or `>` for sorted list |

## 3-File Class Shape

Normal class question:

```text
main.cpp      input, output, object use
thing.h       class declaration
thing.cpp     member definitions
```

Header:
- include guard
- private data
- public prototypes

Source:
- `#include "thing.h"`
- `ClassName::functionName` definitions

Compile:

```bash
g++ -std=c++17 -Wall main.cpp thing.cpp -o app
```

Do not compile the header.

## Template File Shape

Lab-style template question:

```text
main.cpp       includes both files
dynarr.h       template class declaration
dynarr.cpp     template member definitions
```

In `main.cpp`:

```cpp
#include "dynarr.h"
#include "dynarr.cpp"
```

Compile only `main.cpp`:

```bash
g++ -std=c++17 -Wall main.cpp -o app
```

Reason: template bodies must be visible to the compiler when `dynArr<int>` or
`dynArr<double>` is created.

## Allocate Pattern

Use a separate `allocate` function when:

- object starts empty and size comes later
- question says resize
- constructor should call shared allocation logic
- you want one safe place for invalid size handling

For 1D:

```cpp
void allocate(int s);
void clear();
```

Core order:

1. Delete old memory with `clear()`.
2. If size is invalid, stay empty.
3. Allocate new memory.
4. Save the new size.

For 2D:

```cpp
void allocate(int r, int c);
void clear();
```

Core order:

1. Delete each row.
2. Delete the outer pointer.
3. If rows or columns are invalid, stay empty.
4. Allocate row pointers.
5. Allocate each row.

## Memory Rules

| You write | You free with |
|---|---|
| `new int` | `delete p;` |
| `new int[n]` | `delete[] arr;` |
| `new int*[rows]` and row arrays | delete each row, then `delete[] outer;` |

After delete, set the pointer to `nullptr` when the pointer will still exist.

## Raw Array Patterns

1D dynamic array:

```cpp
int* arr = new int[n];
```

2D equal-column matrix:

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

Character word table:

```cpp
char** words = new char*[rows];
words[i] = new char[maxLength + 1];
```

The `+ 1` is for the null character.

## dynArr Class

Use for Lab 3 style questions where a class owns dynamic memory.

Common fields:

```cpp
int* data;
int size;
```

or for 2D:

```cpp
int** data;
int rows;
int cols;
```

Useful member functions:

- default constructor
- parameterized constructor
- destructor
- `clear()`
- `allocate(...)`
- `setValue(...)`
- `getValue(...)`
- `getSize()` or `getRows()`/`getCols()`
- `isEmpty()`

If copying objects is possible, add:

- copy constructor
- assignment operator

## Template dynArr

Use for Lab 4 template-class assessment.

Change concrete type to `T`:

```cpp
T* data;
void setValue(int index, T value);
T getValue(int index);
```

Every definition in `dynarr.cpp` starts with:

```cpp
template <class T>
```

And uses:

```cpp
dynArr<T>::
```

Stay with `dynArr<T>` unless the question specifically teaches another template
class. No operator-heavy template detour is needed for your current assessment
style.

## Unsorted List

Unsorted list behavior:

- `Insert`: put item at `currentSize`
- `Search`: scan from first to last
- `Delete`: find item, replace it with the last item, reduce size
- `Reset`: set cursor to `-1`
- `GetNext`: move cursor and return item

Important: unsorted delete does not preserve order.

Use this when the prompt does not say the list must stay sorted.

## Sorted List

Sorted list behavior:

- `Insert`: find correct location, shift right, insert
- `Search`: stop early when current item becomes bigger than target
- `Delete`: find item, shift left, reduce size

Important: sorted delete preserves order.

Use this when the prompt says ascending, sorted, ordered, or binary/early search
style.

Lab 6 uses `SortedType<T>`. For integers, sorted order is normal ascending
number order. For `timeStamp`, compare by actual time of day: hours first, then
minutes, then seconds, even though the manual inputs values as
`seconds minutes hours`.

## Custom Object

For a custom object inside an ADT:

- default constructor
- parameterized constructor
- `operator==` for search/delete
- `operator<` or `operator>` for sorted list
- `Print()` for output

For `Student`, compare by ID unless the question says otherwise.

For Lab 6 `timeStamp`, write `operator==`, `operator<`, and `operator>` because
sorted insert/search depend on comparisons.

## Exam Hall Checklist

Before submitting:

1. Did every `new[]` have a matching `delete[]`?
2. Did every `new` have a matching `delete`?
3. Did constructors initialize pointers to `nullptr`?
4. Did `allocate` handle invalid sizes?
5. Did `setValue` and `getValue` avoid invalid indexes?
6. Did template definitions stay visible by including the `.cpp` in `main.cpp`?
7. Did custom objects define the operators the list uses?
8. Did sorted operations shift, and unsorted delete swap with last?
