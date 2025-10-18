// filename: sieve.c
// Compile: gcc -o sieve sieve.c
// Run: ./sieve 50

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    if (n < 2) {
        printf("No primes <= %d\n", n);
        return 0;
    }

    bool *isPrime = malloc((n+1) * sizeof(bool));
    for (int i = 0; i <= n; ++i) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p)
                isPrime[multiple] = false;
        }
    }

    printf("Primes <= %d:\n", n);
    for (int i = 2; i <= n; ++i) if (isPrime[i]) printf("%d ", i);
    printf("\n");

    free(isPrime);
    return 0;
}
