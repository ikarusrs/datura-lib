# datura-lib

Data Structures library in **C++, C and Rust**.

`datura-lib` is a collection of data structures and related algorithms implemented from scratch, with a focus on understanding their underlying memory models, interfaces, and performance characteristics.

The project is primarily an educational and experimental implementation rather than a replacement for the standard libraries of each language.

## Languages

- C++
- C
- Rust

Each implementation is developed independently where the language's memory model and idioms make that appropriate.

## Goals

- Implement common data structures from first principles.
- Understand memory management and data representation.
- Explore the differences between C, C++, and Rust implementations.
- Provide clean and predictable APIs.
- Measure performance through benchmarks.
- Write tests for correctness and edge cases.
- Document the complexity and implementation details of each structure.

## Data Structures

The library is being developed incrementally.

### Linear Structures

- [ ] Dynamic Array
- [ ] Singly Linked List
- [ ] Doubly Linked List
- [ ] Stack
- [ ] Queue
- [ ] Deque

### Trees

- [ ] Binary Search Tree
- [ ] AVL Tree
- [ ] Red-Black Tree
- [ ] Heap
- [ ] Trie

### Hash-Based Structures

- [ ] Hash Table
- [ ] Hash Map
- [ ] Hash Set

### Graph Structures

- [ ] Graph
- [ ] Directed Graph
- [ ] Weighted Graph

### Other

- [ ] Disjoint Set / Union-Find
- [ ] Bloom Filter
- [ ] Sparse Matrix

## Algorithms

Algorithms will be added alongside the structures they operate on.

Planned categories include:

- Searching
- Sorting
- Tree traversal
- Graph traversal
- Graph algorithms
- Heap operations
- Hashing

## Design

The implementations aim to make the underlying mechanics visible rather than hiding them behind abstractions.

For example, a dynamic array implementation should deal explicitly with:

```text
allocation
    ↓
raw storage
    ↓
object construction
    ↓
growth / reallocation
    ↓
element movement
    ↓
object destruction
    ↓
deallocation
```

The C++ implementation will make use of templates and RAII, while the C implementation will expose the manual memory-management model directly. Rust implementations will use ownership and borrowing rather than reproducing C-style memory management.

## Example

C++:

```cpp
#include <datura/vector.hpp>

int main() {
    datura::Vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    for (const auto& number : numbers) {
        std::cout << number << '\n';
    }
}
```

The API is subject to change while the library is being developed.

## Complexity

Each data structure will document the expected complexity of its major operations.

For example:

| Operation | Dynamic Array |
|-----------|---------------|
| Access | O(1) |
| Search | O(n) |
| Append | O(1) amortized |
| Insert | O(n) |
| Delete | O(n) |

Actual performance will also be evaluated through benchmarks rather than relying exclusively on asymptotic complexity.

## Project Structure

```text
datura-lib/
├── cpp/
│   ├── include/
│   ├── src/
│   ├── tests/
│   └── benchmarks/
│
├── c/
│   ├── include/
│   ├── src/
│   ├── tests/
│   └── benchmarks/
│
├── rust/
│   ├── src/
│   └── tests/
│
├── examples/
├── docs/
├── benchmarks/
└── README.md
```

The exact structure may change as the project grows. Because apparently deciding where to put a header file is also a software architecture problem.

## Testing

Correctness is tested against expected behavior and edge cases.

Tests will cover cases such as:

- Empty structures
- Single-element structures
- Large collections
- Duplicate values
- Boundary conditions
- Invalid operations
- Memory ownership
- Copy and move semantics in C++
- Ownership and borrowing rules in Rust

## Benchmarks

Where appropriate, implementations will be benchmarked against:

- Different implementations within `datura-lib`
- Equivalent standard-library structures
- Different input sizes
- Different access patterns

The purpose of benchmarking is to understand why implementations perform differently, not merely to produce a number that looks impressive in a README.

## Status

**Early development.**

The library is being implemented incrementally. APIs, internal implementations, and project structure may change substantially.

## License

[License information goes here.]

---

*datura-lib: data structures, implemented the hard way.*