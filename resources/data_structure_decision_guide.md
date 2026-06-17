# Data Structure Decision Guide

Use this when a problem asks you to choose or design a structure.

## Fast Choice Table

| Problem Need | Good Choice | Why |
|---|---|---|
| Access by index | `vector`, array | `O(1)` random access |
| Frequent insert/delete at end | `vector`, stack | amortized `O(1)` push/pop back |
| Frequent insert/delete at front | `deque`, queue | efficient front operations |
| Last-in-first-out | stack | undo, parsing, recursion simulation |
| First-in-first-out | queue | scheduling, BFS, waiting lines |
| Need min/max repeatedly | heap / `priority_queue` | `O(log n)` insert and remove best |
| Search by key, no order needed | `unordered_map`, `unordered_set` | average `O(1)` lookup |
| Search by key, sorted order needed | `map`, `set` | `O(log n)` and ordered iteration |
| Store relationships | graph adjacency list | natural model for networks |
| Hierarchical data | tree | parent/child structure |
| Prefix/string dictionary | trie | efficient prefix search |
| Connect components dynamically | DSU / union-find | very fast merge and find |

## Domain Analysis Questions

Ask these before coding:

1. What operation happens most often?
2. Do I need order, or only membership?
3. Do I need random access by index?
4. Do I need fast insertion/deletion in the middle?
5. Are relationships pairwise, hierarchical, or sequential?
6. Is the answer based on the smallest/largest item repeatedly?
7. Are duplicate values important?
8. What are the constraints: `n <= 100`, `n <= 10^5`, or bigger?

## Common Patterns

### Need Existence Or Frequency

Use:

```cpp
unordered_set<int> seen;
unordered_map<int, int> freq;
```

Typical problems:

- two sum,
- first unique character,
- duplicate detection,
- frequency counting.

### Need Sorted Traversal

Use:

```cpp
set<int> values;
map<string, int> score;
```

Typical problems:

- ranking,
- ordered keys,
- lower/upper bound queries.

### Need Shortest Path In Unweighted Network

Use:

```cpp
vector<vector<int>> adj;
queue<int> q;
```

That is BFS.

### Need Best Item Again And Again

Use:

```cpp
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
```

Typical problems:

- top K,
- scheduling,
- Dijkstra,
- merging sorted lists.

### Need Undo Or Nested Matching

Use stack.

Typical problems:

- balanced brackets,
- expression parsing,
- browser history,
- DFS without recursion.

## Tradeoff Reminder

There is no universally best data structure. A structure is good when its strengths match the problem's most frequent operations.
