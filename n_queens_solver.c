#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 20

typedef struct {
    int n;
    int board[MAX_N];
    int solution_count;
} NQueensSolver;

void init_solver(NQueensSolver* solver, int n) {
    solver->n = n;
    solver->solution_count = 0;
    for (int i = 0; i < n; i++) {
        solver->board[i] = -1;
    }
}

bool is_safe(NQueensSolver* solver, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (solver->board[i] == col) {
            return false;
        }
        
        if (solver->board[i] - i == col - row) {
            return false;
        }
        
        if (solver->board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void print_board(NQueensSolver* solver, int* solution) {
    for (int row = 0; row < solver->n; row++) {
        for (int col = 0; col < solver->n; col++) {
            if (solution[row] == col) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void solve_recursive(NQueensSolver* solver, int row, bool find_all) {
    if (row == solver->n) {
        solver->solution_count++;
        
        if (find_all || solver->solution_count == 1) {
            printf("Solution %d:\n", solver->solution_count);
            print_board(solver, solver->board);
        }
        return;
    }
    
    for (int col = 0; col < solver->n; col++) {
        if (is_safe(solver, row, col)) {
            solver->board[row] = col;
            solve_recursive(solver, row + 1, find_all);
            solver->board[row] = -1;
            
            if (!find_all && solver->solution_count > 0) {
                return;
            }
        }
    }
}

void solve_all(NQueensSolver* solver) {
    solver->solution_count = 0;
    solve_recursive(solver, 0, true);
}

void solve_first(NQueensSolver* solver) {
    solver->solution_count = 0;
    solve_recursive(solver, 0, false);
}

int count_solutions(NQueensSolver* solver) {
    solver->solution_count = 0;
    
    void count_recursive(NQueensSolver* s, int row) {
        if (row == s->n) {
            s->solution_count++;
            return;
        }
        
        for (int col = 0; col < s->n; col++) {
            if (is_safe(s, row, col)) {
                s->board[row] = col;
                count_recursive(s, row + 1);
                s->board[row] = -1;
            }
        }
    }
    
    count_recursive(solver, 0);
    return solver->solution_count;
}

int main() {
    printf("=== N-Queens Problem Solver ===\n\n");
    
    printf("Solution counts for different board sizes:\n");
    for (int n = 4; n <= 8; n++) {
        NQueensSolver solver;
        init_solver(&solver, n);
        int count = count_solutions(&solver);
        printf("%d-Queens: %d solutions\n", n, count);
    }
    
    printf("\n=== Detailed Solutions for 4-Queens ===\n\n");
    NQueensSolver solver4;
    init_solver(&solver4, 4);
    solve_all(&solver4);
    printf("Total solutions: %d\n\n", solver4.solution_count);
    
    printf("=== First Solution for 8-Queens ===\n\n");
    NQueensSolver solver8;
    init_solver(&solver8, 8);
    solve_first(&solver8);
    
    if (solver8.solution_count > 0) {
        printf("Queen positions (row, col):\n");
        for (int i = 0; i < 8; i++) {
            printf("(%d, %d) ", i, solver8.board[i]);
        }
        printf("\n");
    }
    
    return 0;
}
