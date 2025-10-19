#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX) {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;
        return isValidBST(root->left, min, root->val) && 
               isValidBST(root->right, root->val, max);
    }
};

int main() {
    Solution s;
    
    // Valid BST: [2,1,3]
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    cout << "Tree [2,1,3]: " << (s.isValidBST(root1) ? "Valid" : "Invalid") << endl;
    
    // Invalid BST: [5,1,4,null,null,3,6]
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    cout << "Tree [5,1,4,3,6]: " << (s.isValidBST(root2) ? "Valid" : "Invalid") << endl;
    
    return 0;