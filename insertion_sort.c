// Start from the second element of the array (index 1) and consider it as the “key”.

// Compare the key with all elements before it.

// Shift all elements that are greater than the key one position to the right.

// Insert the key in its correct position.

// Repeat steps 1–4 for all elements until the array is sorted.

//Sample Input : 
//n=5
//arr = [4,2,5,1,3]
//Sample output
// arr = [1,2,3,4,5]


//Code
#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

int main() {
    int n, i, j, key;
    int *arr = NULL; // Pointer to the array

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of elements.\n");
        return 1;
    }

    // 1. Dynamic Allocation using malloc()
    // Allocate memory for n integers (n * sizeof(int) bytes)
    arr = (int *)malloc(n * sizeof(int)); 

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Return an error code
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input for array element.\n");
            free(arr); // Clean up allocated memory before exiting
            return 1;
        }
    }

    // --- Insertion Sort Algorithm ---
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1; 
        
        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insert the key into its correct position
        arr[j + 1] = key;
    }

    // --- Output Section ---
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 2. Freeing the memory
    // Always release dynamically allocated memory when done
    free(arr);

    return 0;
}