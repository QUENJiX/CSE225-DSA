# Exam Workspace - Lab 5 Assessment Starter

Use this for the Lab 5 assessment on array-based `UnsortedType<T>`.
For your assessment on July 5, 2026, this folder is the clean project to open
first.

## What Is Ready

- 3-file structure: `main.cpp`, `unsortedtype.h`, `unsortedtype.cpp`
- template `UnsortedType<T>`
- default constructor
- destructor
- `Length`, `IsFull`, `IsEmpty`, `MakeEmpty`
- `Insert`, `Search`, `Delete`
- `Reset`, `GetNext`
- integer list driver
- custom `Student` object driver

## Template Split

Definitions stay in `unsortedtype.cpp` to match the lab style. Because templates
must be visible when used, `main.cpp` includes the source file:

```cpp
#include "unsortedtype.h"
#include "unsortedtype.cpp"
```

Compile only `main.cpp`:

```bash
g++ -std=c++17 -Wall main.cpp -o app
```

## Fast Exam Edits

- Need only integers? Keep `UnsortedType<int>` and delete the `Student` part.
- Need a custom class? Rename `Student`, change fields, keep `operator==`.
- Need search/delete by ID? Create a temporary object with only the ID filled.
- Need print traversal? Use `Reset()` before the `GetNext()` loop.
- Need full-list behavior? Keep `IsFull()` before or inside insert.
- If the instructor gives `unsortedtype.h/.cpp`, do not edit them unless asked.

## Edge-Case Habits

- Insert into a full list prints an error and does not change length.
- Search sets `found` to `false` first.
- Delete from an unsorted list replaces the removed item with the last item.
- Delete does not preserve order.
- `MakeEmpty()` should reset both length and traversal cursor.
- `Reset()` should happen before every traversal loop.
