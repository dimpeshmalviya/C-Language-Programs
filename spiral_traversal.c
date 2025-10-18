/*
 * spiral_traversal.c
 * Program to print elements of a 2D matrix in spiral (clockwise) order.
 *
 * Compilation:
 *   gcc spiral_traversal.c -o spiral_traversal
 *
 * Usage:
 *   ./spiral_traversal
 *
 * Example:
 *   Input:
 *     3 3
 *     1 2 3
 *     4 5 6
 *     7 8 9
 *
 *   Output:
 *     Spiral Traversal: 1 2 3 6 9 8 7 4 5
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    if (rows <= 0 || cols <= 0) {
        fprintf(stderr, "Rows and columns must be positive.\n");
        return 1;
    }

    // Dynamic allocation of 2D matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Input matrix elements
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    // Spiral traversal
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    printf("Spiral Traversal: ");
    while (top <= bottom && left <= right) {
        // Left to Right
        for (int j = left; j <= right; j++)
            printf("%d ", matrix[top][j]);
        top++;

        // Top to Bottom
        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // Right to Left
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                printf("%d ", matrix[bottom][j]);
            bottom--;
        }

        // Bottom to Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
    printf("\n");

    // Free memory
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
