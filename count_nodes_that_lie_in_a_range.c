// C program to count BST nodes
// within a given range
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Returns count of nodes in BST in range [l, h]
int getCount(struct Node *root, int l, int h)
{

    // Base case
    if (root == NULL)
        return 0;

    // If current node is in range, then
    // include it in count and recur for
    // left and right children of it
    if (root->data <= h && root->data >= l)
        return 1 + getCount(root->left, l, h) +
               getCount(root->right, l, h);

    // If current node is smaller than low,
    // then recur for right child
    else if (root->data < l)
        return getCount(root->right, l, h);

    // Else recur for left child
    else
        return getCount(root->left, l, h);
}

struct Node *createNode(int x)
{
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{

    // Create a hard coded bst.
    //        10
    //       /  \
    //      5   50
    //     /   /  \
    //    1   40  100
    struct Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(50);
    root->left->left = createNode(1);
    root->right->left = createNode(40);
    root->right->right = createNode(100);

    int l = 5;
    int h = 45;

    printf("%d\n", getCount(root, l, h));

    return 0;
}