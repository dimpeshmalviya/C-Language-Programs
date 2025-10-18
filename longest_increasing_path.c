// longest_increasing_path.c
#include <stdio.h>
#include <stdlib.h>

int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int dfs(int** matrix, int r, int c, int R, int C, int** memo) {
    if (memo[r][c] != 0) return memo[r][c];
    int best = 1;
    for (int k = 0; k < 4; ++k) {
        int nr = r + dirs[k][0], nc = c + dirs[k][1];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && matrix[nr][nc] > matrix[r][c]) {
            int len = 1 + dfs(matrix, nr, nc, R, C, memo);
            if (len > best) best = len;
        }
    }
    memo[r][c] = best;
    return best;
}

int longestIncreasingPath(int** matrix, int R, int C) {
    if (R == 0 || C == 0) return 0;
    int** memo = (int**)malloc(sizeof(int*) * R);
    for (int i = 0; i < R; ++i) {
        memo[i] = (int*)calloc(C, sizeof(int));
    }
    int ans = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            int cur = dfs(matrix, i, j, R, C, memo);
            if (cur > ans) ans = cur;
        }
    }
    for (int i = 0; i < R; ++i) free(memo[i]);
    free(memo);
    return ans;
}

int main() {
    int R = 3, C = 3;
    int vals[3][3] = {
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };
    // allocate matrix pointers
    int** matrix = (int**)malloc(sizeof(int*) * R);
    for (int i = 0; i < R; ++i) {
        matrix[i] = (int*)malloc(sizeof(int)*C);
        for (int j = 0; j < C; ++j) matrix[i][j] = vals[i][j];
    }
    printf("Longest increasing path length = %d\n", longestIncreasingPath(matrix, R, C)); // expected 4

    for (int i = 0; i < R; ++i) free(matrix[i]);
    free(matrix);
    return 0;
}