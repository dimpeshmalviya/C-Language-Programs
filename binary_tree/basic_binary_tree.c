#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node(constructor)
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

// Root -> Left -> Right
void preOrder(struct Node* root){
    if(root == NULL) return; // base case
    printf("%d ", root->data);  // root
    preOrder(root->left);   // left
    preOrder(root->right);  // right
}

// Left -> Root -> Right
void inOrder(struct Node* root){
    if(root == NULL) return; // base case
    inOrder(root->left);    // left
    printf("%d ", root->data); // root
    inOrder(root->right);   // right
}

// Left -> Right -> Root
void postOrder(struct Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

//  delete the tree
void delt(struct Node* root){
    if(root == NULL) return;
    delt(root->left);
    delt(root->right);
    free(root);
}

int main(){
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    /*
    
        1
       / \
      2   3
     / \ 
    4  5 

    */

    printf("Pre-order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(root);
    printf("\n");

    delt(root);
    return 0;
}