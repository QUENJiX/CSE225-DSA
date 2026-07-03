# Lab 6 Master Problem - Sorted List ADT

Use an array-based `SortedType<T>` list. This is the sorted version of the Lab 5
list pattern.

## Files

- `sortedtype.h` - template class declaration
- `sortedtype.cpp` - template member definitions
- `main.cpp` - driver with integer and `timeStamp` examples

Because `SortedType` is a template class and the definitions are in
`sortedtype.cpp`, include both files in the driver:

```cpp
#include "sortedtype.h"
#include "sortedtype.cpp"
```

## Part A - Integer List

Create a `SortedType<int>` and perform the manual's operations:

1. Insert `5`, `4`, `2`, and `1`.
2. Print the list. Expected sorted order: `1 2 4 5`.
3. Insert `7`.
4. Insert `12` to show the full-list case.
5. Search `6` and `5`.
6. Print whether the list is full.
7. Delete `1`, then print.
8. Delete `4`, then print.
9. Delete `16` to show the missing-item case.

## Part B - timeStamp List

Create a `timeStamp` class in `main.cpp`.

Private data:
- `seconds`
- `minutes`
- `hours`

Public behavior:
- default constructor
- parameterized constructor
- `operator==`
- `operator<`
- `operator>`
- `Print()`

The input order is `seconds minutes hours`, but sorting should compare the real
time of day: hours first, then minutes, then seconds.

Insert these values:

```text
15 34 23
13 13 02
43 45 12
25 36 17
52 02 20
```

Delete `25 36 17`, then print the remaining list.

Expected order:

```text
13: 13: 02
43: 45: 12
52: 02: 20
15: 34: 23
```

## Build

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o app
```
