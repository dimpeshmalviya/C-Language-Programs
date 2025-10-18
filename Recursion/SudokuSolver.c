/*
 Program: Sudoku Solver using Recursion (Backtracking)
 Problem: Fill a 9x9 Sudoku grid such that every row, column, and 3x3 box
          contains digits 1–9 exactly once.
 Input: A Sudoku grid with 0 representing empty cells.
 Output: Completed Sudoku grid.

 Example Input:
 5 3 0 0 7 0 0 0 0
 6 0 0 1 9 5 0 0 0
 0 9 8 0 0 0 0 6 0
 8 0 0 0 6 0 0 0 3
 4 0 0 8 0 3 0 0 1
 7 0 0 0 2 0 0 0 6
 0 6 0 0 0 0 2 8 0
 0 0 0 4 1 9 0 0 5
 0 0 0 0 8 0 0 7 9

 Example Output:
 5 3 4 6 7 8 9 1 2
 6 7 2 1 9 5 3 4 8
 1 9 8 3 4 2 5 6 7
 8 5 9 7 6 1 4 2 3
 4 2 6 8 5 3 7 9 1
 7 1 3 9 2 4 8 5 6
 9 6 1 5 3 7 2 8 4
 2 8 7 4 1 9 6 3 5
 3 4 5 2 8 6 1 7 9

 Complexity: O(9^(n*n)) worst-case, but recursion + backtracking prunes many states.
 Compile: gcc SudokuSolver.c -o SudokuSolver
 Run: ./SudokuSolver
*/

#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to print Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Check if placing num at grid[row][col] is safe
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Row check
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num) return false;

    // Column check
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num) return false;

    // 3x3 subgrid check
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num) return false;

    return true;
}

// Recursive backtracking solver
bool solveSudoku(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N) return true; // Solved
    if (col == N) { // Move to next row
        row++;
        col = 0;
    }
    if (grid[row][col] != 0) // Skip filled cells
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) return true;
            grid[row][col] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    int grid[N][N] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        printf("No solution exists\n");

    return 0;
}
