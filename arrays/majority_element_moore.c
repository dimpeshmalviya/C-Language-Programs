/**
 
 * Program Name: Majority Element (Moore's Voting Algorithm)
 *
 * Problem Statement:
 * Given an array of size n, find the element that appears more than ⌊n/2⌋
 * times. The algorithm first finds a potential candidate and then verifies if
 * that candidate is indeed the majority element.
 *
 * Input/Output Examples:
 * 1. Majority element exists:
 * - Input Array: [2, 2, 1, 1, 1, 2, 2]
 * - Output: The majority element is 2
 *
 * 2. No majority element exists:
 * - Input Array: [1, 2, 3, 4, 5, 6]
 * - Output: No majority element found
 *
 * Complexity:
 * - Time Complexity: O(n) - The array is traversed at most twice.
 * - Space Complexity: O(1) - No extra space is used besides a few variables.
 
 */

#include <stdio.h>
#include <stdbool.h>

// Finds a potential candidate for the majority element.
int findCandidate(int arr[], int n) {
    int majority_index = 0;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[majority_index]) {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            majority_index = i;
            count = 1;
        }
    }
    return arr[majority_index];
}

// Verifies if the candidate is truly the majority element.
bool isMajority(int arr[], int n, int candidate) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }
    return count > n / 2;
}

// Main function to drive the program.
int main() {
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int candidate = findCandidate(arr, n);

    if (isMajority(arr, n, candidate)) {
        printf("The majority element is %d\n", candidate);
    } else {
        printf("No majority element found\n");
    }

    return 0;
}