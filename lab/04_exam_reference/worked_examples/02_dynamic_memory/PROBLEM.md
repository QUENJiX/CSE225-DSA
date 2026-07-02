# Lab 2 Master Problem - Dynamic Memory

Write one C++ program in `main.cpp` that covers the Lab 2 dynamic memory tasks.

## Tasks

1. Allocate one integer using `new int`, assign a value, print it, then `delete`.
2. Read a size, allocate a dynamic 1D integer array, input values, print values,
   then `delete[]`. Use separate allocate/delete helper functions.
3. Read rows and maximum word length, allocate a 2D character array using
   `char**`, input one word per row, print the words, then free all rows and the
   outer pointer. Use separate allocate/delete helper functions.
4. Read row count and each row length, allocate a jagged 2D integer array using
   `int**`, input values, print the array, then free all rows, the outer pointer,
   and the row-length array. Handle invalid row lengths as empty rows.

Each dynamic pattern should handle invalid sizes without trying to allocate bad
memory.

## Build

```bash
g++ -std=c++17 -Wall main.cpp -o app
```
