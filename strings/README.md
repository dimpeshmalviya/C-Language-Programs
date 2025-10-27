# String Algorithms

This directory contains implementations of various string matching and manipulation algorithms in C.

## Algorithms Included

### 1. Rabin-Karp String Matching Algorithm (`rabin_karp.c`)

**Description:** Implements the Rabin-Karp algorithm for finding all occurrences of a pattern in a text using rolling hash technique.

**Features:**
- Uses rolling hash for efficient pattern matching
- Handles hash collisions with character-by-character verification
- Time Complexity: O(n + m) average case, O(nm) worst case
- Space Complexity: O(1)

**Compile and Run:**
```bash
gcc rabin_karp.c -o rabin_karp
./rabin_karp
```

**Example:**
```
Enter text: abcdabcabc
Enter pattern: abc
Pattern found at positions: 0 4 7
```

### 2. Knuth-Morris-Pratt (KMP) Algorithm (`kmp_algorithm.c`)

**Description:** Implements the KMP algorithm for efficient string matching using the failure function (LPS array).

**Features:**
- Uses failure function to avoid unnecessary character comparisons
- Guaranteed linear time complexity
- Time Complexity: O(n + m) where n = text length, m = pattern length
- Space Complexity: O(m) for the failure function

**Compile and Run:**
```bash
gcc kmp_algorithm.c -o kmp_algorithm
./kmp_algorithm
```

**Example:**
```
Enter text: abcdabcabc
Enter pattern: abc
Pattern found at positions: 0 4 7
```

### 3. Boyer-Moore String Matching Algorithm (`boyer_moore.c`)

**Description:** Implements the Boyer-Moore algorithm for efficient string matching using bad character and good suffix heuristics.

**Features:**
- Uses bad character and good suffix heuristics for optimal skipping
- Often performs better than other algorithms in practice
- Time Complexity: O(n/m) best case, O(nm) worst case
- Space Complexity: O(σ) where σ is the alphabet size

**Compile and Run:**
```bash
gcc boyer_moore.c -o boyer_moore
./boyer_moore
```

**Example:**
```
Enter text: abcdabcabc
Enter pattern: abc
Pattern found at positions: 0 4 7
```

## Comparison of String Matching Algorithms

| Algorithm | Time Complexity | Space Complexity | Best Use Case |
|-----------|----------------|------------------|---------------|
| Naive | O(nm) | O(1) | Simple cases, short patterns |
| Rabin-Karp | O(n + m) avg, O(nm) worst | O(1) | Multiple pattern matching |
| KMP | O(n + m) | O(m) | Single pattern, worst-case guarantee |
| Boyer-Moore | O(n/m) best, O(nm) worst | O(σ) | General purpose, often fastest in practice |

## Usage Notes

- All programs handle input validation and error cases
- Programs work with any printable ASCII characters
- Input is read from stdin for easy testing and integration
- Memory is properly managed (especially in KMP and Boyer-Moore algorithms)
- Each algorithm has different strengths and use cases

## Contributing

When adding new string algorithms to this directory:

1. Follow the existing code style and documentation format
2. Include comprehensive comments explaining the algorithm
3. Add input/output examples in the header comment
4. Include time and space complexity analysis
5. Test thoroughly with various inputs
6. Update this README with the new algorithm information
