#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Helper function to create new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Reverse a linked list and return new head
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *next = NULL, *curr = head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Check if linked list is palindrome
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle using slow-fast pointers
    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    struct ListNode* secondHalf = reverseList(slow->next);

    // Step 3: Compare both halves
    struct ListNode* firstHalf = head;
    struct ListNode* temp = secondHalf;
    bool palindrome = true;

    while (temp) {
        if (firstHalf->val != temp->val) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    // Step 4: (Optional) Restore original list
    slow->next = reverseList(secondHalf);

    return palindrome;
}

// Example usage
int main() {
    // Create linked list: 1 -> 2 -> 2 -> 1
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(2);
    head->next->next->next = newNode(1);

    if (isPalindrome(head))
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}
