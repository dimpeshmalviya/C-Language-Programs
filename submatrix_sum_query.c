#include <stdio.h>

#define ROWS 5
#define COLS 5

int main() {
    int matrix[ROWS][COLS] = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    int prefix[ROWS + 1][COLS + 1] = {0};

    // Precompute prefix sums
    for (int i = 1; i <= ROWS; i++) {
        for (int j = 1; j <= COLS; j++) {
            prefix[i][j] = matrix[i - 1][j - 1]
                         + prefix[i - 1][j]
                         + prefix[i][j - 1]
                         - prefix[i - 1][j - 1];
        }
    }

    int r1 = 2, c1 = 1, r2 = 4, c2 = 3;

    int sum = prefix[r2 + 1][c2 + 1]
            - prefix[r1][c2 + 1]
            - prefix[r2 + 1][c1]
            + prefix[r1][c1];

    printf("Sum of submatrix (%d,%d) to (%d,%d): %d\n", r1, c1, r2, c2, sum);

    return 0;
}