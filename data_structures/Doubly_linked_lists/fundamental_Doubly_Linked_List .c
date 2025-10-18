#include <stdio.h>
#include <stdlib.h>

// Definition of a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at the end of the DLL
void insert_at_end(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node with a given key
void delete_node(int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;  // Deleting head

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Display DLL from head to tail
void display_forward() {
    struct Node* temp = head;
    printf("DLL forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display DLL from tail to head
void display_backward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("DLL is empty.\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("DLL backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function to test the DLL
int main() {
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);

    display_forward();   // Output: 10 20 30
    display_backward();  // Output: 30 20 10

    delete_node(20);

    display_forward();   // Output: 10 30
    display_backward();  // Output: 30 10

    return 0;
}
