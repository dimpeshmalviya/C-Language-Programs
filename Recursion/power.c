/*
Program Name:
Power Function (xⁿ) using Recursion

Problem Statement:
Implement a function to calculate the power of a number using recursion.
Given a base x and an integer exponent n, calculate x raised to the power n (xⁿ).
The function should also handle negative exponents.

Example 1:
Input: x = 2, n = 3
Output: 8
Explanation: 2^3 = 8

Example 2:
Input: x = 5, n = 0
Output: 1
Explanation: Any number raised to 0 is 1

Example 3:
Input: x = 2, n = -2
Output: 0.25
Explanation: 2^-2 = 1/(2^2) = 0.25

Compilation Command:
gcc power.c -o power

Constraints:
-10^9 <= x <= 10^9
-10^9 <= n <= 10^9
*/

// Code:
#include <stdio.h>

double power(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n > 0)
        return x * power(x, n - 1);
    else
        return 1 / power(x, -n); // handle negative powers
}

int main()
{
    double x;
    int n;
    scanf("%lf %d", &x, &n);
    printf("%.6lf\n", power(x, n));
    return 0;
}
