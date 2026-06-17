# Big-O Cheat Sheet

## Common Growth Rates

- `O(1)` - direct lookup, stack push/pop, arithmetic.
- `O(log n)` - binary search, balanced tree operation.
- `O(n)` - one pass through input.
- `O(n log n)` - comparison sorting, divide and conquer with merge.
- `O(n^2)` - all pairs, nested loops over same input.
- `O(2^n)` - subsets.
- `O(n!)` - permutations.

## Fast Estimates

For competitive/problem-solving constraints:

- `n <= 20`: backtracking/subsets may be possible.
- `n <= 100`: `O(n^3)` may pass.
- `n <= 2,000`: `O(n^2)` may pass.
- `n <= 100,000`: usually need `O(n log n)` or `O(n)`.
- `n >= 1,000,000`: usually need `O(n)` or better.

## C++ Overflow Reminder

Use `long long` when multiplying or summing many `int` values.

```cpp
long long area = 1LL * width * height;
```

