# C++ Standard Template Library (STL)

The STL is a powerful library in C++ that provides generic classes and functions for common data structures and algorithms. It includes:

- Containers (e.g., `vector`, `list`, `map`, etc.)
- Iterators (to traverse containers)
- Algorithms (e.g., `sort`, `find`, etc.)
- Functors (function objects)

# Vector in C++

A `vector` is a dynamic array provided by the STL. Unlike static arrays, vectors can grow or shrink in size dynamically.

## Key Features of `vector`:

- Dynamic resizing
- Random access using indices
- Automatic memory management
- Rich set of member functions

# Common Vector Functions

1. **Capacity Functions**:

   - `size()`: Returns the number of elements.
   - `capacity()`: Returns the allocated storage capacity.
   - `resize(n)`: Resizes the vector to contain `n` elements.

2. **Element Access**:

   - `front()`: Returns the first element.
   - `back()`: Returns the last element.
   - `at(index)`: Returns the element at the specified index.

3. **Modifiers**:
   - `push_back(value)`: Adds an element to the end.
   - `pop_back()`: Removes the last element.
   - `insert(pos, value)`: Inserts an element at the specified position.
   - `erase(pos)`: Removes an element at the specified position.
   - `clear()`: Removes all elements.

# Static vs Dynamic Memory Allocation

1. **Static Memory Allocation**:

   - Memory is allocated at compile time.
   - Fixed size, cannot grow or shrink.
   - Example: `int arr[10];`

2. **Dynamic Memory Allocation**:
   - Memory is allocated at runtime.
   - Can grow or shrink as needed.
   - Example: Using `vector` or `new`/`delete`.

# Creation of Vectors in Memory

When a `vector` is created:

1. Memory is allocated dynamically on the heap.
2. The `vector` manages its own memory, resizing as needed.
3. The `capacity()` function shows the allocated memory, which may be larger than the current size.
4. When a value is added to a full `vector`, its capacity typically doubles (or increases by a factor determined by the implementation) to accommodate additional elements. This ensures amortized constant time complexity for insertion operations, as resizing happens infrequently.

# LeetCode Problem: Single Number (136)

**Problem Statement**: Given a non-empty array of integers, every element appears twice except for one. Find that single one.

**Solution**:
The XOR operation can be used to solve this efficiently:

- XOR of a number with itself is `0`.
- XOR of a number with `0` is the number itself.
- XOR is commutative and associative.

**Code**:

```cpp
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int val : nums) {
        result ^= val; // XOR all numbers
    }
    return result;
}
```

**Example**:
Input: `[4, 1, 2, 1, 2]`  
Output: `4`
