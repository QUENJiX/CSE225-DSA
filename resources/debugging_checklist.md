# C++ Debugging Checklist

- Did I initialize every variable?
- Did I use `long long` for sums/products that can exceed `int`?
- Is the loop boundary correct: `< n` vs `<= n`?
- Did I handle `n == 0` or empty string/vector?
- Did I accidentally copy a big vector instead of passing by reference?
- Did I sort before using binary search or two pointers?
- Does my recursion have a base case that always gets reached?
- Did I clear global arrays/vectors between test cases?
- Is the graph 0-indexed or 1-indexed?
- Is the problem asking for count, existence, minimum, maximum, or actual path?

