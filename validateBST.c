// School-level C code to validate a Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Helper function to check BST validity
int isBSTUtil(struct Node* node, int min, int max) {
    if (node == NULL)
        return 1;

    if (node->data <= min || node->data >= max)
        return 0;

    return isBSTUtil(node->left, min, node->data) &&
           isBSTUtil(node->right, node->data, max);
}

// Wrapper function
int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    struct Node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    if (isBST(root))
        printf("Valid BST\n");
    else
        printf("Invalid BST\n");

    return 0;
}
