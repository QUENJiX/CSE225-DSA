# Exam Kit Edge Cases Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Restore edge-case-heavy, exam-useful patterns to the CSE225L exam kit.

**Architecture:** Keep the kit split into a decision map, a pasteable code bank,
worked examples, and an adaptive exam workspace. The current assessment starter
uses lab-style template source definitions in `.cpp`, with `main.cpp` including
that source file so templates compile.

**Tech Stack:** C++17, Code::Blocks project files, PowerShell verification.

---

### Task 1: Add Exam Workspace Self-Check

**Files:**
- Create: `tests/exam_workspace_dynarr_self_check.cpp`

- [ ] **Step 1: Write a failing self-check**

Create a test driver that includes `solution.h` and `solution.cpp`, then checks
`clear`, invalid allocation, bounds-safe access, copy constructor, and assignment.
This should fail before the production code has those methods.

- [ ] **Step 2: Run the self-check and confirm RED**

Run:

```bash
g++ -std=c++17 -Wall -Wextra -I lab/exam_workspace tests/exam_workspace_dynarr_self_check.cpp -o tests/exam_workspace_dynarr_self_check.exe
```

Expected: compile fails because `clear`, copy constructor, or assignment support
is missing from `dynArr<T>`.

### Task 2: Strengthen Exam Workspace

**Files:**
- Modify: `lab/exam_workspace/solution.h`
- Modify: `lab/exam_workspace/solution.cpp`
- Modify: `lab/exam_workspace/main.cpp`
- Modify: `lab/exam_workspace/README.md`

- [ ] **Step 1: Add robust template-class members**

Add `clear`, copy constructor, assignment operator, bounds-safe `setValue` and
`getValue`, and `isEmpty`.

- [ ] **Step 2: Run the self-check and confirm GREEN**

Run the same compile command and execute the resulting `.exe`.

### Task 3: Strengthen Worked Examples

**Files:**
- Modify: `lab/04_exam_reference/worked_examples/02_dynamic_memory/main.cpp`
- Modify: `lab/04_exam_reference/worked_examples/03_dynarr_class/dynarr.h`
- Modify: `lab/04_exam_reference/worked_examples/03_dynarr_class/dynarr.cpp`
- Modify: `lab/04_exam_reference/worked_examples/04_template_dynarr/dynarr.h`
- Modify: `lab/04_exam_reference/worked_examples/04_template_dynarr/dynarr.cpp`
- Modify: `lab/04_exam_reference/worked_examples/04_template_dynarr/main.cpp`
- Modify: `lab/04_exam_reference/worked_examples/05_list_adt/unsortedtype.h`
- Modify: `lab/04_exam_reference/worked_examples/05_list_adt/unsortedtype.cpp`

- [ ] **Step 1: Add realistic edge-case handling**

Show invalid sizes, helper allocation/deletion, reallocation, bounds checks,
empty/full list handling, and missing-item behavior.

- [ ] **Step 2: Compile each changed worked example**

Run `g++ -std=c++17 -Wall -Wextra main.cpp -o app.exe` inside each changed
example directory.

### Task 4: Rewrite Reference Docs

**Files:**
- Modify: `lab/04_exam_reference/QUICK_REFERENCE.md`
- Modify: `lab/04_exam_reference/COPY_PASTE_SNIPPETS.md`

- [ ] **Step 1: Make Quick Reference a decision map**

Clearly explain that Quick Reference tells which pattern to use, while Snippets
contains pasteable code.

- [ ] **Step 2: Make Snippets an extensive code bank**

Add separate allocate/delete helpers, safe dynamic array patterns, robust
`dynArr`, template `dynArr`, sorted list operations, unsorted list operations,
and custom object operators.

### Task 5: Regenerate Projects, Verify, Commit

**Files:**
- Modify generated `.cbp` and `.workspace` files as needed.

- [ ] **Step 1: Run make_cbp scripts**

Run:

```bash
python lab/exam_workspace/make_cbp.py
python lab/04_exam_reference/make_cbp.py
```

- [ ] **Step 2: Run compile checks**

Compile the self-check and changed examples.

- [ ] **Step 3: Commit**

Stage the revision and commit with:

```bash
git commit -m "chore: enrich CSE225L exam edge cases"
```
