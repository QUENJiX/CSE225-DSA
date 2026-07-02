# Exam Workspace - Adaptive Lab 3/4 Starter

Use this when the assessment is about `dynArr`, dynamic arrays, or template
classes. It is not a solved answer; it is a clean starting point.

## What Is Ready

- 3-file structure: `main.cpp`, `solution.h`, `solution.cpp`
- template `dynArr<T>`
- default constructor
- parameterized constructor
- copy constructor and assignment operator
- destructor
- `clear()`
- `allocate(int s)`
- `setValue`, `getValue`, `getSize`, `isEmpty`
- small driver helpers for reading, printing, counting, and first-index search

## Template Split

Definitions stay in `solution.cpp` to match the lab style. Because templates must
be visible when used, `main.cpp` includes the source file:

```cpp
#include "solution.h"
#include "solution.cpp"
```

Compile only `main.cpp`:

```bash
g++ -std=c++17 -Wall main.cpp -o app
```

## Fast Exam Edits

- Need `double`? Change `dynArr<int>` and `int value` to `double`.
- Need a parameterized constructor? Use `dynArr<int> arr(n);`.
- Need default constructor + allocation? Keep `dynArr<int> arr; arr.allocate(n);`.
- Need only storage? Delete the helper functions in `main.cpp` and keep the class.
- Need search/count? Keep `countValue` or `findFirstIndex`.
- Need to resize? Call `arr.allocate(newSize);`. It safely clears the old memory.
- Need to empty the array? Call `arr.clear();`.
- Need raw `int*` or `int**` instead? Copy from `../04_exam_reference/COPY_PASTE_SNIPPETS.md`.

## Edge-Case Habits

- Invalid size becomes an empty array.
- Invalid index is ignored for `setValue`.
- Invalid index returns `T()` for `getValue`.
- Copying creates a separate array, so changing the copy does not change the original.
