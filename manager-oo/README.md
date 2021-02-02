# Manager - Object Orientated variant

Binary size: 61440 (61K) Debug, 25600 (24K) Release, both on Windows

## Benefits

- Fast for inserts (3.82% of overall run time)
- Memory efficient
- No moves or copies of SubDevice (I've explicitly deleted the copy and move constructors to be sure)

## Problems

- Creation functions, container, find functions all return the base class type, not parent class type
- Uses the heap (not great for embedded architectures)
- Slow lookups through iterating in order over a vector (Although this is simple and sufficient for small containers)
- Memory use - x% for data, y% for pointers, vptrs, shared_ptrs, etc
- Returning 'references to shared pointers' - not just references or shared_ptrs
- Returns only first match from matches function, not multiple matches (which are possible with vector through operator== overloads on elements within it)
