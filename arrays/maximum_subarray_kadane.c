/**
 
 * Program Name: Maximum Subarray Sum (Kadane's Algorithm)
 *
 * Problem Statement:
 * Given an array of integers, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Input/Output Examples:
 * 1. Input Array: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 * Output: The maximum subarray sum is 6
 * (The subarray is [4, -1, 2, 1])
 *
 * 2. Input Array: [5, 4, -1, 7, 8]
 * Output: The maximum subarray sum is 23
 * (The subarray is the entire array)
 *
 * Complexity:
 * - Time Complexity: O(n) - The array is traversed only once.
 * - Space Complexity: O(1) - Only a few variables are used for storage.
 *
 */

#include <stdio.h>

// A utility function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Implements Kadane's Algorithm to find the maximum subarray sum.
int maxSubArraySum(int arr[], int n) {
    if (n <= 0) {
        return 0; // Or handle as an error
    }

    int max_so_far = arr[0];
    int current_max = arr[0];

    for (int i = 1; i < n; i++) {
        // The current max is either the current element itself,
        // or the current element combined with the previous subarray sum.
        current_max = max(arr[i], current_max + arr[i]);

        // Update the overall maximum sum found so far.
        max_so_far = max(max_so_far, current_max);
    }
    return max_so_far;
}

// Main function to drive the program.
int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = maxSubArraySum(arr, n);
    printf("The maximum subarray sum is %d\n", max_sum);

    return 0;
}