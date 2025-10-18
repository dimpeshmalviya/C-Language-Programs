# Regular Expression Matching

This is a C++ solution for LeetCode Problem 10: Regular Expression Matching.

## Problem
Given an input string `s` and a pattern `p`, implement regular expression matching with support for:
- `.` - matches any single character
- `*` - matches zero or more of the preceding element

The matching should cover the entire input string.

## Example
```
Input: s = "mississippi", p = "misisp*."
Output: true
```

## Solution
Uses dynamic programming with a 2D table to track matches.

## How to run
```bash
g++ -o regex_matching regular_expression_matching.cpp
./regex_matching
```

## Files
- `regular_expression_matching.cpp` - Main implementation
- `README_regex_matching.md` - This file