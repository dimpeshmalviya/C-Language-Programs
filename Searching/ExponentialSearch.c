#include <stdio.h>

// Standard Binary Search function
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Exponential Search function
int exponentialSearch(int arr[], int n, int target) {
    if (arr[0] == target)
        return 0;

    int i = 1;
    // Find the range for binary search by repeated doubling
    while (i < n && arr[i] <= target)
        i = i * 2;

    // Call binary search for the found range
    return binarySearch(arr, i / 2, (i < n) ? i : n - 1, target);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = exponentialSearch(arr, n, target);
    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
