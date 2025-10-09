/*
 * linked_list_example.c
 * Singly linked list with insert, delete, and print operations.
 * Compile: gcc -std=c11 -Wall -Wextra -o linked_list_example linked_list_example.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *create_node(int v) {
    Node *n = malloc(sizeof(*n));
    if (!n) return NULL;
    n->val = v;
    n->next = NULL;
    return n;
}

void push_front(Node **head, int v) {
    Node *n = create_node(v);
    if (!n) return;
    n->next = *head;
    *head = n;
}

void delete_value(Node **head, int v) {
    Node **cur = head;
    while (*cur) {
        if ((*cur)->val == v) {
            Node *tmp = *cur;
            *cur = tmp->next;
            free(tmp);
            return;
        }
        cur = &(*cur)->next;
    }
}

void print_list(const Node *head) {
    const Node *it = head;
    while (it) {
        printf("%d -> ", it->val);
        it = it->next;
    }
    puts("NULL");
}

void free_list(Node *head) {
    while (head) {
        Node *t = head;
        head = head->next;
        free(t);
    }
}

int main(void) {
    Node *head = NULL;
    push_front(&head, 3);
    push_front(&head, 7);
    push_front(&head, 5);
    push_front(&head, 9);

    printf("List after inserts: ");
    print_list(head);

    delete_value(&head, 5);
    printf("List after deleting 5: ");
    print_list(head);

    delete_value(&head, 9);
    printf("List after deleting 9: ");
    print_list(head);

    free_list(head);
    return 0;
}
