/*
Program Name: Armstrong Number Checker
Problem Statement:
    Write a C program to check whether a given number is an Armstrong number or not.
    An Armstrong number is a number that is equal to the sum of cubes of its digits.

Example:
    Input: 153
    Output: 153 is an Armstrong number.

    Input: 123
    Output: 123 is not an Armstrong number.

Compilation:
    gcc armstrong_number.c -o armstrong
Execution:
    ./armstrong

Time Complexity: O(d), where d = number of digits
Space Complexity: O(1)
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int num, originalNum, remainder, n = 0;
    double result = 0.0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Count number of digits
    while (originalNum != 0)
    {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;

    // Calculate the sum of nth powers of digits
    while (originalNum != 0)
    {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }

    if ((int)result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
