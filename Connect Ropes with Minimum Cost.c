/*
 * Connect Ropes with Minimum Cost
 *
 * Problem:
 * You are given an array 'ropes' where each element represents the length of a rope.
 * You need to connect all ropes into one rope.
 * The cost of connecting two ropes is equal to the sum of their lengths.
 * The goal is to find the minimum total cost to connect all ropes into one.
 *
 * Example:
 * Input : [4, 3, 2, 6]
 * Output: 29
 *
 * Explanation:
 * - Connect ropes 2 and 3 → cost = 5  → new ropes = [4, 5, 6]
 * - Connect ropes 4 and 5 → cost = 9  → new ropes = [6, 9]
 * - Connect ropes 6 and 9 → cost = 15 → total cost = 5 + 9 + 15 = 29
 *
 * Approach:
 *  - Use a Min-Heap (Priority Queue) to always connect the two smallest ropes first.
 *  - Push all rope lengths into the heap.
 *  - While heap size > 1:
 *        Extract two smallest elements (a, b)
 *        Connect them → cost = a + b
 *        Push the combined rope (a + b) back into heap
 *        Add cost to total
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

// -------- Min Heap Implementation --------
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(int heap[], int *size, int value) {
    heap[(*size)++] = value;
    heapifyUp(heap, *size - 1);
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return root;
}

// -------- Main Logic --------
int connectRopesMinCost(int ropes[], int n) {
    int heap[1000];
    int size = 0;
    int totalCost = 0;

    // Build Min-Heap
    for (int i = 0; i < n; i++)
        push(heap, &size, ropes[i]);

    // Combine ropes until one remains
    while (size > 1) {
        int first = pop(heap, &size);
        int second = pop(heap, &size);
        int cost = first + second;
        totalCost += cost;
        push(heap, &size, cost);
    }

    return totalCost;
}

int main() {
    // Test Case 1
    int ropes1[] = {4, 3, 2, 6};
    int n1 = sizeof(ropes1) / sizeof(ropes1[0]);
    printf("Output 1: %d\n", connectRopesMinCost(ropes1, n1)); // 29

    // Test Case 2
    int ropes2[] = {5, 2, 4, 3, 8};
    int n2 = sizeof(ropes2) / sizeof(ropes2[0]);
    printf("Output 2: %d\n", connectRopesMinCost(ropes2, n2)); // 54

    // Test Case 3 (Edge Case)
    int ropes3[] = {10};
    int n3 = sizeof(ropes3) / sizeof(ropes3[0]);
    printf("Output 3: %d\n", connectRopesMinCost(ropes3, n3)); // 0

    return 0;
}
