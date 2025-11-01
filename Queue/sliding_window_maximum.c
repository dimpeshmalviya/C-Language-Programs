#include <stdio.h>
#include <stdlib.h>

// Deque structure to store indices
typedef struct {
    int *data;
    int front, rear, size;
} Deque;

// Initialize deque
Deque* createDeque(int size) {
    Deque *dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(size * sizeof(int));
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
    return dq;
}

// Check if deque is empty
int isEmpty(Deque *dq) {
    return dq->size == 0;
}

// Push element to back
void pushBack(Deque *dq, int value) {
    dq->rear++;
    dq->data[dq->rear] = value;
    dq->size++;
}

// Pop element from back
void popBack(Deque *dq) {
    if (!isEmpty(dq)) {
        dq->rear--;
        dq->size--;
    }
}

// Pop element from front
void popFront(Deque *dq) {
    if (!isEmpty(dq)) {
        dq->front++;
        dq->size--;
    }
}

// Get front element
int front(Deque *dq) {
    return dq->data[dq->front];
}

// Get back element
int back(Deque *dq) {
    return dq->data[dq->rear];
}

// Main function to find sliding window maximum
void maxSlidingWindow(int nums[], int n, int k) {
    Deque *dq = createDeque(n);
    int resultCount = 0;
    int *result = (int*)malloc((n - k + 1) * sizeof(int));

    for (int i = 0; i < n; i++) {
        // Remove indices out of the current window
        if (!isEmpty(dq) && front(dq) <= i - k)
            popFront(dq);

        // Remove smaller elements from back
        while (!isEmpty(dq) && nums[back(dq)] <= nums[i])
            popBack(dq);

        // Add current index
        pushBack(dq, i);

        // Store max for full window
        if (i >= k - 1)
            result[resultCount++] = nums[front(dq)];
    }

    // Print results
    printf("Sliding Window Maximum: ");
    for (int i = 0; i < resultCount; i++)
        printf("%d ", result[i]);
    printf("\n");

    // Free memory
    free(dq->data);
    free(dq);
    free(result);
}

// Example usage
int main() {
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int n = sizeof(nums) / sizeof(nums[0]);

    maxSlidingWindow(nums, n, k);

    return 0;
}
