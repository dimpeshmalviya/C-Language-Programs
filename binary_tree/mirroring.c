/*program : to mirror a binary tree

step-1 check if the root node is equal to null then return null
step-2 swap the left and the right root 
step-3 recursively call for the left and right

Time Complexity: O(n), where n is the number of nodes in the tree
Space Complexity: O(h), where h is the height of the tree due to recursion stack


before ->1 3 4 5 6 8 10 20 
after -> 20 10 8 6 5 4 3 1 
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Mirror the tree
struct Node* mirror(struct Node* root) {
    if (root == NULL) return NULL;

    // Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recurse
    mirror(root->left);
    mirror(root->right);

    return root;
}

// Inorder traversal
void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(20);
    root->right->left->right = createNode(8);

    printf("Before Mirroring:\n");
    printInorder(root);

    mirror(root);

    printf("\nAfter Mirroring:\n");
    printInorder(root);

    return 0;
}