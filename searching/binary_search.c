/*
Program Name: Binary Search in C
Problem Statement:
Write a C program to perform binary search on a sorted array of size N to find a given element.

Example:
Input:
Enter number of elements: 5
Enter sorted elements: 1 3 5 7 9
Enter element to be found: 5

Output:
Element 5 found at position 3

Compilation Command:
gcc binary_search.c -o binary_search

Time Complexity: O(log N)
Space Complexity: O(1)
*/

#include <stdio.h>

int main() {
    int n, ele, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int x[n];
    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    printf("Enter element to be found: ");
    scanf("%d", &ele);

    int p = 0, q = n - 1, mid;
    int found = 0;

    while (p <= q) {
        mid = (p + q) / 2;
        if (x[mid] == ele) {
            found = 1;
            printf("Element %d found at position %d\n", ele, mid + 1);
            break; // stop once found
        } else if (x[mid] < ele) {
            p = mid + 1;
        } else {
            q = mid - 1;
        }
    }

    if (!found) {
        printf("Element not found.\n");
    }

    return 0;
}
