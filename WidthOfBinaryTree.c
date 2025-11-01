/*
 Program: Maximum Width of a Binary Tree
 Problem: Find the maximum number of nodes present at any level of a binary tree.
 Input: Binary Tree
 Output: Maximum width

 Example:
        1
      /   \
     2     3
    / \     \
   4   5     8
            / \
           6   7

 Level order:
 Level 1: 1 → width = 1
 Level 2: 2,3 → width = 2
 Level 3: 4,5,8 → width = 3
 Level 4: 6,7 → width = 2
 Maximum Width = 3

 Complexity: O(n) where n = number of nodes
 Compile: gcc WidthOfTree.c -o WidthOfTree
 Run: ./WidthOfTree
*/

#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue node for level order traversal
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

// Simple queue implementation
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    struct Node* node = temp->treeNode;
    free(temp);
    return node;
}

int queueSize(struct Queue* q) {
    int size = 0;
    struct QueueNode* temp = q->front;
    while (temp) {
        size++;
        temp = temp->next;
    }
    return size;
}

// Function to get maximum width
int getMaxWidth(struct Node* root) {
    if (root == NULL) return 0;

    int maxWidth = 0;
    struct Queue* q = createQueue();
    enqueue(q, root);

    while (q->front != NULL) {
        int count = queueSize(q);
        if (count > maxWidth) maxWidth = count;

        for (int i = 0; i < count; i++) {
            struct Node* node = dequeue(q);
            if (node->left != NULL) enqueue(q, node->left);
            if (node->right != NULL) enqueue(q, node->right);
        }
    }
    return maxWidth;
}

int main() {
    // Example tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    printf("Maximum width of the tree: %d\n", getMaxWidth(root));
    return 0;
}
