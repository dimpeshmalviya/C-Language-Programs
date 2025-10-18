#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Regular Expression Matching - LeetCode 10
// '.' matches any single character
// '*' matches zero or more of the preceding element

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        
        // Handle patterns like a*, a*b* that can match empty string
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // Don't use the star
                    dp[i][j] = dp[i][j - 2];
                    
                    // Use the star if current char matches
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else {
                    // Direct character match
                    if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};

// Test the solution
void test() {
    Solution sol;
    
    // Test cases
    cout << "Testing Regular Expression Matching:\n";
    cout << "====================================\n";
    
    // Basic tests
    cout << "aa, a: " << (sol.isMatch("aa", "a") ? "true" : "false") << " (expected: false)\n";
    cout << "aa, a*: " << (sol.isMatch("aa", "a*") ? "true" : "false") << " (expected: true)\n";
    cout << "ab, .*: " << (sol.isMatch("ab", ".*") ? "true" : "false") << " (expected: true)\n";
    cout << "aab, c*a*b: " << (sol.isMatch("aab", "c*a*b") ? "true" : "false") << " (expected: true)\n";
    
    // The example from the issue
    cout << "mississippi, misisp*.: " << (sol.isMatch("mississippi", "misisp*.") ? "true" : "false") << " (expected: true)\n";
    
    // Edge cases
    cout << "\"\", .*: " << (sol.isMatch("", ".*") ? "true" : "false") << " (expected: true)\n";
    cout << "\"\", \"\": " << (sol.isMatch("", "") ? "true" : "false") << " (expected: true)\n";
    cout << "a, \"\": " << (sol.isMatch("a", "") ? "true" : "false") << " (expected: false)\n";
    
    cout << "\nAll tests completed!\n";
}

int main() {
    test();
    return 0;
}