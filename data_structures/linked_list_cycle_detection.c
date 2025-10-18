/**
 * Program Name: Detect Cycle in a Linked List (Floyd's Tortoise and Hare)
 *
 * Problem Statement:
 * Given the head of a linked list, determine if the linked list has a cycle
 * in it. A cycle exists if some node in the list can be reached again by
 * continuously following the 'next' pointer.
 *
 * Input/Output Example:
 * - Input: A linked list where the last node points back to an earlier node.
 * (e.g., 1 -> 2 -> 3 -> 4 -> 2)
 * - Output: Cycle detected in the linked list.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the number of nodes in the list.
 * - Space Complexity: O(1), as it only uses two pointers.
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Creates a new node.
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Detects a cycle in a linked list using Floyd's Tortoise and Hare algorithm.
bool detectCycle(struct Node* head) {
    struct Node *slow_p = head, *fast_p = head;

    while (fast_p != NULL && fast_p->next != NULL) {
        slow_p = slow_p->next;      // Moves one step
        fast_p = fast_p->next->next; // Moves two steps

        // If slow and fast pointers meet, a cycle is present
        if (slow_p == fast_p) {
            return true;
        }
    }

    // If the loop finishes, no cycle was found
    return false;
}

// Main function to drive the program.
int main() {
    // Create a sample linked list
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    /* Create a loop for testing */
    // The last node (5) points back to the second node (2)
    head->next->next->next->next->next = head->next;

    if (detectCycle(head)) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle detected in the linked list.\n");
    }

    // Note: In a real application with a cycle, you cannot simply
    // traverse to free the nodes. Freeing memory would require
    // breaking the cycle first.
    return 0;
}