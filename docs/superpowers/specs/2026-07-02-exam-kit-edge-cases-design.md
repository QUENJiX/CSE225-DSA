# Exam Kit Edge Cases Design

## Goal

Restore grade-protective edge cases to the CSE225L exam kit while keeping the
files easy to use under time pressure.

## Scope

This revision updates the existing `lab/exam_workspace` and
`lab/04_exam_reference` material. It does not add unrelated lecture content or
turn the examples into production libraries.

## Design

`QUICK_REFERENCE.md` is the decision map. It explains which pattern to pick when
an exam prompt mentions allocation, template classes, raw arrays, sorted lists,
unsorted lists, or three-file class answers.

`COPY_PASTE_SNIPPETS.md` is the code bank. It contains paste-ready versions of
the patterns students are likely to need: separate allocate/delete helpers,
safe `dynArr` methods, template `.h/.cpp` split, raw 1D/2D/jagged arrays, and
sorted/unsorted list operations.

`exam_workspace` stays focused on the current template-class assessment. It
uses a lab-style `dynArr<T>` with method definitions in `solution.cpp`, included
from `main.cpp`. It adds practical edge cases: invalid allocation, safe clear,
safe reallocation, bounds checks, copy constructor, and assignment operator.

`worked_examples` remain one master problem per lab area, but the answers stop
being happy-path only. They should show invalid-size handling, cleanup helpers,
missing-item handling, full-list handling, and reallocation patterns where those
patterns fit the lab.

## Verification

Compile the updated examples with `g++`. Add a small C++ self-check for
`exam_workspace` so the new `dynArr<T>` edge behavior is tested directly.
