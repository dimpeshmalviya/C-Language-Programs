#include <stdio.h>

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    // Start from the second element (element at index 1)
    // as the first element is already considered sorted.
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // The element to be inserted into the sorted portion
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position.
        // This loop shifts elements to the right to make space for the key.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Place the key at its correct position in the sorted subarray.
        arr[j + 1] = key;
    }
}

int main() {
    int data[] = {12, 11, 13, 5, 6};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted array: ");
    printArray(data, n);

    insertionSort(data, n);

    printf("Sorted array:   ");
    printArray(data, n);

    return 0;
}