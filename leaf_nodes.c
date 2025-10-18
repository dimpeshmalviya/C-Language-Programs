#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printLeafNodes(struct Node* root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
        return;
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    printf("Leaf nodes: ");
    printLeafNodes(root);
    printf("\n");
    return 0;
}