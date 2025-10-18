#include <stdio.h>

#define N 8

int isSafe(int mat[N][N], int row, int col) {
    int i, j;

    for (i = 0; i < row; i++)
        if (mat[i][col])
            return 0;

    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j])
            return 0;

    for (i = row - 1, j = col + 1; j < N && i >= 0; i--, j++)
        if (mat[i][j])
            return 0;

    return 1;
}

int placeQueens(int row, int mat[N][N]) {
    if (row == N) return 1;

    for (int i = 0; i < N; i++) {
        if (isSafe(mat, row, i)) {
            mat[row][i] = 1;
            if (placeQueens(row + 1, mat))
                return 1;
            mat[row][i] = 0;
        }
    }
    return 0;
}

int main() {
    int mat[N][N] = {0};
    placeQueens(0, mat);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
