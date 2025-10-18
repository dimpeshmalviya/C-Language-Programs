/*
 * Program: Binary Search Algorithm
 * 
 * Problem Statement:
 * Implement binary search to find the position of a target element in a sorted array.
 * Binary search works by repeatedly dividing the search interval in half and comparing
 * the target with the middle element.
 * 
 * Input: 
 * - A sorted array of integers
 * - Target element to search for
 * 
 * Output:
 * - Index of the target element (0-based indexing)
 * - -1 if element is not found
 * 
 * Example:
 * Array: [2, 5, 8, 12, 16, 23, 38, 56, 67, 78]
 * Target: 23
 * Output: Index 5
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * 
 * Compile with: gcc BinarySearch.c -o BinarySearch
 */

#include <stdio.h>

// Function to perform binary search
int binarySearch(int array[], int size, int target) {
    int left = 0;              // Left boundary of search range
    int right = size - 1;      // Right boundary of search range
    
    while (left <= right) {
        // Calculate middle index to avoid integer overflow
        int middle = left + (right - left) / 2;
        
        // Target found at middle position
        if (array[middle] == target) {
            return middle;
        }
        
        // Target is smaller, search left half
        if (array[middle] > target) {
            right = middle - 1;
        }
        // Target is larger, search right half
        else {
            left = middle + 1;
        }
    }
    
    // Target not found
    return -1;
}

// Function to display array elements
void displayArray(int array[], int size) {
    printf("Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    // Example sorted array for demonstration
    int array[] = {2, 5, 8, 12, 16, 23, 38, 56, 67, 78};
    int size = sizeof(array) / sizeof(array[0]);
    int target;
    
    printf("=== Binary Search Algorithm Demo ===\n\n");
    
    // Display the sorted array
    displayArray(array, size);
    printf("Array size: %d elements\n\n", size);
    
    // Get target element from user
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    
    // Perform binary search
    int result = binarySearch(array, size, target);
    
    // Display results
    printf("\nSearching for: %d\n", target);
    
    if (result != -1) {
        printf("✓ Element found at index: %d\n", result);
        printf("✓ Element value: %d\n", array[result]);
    } else {
        printf("✗ Element not found in the array\n");
        printf("Note: Binary search only works on sorted arrays\n");
    }
    
    // Additional test cases for demonstration
    printf("\n=== Running Additional Test Cases ===\n");
    
    int testCases[] = {2, 23, 78, 15, 100};
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        int testResult = binarySearch(array, size, testCases[i]);
        printf("Search %d: ", testCases[i]);
        
        if (testResult != -1) {
            printf("Found at index %d\n", testResult);
        } else {
            printf("Not found\n");
        }
    }
    
    printf("\nTime Complexity: O(log n)\n");
    printf("Space Complexity: O(1)\n");
    
    return 0;
}