# Exam Command Center Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Reorganize the CSE225L exam materials so the under-pressure workflow is obvious.

**Architecture:** Preserve the existing lab/course content and only rename the confusing exam-prep pieces. Use local scripts to regenerate Code::Blocks project metadata after moving files, then verify with text searches and C++ compile checks.

**Tech Stack:** PowerShell, Git, Python `make_cbp.py`, Code::Blocks `.cbp` metadata, C++17 with `g++`.

---

### Task 1: Rename Exam Folders And Files

**Files:**
- Move: `lab/Assessment/` to `lab/exam_workspace/`
- Move: `lab/04_exam_reference/lecture_problems/` to `lab/04_exam_reference/worked_examples/`
- Move: `lab/04_exam_reference/CHEATSHEET.md` to `lab/04_exam_reference/QUICK_REFERENCE.md`
- Move: `lab/04_exam_reference/SNIPPETS.md` to `lab/04_exam_reference/COPY_PASTE_SNIPPETS.md`

- [ ] **Step 1: Move paths**

```powershell
Move-Item -LiteralPath lab\Assessment -Destination lab\exam_workspace
Move-Item -LiteralPath lab\04_exam_reference\lecture_problems -Destination lab\04_exam_reference\worked_examples
Move-Item -LiteralPath lab\04_exam_reference\CHEATSHEET.md -Destination lab\04_exam_reference\QUICK_REFERENCE.md
Move-Item -LiteralPath lab\04_exam_reference\SNIPPETS.md -Destination lab\04_exam_reference\COPY_PASTE_SNIPPETS.md
```

- [ ] **Step 2: Check expected paths exist**

```powershell
Test-Path lab\exam_workspace
Test-Path lab\04_exam_reference\worked_examples
Test-Path lab\04_exam_reference\QUICK_REFERENCE.md
Test-Path lab\04_exam_reference\COPY_PASTE_SNIPPETS.md
```

Expected: each command prints `True`.

### Task 2: Update Documentation And Script Text

**Files:**
- Modify: `README.md`
- Modify: `lab/README.md`
- Modify: `lab/04_exam_reference/README.md`
- Modify: `lab/04_exam_reference/QUICK_REFERENCE.md`
- Modify: `lab/04_exam_reference/COPY_PASTE_SNIPPETS.md`
- Modify: `lab/04_exam_reference/make_cbp.py`
- Modify: `lab/exam_workspace/README.md`
- Modify: `lab/exam_workspace/main.cpp`
- Modify: `lab/exam_workspace/solution.h`
- Modify: `lab/exam_workspace/make_cbp.py`

- [ ] **Step 1: Replace old path names**

```powershell
rg -n "Assessment|lecture_problems|CHEATSHEET|SNIPPETS|04_exam_prep|toolkit" README.md lab
```

Expected before editing: matches for old names. Expected after editing: only intentional historical mentions, if any.

- [ ] **Step 2: Rewrite the top of `lab/04_exam_reference/README.md`**

Make the first section say:

```markdown
# CSE225L Exam Reference - Labs 1-5

Use this when studying before the exam. During the exam, write code in `../exam_workspace/`.
```

- [ ] **Step 3: Rewrite the top of `lab/exam_workspace/README.md`**

Make the first section say:

```markdown
# Exam Workspace

Open this folder during an assessment. It is the clean 3-file project for writing the answer fast.
```

### Task 3: Regenerate Code::Blocks Metadata

**Files:**
- Modify: `lab/04_exam_reference/exam_reference.workspace`
- Modify: `lab/04_exam_reference/worked_examples/*/*.cbp`
- Modify: `lab/04_exam_reference/past_assessments/assessment_1/solutions/*/*.cbp`
- Delete or replace: `lab/exam_workspace/Assessment.cbp`
- Create: `lab/exam_workspace/exam_workspace.cbp`

- [ ] **Step 1: Run reference generator**

```powershell
python lab\04_exam_reference\make_cbp.py
```

Expected: output lists projects under `worked_examples/` and `past_assessments/`.

- [ ] **Step 2: Run exam workspace generator**

```powershell
python lab\exam_workspace\make_cbp.py
```

Expected: output says `Wrote exam_workspace.cbp`.

### Task 4: Verify Exam Workflow

**Files:**
- Read: generated `.cbp` and `.workspace` files
- Read: docs changed in Task 2

- [ ] **Step 1: Compile exam workspace**

```powershell
g++ -std=c++17 -Wall lab\exam_workspace\main.cpp lab\exam_workspace\solution.cpp -o .build_check\exam_workspace.exe
```

Expected: exit code `0`.

- [ ] **Step 2: Compile reference projects**

Run representative `g++` commands for the worked examples and past assessment solutions.

Expected: each command exits `0`.

- [ ] **Step 3: Final old-name sweep**

```powershell
rg -n "04_exam_prep|lecture_problems|CHEATSHEET|SNIPPETS|toolkit|../Assessment|Assessment.cbp" README.md lab
```

Expected: no stale references that would send the student to the wrong place.
