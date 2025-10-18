#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kadane(vector<int>& arr, int& start, int& finish, int n) {
        int sum = 0, maxSum = INT_MIN, localStart = 0;
        finish = -1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum < arr[i]) {
                sum = arr[i];
                localStart = i;
            }

            if (sum > maxSum) {
                maxSum = sum;
                start = localStart;
                finish = i;
            }
        }

        if (finish == -1) { // All numbers are negative
            maxSum = arr[0];
            start = finish = 0;
            for (int i = 1; i < n; i++) {
                if (arr[i] > maxSum) {
                    maxSum = arr[i];
                    start = finish = i;
                }
            }
        }

        return maxSum;
    }

    int maxSumRectangle(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();

        int maxSum = INT_MIN;
        int left, right, top, bottom;

        for (int leftCol = 0; leftCol < cols; leftCol++) {
            vector<int> temp(rows, 0);

            for (int rightCol = leftCol; rightCol < cols; rightCol++) {
                for (int i = 0; i < rows; i++)
                    temp[i] += matrix[i][rightCol];

                int start = 0, finish = 0;
                int sum = kadane(temp, start, finish, rows);

                if (sum > maxSum) {
                    maxSum = sum;
                    left = leftCol;
                    right = rightCol;
                    top = start;
                    bottom = finish;
                }
            }
        }

        cout << "Maximum sum rectangle: (" << top << "," << left << ") to (" << bottom << "," << right << ")\n";
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}
    };

    int maxSum = sol.maxSumRectangle(matrix);
    cout << "Maximum sum of rectangle: " << maxSum << endl;
    return 0;
}
