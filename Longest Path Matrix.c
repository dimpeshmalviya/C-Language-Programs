#include <stdio.h>

#define MAX 200

int rows, cols;
int dp[MAX][MAX];  // memoization table
int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

// DFS function to find longest increasing path from (r, c)
int dfs(int matrix[MAX][MAX], int r, int c) {
    if (dp[r][c] != 0) return dp[r][c];  // return cached result

    int maxLen = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + directions[i][0];
        int nc = c + directions[i][1];

        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[r][c]) {
            int len = 1 + dfs(matrix, nr, nc);
            if (len > maxLen) maxLen = len;
        }
    }
    dp[r][c] = maxLen;
    return maxLen;
}

int longestIncreasingPath(int matrix[MAX][MAX], int r, int c) {
    rows = r;
    cols = c;
    int result = 0;

    // Initialize memo table
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            dp[i][j] = 0;

    // Try every cell as a starting point
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int len = dfs(matrix, i, j);
            if (len > result) result = len;
        }
    }
    return result;
}

int main() {
    int matrix[MAX][MAX] = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    int r = 3, c = 3;

    int ans = longestIncreasingPath(matrix, r, c);
    printf("Longest Increasing Path Length: %d\n", ans);
    return 0;
}
