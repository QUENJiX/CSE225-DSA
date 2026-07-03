# CSE225L Exam Reference - Labs 1-6

Use this folder before the exam. During the exam, code in
[`../exam_workspace/`](../exam_workspace/).

## Fast Route

1. Need the full pattern? Open [`QUICK_REFERENCE.md`](QUICK_REFERENCE.md).
2. Need a block to type fast? Open [`COPY_PASTE_SNIPPETS.md`](COPY_PASTE_SNIPPETS.md).
3. Need a full lab-style answer? Open [`worked_examples/`](worked_examples/).
4. Need the real first assessment? Open [`past_assessments/assessment_1/`](past_assessments/assessment_1/).

## Worked Examples

Each folder is one master problem for one lab. The goal is not random practice.
The goal is one organized answer that covers the lab's main functions, file
split, and usage.

| Folder | Covers |
|---|---|
| `worked_examples/01_basics_and_class/` | Lab 1: input/output, functions, loops, calculator, primes, `Box` class |
| `worked_examples/02_dynamic_memory/` | Lab 2: `new`, `delete`, 1D array, 2D char array, jagged int array |
| `worked_examples/03_dynarr_class/` | Lab 3: non-template `dynArr` class with dynamic 2D memory |
| `worked_examples/04_template_dynarr/` | Lab 4: template `dynArr<T>` only |
| `worked_examples/05_list_adt/` | Lab 5: `UnsortedType<T>` with `int` and `Student` |
| `worked_examples/06_sorted_list_adt/` | Lab 6: `SortedType<T>` with `int` and `timeStamp` |

## Code::Blocks

Regenerate projects after changing files:

```bash
cd lab/04_exam_reference
python make_cbp.py
```

Then open `exam_reference.workspace`, or open a single `.cbp` inside a worked
example folder.

For template examples, the driver includes the template `.cpp`, so the generator
marks that `.cpp` as not compiled separately.

## Mark-Saving Habits

1. Match the requested files: `main.cpp`, header, source.
2. Header has declarations only, except template notes from the lab style.
3. Free memory correctly: rows first, outer pointer last.
4. For templates split into `.h` and `.cpp`, include the `.cpp` in `main.cpp`.
