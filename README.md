# CSE225: Data Structures and Algorithms in C++

This workspace is set up for a low-friction CSE225 semester: quick compile/run/debug from VS Code, ready-to-use problem templates, focused demo files, and notes that connect C++ syntax to DSA habits.

## Quick Start

1. Open `../Semester-04.code-workspace` for the full semester setup, or open this folder for a focused coding session.
2. Install a C++ compiler if `g++ --version` does not work in the terminal.
   - Windows-friendly choices: MSYS2 MinGW-w64, WinLibs, or the MinGW toolchain bundled with some IDEs.
3. Open any `.cpp` file.
4. Use:
   - `Ctrl+Shift+B` -> build the active file.
   - Terminal -> Run Task -> `Run active C++ file`.
   - Terminal -> Run Task -> `Run active C++ file with templates/input.txt`.
   - Run and Debug -> `Debug active C++ file`.

## Folder Map

- `00_cpp_refresh/` - C++ syntax and STL refreshers before OOP/DSA.
- `01_oop_cpp/` - C++ OOP for someone who already knows Java OOP.
- `02_adt_and_domain_analysis/` - ADTs, interface vs implementation, and choosing structures from problem-domain features.
- `03_complexity/` - Big-O and binary search patterns.
- `04_linear_ds/` - arrays, strings, linked lists, stacks, queues, maps, sets.
- `05_recursion_backtracking/` - recursion, subsets, permutations, backtracking.
- `06_sorting_searching/` - classic sorting and searching algorithms.
- `07_trees/` - binary trees, BSTs, heaps.
- `08_graphs/` - BFS, DFS, shortest paths, MST, topological sort.
- `09_dynamic_programming/` - memoization, tabulation, common DP shapes.
- `10_problem_solving/` - solved problems, contest files, and pattern notes.
- `lab/` - CSE225L notes, practice, submissions, and assessment rebuilds.
- `templates/` - starter templates for problems, classes, and algorithm notes.
- `resources/` - cheat sheets, syllabus alignment, data-structure decision guide, debugging checklist, and book tracker.
- `playground/` - scratch experiments that do not need to be polished.
- `scripts/` - helper scripts for making new problem files.

## Material Library

Official PDFs, slides, textbooks, quizzes, and lab manuals are kept in `../Materials/CSE225/` and `../Materials/CSE225L/`.
Use `resources/materials_index.md` to map those materials to this workspace's topic folders.

## Create A New Problem File

From the VS Code terminal:

```powershell
.\scripts\New-Problem.ps1 two_sum
```

That creates:

```text
10_problem_solving/solved/two_sum.cpp
```

You can also choose another folder:

```powershell
.\scripts\New-Problem.ps1 binary_search 03_complexity
```

## Study Rhythm

1. Read one demo file.
2. Run it.
3. Change one thing and predict the output.
4. Solve 2 to 4 small problems using that topic.
5. Write the pattern in `10_problem_solving/notes/patterns.md`.

The goal is not to collect files. The goal is to make every concept executable.





