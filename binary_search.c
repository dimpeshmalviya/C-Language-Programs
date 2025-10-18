/*
binary_search.c
Perform iterative binary search on a sorted array of integers.

Compile:
  gcc -o binary_search binary_search.c

Usage:
  ./binary_search
  Number of elements: 5
  Enter 5 sorted integers: 1 3 5 7 9
  Enter target: 7
  Found at index 3 (0-based)
*/
#include <stdio.h>

int binary_search(int a[], int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        else if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main(void) {
    int n;
    printf("Number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int a[n];
    printf("Enter %d sorted integers: ", n);
    for (int i = 0; i < n; ++i) if (scanf("%d", &a[i]) != 1) return 1;
    int target;
    printf("Enter target: ");
    if (scanf("%d", &target) != 1) return 1;
    int idx = binary_search(a, n, target);
    if (idx >= 0) printf("Found at index %d (0-based)\n", idx);
    else printf("Not found\n");
    return 0;
}
