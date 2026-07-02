# Exam Command Center Design

## Goal

Make the CSE225L lab area easy to use under exam pressure: one obvious place to code, one obvious place to read explanations, one obvious place to copy small patterns, and one obvious place to compare worked examples.

## Approved Direction

Use an exam command center structure instead of a course archive structure. The existing numbered lab folders stay intact, but the assessment-related material gets clearer names and links.

## Target Layout

```text
lab/
├── 00_lab_notes/
├── 01_lab_practice/
├── 02_lab_submissions/
├── 03_assessment_rebuilds/
├── 04_exam_reference/
│   ├── README.md
│   ├── QUICK_REFERENCE.md
│   ├── COPY_PASTE_SNIPPETS.md
│   ├── worked_examples/
│   ├── past_assessments/
│   ├── make_cbp.py
│   └── exam_reference.workspace
└── exam_workspace/
    ├── README.md
    ├── main.cpp
    ├── solution.h
    ├── solution.cpp
    ├── make_cbp.py
    └── exam_workspace.cbp
```

## Naming Rules

- `exam_workspace/` is the only folder meant for writing code during an exam.
- `04_exam_reference/` is read-only study support.
- `QUICK_REFERENCE.md` is the explained cheat sheet.
- `COPY_PASTE_SNIPPETS.md` is the terse copy-paste file.
- `worked_examples/` contains polished topic examples that used to be called lecture problems.
- `past_assessments/` keeps real prior questions and solutions.

## Documentation Rules

- Every README should answer "where do I go right now?" within the first few lines.
- Cross-links must use the new names.
- Remove references to missing folders, especially the nonexistent `toolkit/`.
- Keep Code::Blocks instructions visible because the exam workflow depends on them.

## Verification

- Regenerate Code::Blocks projects with the local `make_cbp.py` scripts.
- Compile at least the standalone `exam_workspace` project.
- Compile the worked examples and past assessment solutions where possible.
- Run a final text search for old names: `Assessment`, `lecture_problems`, `CHEATSHEET`, `SNIPPETS`, `04_exam_prep`, and `toolkit`.
