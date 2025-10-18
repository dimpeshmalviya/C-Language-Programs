/*
 * Shell Sort Algorithm
 * --------------------
 * Shell sort is an in-place comparison-based sorting algorithm.
 * It generalizes insertion sort by allowing exchanges of elements far apart.
 * The algorithm starts with a large gap and reduces it until it becomes 1,
 * performing a gapped insertion sort at each step.
 *
 * Time complexity varies based on the gap sequence,
 * average around O(n^(3/2)) for the commonly used gaps.
 */

#include <stdio.h>

void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 34, 54, 2, 3, 7, 19, 45};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
