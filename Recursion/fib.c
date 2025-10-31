/*
Program Name: Fibonacci using Recursion
Problem Statement:
    Write a C program to print the nth Fibonacci number using recursion.

Example Input/Output:
    Input: 5
    Output: 5   (Fibonacci sequence: 0 1 1 2 3 5 ...)

Recursion Tree for fibonacci(5):

                        fib(5)
                       /     \
                  fib(4)       fib(3)
                 /     \       /     \
            fib(3)     fib(2) fib(2)  fib(1)
           /     \     /   \  /   \
      fib(2)   fib(1) fib(1) fib(0) fib(1)
      /   \
  fib(1)  fib(0)

This shows how the recursive calls branch out until reaching the base cases.

Complexity:
    Time: O(2^n)  (because many calls are repeated)
    Space: O(n)   (recursion depth)

Compilation:
    gcc fibonacci.c -o fibonacci && ./fibonacci
*/

#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;  // base case
    if (n == 1) return 1;  // base case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter position (n): ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Error: Position must be non-negative.\n");
        return 1;
    } 
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    return 0;
}
