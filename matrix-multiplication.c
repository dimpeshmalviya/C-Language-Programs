/*
matrix_multiplication.c
Multiply two matrices: A (m x n) and B (n x p) -> C (m x p).

Compile:
  gcc -o matrix_multiplication matrix_multiplication.c

Usage (example):
  ./matrix_multiplication
  Enter m n p: 2 3 2
  Enter matrix A (2x3):
  1 2 3
  4 5 6
  Enter matrix B (3x2):
  7 8
  9 10
  11 12
  Result:
  58 64
  139 154
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n, p;
    printf("Enter m n p: ");
    if (scanf("%d %d %d", &m, &n, &p) != 3) return 1;
    if (m <= 0 || n <= 0 || p <= 0) return 1;

    int **A = malloc(m * sizeof(int*));
    int **B = malloc(n * sizeof(int*));
    int **C = malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) C[i] = calloc(p, sizeof(int));
    for (int i = 0; i < m; ++i) A[i] = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) B[i] = malloc(p * sizeof(int));

    printf("Enter matrix A (%dx%d):\n", m, n);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (scanf("%d", &A[i][j]) != 1) return 1;

    printf("Enter matrix B (%dx%d):\n", n, p);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j)
            if (scanf("%d", &B[i][j]) != 1) return 1;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];
        }

    printf("Result:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j)
            printf("%d%c", C[i][j], j+1==p?'\n':' ');
    }

    for (int i = 0; i < m; ++i) free(A[i]);
    for (int i = 0; i < n; ++i) free(B[i]);
    for (int i = 0; i < m; ++i) free(C[i]);
    free(A); free(B); free(C);
    return 0;
}
