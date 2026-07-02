# Lab 3 Master Problem - dynArr Class

Build a class that owns a dynamic 2D integer array.

## Files

- `dynarr.h` - class declaration
- `dynarr.cpp` - member function definitions
- `main.cpp` - driver

## Class

Class name: `dynArr`

Private data:
- `int** data`
- `int rows`
- `int cols`

Public functions:
- default constructor
- parameterized constructor `dynArr(int r, int c)`
- copy constructor
- destructor
- assignment operator
- `clear()`
- `allocate(int r, int c)`
- `setValue(int row, int col, int value)`
- `getValue(int row, int col)`
- `getRows()`
- `getCols()`
- `isEmpty()`

## Driver

In `main.cpp`, read row and column counts, create a `dynArr`, input all values,
and print the matrix. Also show invalid-index access, copying, and `clear()`.

The class should handle invalid row/column counts by becoming empty.

## Build

```bash
g++ -std=c++17 -Wall main.cpp dynarr.cpp -o app
```
