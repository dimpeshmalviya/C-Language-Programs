// File: nqueens.cpp
// Issue: #218
// Title: N-Queens Problem (Backtracking)

#include <bits/stdc++.h>
using namespace std;

void solve(int n, int row, vector<string> &board,
           vector<vector<string>> &ans,
           vector<int> &cols, vector<int> &diag1, vector<int> &diag2) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
            continue;

        board[row][col] = 'Q';
        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 1;

        solve(n, row + 1, board, ans, cols, diag1, diag2);

        board[row][col] = '.';
        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 0;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<int> cols(n, 0), diag1(2 * n, 0), diag2(2 * n, 0);

    solve(n, 0, board, ans, cols, diag1, diag2);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);

    cout << "[\n";
    for (auto &sol : solutions) {
        cout << "[\n";
        for (auto &row : sol) cout << "\"" << row << "\",\n";
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}
