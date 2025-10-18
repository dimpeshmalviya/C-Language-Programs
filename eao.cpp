#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;

    void backtrack(string num, long long target, int pos, long long eval, long long multed, string path) {
        if (pos == num.size()) {
            if (eval == target) result.push_back(path);
            return;
        }

        for (int i = pos; i < num.size(); i++) {
            // Prevent numbers with leading zeros
            if (i != pos && num[pos] == '0') break;

            string curStr = num.substr(pos, i - pos + 1);
            long long curNum = stoll(curStr);

            if (pos == 0) {
                // Start of expression
                backtrack(num, target, i + 1, curNum, curNum, curStr);
            } else {
                // Add '+'
                backtrack(num, target, i + 1, eval + curNum, curNum, path + "+" + curStr);
                // Add '-'
                backtrack(num, target, i + 1, eval - curNum, -curNum, path + "-" + curStr);
                // Add '*'
                backtrack(num, target, i + 1, eval - multed + multed * curNum, multed * curNum, path + "*" + curStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        result.clear();
        if (num.empty()) return result;
        backtrack(num, target, 0, 0, 0, "");
        return result;
    }
};

int main() {
    Solution sol;
    string num = "123";
    int target = 6;

    vector<string> expressions = sol.addOperators(num, target);
    cout << "Possible expressions: [";
    for (int i = 0; i < expressions.size(); i++) {
        cout << "\"" << expressions[i] << "\"";
        if (i < expressions.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
