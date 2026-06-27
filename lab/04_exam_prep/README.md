# CSE225L Exam Prep — Labs 1–3

Quick-access prep for the in-lab exam where the instructor either gives you
**incomplete functions to complete** or asks you to **write full code**.

## What is here

| File | Use it for |
|------|-----------|
| [`CHEATSHEET.md`](CHEATSHEET.md) | The master quick reference. Skim it, recall exact syntax for "complete the function" tasks, copy patterns for "write full code" tasks. |
| [`template_project/`](template_project/) | A complete, compile-tested `.h` / `.cpp` / `main.cpp` trio for the `dynArr` class. This is the *shape* to reproduce when asked to write a full multi-file program. |

## How the exam usually works (based on lab1–3)

1. **Complete the function** — you get a header + driver and must fill in method bodies.
   → Jump to the matching section in `CHEATSHEET.md`, recall the body.
2. **Write full code** — you reproduce a `.h` + `.cpp` + `main.cpp` from a spec.
   → Reproduce the `template_project/` shape, then adapt names/logic.

## Compile & run (Code::Blocks or terminal)

```bash
# from inside template_project/
g++ -std=c++17 -Wall main.cpp dynarr.cpp -o app
./app          # (Windows: .\app.exe)
```

In Code::Blocks: put `dynarr.h`, `dynarr.cpp`, `main.cpp` in one project and Build & Run (F9).

## The 3 things that lose the most marks

1. **Deallocation** — every `new` needs a matching `delete`; every `new[]` needs `delete[]`.
   For 2D, delete each row first, then the outer array.
2. **Header guards** — `#ifndef / #define / #endif` in every `.h`.
3. **Off-by-one** — loops run `0 .. size-1`; char arrays need `columns + 1` for `'\0'`.
