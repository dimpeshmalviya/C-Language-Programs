#include <stdio.h>

// Function to swap values at two pointers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to check if swapping will produce a duplicate permutation
int shouldSwap(int arr[], int start, int curr) {
    for (int i = start; i < curr; i++) {
        if (arr[i] == arr[curr])
            return 0;
    }
    return 1;
}

// Recursive function to generate all permutations
void permute(int arr[], int l, int r) {
    if (l == r) {
        for (int i = 0; i <= r; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for (int i = l; i <= r; i++) {
        if (shouldSwap(arr, l, i)) {
            swap(&arr[l], &arr[i]);
            permute(arr, l + 1, r);
            swap(&arr[l], &arr[i]); // backtrack
        }
    }
}

int main() {
    int arr[] = {1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    permute(arr, 0, n - 1);
    return 0;
}
