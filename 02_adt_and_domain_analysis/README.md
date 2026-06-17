# ADTs and Domain Analysis

This section connects the official CSE225 wording to code.

## Abstract Data Type

An ADT describes **what operations are allowed** and **what behavior those operations promise**. It does not force one exact implementation.

Examples:

- Stack ADT: `push`, `pop`, `top`, `empty`.
- Queue ADT: `enqueue`, `dequeue`, `front`, `empty`.
- List ADT: `insert`, `erase`, `get`, `size`.
- Map/Dictionary ADT: `put`, `get`, `contains`, `erase`.

## Implementation

The implementation is **how the ADT is built internally**.

A stack can be implemented with:

- an array/vector,
- a linked list,
- a deque.

Same ADT. Different tradeoffs.

## Domain Analysis

Problem domain analysis means looking at the actual problem and asking:

- Do I need fast search by key?
- Do I need sorted order?
- Do I need only the most recent item?
- Do I need first-in-first-out behavior?
- Do I need relationships between objects?
- Do I need the minimum/maximum repeatedly?
- Are insertions/deletions frequent?
- Are duplicates meaningful?

The answer should guide the data structure choice.

## Files

- `01_stack_adt.cpp` - Stack interface with vector and linked-list implementations.
- `02_queue_adt.cpp` - Queue interface with deque and circular-array implementations.
- `03_list_adt.cpp` - List interface with array-list and linked-list implementations.
- `04_domain_analysis_student_records.cpp` - Choosing structures from problem-domain features.
