# Lab 1 Master Problem - C++ Basics and Box Class

Write one C++ program that covers the Lab 1 basics.

## Part A - Basic C++ in `main.cpp`

1. Read two integers and print their sum.
2. Read an integer `n` and print `n!`.
3. Read `a op b` where `op` is `+`, `-`, `*`, or `/`, then print the result.
4. Print all prime numbers from 300 to 500 using an `isPrime` function.

## Part B - Box class

Create a `Box` class using `box.h` and `box.cpp`.

Private data:
- `height`
- `width`
- `depth`

Public functions:
- default constructor
- parameterized constructor
- `setInfo(h, w, d)`
- `volume()`

In `main.cpp`, create two `Box` objects and print their volumes.

## Build

```bash
g++ -std=c++17 -Wall main.cpp box.cpp -o app
```
