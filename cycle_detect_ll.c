#include <stdio.h>
#include <stdlib.h>

struct Node {int data; struct Node *next;};

struct Node* newNode(int val){
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val; n->next = NULL; return n;
}

int hasCycle(struct Node* head){
    struct Node *slow = head, *fast = head;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

int main(){
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head->next; // cycle
    printf(hasCycle(head) ? "Cycle detected\n" : "No cycle\n");
}