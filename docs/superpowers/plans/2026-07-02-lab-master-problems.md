# Lab Master Problems Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Rewrite the exam reference internals into lab-authentic master problems and make `exam_workspace` ready for a template-class assessment.

**Architecture:** Keep one folder per lab under `lab/04_exam_reference/worked_examples/`. Each folder contains `PROBLEM.md`, `main.cpp`, and the lab-style header/source files needed for that topic. Keep template implementations in `.cpp` files and include those `.cpp` files from `main.cpp` where needed.

**Tech Stack:** C++17, Code::Blocks `.cbp`, PowerShell, Python `make_cbp.py`, Markdown.

---

### Task 1: Exam Workspace Template Starter

**Files:**
- Modify: `lab/exam_workspace/main.cpp`
- Modify: `lab/exam_workspace/solution.h`
- Modify: `lab/exam_workspace/solution.cpp`
- Modify: `lab/exam_workspace/README.md`

- [ ] Replace the generic `Solution` class with a template `dynArr<T>` starter.
- [ ] Keep method definitions in `solution.cpp`.
- [ ] Include `solution.cpp` from `main.cpp`.
- [ ] Keep comments short and exam-facing.

### Task 2: Worked Examples

**Files:**
- Modify/create/delete files under `lab/04_exam_reference/worked_examples/`

- [ ] Lab 1: one master problem covering basic input, functions, loops, and `Box`.
- [ ] Lab 2: one master problem covering raw dynamic memory only.
- [ ] Lab 3: one master problem covering non-template `dynArr`.
- [ ] Lab 4: one master problem covering template `dynArr<T>` only.
- [ ] Lab 5: one master problem covering `UnsortedType<T>` and `Student`.

### Task 3: Reference Documents

**Files:**
- Modify: `lab/04_exam_reference/README.md`
- Modify: `lab/04_exam_reference/QUICK_REFERENCE.md`
- Modify: `lab/04_exam_reference/COPY_PASTE_SNIPPETS.md`

- [ ] Update folder names and lab map.
- [ ] Remove `Complex` and operator-overloading material from the Labs 1-5 exam reference.
- [ ] Keep snippets short and copy-paste oriented.

### Task 4: Project Metadata And Verification

**Files:**
- Generated: `.cbp` files and `exam_reference.workspace`

- [ ] Run `python lab\04_exam_reference\make_cbp.py`.
- [ ] Run `python lab\exam_workspace\make_cbp.py`.
- [ ] Compile all examples.
- [ ] Search for stale `Complex`, operator-overloading, and old folder references.
