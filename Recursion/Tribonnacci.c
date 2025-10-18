#include <stdio.h>

/*
 * Function: tribonacci
 * --------------------
 * Recursively computes the k-th Tribonacci number.
 * - tribonacci(0) = 0
 * - tribonacci(1) = 1
 * - tribonacci(2) = 1
 * - For k >= 3: tribonacci(k) = tribonacci(k-1) + tribonacci(k-2) + tribonacci(k-3)
 *
 * k: which term to compute (zero-based index)
 *
 * Example:
 * tribonacci(4) returns 4 (since sequence is 0, 1, 1, 2, 4, ...)
 */
int tribonacci(int k) {
    // Base cases for the first three terms
    if (k == 0) return 0;
    if (k == 1) return 1;
    if (k == 2) return 1;
    // Recursive computation for subsequent terms
    return tribonacci(k - 1) + tribonacci(k - 2) + tribonacci(k - 3);
}

/*
 * Function: printTribonacciRecursive
 * ----------------------------------
 * Prints the first n terms of the Tribonacci sequence using recursion.
 *
 * n: number of terms to print
 *
 * Example usage:
 * printTribonacciRecursive(6); // Output: 0 1 1 2 4 7
 */
void printTribonacciRecursive(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tribonacci(i));
    }
    printf("\n");
}

int main() {
    int num_terms = 10;
    printf("Tribonacci series up to %d terms (using recursion):\n", num_terms);
    printTribonacciRecursive(num_terms);
    // Working example:
    printf("Example (first 6 Tribonacci terms, recursion):\n");
    printTribonacciRecursive(6); // Output: 0 1 1 2 4 7
    return 0;
}
