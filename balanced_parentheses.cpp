#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        
        for (char c : s) {
            if (pairs.count(c)) {
                if (st.empty() || st.top() != pairs[c]) return false;
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    
    cout << "\"()\" -> " << (sol.isValid("()") ? "true" : "false") << endl;
    cout << "\"()[]{}\" -> " << (sol.isValid("()[]{}") ? "true" : "false") << endl;
    cout << "\"(]\" -> " << (sol.isValid("(]") ? "true" : "false") << endl;
    cout << "\"([)]\" -> " << (sol.isValid("([)]") ? "true" : "false") << endl;
    cout << "\"{[]}\" -> " << (sol.isValid("{[]}") ? "true" : "false") << endl;
    
    return 0;
}