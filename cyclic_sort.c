#include <stdio.h>

// Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform cyclic sort
void cyclicSort(int arr[], int n) {
    int i = 0;
    while (i < n) {
        int correctIndex = arr[i] - 1;

        // If current element is not at its correct position, swap it
        if (arr[i] != arr[correctIndex]) {
            swap(&arr[i], &arr[correctIndex]);
        } else {
            i++; // Move to next index
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {3, 5, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr, n);

    cyclicSort(arr, n);

    printf("After sorting:  ");
    printArray(arr, n);

    return 0;
}
