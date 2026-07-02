# Adaptive Exam Kit Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Turn the template workspace and reference files into a reusable exam kit for unknown Lab 3/4-style questions.

**Architecture:** Keep `exam_workspace` as a 3-file Code::Blocks project with a template `dynArr<T>` that includes `allocate(int s)`. Expand reference markdown files as structured pattern indexes, separating explanation from copy-paste blocks.

**Tech Stack:** C++17, Markdown, Python Code::Blocks generator, PowerShell verification.

---

### Task 1: Adaptive Exam Workspace

**Files:**
- Modify: `lab/exam_workspace/main.cpp`
- Modify: `lab/exam_workspace/solution.h`
- Modify: `lab/exam_workspace/solution.cpp`
- Modify: `lab/exam_workspace/README.md`

- [ ] Add `allocate(int s)` to `dynArr<T>`.
- [ ] Make `main.cpp` read size and values instead of using fixed demo values.
- [ ] Keep short comments for common exam swaps.

### Task 2: Extensive Reference Files

**Files:**
- Modify: `lab/04_exam_reference/QUICK_REFERENCE.md`
- Modify: `lab/04_exam_reference/COPY_PASTE_SNIPPETS.md`

- [ ] Add indexed sections for raw memory, `allocate`, class-owned arrays, template arrays, sorted lists, unsorted lists, and custom object ADT usage.
- [ ] Keep snippets complete enough to paste but organized by heading.

### Task 3: Regenerate And Verify

**Files:**
- Generated: `lab/exam_workspace/exam_workspace.cbp`
- Generated: `lab/04_exam_reference/exam_reference.workspace`
- Generated: worked example `.cbp` files

- [ ] Run both `make_cbp.py` scripts.
- [ ] Compile all examples.
- [ ] Run content checks.
- [ ] Commit the exam cleanup.
