#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) return root;
        return left ? left : right;
    }
};

int main() {
    Solution s;
    
    // Tree: [3,5,1,6,2,0,8,null,null,7,4]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    TreeNode* p = root->left;       // Node 5
    TreeNode* q = root->right;      // Node 1
    TreeNode* lca = s.lowestCommonAncestor(root, p, q);
    cout << "LCA of 5 and 1: " << lca->val << endl;  // 3
    
    p = root->left;                 // Node 5
    q = root->left->right->right;   // Node 4
    lca = s.lowestCommonAncestor(root, p, q);
    cout << "LCA of 5 and 4: " << lca->val << endl;  // 5
    
    return 0;
}