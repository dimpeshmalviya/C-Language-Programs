#include <stdio.h>
#include <stdlib.h>

// --- Data Structure Definition ---

/**
 * @brief Structure for a singly linked list node.
 * Contains an integer data value and a pointer to the next node.
 */
typedef struct Node {
    int data;
    struct Node* next;
} Node;


// --- Utility Functions ---

/**
 * @brief Creates a new node with the given data.
 * @param data The integer value to store in the new node.
 * @return A pointer to the newly created node.
 */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Inserts a new node at the beginning (head) of the linked list.
 * @param head_ref A pointer to the head of the list (passed by reference).
 * @param data The integer value to insert.
 */
void insertAtBeginning(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

/**
 * @brief Prints all elements of the linked list from the head.
 * @param head The starting node of the list.
 */
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * @brief Frees all memory allocated for the linked list to prevent leaks.
 * @param head The starting node of the list.
 */
void freeList(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}


// --- Core Contribution Function ---

/**
 * @brief Reverses a singly linked list iteratively.
 * This function updates the head pointer to point to the new head (original tail).
 * * @param head The original head of the linked list.
 * @return The new head of the reversed list.
 */
Node* reverseList(Node* head) {
    // Pointers for reversal: previous, current, and next node storage
    Node* prev = NULL;
    Node* current = head;
    Node* next_node = NULL;

    // Iterate through the list, changing 'next' pointers one by one
    while (current != NULL) {
        // 1. Store the next node before modifying the current node's next pointer
        next_node = current->next;
        
        // 2. Reverse the current node's pointer: point it to the previous node
        current->next = prev;
        
        // 3. Move pointers one position ahead
        prev = current;
        current = next_node;
    }

    // 'prev' is the new head (the original tail)
    return prev;
}


// --- Main Execution ---

int main() {
    Node* head = NULL;

    // 1. Build the list: 1 -> 2 -> 3 -> 4 -> NULL
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Original List:\n");
    printList(head);

    // 2. Reverse the list
    head = reverseList(head);

    printf("\nReversed List (Result):\n");
    printList(head); // Output: 4 -> 3 -> 2 -> 1 -> NULL

    // 3. Clean up memory
    freeList(head);
    
    return 0;
}
