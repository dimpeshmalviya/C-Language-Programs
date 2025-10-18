#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            int minCuts = i; // Maximum cuts = i (cut before every char)
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 1 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    // If palindrome starts from index 0, no cut needed
                    minCuts = (j == 0) ? 0 : min(minCuts, dp[j - 1] + 1);
                }
            }
            dp[i] = minCuts;
        }
        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    string s = "aab";
    cout << "Minimum cuts needed: " << sol.minCut(s) << endl;
    return 0;
}
