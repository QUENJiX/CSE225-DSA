# CSE225L — Assessment 1 (Summer 2026, Section 8)

*Time: 45 minutes · Total: 30 marks.* Worked solutions in [`solutions/`](solutions/).

---

## Question 1 — [10 marks]

Write a C++ program that takes an integer `N` as input and performs **only one** of
the following operations:

- If `N` is divisible by 4, print the squares of all integers from 1 to `N`.
- Else if `N` is divisible by 6, print all odd numbers from 1 to `N`.
- Else if `N` is divisible by 9, calculate and print the sum of all integers from 1 to `N`.
- Otherwise, print: `Invalid Category`

→ Solution: [`solutions/q1_control_flow/`](solutions/q1_control_flow/)

---

## Question 2 — [10 marks]

Write a C++ program that:

1. Takes the number of rows and columns from the user.
2. Dynamically allocates a 2D integer array using a pointer-to-pointer (`int**`).
3. Takes the elements of the array as input.
4. Prints the matrix row by row **in reverse order**.

```
Sample Input        Sample Output
3 3                 7 8 9
1 2 3               4 5 6
4 5 6               1 2 3
7 8 9
```

→ Solution: [`solutions/q2_reverse_matrix/`](solutions/q2_reverse_matrix/)

---

## Question 3 — [10 marks]

A kindergarten wants to maintain information about its children. The header
(`Child.h`) and source (`Child.cpp`) are provided with fields `name`, `age`,
`favoriteColor`, `favoriteFood`, a default constructor, a parameterized
constructor, `setInfo(...)`, and `printInfo()`.

**Part A [5 marks]** — In `main.cpp`:
1. Create a `Child` object.
2. Use the default constructor and `setInfo()` to initialize it from user input.
3. Print the child's information using `printInfo()`.

**Part B [5 marks]** — Modify the header and source by adding a member function
for the child's favorite subject. In `main.cpp`, call it on the object from Part A
and print the result after taking the relevant input.

→ Solution: [`solutions/q3_child_class/`](solutions/q3_child_class/)
*(Part B's wording is ambiguous — the solution stores and returns the subject as a
`string`; adjust if your version differs.)*
