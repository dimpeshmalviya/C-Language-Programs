/*
 * bst_example.c
 * Simple binary search tree: insert, inorder traversal, and free.
 * Compile: gcc -std=c11 -Wall -Wextra -o bst_example bst_example.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node *new_node(int key) {
    Node *n = malloc(sizeof(*n));
    if (!n) return NULL;
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, int key) {
    if (!root) return new_node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

void inorder(const Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void free_tree(Node *root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {
    int keys[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    size_t n = sizeof(keys)/sizeof(*keys);
    Node *root = NULL;
    for (size_t i = 0; i < n; ++i) root = insert(root, keys[i]);

    printf("Inorder traversal of BST: ");
    inorder(root);
    putchar('\n');

    free_tree(root);
    return 0;
}
