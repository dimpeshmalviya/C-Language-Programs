/*
 * Zero Array Transformation
 *
 * Problem:
 * You are given an integer array 'nums' and a list of queries [li, ri, vali].
 * Each query allows selecting a subset of indices in range [li, ri] 
 * and decrementing each selected index by exactly 'vali'.
 *
 * Goal:
 * Return the minimum k (1-indexed) such that after applying the first k queries,
 * nums becomes a Zero Array (all elements are 0).
 * If impossible, return -1.
 *
 * Approach:
 *  - Simulate prefix-based range decrements using a difference array.
 *  - For each query [l, r, val]:
 *        diff[l] += val
 *        if (r + 1 < n) diff[r + 1] -= val
 *  - Keep track of cumulative effect, and check if nums becomes zero after k queries.
 *  - Stop and return k when all nums[i] ≤ 0 exactly after applying k queries.
 *
 * Time Complexity: O(n * q)
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <string.h>

int minQueriesToZeroArray(int nums[], int n, int queries[][3], int q) {
    int diff[1005];  // max queries = 1000, max nums.length = 10 (safe bound)
    int temp[1005];

    for (int k = 1; k <= q; k++) {
        // Reset difference array
        memset(diff, 0, sizeof(diff));

        // Apply first k queries as difference updates
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] += val;
            if (r + 1 < n) diff[r + 1] -= val;
        }

        // Apply cumulative effect to copy of nums
        memcpy(temp, nums, n * sizeof(int));

        int current = 0;
        for (int i = 0; i < n; i++) {
            current += diff[i];
            temp[i] -= current;
        }

        // Check if zero array
        int allZero = 1;
        for (int i = 0; i < n; i++) {
            if (temp[i] != 0) {
                allZero = 0;
                break;
            }
        }

        if (allZero)
            return k;
    }

    return -1;
}

int main() {
    // Test Case 1
    int nums1[] = {2, 0, 2};
    int queries1[][3] = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int q1 = sizeof(queries1) / sizeof(queries1[0]);
    printf("Output 1: %d\n", minQueriesToZeroArray(nums1, n1, queries1, q1)); // 2

    // Test Case 2
    int nums2[] = {4, 3, 2, 1};
    int queries2[][3] = {{1, 3, 2}, {0, 2, 1}};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    int q2 = sizeof(queries2) / sizeof(queries2[0]);
    printf("Output 2: %d\n", minQueriesToZeroArray(nums2, n2, queries2, q2)); // -1

    // Test Case 3
    int nums3[] = {1, 2, 3, 2, 1};
    int queries3[][3] = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 4, 1}};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    int q3 = sizeof(queries3) / sizeof(queries3[0]);
    printf("Output 3: %d\n", minQueriesToZeroArray(nums3, n3, queries3, q3)); // 4

    // Test Case 4
    int nums4[] = {1, 2, 3, 2, 6};
    int queries4[][3] = {{0, 1, 1}, {0, 2, 1}, {1, 4, 2}, {4, 4, 4}, {3, 4, 1}, {4, 4, 5}};
    int n4 = sizeof(nums4) / sizeof(nums4[0]);
    int q4 = sizeof(queries4) / sizeof(queries4[0]);
    printf("Output 4: %d\n", minQueriesToZeroArray(nums4, n4, queries4, q4)); // 4

    return 0;
}
