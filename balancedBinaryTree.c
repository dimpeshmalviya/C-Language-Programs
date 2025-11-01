/*
Program: Balanced Binary Tree Check
Problem Statement:
    A binary tree is considered balanced if for every node,
    the height difference between its left and right subtree is at most 1.

Approach:
    - Use recursion to calculate height of left and right subtrees.
    - While calculating, check the balance condition.
    - If any subtree is unbalanced, propagate -1 upward to indicate failure.

Example Input (Tree):
          1
         / \
        2   3
       / \
      4   5

Example Output:
    Tree is balanced.

Complexity:
    Time: O(n), where n = number of nodes
    Space: O(h), recursion stack where h = height of tree
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to check height and balance
int checkHeight(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1; // left subtree unbalanced

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1; // right subtree unbalanced

    if (abs(leftHeight - rightHeight) > 1)
        return -1; // current node unbalanced

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Wrapper function
int isBalanced(struct Node* root) {
    return (checkHeight(root) != -1);
}

// Driver code
int main() {
    // Example tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    if (isBalanced(root))
        printf("Tree is balanced.\n");
    else
        printf("Tree is NOT balanced.\n");

    return 0;
}
