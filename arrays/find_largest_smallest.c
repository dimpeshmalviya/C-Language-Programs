// largest_smallest_array.c
#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int largest, smallest;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize largest and smallest with the first element
    largest = smallest = arr[0];

    // Compare each element
    for(i = 1; i < n; i++) {
        if(arr[i] > largest)
            largest = arr[i];
        if(arr[i] < smallest)
            smallest = arr[i];
    }

    // Display results
    printf("\nLargest element = %d\n", largest);
    printf("Smallest element = %d\n", smallest);

    return 0;
}
