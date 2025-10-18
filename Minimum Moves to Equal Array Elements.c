/*
 * Minimum Moves to Equal Array Elements
 *
 * Problem:
 * You are given an integer array 'nums'.
 * In one move, you can increment n - 1 elements by 1.
 * You must find the minimum number of moves required to make all array elements equal.
 *
 * Approach:
 * - Observation: Incrementing n - 1 elements by 1 is equivalent to
 *   decrementing 1 element by 1 each move (simplifies reasoning).
 * - Therefore, total moves = sum(nums) - n * min(nums).
 * - This works because every element must be reduced to the smallest one.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int minMoves(int* nums, int numsSize) {
    int minVal = nums[0];
    long long sum = nums[0];

    // Find minimum element and total sum
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minVal)
            minVal = nums[i];
        sum += nums[i];
    }

    // Formula: total moves = sum(nums) - n * min(nums)
    return (int)(sum - (long long)numsSize * minVal);
}

int main() {
    // Test Case 1
    int nums1[] = {1, 2, 3};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output 1: %d\n", minMoves(nums1, n1)); // 3

    // Test Case 2
    int nums2[] = {5, 6, 8, 8};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output 2: %d\n", minMoves(nums2, n2)); // 5

    // Test Case 3
    int nums3[] = {1, 1, 1};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output 3: %d\n", minMoves(nums3, n3)); // 0

    return 0;
}
