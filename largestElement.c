#include <stdio.h>

int largest(int arr[], int n) {
    int max_val = arr[0];  // Initialize first element as maximum

    // Traverse the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    return max_val;
}

int main() {
    int n;

    // Input size of array
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Function call
    int result = largest(arr, n);
    printf("The largest element is: %d\n", result);

    return 0;
}
