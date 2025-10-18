/*
 * Equalize Array Elements by Doubling
 *
 * Problem:
 * You can double any element in an array.
 * Find the minimum number of operations required to make all elements equal.
 * Return -1 if impossible.
 *
 * Example:
 * Input : [4, 8, 16]
 * Output: 2
 *
 * Approach:
 *  - Find the maximum element (target)
 *  - For each element:
 *        while (num < target):
 *            num *= 2
 *            count++
 *        if (num != target) => impossible
 *  - Return total count
 *
 * Time Complexity: O(n log M)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int equalizeByDoubling(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int operations = 0;

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        while (num < max) {
            num *= 2;
            operations++;
        }
        if (num != max)
            return -1; // can't make equal
    }

    return operations;
}

int main() {
    int arr1[] = {4, 8, 16};
    int arr2[] = {3, 10, 6};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Output 1: %d\n", equalizeByDoubling(arr1, n1)); // 2
    printf("Output 2: %d\n", equalizeByDoubling(arr2, n2)); // -1

    return 0;
}
