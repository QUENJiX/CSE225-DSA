# Lab 5 Master Problem - Unsorted List ADT

Use the given array-based `UnsortedType<T>` list.

## Part A - Integer list

In `main.cpp`:

1. Create an `UnsortedType<int>`.
2. Insert `5`, `7`, `6`, and `9`.
3. Insert extra values to show the full-list case.
4. Print the list using `Reset()` and `GetNext()`.
5. Search for `6`.
6. Delete `7`.
7. Try to delete a missing value.
8. Print the list again.

## Part B - Student list

Create a `Student` class in `main.cpp`.

Private data:
- `id`
- `name`
- `cgpa`

Public functions:
- default constructor
- parameterized constructor
- `operator==` that compares by `id`
- `Print()`

Create an `UnsortedType<Student>`, insert three students, delete the student
with ID `15467`, print the remaining students, then call `MakeEmpty()`.

## Build

```bash
g++ -std=c++17 -Wall main.cpp -o app
```
