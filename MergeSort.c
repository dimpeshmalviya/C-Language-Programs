/*
 * Program: Merge Sort Algorithm
 * 
 * Problem Statement:
 * Implement merge sort to sort an array of integers in ascending order.
 * Merge sort is a divide-and-conquer algorithm that divides the array into halves,
 * recursively sorts them, and then merges the sorted halves back together.
 * 
 * Input: 
 * - An unsorted array of integers
 * - Size of the array
 * 
 * Output:
 * - The same array sorted in ascending order
 * 
 * Example:
 * Input:  [64, 34, 25, 12, 22, 11, 90, 5]
 * Output: [5, 11, 12, 22, 25, 34, 64, 90]
 * 
 * Time Complexity: O(n log n) - for all cases (best, average, worst)
 * Space Complexity: O(n) - requires additional space for temporary arrays
 * 
 * Compile with: gcc MergeSort.c -o MergeSort
 */

#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted subarrays
void merge(int array[], int left, int middle, int right) {
    int i, j, k;
    
    // Calculate sizes of the two subarrays to be merged
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    
    // Create temporary arrays for left and right subarrays
    int *leftArray = (int*)malloc(leftSize * sizeof(int));
    int *rightArray = (int*)malloc(rightSize * sizeof(int));
    
    // Copy data to temporary arrays
    for (i = 0; i < leftSize; i++) {
        leftArray[i] = array[left + i];
    }
    for (j = 0; j < rightSize; j++) {
        rightArray[j] = array[middle + 1 + j];
    }
    
    // Merge the temporary arrays back into array[left..right]
    i = 0;    // Initial index of left subarray
    j = 0;    // Initial index of right subarray
    k = left; // Initial index of merged subarray
    
    // Compare elements from both arrays and merge in sorted order
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of leftArray[], if any
    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of rightArray[], if any
    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
    
    // Free allocated memory
    free(leftArray);
    free(rightArray);
}

// Main merge sort function
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        // Calculate middle point to divide array into two halves
        int middle = left + (right - left) / 2;
        
        // Recursively sort first and second halves
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        
        // Merge the sorted halves
        merge(array, left, middle, right);
    }
}

// Function to display array elements
void displayArray(int array[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

// Function to copy array (for demonstration purposes)
void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

// Function to check if array is sorted
int isSorted(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}

int main() {
    printf("=== Merge Sort Algorithm Demo ===\n\n");
    
    // Example array for demonstration
    int originalArray[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int size = sizeof(originalArray) / sizeof(originalArray[0]);
    
    // Create a copy to sort (keep original for display)
    int *arrayToSort = (int*)malloc(size * sizeof(int));
    copyArray(originalArray, arrayToSort, size);
    
    // Display original array
    printf("Original array: ");
    displayArray(originalArray, size);
    printf("\nArray size: %d elements\n\n", size);
    
    // Perform merge sort
    printf("Sorting array using Merge Sort...\n");
    mergeSort(arrayToSort, 0, size - 1);
    
    // Display sorted array
    printf("\nSorted array:   ");
    displayArray(arrayToSort, size);
    printf("\n");
    
    // Verify sorting
    if (isSorted(arrayToSort, size)) {
        printf("✓ Array successfully sorted!\n");
    } else {
        printf("✗ Sorting failed!\n");
    }
    
    // Interactive section for user input
    printf("\n=== Try with your own array ===\n");
    int userSize;
    
    printf("Enter the number of elements (max 20): ");
    scanf("%d", &userSize);
    
    if (userSize > 0 && userSize <= 20) {
        int *userArray = (int*)malloc(userSize * sizeof(int));
        
        printf("Enter %d integers:\n", userSize);
        for (int i = 0; i < userSize; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &userArray[i]);
        }
        
        printf("\nYour array: ");
        displayArray(userArray, userSize);
        printf("\n");
        
        // Sort user's array
        printf("Sorting your array...\n");
        mergeSort(userArray, 0, userSize - 1);
        
        printf("Sorted array: ");
        displayArray(userArray, userSize);
        printf("\n");
        
        if (isSorted(userArray, userSize)) {
            printf("✓ Your array was successfully sorted!\n");
        }
        
        free(userArray);
    } else {
        printf("Invalid size. Please enter a number between 1 and 20.\n");
    }
    
    // Additional test cases
    printf("\n=== Additional Test Cases ===\n");
    
    // Test case 1: Already sorted array
    int sortedArray[] = {1, 2, 3, 4, 5};
    int sortedSize = 5;
    printf("\nTest 1 - Already sorted: ");
    displayArray(sortedArray, sortedSize);
    mergeSort(sortedArray, 0, sortedSize - 1);
    printf("\nAfter sorting: ");
    displayArray(sortedArray, sortedSize);
    printf("\n");
    
    // Test case 2: Reverse sorted array
    int reverseArray[] = {5, 4, 3, 2, 1};
    int reverseSize = 5;
    printf("\nTest 2 - Reverse sorted: ");
    displayArray(reverseArray, reverseSize);
    mergeSort(reverseArray, 0, reverseSize - 1);
    printf("\nAfter sorting: ");
    displayArray(reverseArray, reverseSize);
    printf("\n");
    
    // Test case 3: Array with duplicates
    int duplicateArray[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int duplicateSize = 9;
    printf("\nTest 3 - With duplicates: ");
    displayArray(duplicateArray, duplicateSize);
    mergeSort(duplicateArray, 0, duplicateSize - 1);
    printf("\nAfter sorting: ");
    displayArray(duplicateArray, duplicateSize);
    printf("\n");
    
    // Algorithm complexity information
    printf("\n=== Algorithm Analysis ===\n");
    printf("Time Complexity:\n");
    printf("  - Best Case:    O(n log n)\n");
    printf("  - Average Case: O(n log n)\n");
    printf("  - Worst Case:   O(n log n)\n");
    printf("Space Complexity: O(n)\n");
    printf("\nAdvantages:\n");
    printf("  - Stable sorting algorithm\n");
    printf("  - Consistent O(n log n) performance\n");
    printf("  - Good for large datasets\n");
    printf("  - Parallelizable\n");
    printf("\nDisadvantages:\n");
    printf("  - Requires O(n) extra space\n");
    printf("  - Not in-place sorting\n");
    
    free(arrayToSort);
    return 0;
}