#include <stdio.h>
#include <math.h>

// Function to perform jump search
int jumpSearch(int arr[], int n, int target) {
    int step = sqrt(n); // jump size
    int prev = 0;

    // Jump ahead until we find a block containing the target
    while (arr[(step < n ? step : n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; // target not found
        }
    }

    // Linear search within the block
    for (int i = prev; i < (step < n ? step : n); i++) {
        if (arr[i] == target) {
            return i; // target found, return index
        }
    }

    return -1; // target not found
}

int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    int index = jumpSearch(arr, n, target);

    if (index != -1)
        printf("Element %d found at index %d.\n", target, index);
    else
        printf("Element %d not found in the array.\n", target);

    return 0;
}
