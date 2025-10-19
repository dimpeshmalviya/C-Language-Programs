#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                result[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};

int main() {
    Solution s;
    
    vector<int> nums1 = {4, 5, 2, 10, 8};
    vector<int> res1 = s.nextGreaterElement(nums1);
    cout << "Input:  [4, 5, 2, 10, 8]" << endl;
    cout << "Output: [";
    for (int i = 0; i < res1.size(); i++) {
        cout << res1[i];
        if (i < res1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    vector<int> nums2 = {1, 3, 2, 4};
    vector<int> res2 = s.nextGreaterElement(nums2);
    cout << "Input:  [1, 3, 2, 4]" << endl;
    cout << "Output: [";
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i];
        if (i < res2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}