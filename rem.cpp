#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        // Handle patterns like a*, a*b*, etc. that can match an empty string
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*' && j >= 2)
                dp[0][j] = dp[0][j - 2];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]; // Treat '*' as zero occurrence
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // One or more occurrences
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    Solution sol;
    string s = "mississippi";
    string p = "misisp*.";

    cout << (sol.isMatch(s, p) ? "true" : "false") << endl;
    return 0;
}
