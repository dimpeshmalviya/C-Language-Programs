/*
Program Name: Factorial using Recursion
Problem Statement:
    Write a C program to find the factorial of a number (positive integers) using recursion.

Example Input/Output:
    Input: 5
    Output: 120

Recursion Tree for factorial(5):

                    fact(5)
                      |
               5 * fact(4)
                      |
               4 * fact(3)
                      |
               3 * fact(2)
                      |
               2 * fact(1)
                      |
               1 (base case)

This shows how the recursive calls keep reducing n until the base case is reached,
and then values are multiplied during the backtracking phase.

Complexity:
    Time: O(n)
    Space: O(n) (due to recursive call stack)

Compilation:
    gcc factorial.c -o factorial && ./factorial
*/

#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) return 1; // base case
    return n * factorial(n - 1);    // recursive call
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Factorial of %d = %d\n", num, factorial(num));
    return 0;
}
