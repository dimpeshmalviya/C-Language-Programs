/*
gcd_euclid.c
Compute the GCD of two integers using the iterative Euclidean algorithm.

Compile:
  gcc -o gcd_euclid gcd_euclid.c

Usage:
  ./gcd_euclid
  Enter two integers: 48 18
  GCD = 6
*/
#include <stdio.h>
#include <stdlib.h>

long gcd(long a, long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void) {
    long x, y;
    printf("Enter two integers: ");
    if (scanf("%ld %ld", &x, &y) != 2) return 1;
    printf("GCD = %ld\n", gcd(x, y));
    return 0;
}
