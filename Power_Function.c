/*
Program Name   : Power Function Using Recursion
Problem Statement:
    Write a program to calculate the power of a number x raised to n (x^n)
    using recursion.

Example:
    Input: x = 2, n = 5
    Output: 32

Time Complexity : O(n)          // Each recursive call multiplies once
Space Complexity: O(n)          // Recursion stack depth
*/

#include <stdio.h>

// Recursive function to calculate x^n
long long power(int x, int n) {
    if (n == 0)
        return 1;             // Base case: any number^0 = 1
    if (n < 0)
        return 1 / power(x, -n); // Handle negative exponents (optional)
    return x * power(x, n - 1); // Recursive step
}

int main() {
    int x, n;
    printf("Enter base (x) and exponent (n): ");
    scanf("%d %d", &x, &n);

    long long result = power(x, n);
    printf("%d^%d = %lld\n", x, n, result);

    return 0;
}
