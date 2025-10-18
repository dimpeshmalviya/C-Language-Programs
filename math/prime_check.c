/*
Program name: Prime Number Check
Problem statement: Write a C program to check if a given number is prime or not.
Input / Output examples:
Input: 7
Output: 7 is a prime number.
Input: 10
Output: 10 is not a prime number.
Complexity: O(sqrt(n))
*/

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}