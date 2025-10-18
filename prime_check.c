// filename: prime_check.c
// Compile: gcc prime_check.c -o prime_check
// Run: ./prime_check 29
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPrime(int n) {
 if (n <= 1) return false;
 for (int i = 2; i * i <= n; i++) {
 if (n % i == 0) return false;
 }
 return true;
}
int main(int argc, char *argv[]) {
 if (argc != 2) {
 printf("Usage: %s <number>\n", argv[0]);
 return 1;
 }
 int n = atoi(argv[1]);
 if (isPrime(n))
 printf("%d is a prime number.\n", n);
 else
 printf("%d is not a prime number.\n", n);
 return 0;
}
