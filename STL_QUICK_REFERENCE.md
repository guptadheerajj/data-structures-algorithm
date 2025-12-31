# C++ STL Quick Reference Guide

## Table of Contents

1. [Containers](#containers)
2. [Iterators](#iterators)
3. [Algorithms](#algorithms)
4. [Time Complexities](#time-complexities)
5. [When to Use Which Container](#when-to-use-which-container)

---

## Containers

### 1. **Vector** - Dynamic Array

```cpp
vector<int> v;
```

- **Features**: Dynamic size, random access, contiguous memory
- **Operations**:
  - Insert at end: O(1) amortized
  - Random access: O(1)
  - Insert/delete at middle: O(n)
- **Use when**: Need dynamic array with random access

### 2. **List** - Doubly Linked List

```cpp
list<int> ls;
```

- **Features**: Fast insertion/deletion anywhere
- **Operations**:
  - Insert/delete: O(1) with iterator
  - No random access
- **Use when**: Frequent insertions/deletions in middle

### 3. **Deque** - Double-Ended Queue

```cpp
deque<int> dq;
```

- **Features**: Fast insertion/deletion at both ends + random access
- **Operations**:
  - Insert/delete at ends: O(1)
  - Random access: O(1)
- **Use when**: Need fast operations at both ends

### 4. **Stack** - LIFO Container

```cpp
stack<int> st;
```

- **Features**: Last In First Out
- **Operations**: push(), pop(), top() - all O(1)
- **Use when**: DFS, expression evaluation, backtracking

### 5. **Queue** - FIFO Container

```cpp
queue<int> q;
```

- **Features**: First In First Out
- **Operations**: push(), pop(), front(), back() - all O(1)
- **Use when**: BFS, level order traversal, scheduling

### 6. **Priority Queue** - Heap

```cpp
// Max Heap (default)
priority_queue<int> pq;

// Min Heap
priority_queue<int, vector<int>, greater<int>> minPQ;
```

- **Features**: Always maintains max/min element at top
- **Operations**:
  - Insert: O(log n)
  - Get top: O(1)
  - Remove top: O(log n)
- **Use when**: Need quick access to max/min, Dijkstra's algorithm

### 7. **Set** - Ordered Unique Elements

```cpp
set<int> s;
```

- **Features**: Unique elements, sorted order, BST implementation
- **Operations**: Insert, find, erase - all O(log n)
- **Use when**: Need sorted unique elements, binary search operations

### 8. **Multiset** - Ordered Elements (Allows Duplicates)

```cpp
multiset<int> ms;
```

- **Features**: Like set but allows duplicates
- **Warning**: `erase(value)` removes ALL occurrences
- **Use when**: Need sorted elements with duplicates

### 9. **Unordered Set** - Hash Set

```cpp
unordered_set<int> us;
```

- **Features**: Unique elements, no order, hash table
- **Operations**: Insert, find, erase - O(1) average, O(n) worst
- **Use when**: Need fast lookups, don't care about order

### 10. **Map** - Key-Value Pairs (Ordered)

```cpp
map<int, int> mp;
```

- **Features**: Unique keys, sorted by key, BST implementation
- **Operations**: Insert, find, erase - all O(log n)
- **Use when**: Need key-value mapping with ordered keys

### 11. **Multimap** - Allows Duplicate Keys

```cpp
multimap<int, int> mmp;
```

- **Features**: Like map but allows duplicate keys
- **Note**: Cannot use `[]` operator
- **Use when**: One key needs multiple values

### 12. **Unordered Map** - Hash Map

```cpp
unordered_map<int, int> ump;
```

- **Features**: Key-value pairs, no order, hash table
- **Operations**: Insert, find, erase - O(1) average, O(n) worst
- **Use when**: Need fast key-value lookups, don't care about order

---

## Iterators

### Types of Iterators

```cpp
// Begin and End
container.begin()   // Points to first element
container.end()     // Points PAST last element

// Reverse iterators
container.rbegin()  // Points to last element (reverse begin)
container.rend()    // Points before first element (reverse end)
```

### Iterator Loops

```cpp
// Method 1: Full syntax
for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it;
}

// Method 2: Auto keyword (preferred)
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it;
}

// Method 3: Range-based (simplest)
for (auto element : v) {
    cout << element;
}
```

---

## Algorithms

### 1. **Sorting**

```cpp
// Sort array
int arr[] = {5, 2, 8, 1};
sort(arr, arr + 4);  // Ascending

// Sort vector
vector<int> v = {5, 2, 8, 1};
sort(v.begin(), v.end());

// Descending order
sort(v.begin(), v.end(), greater<int>());

// Custom comparator
bool comp(int a, int b) {
    return a > b;  // Descending
}
sort(v.begin(), v.end(), comp);
```

### 2. **Binary Search**

```cpp
// lower_bound: first element >= x
auto it = lower_bound(v.begin(), v.end(), x);

// upper_bound: first element > x
auto it = upper_bound(v.begin(), v.end(), x);
```

### 3. **Min/Max Element**

```cpp
int maxVal = *max_element(v.begin(), v.end());
int minVal = *min_element(v.begin(), v.end());
```

### 4. **Permutations**

```cpp
string s = "abc";
sort(s.begin(), s.end());  // Must sort first!
do {
    cout << s << endl;
} while (next_permutation(s.begin(), s.end()));
// Prints: abc, acb, bac, bca, cab, cba
```

### 5. **Builtin Functions**

```cpp
// Count set bits (1's in binary)
int num = 7;  // Binary: 111
int bits = __builtin_popcount(num);  // Returns 3

// For long long
long long bigNum = 123456;
int bits = __builtin_popcountll(bigNum);
```

---

## Time Complexities

| Container      | Insert                 | Delete                 | Access        | Search   | Order          |
| -------------- | ---------------------- | ---------------------- | ------------- | -------- | -------------- |
| Vector         | O(1) end, O(n) middle  | O(1) end, O(n) middle  | O(1)          | O(n)     | No             |
| List           | O(1)                   | O(1) with iterator     | O(n)          | O(n)     | No             |
| Deque          | O(1) ends, O(n) middle | O(1) ends, O(n) middle | O(1)          | O(n)     | No             |
| Set            | O(log n)               | O(log n)               | O(log n)      | O(log n) | Yes (sorted)   |
| Unordered Set  | O(1) avg               | O(1) avg               | O(1) avg      | O(1) avg | No             |
| Map            | O(log n)               | O(log n)               | O(log n)      | O(log n) | Yes (sorted)   |
| Unordered Map  | O(1) avg               | O(1) avg               | O(1) avg      | O(1) avg | No             |
| Priority Queue | O(log n)               | O(log n)               | O(1) top only | -        | Max/Min at top |

---

## When to Use Which Container

### Decision Tree

**Need Key-Value Pairs?**

- Yes → **Map** (sorted) or **Unordered Map** (faster)
- No → Continue...

**Need Unique Elements?**

- Yes → **Set** (sorted) or **Unordered Set** (faster)
- No → Continue...

**Need Fast Insert/Delete at Ends?**

- Both ends → **Deque**
- One end only → **Stack** (LIFO) or **Queue** (FIFO)
- Middle too → **List**

**Need Random Access?**

- Yes → **Vector** (most common choice)
- No → **List**

**Need Always Max/Min?**

- Yes → **Priority Queue**

### Common Use Cases

| Problem Type                     | Best Container    |
| -------------------------------- | ----------------- |
| Dynamic array, random access     | Vector            |
| DFS, recursion, undo operations  | Stack             |
| BFS, level order, scheduling     | Queue             |
| Dijkstra's, Huffman coding       | Priority Queue    |
| Binary search, sorted data       | Set/Map           |
| Fast lookups, no order needed    | Unordered Set/Map |
| Sliding window maximum           | Deque             |
| Frequent insert/delete in middle | List              |

---

## Important Notes

1. **Vector vs Array**: Vector is dynamic, array is fixed size
2. **Set vs Unordered Set**: Set is O(log n) but sorted, Unordered is O(1) but no order
3. **Map [] operator**: Creates key if doesn't exist! Use `find()` to check first
4. **Multiset erase**: `erase(value)` removes ALL occurrences. Use `erase(find(value))` for one
5. **Iterator validity**: Inserting/deleting can invalidate iterators
6. **Auto keyword**: Use `auto` for cleaner code with iterators
7. **emplace vs insert**: emplace is more efficient (constructs in place)

---

## Quick Tips

- Always use `auto` with iterators for cleaner code
- Use `emplace` instead of `insert/push` for efficiency
- Remember: `end()` points PAST the last element
- For custom sorting, write a comparator function
- Unordered containers are faster but use more memory
- Use `const auto&` in range loops to avoid copies
