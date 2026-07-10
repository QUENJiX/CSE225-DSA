# Lab 5 + Lab 6 Assessment Workspace

This is one ready-to-run project for both array-based template ADTs:

- `UnsortedType<T>` from Lab 5
- `SortedType<T>` from Lab 6
- `Book` as an equality-based custom type
- `Appointment` as an ordered custom type
- one `main.cpp` demonstrating integers and custom objects

## Files to Know

| Files | Assessment concept |
|---|---|
| `unsortedtype.h/.cpp` | template, linear search, last-item replacement delete |
| `sortedtype.h/.cpp` | template, sorted insertion, binary search, shifting delete |
| `book.h/.cpp` | constructors and `==`, `!=` overloads |
| `appointment.h/.cpp` | constructors and `<`, `>`, `==` overloads |
| `main.cpp` | traversal, search, delete, and both custom object lists |

## Build

From this folder:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp book.cpp appointment.cpp -o exam_app
./exam_app
```

The template implementation files are included by `main.cpp`, so do **not** add
`unsortedtype.cpp` or `sortedtype.cpp` to the compile command.

For Code::Blocks, run `python make_cbp.py`, open `exam_workspace.cbp`, and press
F9. The generated project handles the template source files correctly.

## Fast Assessment Adaptation

1. Replace the sample values in `main.cpp` with the question's values.
2. Rename `Book` or `Appointment` if the question gives another domain class.
3. For an unsorted custom object, overload `==` for search/delete.
4. For a sorted custom object, overload `<`, `>`, and `==` using the field that
   defines ordering.
5. Call `Reset()` before every traversal using `GetNext()`.

## Behaviors to Remember

- Unsorted insert appends at the end.
- Unsorted search is linear: `O(n)`.
- Unsorted delete replaces the deleted slot with the last item: `O(n)` search,
  then `O(1)` removal; original order is not preserved.
- Sorted insert shifts items right: `O(n)`.
- Sorted search uses binary search: `O(log n)`.
- Sorted delete shifts items left: `O(n)`; sorted order is preserved.
- A template's method definitions must be visible where the template is used.
- Both lists have capacity 5 to match the labs.
