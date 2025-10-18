/*
 Program: Symmetric Binary Tree (Mirror Check)
 Problem: Check if a binary tree is symmetric (mirror of itself).
 Input: A binary tree
 Output: "Symmetric" or "Not Symmetric"

 Example:
        1
      /   \
     2     2
    / \   / \
   3   4 4   3
 Output: Symmetric

 Complexity: O(n) where n = number of nodes
 Compile: gcc SymmetricTree.c -o SymmetricTree
 Run: ./SymmetricTree
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to check mirror
bool isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int main() {
    // Example tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isMirror(root, root))
        printf("Symmetric\n");
    else
        printf("Not Symmetric\n");
    return 0;
}
