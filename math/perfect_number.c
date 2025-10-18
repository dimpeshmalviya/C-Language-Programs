/*
Program Name: Perfect Number Checker
Problem Statement:
    Write a C program to check whether a given number is a Perfect Number or not.
    A Perfect Number is a number that is equal to the sum of its proper divisors (excluding itself).

Example:
    Input: 6
    Output: 6 is a Perfect Number.

    Input: 12
    Output: 12 is not a Perfect Number.

Compilation:
    gcc perfect_number.c -o perfect
Execution:
    ./perfect

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>

int main()
{
    int num, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Calculate sum of proper divisors
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
            sum += i;
    }

    // Check condition
    if (sum == num && num != 0)
        printf("%d is a Perfect Number.\n", num);
    else
        printf("%d is not a Perfect Number.\n", num);

    return 0;
}
