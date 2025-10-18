#include <stdio.h>
#include <stdbool.h>

#define N 9  // Size of the Sudoku grid (9x9)

// Function to print the Sudoku board
void printBoard(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0 && row != 0)
            printf("---------------------\n");
        for (int col = 0; col < N; col++) {
            if (col % 3 == 0 && col != 0)
                printf("| ");
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Check if placing num at board[row][col] is valid
bool isSafe(int board[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

// Recursive function to solve Sudoku using backtracking
bool solveSudoku(int board[N][N], int row, int col) {
    if (row == N - 1 && col == N)
        return true;
    if (col == N)
        return solveSudoku(board, row + 1, 0);
    if (board[row][col] != 0)
        return solveSudoku(board, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board, row, col + 1))
                return true;
        }
        board[row][col] = 0; // backtrack
    }
    return false;
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Original Sudoku Puzzle:\n");
    printBoard(board);

    if (solveSudoku(board, 0, 0)) {
        printf("\nSolved Sudoku Puzzle:\n");
        printBoard(board);
    } else {
        printf("No solution exists!\n");
    }

    return 0;
}
