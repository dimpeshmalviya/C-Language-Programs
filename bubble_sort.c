/*
 * Program: Bubble Sort Algorithm
 * 
 * Problem Statement:
 * Implement bubble sort to sort an array of integers in ascending order.
 * 
 * Input/Output Example:
 * Enter the number of elements: 5
 * Enter 5 integers: 64 34 25 12 22
 * Original array: 64 34 25 12 22
 * Sorted array: 12 22 25 34 64
 * 
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * 
 * Compile: gcc bubble_sort.c -o bubble_sort
 */

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
