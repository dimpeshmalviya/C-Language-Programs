/*
Program Name: Fenwick Tree 
Problem Statement: To implement a Fenwick Tree to efficiently perform prefix sum and update operations on an array.

Example:
Input Array: [1, 2, 3, 4, 5]
Queries:
    Prefix sum(3) = 6
    Update index 2 by +3
    Prefix sum(3) = 9
*/

#include <stdio.h>


int bit[1000];    // Binary Indexed Tree array
int n;           // input size of array

// update BIT for index i by adding val
void update(int i, int val) {
    while (i <= n) {
        bit[i] += val;
        i += i & (-i);  // Move to next index
    }
}

// get prefix sum from 1 to i
int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= i & (-i);  // Move to parent index
    }
    return sum;
}

// build the BIT
void build(int arr[]) {
    for (int i = 1; i <= n; i++)
        update(i, arr[i]);
}

// print bit array
void printbit() {
    printf("Fenwick Tree: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", bit[i]);
    printf("\n");
}

int main() {
    int arr[1000];
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    // implement fenwick tree
    build(arr);
    // print 
    printbit();

    int choice, idx, val;
    while (1) {
        printf("\nMenu:\n1. Get Prefix Sum\n2. Update Value\n3. Exit\nChoose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter index for prefix sum: ");
            scanf("%d", &idx);
            printf("Prefix Sum up to %d = %d\n", idx, query(idx));
        } else if (choice == 2) {
            printf("Enter index and value to add: ");
            scanf("%d %d", &idx, &val);
            update(idx, val);
            printbit();
        } else break;
    }

    return 0;
}