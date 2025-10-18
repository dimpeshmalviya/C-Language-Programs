/*
Program Name: Harshad (Niven) Number Checker
Problem Statement:
A Harshad number is an integer that is divisible by the sum of its digits.

Input:
Enter a number: 18

Output:
18 is a Harshad Number.

Complexity:
Time Complexity: O(log10(n))
Space Complexity: O(1)
*/

#include <stdio.h>

int main() {
    int num, sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    if (num % sum == 0)
        printf("%d is a Harshad Number.\n", num);
    else
        printf("%d is not a Harshad Number.\n", num);

    return 0;
}

/*
Example Run:
Enter a number: 21
21 is not a Harshad Number.
*/
