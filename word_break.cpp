#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> wordSet;
    unordered_map<string, vector<string>> memo;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }

    vector<string> dfs(string s) {
        if (memo.count(s)) return memo[s];

        vector<string> result;
        if (wordSet.count(s)) result.push_back(s);

        for (int i = 1; i < s.size(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);

            if (wordSet.count(left)) {
                vector<string> sublist = dfs(right);
                for (string str : sublist)
                    result.push_back(left + " " + str);
            }
        }

        return memo[s] = result;
    }
};

int main() {
    Solution sol;
    string s = "catsanddog";
    vector<string> dict = {"cat", "cats", "and", "sand", "dog"};

    vector<string> result = sol.wordBreak(s, dict);
    cout << "Possible sentences: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
