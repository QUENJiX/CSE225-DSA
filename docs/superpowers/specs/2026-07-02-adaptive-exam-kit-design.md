# Adaptive Exam Kit Design

## Goal

Make `exam_workspace` useful when the actual question is unknown, especially for Lab 3 and Lab 4 variants involving arrays, `dynArr`, `allocate`, and template classes.

## Design

- `exam_workspace` should be a launchpad, not a solved lab answer.
- Keep the three-file structure: `main.cpp`, `solution.h`, and `solution.cpp`.
- Keep template definitions in `solution.cpp` and include it from `main.cpp`.
- Include reusable methods likely to appear in Lab 3/4 questions:
  - constructors
  - destructor
  - `allocate(int s)`
  - `setValue`
  - `getValue`
  - `getSize`
- `main.cpp` should read `n`, allocate a dynamic array, input values, print values, and include short swap notes for different types or question variants.
- `QUICK_REFERENCE.md` should be a broad indexed guide, not a tiny summary.
- `COPY_PASTE_SNIPPETS.md` should be an extensive code bank with raw memory, class, template, sorted list, unsorted list, and custom object patterns.

## Verification

- Red checks confirm missing `allocate` before editing.
- Compile `exam_workspace` and all worked examples.
- Run project generators after editing.
- Confirm snippets include `SortedType`, `UnsortedType`, `allocate(int s)`, and major delete patterns.
