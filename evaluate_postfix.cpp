#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (t == "+") st.push(a + b);
                else if (t == "-") st.push(a - b);
                else if (t == "*") st.push(a * b);
                else st.push(a / b);
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};

int main() {
    Solution s;
    
    vector<string> expr1 = {"2", "1", "+", "3", "*"};
    cout << "Result: " << s.evalRPN(expr1) << endl; // (2+1)*3 = 9
    
    vector<string> expr2 = {"4", "13", "5", "/", "+"};
    cout << "Result: " << s.evalRPN(expr2) << endl; // 4+(13/5) = 6
    
    vector<string> expr3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Result: " << s.evalRPN(expr3) << endl; // 22
    
    return 0;
}