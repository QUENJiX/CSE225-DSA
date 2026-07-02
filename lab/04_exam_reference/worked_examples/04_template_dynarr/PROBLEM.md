# Lab 4 Master Problem - Template dynArr

Convert the `dynArr` class into a template class so it can store different data
types.

## Files

- `dynarr.h` - template class declaration
- `dynarr.cpp` - template member definitions
- `main.cpp` - driver

## Class

Class name: `dynArr<T>`

Private data:
- `T* data`
- `int size`

Public functions:
- default constructor
- parameterized constructor `dynArr(int s)`
- destructor
- `setValue(int index, T value)`
- `getValue(int index)`
- `getSize()`

## Driver

In `main.cpp`, create and test:

1. `dynArr<int>`
2. `dynArr<double>`

Because this is a template and the definitions are in `dynarr.cpp`, include both
files in `main.cpp`:

```cpp
#include "dynarr.h"
#include "dynarr.cpp"
```

## Build

```bash
g++ -std=c++17 -Wall main.cpp -o app
```
