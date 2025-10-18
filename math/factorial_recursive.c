/*
===============================================================
Program Name: Factorial using Recursion
Problem Statement:
Write a C program to find the factorial of a number using recursion.

Input:
An integer n (n >= 0)

Output:
The factorial of n

Example:
Input: 5
Output: 120

Complexity:
Time Complexity: O(n)
Space Complexity: O(n)  // due to recursive function calls
===============================================================
*/

#include <stdio.h>

// Function to calculate factorial recursively
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;  // Base case
    else
        return n * factorial(n - 1);  // Recursive step
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is: %lld\n", num, factorial(num));
    }
    
    return 0;
}

/*
======================
Example Run:
======================
Input: 5
Output: Factorial of 5 is: 120

To compile and run:
gcc factorial_recursive.c -o factorial
./factorial
======================
*/
