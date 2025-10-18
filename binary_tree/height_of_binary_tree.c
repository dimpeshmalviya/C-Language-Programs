/*
Program to calculate and print the height of a binary tree in C.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the height of the binary tree
int height(struct Node* root) {
    if (root == NULL)
        return 0; // Base case: empty tree has height 0

    // Recursively find height of left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Height is the larger one + 1 for current node
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    /*
        Example tree:
                1
               / \
              2   3
             / \
            4   5
    */

    // Create root node
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Calculate and print the height of the tree
    printf("Height of the binary tree is: %d\n", height(root));

    return 0;
}

/*
Sample Input (Tree created inside main):

        1
       / \
      2   3
     / \
    4   5

Sample Output:
Height of the binary tree is: 3

Time Complexity: Each node is visited once. So, O(N) where N = number of nodes in the tree.

Space Complexity: In the worst case (skewed tree), recursion goes as deep as N calls.
Space complexity = O(H), where H = height of the tree.
    Worst case: O(N) (skewed tree).
    Best case: O(log N) (balanced tree).

*/

