/*
 * Program Name: Doubly Linked List Implementation
 * * * Problem Statement:
 * Implement the fundamental Doubly Linked List (DLL) data structure in C.
 * A DLL is a sequence of elements where each node contains the data, a pointer
 * to the next node, AND a pointer to the previous node. This allows for
 * efficient bi-directional traversal.
 * * * Functions Included:
 * 1. insert_at_end() - Adds a new node to the end of the list.
 * 2. delete_node() - Deletes a node with a given key value.
 * 3. display_forward() - Prints the list from head to tail.
 * 4. display_backward() - Prints the list from tail to head (unique to DLL).
 * * * Input / Output Examples (Menu-Driven):
 * * --- Input 1 ---
 * Enter choice: 1 (Insert 10)
 * Enter choice: 1 (Insert 20)
 * Enter choice: 3 (Display Forward)
 * Enter choice: 4 (Display Backward)
 * * * --- Output 1 ---
 * List Forward: 10 -> 20 -> NULL
 * List Backward: 20 -> 10 -> NULL
 * * * --- Input 2 (Continuing from above) ---
 * Enter choice: 2 (Delete 10)
 * Enter choice: 3 (Display Forward)
 * * * --- Output 2 ---
 * Node with value 10 deleted.
 * List Forward: 20 -> NULL
 * * * Complexity (Worst-Case):
 * - Insertion at End (with tail pointer): O(1)
 * - Deletion of a specific node (after searching): O(N)
 * - Traversal (Forward/Backward): O(N)
 * * * Compilation Command:
 * gcc data_structures/doubly_linked_list.c -o dll
 * * * Approach:
 * The program uses a structure for the node containing an integer data field,
 * a 'next' pointer, and a 'prev' pointer. Global 'head' and 'tail' pointers
 * are maintained for O(1) insertion/deletion at both ends.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the Doubly Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Global pointers for head and tail
struct Node* head = NULL;
struct Node* tail = NULL;

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 1. Insert a node at the end of the list (O(1) with tail pointer)
void insert_at_end(int data) {
    struct Node* newNode = create_node(data);
    
    if (head == NULL) {
        // List is empty
        head = newNode;
        tail = newNode;
    } else {
        // Link the new node to the current tail
        tail->next = newNode;
        newNode->prev = tail;
        // Update the tail pointer
        tail = newNode;
    }
    printf("Inserted %d at the end.\n", data);
}

// 2. Delete a node with the given key value (O(N) due to search)
void delete_node(int key) {
    struct Node* current = head;

    // Search for the node
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    // Case 1: Node to be deleted is the head
    if (current == head) {
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; // List is now empty
        }
    } 
    // Case 2: Node to be deleted is the tail (and not the head)
    else if (current == tail) {
        tail = current->prev;
        tail->next = NULL;
    } 
    // Case 3: Node is in the middle
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    printf("Node with value %d deleted.\n", key);
    free(current);
}

// 3. Display the list from head to tail (Forward traversal)
void display_forward() {
    struct Node* current = head;
    printf("List Forward: ");
    if (current == NULL) {
        printf("List is empty.");
    }
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

// 4. Display the list from tail to head (Backward traversal)
void display_backward() {
    struct Node* current = tail;
    printf("List Backward: ");
    if (current == NULL) {
        printf("List is empty.");
    }
    while (current != NULL) {
        printf("%d", current->data);
        if (current->prev != NULL) {
            printf(" -> ");
        }
        current = current->prev;
    }
    printf(" -> NULL\n");
}

void print_menu() {
    printf("\n--- Doubly Linked List Operations ---\n");
    printf("1. Insert at End\n");
    printf("2. Delete Node by Value\n");
    printf("3. Display Forward\n");
    printf("4. Display Backward\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

int main() {
    int choice, data, key;

    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            // Handle non-integer input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 2:
                printf("Enter value of node to delete: ");
                scanf("%d", &key);
                delete_node(key);
                break;
            case 3:
                display_forward();
                break;
            case 4:
                display_backward();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                // Free memory before exit (optional but good practice)
                struct Node* temp;
                while (head != NULL) {
                    temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please select from 1 to 5.\n");
        }
    }
}