# Lab Master Problems Design

## Goal

Make the exam reference code feel like the instructor's lab and assessment style: one grounded master problem per Lab 1-5, simple 3-file answers, and quick references that help during time pressure instead of creating a code jungle.

## User Corrections

- Lab 4 should focus on template `dynArr<T>` only. It should not include `Complex` or operator overloading.
- Template implementations should live in a `.cpp` file because that matches the lab/source split. The driver should include that `.cpp` so the template still compiles.
- `exam_workspace/` should be topic-ready for the current template-class assessment. It should be easy to open at exam start and modify around the day’s topic.

## Design

- `lab/exam_workspace/` becomes a template-class starter with `main.cpp`, `solution.h`, and `solution.cpp`.
- `solution.h` declares `template <class T> class dynArr`.
- `solution.cpp` defines template methods. `main.cpp` includes both `solution.h` and `solution.cpp`.
- `worked_examples/01_basics_and_class/` remains one Lab 1 master problem for C++ basics, functions, and a simple class.
- `worked_examples/02_dynamic_memory/` becomes raw dynamic memory only: single value, 1D array, 2D char strings, and jagged 2D int.
- `worked_examples/03_dynarr_class/` covers the non-template `dynArr` class with constructors, destructor, `allocate`, `setValue`, and `getValue`.
- `worked_examples/04_template_dynarr/` covers only `dynArr<T>`.
- `worked_examples/05_list_adt/` covers `UnsortedType<T>` with `int` and `Student`.
- `QUICK_REFERENCE.md` and `COPY_PASTE_SNIPPETS.md` should be shorter, organized around exam moves, and avoid unrelated/professional C++.

## Verification

- Run red checks before editing for the missing template workspace and unwanted `Complex` material.
- Regenerate Code::Blocks project files.
- Compile `exam_workspace` and every worked example with `g++ -std=c++17 -Wall`.
- Run stale-content search for `Complex`, operator overloading, and old worked-example folder names.
