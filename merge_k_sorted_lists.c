// merge_k_sorted_lists.c
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* newNode(int v) {
    ListNode* n = (ListNode*)malloc(sizeof(ListNode));
    n->val = v; n->next = NULL; return n;
}

/* Min-heap for ListNode* comparing node->val */
typedef struct MinHeap {
    ListNode** arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int cap) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->arr = (ListNode**)malloc(sizeof(ListNode*) * cap);
    h->size = 0; h->capacity = cap;
    return h;
}

void swapNodes(ListNode** a, ListNode** b) {
    ListNode* t = *a; *a = *b; *b = t;
}

void heapifyUp(MinHeap* h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (h->arr[parent]->val > h->arr[idx]->val) {
            swapNodes(&h->arr[parent], &h->arr[idx]);
            idx = parent;
        } else break;
    }
}

void heapifyDown(MinHeap* h, int idx) {
    int left, right, smallest;
    while (1) {
        left = 2*idx + 1; right = 2*idx + 2; smallest = idx;
        if (left < h->size && h->arr[left]->val < h->arr[smallest]->val) smallest = left;
        if (right < h->size && h->arr[right]->val < h->arr[smallest]->val) smallest = right;
        if (smallest != idx) {
            swapNodes(&h->arr[smallest], &h->arr[idx]);
            idx = smallest;
        } else break;
    }
}

void pushHeap(MinHeap* h, ListNode* node) {
    if (h->size == h->capacity) return; // capacity should be k
    h->arr[h->size] = node;
    heapifyUp(h, h->size);
    h->size++;
}

ListNode* popHeap(MinHeap* h) {
    if (h->size == 0) return NULL;
    ListNode* root = h->arr[0];
    h->size--;
    if (h->size > 0) {
        h->arr[0] = h->arr[h->size];
        heapifyDown(h, 0);
    }
    return root;
}

ListNode* mergeKLists(ListNode** lists, int k) {
    MinHeap* heap = createHeap(k);
    for (int i = 0; i < k; ++i) {
        if (lists[i]) pushHeap(heap, lists[i]);
    }
    ListNode dummy; ListNode* tail = &dummy; dummy.next = NULL;

    while (heap->size > 0) {
        ListNode* node = popHeap(heap);
        tail->next = node;
        tail = tail->next;
        if (node->next) pushHeap(heap, node->next);
        tail->next = NULL; // detach rest to keep list clean
    }
    free(heap->arr); free(heap);
    return dummy.next;
}

/* Helper to print list */
void printList(ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create sample lists: [1,4,5], [1,3,4], [2,6]
    ListNode* l1 = newNode(1); l1->next = newNode(4); l1->next->next = newNode(5);
    ListNode* l2 = newNode(1); l2->next = newNode(3); l2->next->next = newNode(4);
    ListNode* l3 = newNode(2); l3->next = newNode(6);

    ListNode* lists[] = {l1, l2, l3};
    ListNode* merged = mergeKLists(lists, 3);
    printList(merged); // expected 1->1->2->3->4->4->5->6

    // free nodes omitted for brevity in this demo
    return 0;
}